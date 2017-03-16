#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<queue>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define sqr(x) ((x)*(x))
#define MAX(a,b) if(a<b) a=b;
#define ll long long
using namespace std;


const int PRIME_MAX = 100000;
int N, J, cnt;
int a[50];
int p[100000], pc;
vector<int> pv[11][32]; 
bool flag[100000];


void prepare()
{
    for(int i = 2; i <= PRIME_MAX; i++)
    {
        if(flag[i] == 0)
        {
            p[pc++] = i;
            for(int j = 2; i * j <= PRIME_MAX; j++) 
            {
                flag[i * j] = 1;
            }
        }
    }
    for(int i = 2; i <= 10; i++)
    {
        for(int j = 0; j < 32; j++)
        {
            if(j == 0) for(int k = 0; k < pc; k++) pv[i][j].push_back(1);
            else
            {
                for(int k = 0; k < pc; k++)
                {
                    pv[i][j].push_back(pv[i][j - 1][k] * i % p[k]);
                }
            }
        }
    }
}
void dfs(int d)
{
    if(cnt == J) return;
    if(d == N - 2)
    {
        int i, j, k;
        int b[12];
        for(i = 2; i <= 10; i++)     
        {

            int x = 1;
            int y = 1;
            for(j = 0; j < N - 2; j++)
            {
                x *= i;
                if(x > PRIME_MAX){ y = -1; break;}
                if(a[j]) y += x;
            }
            if(y != -1)
            {
                x *= i;
                y += x;
            }
            for(j = 0; j < pc; j++)
            {
                int cnt = pv[i][0][j] + pv[i][N - 1][j];
                for(k = 0; k < N - 2; k++) if(a[k]) cnt += pv[i][1 + k][j];
                if(cnt % p[j] == 0 && p[j] != y)
                {
                    break;
                }
            }
            if(j < pc)
            {
                b[i] = p[j];
                continue; 
            }
            break;
        }
        if(i == 11)
        {
            printf("1"); 
            for(i = N - 3; i >= 0; i--) printf("%d", a[i]);
            printf("1"); 
            for(i = 2; i <= 10; i++) printf(" %d", b[i]);
            printf("\n");
            cnt += 1; 

        }
        return;
    }

    a[d] = 0;
    dfs(d + 1);
    a[d] = 1;
    dfs(d + 1);
}
int main() {
    freopen("/home/zyc/Downloads/in", "r", stdin);
    freopen("/home/zyc/Downloads/out", "w", stdout);

//    freopen("in", "r", stdin);
    prepare();

    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d", &N, &J);
        printf("Case #%d:\n", cas);
        dfs(0);
    }
    return 0;
}
