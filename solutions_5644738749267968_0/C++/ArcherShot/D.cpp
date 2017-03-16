#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <numeric>
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define sqr(x) ((x)*(x))
using namespace std;
const int INF = 0x3f3f3f3f;
typedef long long ll;
template<typename X> inline bool minimize(X&p,X q){if(p<=q)return 0;p=q;return 1;}
template<typename X> inline bool maximize(X&p,X q){if(p>=q)return 0;p=q;return 1;}
double A[1005],B[1005];
const double eps=1e-6;
int main()
{
//    freopen("D.in","r",stdin);
//    freopen("D.out","w",stdout);
    int T;
    cin>>T;
    int N;
    for(int t=1;t<=T;++t){
        cin>>N;
        for(int i=0;i<N;++i)cin>>A[i];
        for(int j=0;j<N;++j)cin>>B[j];
        sort(A,A+N);
        sort(B,B+N);
        int y=0,z=0;
        for(int i=0,j=0;i<N;++i){
            j=upper_bound(B+j,B+N,A[i])-B;
            if(j==N)++z;
            else ++j;
        }
        for(int i=0,j=0;i<N;++i){
            if(A[i]>B[j]){
                ++y;
                ++j;
            }
        }
        printf("Case #%d: %d %d\n",t,y,z);
    }
    return 0;
}
