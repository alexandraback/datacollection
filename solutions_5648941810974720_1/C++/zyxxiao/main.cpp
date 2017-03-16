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
#define MAXN 2005
#define inf 0x3f3f3f3f
typedef long long ll ;
const double eps =1e-8;
const int mod = 1000000007;
typedef pair<int, int> P;
const double PI = acos(-1.0);

int a[MAXN];
int b[MAXN];
int c[MAXN];
char s[MAXN];
int dp[MAXN];
bool vis[MAXN];
int n,m;
int ans;


int main()
{
    freopen("A-large (1).in","r",stdin);
    freopen("1.out","w",stdout);
    int t,ca = 1;
    int p,q;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int l = strlen(s);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i = 0 ; i < l ; i++){
            a[s[i]]++;
        }
        while(a['Z']>=1 && a['E']>=1 && a['R']>=1 && a['O']>=1){
            b[0]++;
            a['Z']--;a['E']--;a['R']--;a['O']--;
        }
        while(a['F']>=1 && a['U']>=1 && a['R']>=1 && a['O']>=1){
            b[4]++;
            a['F']--;a['U']--;a['R']--;a['O']--;
        }
        while(a['E']>=1 && a['I']>=1 && a['G']>=1 && a['H']>=1 && a['T']>=1){
            b[8]++;
            a['E']--;a['I']--;a['G']--;a['H']--;a['T']--;
        }
        while(a['T']>=1 && a['E']>=2 && a['R']>=1 && a['H']>=1){
            b[3]++;
            a['T']--;a['E']-=2;a['R']--;a['H']--;
        }
        while(a['F']>=1 && a['I']>=1 && a['V']>=1 && a['E']>=1){
            b[5]++;
            a['F']--;a['I']--;a['V']--;a['E']--;
        }
        while(a['S']>=1 && a['I']>=1 && a['X']>=1 ){
            b[6]++;
            a['S']--;a['I']--;a['X']--;
        }
        while(a['S']>=1 && a['E']>=2 && a['V']>=1 && a['N']>=1){
            b[7]++;
            a['S']--;a['E']-=2;a['V']--;a['N']--;
        }
        while(a['N']>=2 && a['I']>=1 && a['E']>=1 ){
            b[9]++;
            a['N']--;a['I']--;a['N']--;a['E']--;
        }


        while(a['O']>=1 && a['N']>=1 && a['E']>=1){
            b[1]++;
            a['O']--;a['N']--;a['E']--;
        }
        while(a['O']>=1 && a['T']>=1 && a['W']>=1){
            b[2]++;
            a['O']--;a['W']--;a['T']--;
        }






        printf("Case #%d: ",ca++);
        for(int i = 0 ; i < 10 ; i++){
            while(b[i]){
                printf("%d",i);
                b[i]--;
            }
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
