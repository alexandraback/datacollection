#include<stdio.h>
#include<map>
#include<queue>
#include<string>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back

int n, s, m;
int a[110];
int f[110][1000010];

int main(){
    int ca; scanf("%d",&ca);
    FOE(tt,1,ca){
        scanf("%d%d",&s, &n);
        FOR(i,0,n) scanf("%d",&a[i]);
        sort(a,a+n);
        m = a[n-1]+1;

        if (s==1){
            printf("Case #%d: %d\n", tt, n);
            continue;
        }

        int ans = n;
        FOR(i,0,n){
            int x=0, p=s;
            FOE(j,0,i){
                if (p > a[j]) p+=a[j];
                else{
                    while (p <= a[j]){
                        x+=1;
                        p=p*2-1;
                    }
                    p += a[j];
                }
            }
            int cnt = n-i-1 + x;
            ans = min(ans, cnt);
        }

        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}
