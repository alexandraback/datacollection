
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
int main()
{

    int t;
    cin>>t;
    int kase = 0;
    while(t--)
    {
        kase++;
        int s;
        cin>>s;
        string sh;
        cin>>sh;
        int val = 0;
        int ans = 0;
        for(int i=0;i<=s;i++)
        {
            if(sh[i]!='0')
            {
                if(val<i)
                {
                    ans += i-val;
                    val = i;
                }
            }
            val += (sh[i]-'0');
        }
        cout<<"Case #"<<kase<<": ";
        cout<<ans<<endl;

    }
    return 0;
}


