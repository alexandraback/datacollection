#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;

#define PI 2*acos(0.0)
#define FOR(i,n) for(int i = 0;i<n;++i)
#define setbit(a,b) a|=(1<<b)
#define S1(a) scanf("%d",&a)
#define S2(a,b) scanf("%d %d",&a,&b)
#define S3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define C1(a) __builtin_popcount(a)
#define gcd(a,b) __gcd(a,b)
#define ALL(a) (a.begin(),a.end())

typedef long long LL;
typedef vector<int> vi;
const int INF = (1LL<<31)-1;

int sum[25*100000];
vector< int > v;

int main(){

    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-Small_output.txt","w",stdout);
    int t;
    S1(t);

    for(int ca = 1;ca<=t;++ca){

        int n;
        S1(n);

        memset(sum,0,sizeof(sum));
        int A[22];
        for(int i = 0;i<n;++i)
            S1(A[i]);

        v.clear();
        v.push_back(0);
        for(int i = 0;i<n;++i){
            int sz = v.size();
            for(int j = 0;j<sz;++j){
                int a = v[j]+A[i];
                if( !sum[a] )
                    v.push_back(a);
                sum[a]++;
            }
        }
        int mask1,mask2;
        int S = -1;
        for(int i = 1;i<21*100000;++i )if(sum[i]>1){
            S= i;break;
        }

        printf("Case #%d:\n",ca);

        if(S==-1)
            puts("Impossible");
        else{
            for(int i = 0;i<(1<<20);++i){
                int ss = 0;
                for(int j = 0;j<20;++j)if(i&(1<<j))
                    ss += A[j];
                if(ss==S){
                    mask1 = i;break;
                }
            }
            for(int i = mask1+1;i<(1<<20);++i){
                int ss = 0;
                for(int j = 0;j<20;++j)if(i&(1<<j))
                    ss += A[j];
                if(ss==S&&i!=mask2){
                    mask2 = i;break;
                }
            }
            bool s = false;
            for(int i = 0;i<20;++i)if(mask1&(1<<i)){
                if(s)
                    printf(" ");
                printf("%d",A[i]);
                s = true;
            }puts("");
            s = false;
            for(int i = 0;i<20;++i)if(mask2&(1<<i)){
                if(s)
                    printf(" ");
                printf("%d",A[i]);
                s = true;
            }puts("");
        }

    }
	return 0;

}
