#include <bits/stdc++.h>
using namespace std;
#define read            freopen("C:\\Users\\Dell\\Desktop\\in.txt", "r", stdin)
#define write           freopen("C:\\Users\\Dell\\Desktop\\out.txt", "w", stdout)
#define pii             pair<LL , LL >
#define inf             INT_MAX/3
#define linf            LLONG_MAX/3
#define in(a)           scanf("%lld", &a)
#define ins(a)          scanf("%s", a)
#define in2(a, b)       scanf("%lld%lld", &a, &b)
#define in3(a, b, c)    scanf("%lld%lld%lld", &a, &b, &c)
#define pn              printf("\n");
#define pr(a)           printf("%lld\n", a)
#define prs(a)          printf("%lld ", a)
#define pr2(a, b)       printf("%lld %lld\n", a, b)
#define pr3(a, b, c)    printf("%lld %lld %lld\n", a, b, c)
#define pcs(a)          printf("Case %lld: ", a)
#define MP              make_pair
#define vi              vector<LL >
#define cl              clear()
#define sz              size()
#define pb              push_back
#define MEM(a, b)       memset((a), (b), sizeof(a))
#define all(X)          (X).begin(), (X).end ()
#define iter(it, X)     for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define oka(x, y)       ((x)>=0&&(x)<row&&(y)>=0&&(y)<col)

typedef long long LL;
inline LL getnum()
{
    char c = getchar();
    LL num,sign=1;
    for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;
    for(num=0;c>='0'&&c<='9';)
    {
        c-='0';
        num = num*10+c;
        c=getchar();
    }
    return num*sign;
}
string haircut(string a)
{
    LL l=0, r=a.size()-1, i;
    string b;
    while (l<a.size()&&a[l]==')'&&a[i]!=']') l++;
    while (r>=0&&a[r]=='('&&a[i]!='[') r--;
    for (i=l; i<=r; i++) b+=a[i];
    return b;
}
//LL  dx[]={1,0,-1,0};LL dy[]={0,1,0,-1}; //4 Direction
//LL  dx[]={1,1,0,-1,-1,-1,0,1};LL dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//LL  dx[]={2,1,-1,-2,-2,-1,1,2};LL dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
bool check(LL n, LL pos) {return (n & (((LL)1)<<pos))>>pos;} //typecast 1 in case of int
//LL  on(LL n, LL pos) {return n | (1<<pos);} //typecast 1 in case of int
//LL  off(LL n, LL pos) {return n & ~(1<<pos);} //typecast 1 in case of int
//bool operator < (const data &d) const{return cost<d.cost;} //reverse in priority queue

const LL M=500100;
LL A[100][100];
int main()
{
#ifndef ONLINE_JUDGE
    read;
    write;
#endif
    LL t, cs=0, i, j, k, n, w;

    in(t);
    while (t--)
    {
        in2(n, w);
        MEM(A, 0);

        printf("Case #%lld: ", ++cs);
        if (w>(((LL)1)<<(n-2)))
        {
            printf("IMPOSSIBLE\n");
            continue;
        }

        printf("POSSIBLE\n");
        for (i=2; i<n; i++)
            for (j=i+1; j<=n; j++) A[i][j]=1;


        if (w==(((LL)1)<<(n-2)))
        {
            for (i=2; i<=n; i++) A[1][i]=1;
        }
        else
        {
            for (i=60; i>=0; i--)
            {
                if (check(w, i))
                {
                    k=n-1-i;
                    A[1][k]=1;
                }
            }
        }


        for (i=1; i<=n; i++)
        {
            for (j=1; j<=n; j++)
            {
                printf("%d", A[i][j]);
            }
            pn;
        }

    }


return 0;
}
