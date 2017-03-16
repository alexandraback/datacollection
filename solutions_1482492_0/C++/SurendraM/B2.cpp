/*	SURENDRA KUMAR MEENA	*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <queue>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long int LL;
#define ALL(s) (s).begin(),(s).end()
#define R(i,m,n)	for(int i=m;i>=n;i--)
#define FF(i,m,n)	for(int i=m;i<n;i++)
#define F(i,n)	FF(i,0,n)
#define VI vector<int>
#define PB push_back
#define CLR(s,v) memset(s,v,sizeof(s))
string to_str(LL x){ ostringstream o;o<<x;return o.str();}
LL to_int(string s){ istringstream st(s); LL i;	st>>i;return i;}
#define FR(it,t) for(typeof(t.begin()) it=t.begin(); it!=t.end(); ++it)
typedef pair<int,int> PI;
#define MP(x,y) make_pair(x,y)
#define f first
#define s second
#define VP vector<PI>
#define S(t)	scanf("%d",&t)

double eps = 1e-7;

int main(){
    int t;
    cin>>t;
    FF(kase,1,t+1){
        cout<<"Case #"<<kase<<":\n";
        
        double D;
        int N,A;
        cin>>D>>N>>A;
        
        vector<double> t(N), x(N);
        F(i,N)
             cin>>t[i]>>x[i];
        
        F(z,A) {
            double a;
            cin>>a;
            double ans=0.;
            double prvX = 0.;
            double prvT = 0.;
            double prvV = 0.;
            
            F(i,N) {
                if(N>1 && i==0) continue;
                double curT = t[i];
                double curX = x[i];

                if(i>0) {
                double vel = (x[i]-x[i-1])/(t[i]-t[i-1]);
                if(curX > D) {
                    double dist = D - x[i-1];
                    if(dist < 0.)  dist = 0.;
                    double timeTaken = dist / vel;
                    curT = timeTaken + t[i-1];
                    curX = D;
                }
                }
                
                double timeTaken = 0;
                
                if(i>0) {
                    timeTaken = sqrt(2.*D/a);
                    if(timeTaken < curT){
                        timeTaken = curT;
                    }
                }
                else{
                    timeTaken = sqrt(2. * min(D,x[0]) / a);
                }
                
                ans = timeTaken;
//                cout<<i<<" ::: "<<ans<<endl;
            }
            printf("%.8lf\n",ans);
        }
    }
    return 0;
}
