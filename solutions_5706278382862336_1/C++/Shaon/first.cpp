#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

int main(){

    freopen("A-large.in","r",stdin);
    freopen("out.out","w",stdout);


    LL p ,q;
    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        scanf("%lld/%lld",&p,&q);

        LL d = __gcd(p,q);
        p/=d;
        q/=d;

        LL x=1;

        LL save = q;
        while ( save != 1 ){
            if ( save%2!=0 )break;
            save /=2;
        }

        printf("Case #%d: ",kk);
        if ( save != 1 ){
            printf("impossible\n");
            continue;
        }

        LL cnt = 0;

        while ( true ){
            if ( p >= q ){
                break;
            }else{
                cnt++;
                q/=2;
            }
        }

        printf("%d\n",cnt);

    }


    return 0;
}
