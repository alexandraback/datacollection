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

LL dp[105][105];
int n,m;

struct data{
    LL tot,type;
}toy[105],box[105],bakup[105];

LL calc(int i,int j){

    if( i == n || j == m )
        return 0;

    LL &ret = dp[i][j];
    if( ret != -1 )
        return ret;

    ret = 0;

    LL rem = box[i].tot,sum = 0;
    for(int k = j;k<m;++k)if( box[i].type == toy[k].type ){
        LL got = min( rem,toy[k].tot );
        rem -= got;
        sum += got;
        ret = max( ret , calc( i+1,k+1 )+sum );
    }
    ret = max( ret , calc(i+1,j) );
    ret = max( ret , calc( i,j+1 ) );
    return ret;

}

int main(){

    freopen("C-small-attempt4.in","r",stdin);
    freopen("C-Small_output.txt","w",stdout);

    int t,N;
    S1(t);

    for(int ca = 1;ca<=t;++ca){

        S2(N,m);

        for(int i = 0;i<N;++i){
            cin>>box[i].tot>>box[i].type;
        }
        for(int i = 0;i<m;++i){
            cin>>toy[i].tot>>toy[i].type;
        }

        printf("Case #%d: ",ca);

        n = N;
        memset(dp,-1,sizeof(dp));
        LL res = 0;
        res = max( res , calc(0,0) );

        for(int i = 0;i<N;++i){
            bakup[i].tot = box[i].tot;
            bakup[i].type = box[i].type;
        }

        for(int i = 1;i<(1<<N);++i){

            for(int j = 0;j<N;++j){
                box[j].tot = bakup[j].tot;
                box[j].type = bakup[j].type;
            }

            memset(dp,-1,sizeof(dp));
            int least = 0;
            for(int j = 0;j<N;++j)if(i&(1<<j)){
                least = j;
                break;
            }
            n = least;
            for(int j = 0;j<N;++j)if(i&(1<<j)&&box[least].type==box[j].type){
                if(j!=least)
                    box[least].tot += box[j].tot;
            }
            else
                n = max(n,j);
            res = max( res  , calc(0,0) );

        }
        cout<<res<<endl;

    }
    return 0;

}
