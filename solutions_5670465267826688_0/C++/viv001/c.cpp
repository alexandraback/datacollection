
// Author : Vivek Hamirwasia (viv001)
#include<bits/stdc++.h>
using namespace std;

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define LET(x,a) __typeof(a) x(a)
#define MP make_pair
#define tr(container , it) for(LET(it,container.begin) ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LLD long long
#define VI vector < int >
#define PII pair < int , int >
#define MAX 1000000000
#define gi(x) scanf("%d",&x)
//_____starts____here_______
string s,r;
int A[5][5];
int pre[1000002];

int conv(char ch)
{
    if(ch=='i') return 2;
    if(ch=='j') return 3;
    if(ch=='k') return 4;
    return 1;
}

int calc(int a, int b)
{
    int sgn = 1;
    if(a<0) sgn*=-1;
    if(b<0) sgn*=-1;
    return sgn*A[abs(a)][abs(b)];
}

int main()
{

    for(int i=1;i<=4;i++)
        A[1][i] = i;
    A[2][1] = 2;
    A[2][2] = -1;
    A[2][3] = 4;
    A[2][4]  = -3;
    A[3][1] = 3;
    A[3][2] = -4;
    A[3][3] = -1;
    A[3][4] = 2;
    A[4][1] = 4;
    A[4][2] = 3;
    A[4][3] = -2;
    A[4][4] = -1;

    int t;
    cin>>t;
    int kase=0;
    while(kase++<t)
    {
        int l,x;
        cin>>l>>x;
        cin>>s;
        r = "";

        for(int i=0;i<x;i++)
            r += s;

        pre[0] = conv(r[0]);
        int lim = l*x;
        for(int i=1;i<lim;i++)
            pre[i] = calc(pre[i-1], conv(r[i]));
       
        cout<<"Case #"<<kase<<": ";
        if(pre[lim-1]!=-1)
        {
            cout<<"NO\n";
            continue;
        }

        bool f1=0;
        bool ans = false;
        for(int i=0;i<lim-1;i++)
        {
            if(!f1)
            {
                if(pre[i]==2)
                    f1 = true;
            }
            else
                if(pre[i]==4)
                {
                    ans = true;
                    break;
                }
        }
        if(ans)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}


