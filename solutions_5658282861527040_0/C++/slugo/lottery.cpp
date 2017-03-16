#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

#define SORT(x) sort(x.begin(),x.end())
#define REVERSE(x) reverse(x.begin(),x.end())
#define mp(x,y) make_pair(x,y)

using namespace std;

typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<VI> VII;

int main()
{
    ios_base::sync_with_stdio(false);

    freopen("lot.in","r",stdin);
    freopen("lot.out","w",stdout);

    int T;
    cin>>T;
    int t=1;
    while(T--){
    int A,B,K;
    cin>>A>>B>>K;
    int res = 0;
    for(int k=0;k<A;k++)
        for(int i=0;i<B;i++){
            if( (k&i)<K ){
                res++;
                //cout<<k<<" "<<i<<endl;
            }
        }
    cout<<"Case #"<<t<<": "<<res<<endl;
    t++;
    }

    return 0;
}
