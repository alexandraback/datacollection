#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <numeric>
#include <cassert>
using namespace std;
static const double EPS = 1e-10;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SS stringstream
#define DBG1(a) rep(_X,sz(a)){printf("%d ",a[_X]);}puts("");
#define DBG2(a) rep(_X,sz(a)){rep(_Y,sz(a[_X]))printf("%d ",a[_X][_Y]);puts("");}
#define bitcount(b) __builtin_popcount(b)
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

#define delete(a,n) a.erase(remove(all(a),n),a.end())
template<typename T, typename S> vector<T>& operator<<(vector<T>& a, S b) { a.push_back(b); return a; }
template<typename T> void operator>>(vector<T>& a, int b) {while(b--)if(!a.empty())a.pop_back();}
bool isprime(int n){ if(n<2)return false;  for(int i=2;i*i<=n;i++)if(n%i==0)return false;  return true;} 
ll b_pow(ll x,ll n){return n ? b_pow(x*x,n/2)*(n%2?x:1) : 1ll;}
string itos(int n){stringstream ss;ss << n;return ss.str();}

int output(int t){
}

int main(){
	//ios_base::sync_with_stdio(false);
	int T,t=0;
	cin >> T;
	while(T--){
		t++;
		printf("Case #%d:\n",t);
		int N,A;
		double D , t[2001] , x[2001];		
		cin >> D >> N >> A;
		if( N == 1 ){
			cin >> t[0]>> x[0];
			for(int i = 0 ; i < A ; i++){
				double a;
				cin >> a;
				double goalTime = sqrt( 2*D / a );
				printf("%.10lf\n",goalTime);
			}
			continue;
		}
		
		for(int i = 0 ; i < N ; i++) cin >> t[i] >> x[i];
		
		double ans = 0;
		//Dが目標地点なので気をつけて
		
		
		for(int _ = 0 ; _ < A ; _++){
			double a;
			cin >> a;
			double myCarTime = sqrt(2*D/a) , res = 0;

			double prevSpeed = 0;
			for(int i = 0 ; i < N-1 ; i++){
				double carSpeed  = (x[i+1] - x[i]) / (t[i+1] - t[i]);
				//cout << carSpeed << " < " << endl;
				double carTime = (min(D,x[i+1]) - x[i]) / carSpeed;
				
				

				
				if( x[i+1] >= D && 0.5 * a * t[i]*t[i] >= x[i] ){
					double lt = 0 , rt = 1e10;
					rep(_,128){
						double mt = (lt+rt) / 2.0;
						
						if( prevSpeed * mt + 0.5 * a * mt * mt - D + x[i] > 0 ){
							rt = mt;
						}else{
							lt = mt;
						}
					}
					myCarTime = max( myCarTime, res+lt );
				}
				res += carTime;
				prevSpeed = carSpeed;
				//cout << res << " " << min(D,x[i+1]) << endl;
			}
			//cout << myCarTime << endl;
			//cout << "CarTime: "<< carTime << "  GoalTime: "<< goalTime << "  CollideTime :" << lt << " " << " CollidePosition :" << 0.5 * a * lt * lt << " " << x0 + m * lt << endl;
			/*double Pos = 0.5 * a * t1 * t1;
			if( Pos > x1 ){
				Pos = x1;
			}
			*/
			printf("%.10lf\n",max(myCarTime,res));
		}
		
	}
	
}