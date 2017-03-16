//#pragma comment(linker, "/STACK:32777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>
#include <fstream>
using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second
#define sz(a) (int)(a).size()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=1000000000;
const ll mod=1000000007;

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int tt74;
	cin >> tt74;
	FOR(ttt47,0,tt74){
		cout << "Case #" << ttt47 + 1 << ": " << endl;
		long double d;
		int n,A;
		cin >> d >> n >> A;
		long double t[2005];
		long double x[2005];
		FOR(i,0,n)
			cin >> t[i] >> x[i];
		if (n!=1){
			int ii = n-2;
			while (ii>=0 && x[ii] > d){ii--;n--;}
		}
		FOR(cc,0,A){
			long double a;
			cin >> a;
			if (n == 1){
				long double res = sqrt(2 * d / a);
				printf("%.15f\n",res);
				continue;
			}
			long double t0 = sqrt(2.0*x[0]/a);
			long double v1 = a*t0;
			long double v2;
			FOR(i,0,n-2){
				v2 = (x[i+1]-x[i])/(t[i+1]-t[i]);
				long double tt = t0;
				long double D = v1*v1 + 2 * (x[i+1]-x[i]) * a;
				tt += (sqrt(D) - v1) / a;
				if (tt > t[i+1]){
					t0 = tt;
					v1 += a * (t[i+1]-t[i]);
				}
				else{
					t0 = t[i+1];
					v1 = v2;
				}
				//cout << t0 << ' ' << v1 << 'x' << endl;
			}
			long double D = v1*v1 + 2 * (d-x[n-2]) * a;
			t0 += (sqrt(D)-v1)/a;
			long double tt1 = t[n-2] + (d-x[n-2])/(x[n-1]-x[n-2])*(t[n-1]-t[n-2]);
			//cout << tt1 << 'p';
			t0 = max(t0,tt1);
			printf("%.15f\n",t0);
		}
	}
	return 0;
}