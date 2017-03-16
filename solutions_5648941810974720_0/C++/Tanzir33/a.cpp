#include<bits/stdc++.h>
using namespace std;

#define FRE(i,a,b)  for(i = a; i <= b; i++)
#define FRL(i,a,b)  for(i = a; i < b; i++)
#define mem(t, v)   memset ((t) , v, sizeof(t))
#define all(x)      x.begin(),x.end()
#define un(x)       x.erase(unique(all(x)), x.end())
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sl(n)       scanf("%lld", &n)
#define sll(a,b)    scanf("%lld %lld", &a, &b)
#define slll(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
#define D(x)        cout<<#x " = "<<(x)<<endl
#define DBG         pf("Hi\n")
#define pf          printf
#define pii         pair <int, int>
#define pll         pair <LL, LL>
#define pb          push_back
#define PI          acos(-1.00)
#define sz          size()
#define xx          first
#define yy          second
#define eps         1e-9

typedef long long int LL;
typedef double db;
string s;
int cnt[500], A[20];
string dig[20] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
void go(int i)
{
    for(int j = 0; j<dig[i].sz; j++)
    {
        cnt[dig[i][j]]-= A[i];
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i, j, k, cs, t;
    sf(t);
    FRE(cs,1,t)
    {
        cin >> s;
        for(i = 0; i<s.sz; i++)
        {
            cnt[s[i]]++;
        }
        A[0] = cnt[(int)'Z'];
        A[2] = cnt[(int)'W'];
        A[4] = cnt[(int)'U'];
        A[6] = cnt[(int)'X'];
        A[8] = cnt[(int)'G'];
        for(int i = 0; i<9; i+=2)
            go(i);
        A[5] = cnt[(int)'F'];
        go(5);
        A[7] = cnt[(int)'V'];
        go(7);
        A[3] = cnt[(int)'H'];
        go(3);

        A[1] = cnt[(int)'O'];
        go(1);

        A[9] = cnt[(int)'E'];
        go(9);
        for(int i = (int) '0'; i<=(int)'9'; i++);
            assert(cnt[i] == 0);

        printf("Case #%d: ",cs);
        for(int i = 0 ; i<10; i++)
        {
            for(int j = 1; j<=A[i]; j++)
                printf("%d",i);
        }
        puts("");
    }
    return 0;
}


