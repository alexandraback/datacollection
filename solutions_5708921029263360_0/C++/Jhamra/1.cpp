#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pair<int,int> >
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define SIZE 10000002
using namespace std;

inline ll getnum()
{
    char c = getchar();
    ll num,sign=1;
    for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;
    for(num=0;c>='0'&&c<='9';)
    {
        c-='0';
        num = num*10+c;
        c=getchar();
    }
    return num*sign;
}

int A[20][20],B[20][20],C[20][20];
vector<piii > V;

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int tests=getnum();

    for(int cases=1;cases<=tests;cases++)
    {
        int a=getnum(),b=getnum(),c=getnum(),lim=getnum();

        //int ans=min(a*b,min(b*c,a*c));

        if(a+b+c==3)
        {
            printf("Case #%d: 1\n1 1 1\n",cases);
            continue;
        }

        int flag=1;

        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
            {
                for(int k=1;k<=c;k++)
                {
                    if(A[i][j]>=lim||B[i][k]>=lim||C[j][k]>=lim)continue;
                    flag=0;
                    A[i][j]++;
                    B[i][k]++;
                    C[j][k]++;
                    V.pb(mp(i,mp(j,k)));
                }
            }
        }

        printf("Case #%d: %d\n",cases,V.size());

        for(int i=0;i<V.size();i++)
        {
            printf("%d %d %d\n",V[i].ff,V[i].ss.ff,V[i].ss.ss);
        }

        V.clear();
        for(int i=1;i<=10;i++)for(int j=1;j<=10;j++)A[i][j]=B[i][j]=C[i][j]=0;
    }
}
