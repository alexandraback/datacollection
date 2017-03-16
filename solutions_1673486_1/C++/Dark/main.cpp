#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <string>
#include <set>
#include <cstring>
using namespace std;
#define For(i,n) for(int i=0;i<n;i++)
#define sz(i) int(i.size())
#define mst(i,n) memset(i,n,sizeof(i))
#define eps 1e-9
#define INF 1e20
#define MOD 1000000007
#define LL long long
#define pi acos(-1)
LL gcd(LL a,LL b){if(a==0)return b;return gcd(b%a,a);}
int main(){
    int t;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&t);
    For(ca,t){
        int A,B;
        double p[100005];
        scanf("%d %d",&A,&B);double ans=2+B;
        For(i,A)scanf("%lf",&p[i]);
        double t=1.0;
        For(i,A+1){
            double cmp=(B-A+(A-i)*2+1)*(t)+(1-t)*(B-A+(A-i)*2+2+B);
            t*=p[i];
            //printf("@%d %d %lf\n",(B-A+(A-i)*2+1),B-A+(A-i)*2+2+B,cmp);
            if(cmp<ans)ans=cmp;
        }
        printf("Case #%d: %lf\n",ca+1,ans);
    }
}
