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

int B;
ll M;
bool a[55][55];
ll p2[60];

int main() {
    freopen("in","r",stdin);
    freopen("out", "w", stdout);
    int T;
    scanf("%d", &T);
    p2[0] = 1;
    for(int i = 1; i < 60; i++) p2[i] = p2[i - 1] * 2;
    for(int cas = 0; cas < T; cas++)
    { 
        scanf("%d%lld", &B, &M);
        clr(a, 0);
        for(int i = 0; i < B; i++) for(int j = i + 1; j < B; j++) a[i][j] = 1;
        printf("Case #%d: ", cas + 1);
        if(p2[B - 2] < M) printf("IMPOSSIBLE\n");
        else
        {
            printf("POSSIBLE\n");

            if(p2[B - 2] != M)
            {
                a[0][B - 1] = 0;
                for(int i = 0; i < B - 1; i++)
                {
                    if((p2[i] & M) == 0) 
                    {
                        a[i + 1][B - 1] = 0;
                    }
                }
            }

            for(int i = 0; i < B; i++)
            {
                for(int j = 0; j < B; j++)
                {
                    if(a[i][j]) printf("1"); 
                    else printf("0");
                }
                puts("");
            }
        }    
    }

    return 0;
}
