/*    brioso     */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
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

map<string,int> m1;
map<string,int> m2;
set<string> s1;
set<string> s2;
struct node{
    string s;
    string t;
} a[MAXN];
bool cmp(node a,node b){
    return min(m1[a.s],m2[a.t])< min(m1[b.s],m2[b.t]);
}
int b[MAXN];
int c[MAXN];
char s[MAXN];
int dp[MAXN];
bool vis[MAXN];
int n,m;
int ans;


int main()
{
    freopen("C-small-attempt5 (1).in","r",stdin);
    freopen("1.out","w",stdout);
    int t,ca = 1;
    int p,q;
    scanf("%d",&t);
    while(t--){
        m1.clear();
        m2.clear();
        s1.clear();
        s2.clear();
        map<string,int>::iterator mit1;
        map<string,int>::iterator mit2;
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++){
            cin >> a[i].s >> a[i].t;
            mit1 = m1.find(a[i].s);
            if(mit1 != m1.end()){
                int p = m1[a[i].s];
                p++;
                m1.insert(pair<string,int>(a[i].s,p));
            }
            else m1.insert(pair<string,int>(a[i].s,1));
            mit2 = m2.find(a[i].t);
            if(mit2 != m2.end()){
                int p = m2[a[i].t];
                p++;
                m2.insert(pair<string,int>(a[i].t,p));
            }
            else m2.insert(pair<string,int>(a[i].t,1));
        }
        sort(a,a+n,cmp);
        s1.insert(a[0].s);
        s2.insert(a[0].t);
        set<string>::iterator it1;
        set<string>::iterator it2;
        ans = 0;
        for(int i = 1 ; i < n ; i++){
            it1 = s1.find(a[i].s);
            it2 = s2.find(a[i].t);
            if(it1 != s1.end() && it2 != s2.end())
                ans++;
            s1.insert(a[i].s);
            s2.insert(a[i].t);
        }
        printf("Case #%d: ",ca++);
        printf("%d\n",ans);
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
