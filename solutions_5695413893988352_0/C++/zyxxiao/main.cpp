/*    brioso     */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include<set>
#include<map>
#include<queue>

using namespace std;
#define MAXN 1005
#define inf 0x3f3f3f3f
typedef long long ll ;
const double eps =1e-8;
const int mod = 1000000007;
typedef pair<int, int> P;
const double PI = acos(-1.0);

int a[MAXN];
int b[MAXN];
int aa[MAXN];
int bb[MAXN];
int c[MAXN];
char s[MAXN];
char t[MAXN];
int dp[MAXN];
bool vis[MAXN];
int n,m;
int ans;


int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("1.out","w",stdout);
    int T,ca = 1;
    int p,q;
    int aa,bb;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        scanf("%s",t);
        int l = strlen(s);
        for(int i = 0 ; i < l ; i++){
            if(s[i]=='?')
                a[i] = -1;
            else a[i] = s[i]-'0';
        }
        for(int i = 0 ; i < l ; i++){
            if(t[i]=='?')
                b[i] = -1;
            else b[i] = t[i]-'0';
        }
        ans = inf;
        for(int i = 0 ; i < 1000 ; i++){
            if(l==1 && i >9)
                break;
            if(l==2 && i>99)
                break;
            p = 1;
            int now = 0;
            for(int k = l-1 ; k >= 0 ; k--){
                p *= 10;
                if(a[k]==-1)
                    continue;
                if(a[k] != i/(p/10)%10)
                    now = 1;
            }
            if(now)
                continue;
            for(int j = 0 ; j < 1000 ; j++){
                if(l==1 && j >9)
                    break;
                if(l==2 && j>99)
                    break;
                p = 1;
                int now = 0;
                for(int k = l-1 ; k >= 0 ; k--){
                    p *= 10;
                    if(b[k]==-1)
                        continue;
                    if(b[k] != j/(p/10)%10)
                        now = 1;
                }
                if(now)
                    continue;
                if(abs(i-j)<ans){
                    ans = abs(i-j);
                    aa = i;
                    bb = j;
                }
            }
        }
//        p = 0;
//        for(int i = l-1 ; i >= 0 ; i--){
//            if(a[i]==-1 && b[i]==-1){
//                a[i] = 0;
//                b[i] = 0;
//            }
//            else if(a[i]==-1){
//                a[i] = b[i];
//            }
//            else if(b[i]==-1){
//                b[i] = a[i];
//            }
//            else {
//                p = s[i]-t[i];
//            }
//        }
        printf("Case #%d: ",ca++);
        //printf("%d %d",aa,bb);
        for(int i = l-1 ; i >=0 ; i--){
            a[i] = aa%10;
            aa/=10;
        }
        for(int i = l-1 ; i >= 0 ; i--){
            b[i] = bb%10;
            bb/=10;
        }
        for(int i = 0 ; i < l ; i++){
            printf("%d",a[i]);
        }
        printf(" ");
        for(int i = 0 ; i < l ; i++){
            printf("%d",b[i]);
        }
        printf("\n");
    }
    return 0;
}


/*

unsigned   int   0～4294967295
int   2147483648～2147483647
unsigned long 0～4294967295
long   2147483648～2147483647
long long的最大值：9223372036854775807
long long的最小值：-9223372036854775808
unsigned long long的最大值：18446744073709551615

__int64的最大值：9223372036854775807
__int64的最小值：-9223372036854775808
unsigned __int64的最大值：18446744073709551615

*/
