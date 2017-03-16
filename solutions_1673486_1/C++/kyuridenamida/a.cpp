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
#include <sys/time.h>
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

int output(int t,double p){
	printf("Case #%d: %.10lf\n",t,p);
}
double e[100000];

int main(){
	ios_base::sync_with_stdio(false);
	int T,t=0;
	cin >> T;
	while(T--){
		clock_t start, end;
		start = clock();
		t++;
		int A,B;
		cin >> A >> B;
		// 0001
		
		for(int i = 0 ; i < A ; i++){
			cin >> e[i];
			//cout << e[i] << " ";
		}
		vector<double> lst;
		//cout << endl;
		double ans = 0;
		//何か1つ間違っている場合
		double cur_prob = 1.0;
		for(int i = 0 ; i < A ; i++){
			lst.push_back(cur_prob * (1-e[i]));
			//cout << cur_prob * (1-e[i]) * ( (A-i) + (B-i) ) << " " << cur_prob * (1-e[i]) << endl;
			cur_prob *= e[i];
		}
		//全部正しい確率
		double cor_prob = 1.0;
		for(int i = 0 ; i < A ; i++)
			cor_prob *= e[i];
		lst.push_back(cor_prob);
		//lst[0] = 1.0
		
		ans = 2.0+B;
		for(int j = 0 ; j <= A ; j++){
			if( (double)(clock() - start) / CLOCKS_PER_SEC > 30.0 ) break;
			double proba = 0;
			for(int i = 0 ; i < lst.size() ; i++){
					double pr = 0.0;
					if( A-j > i){
						pr = lst[i] * ( 2*j + B-A + 2 + B );
						//cout << pr << "(" << i << "," << j << ")" << " " << ( 2*j + B-A + 2 + B ) <<  endl;
					}else{
						pr = lst[i] * ( 2*j + B-A+1);
						//cout << pr << "(" << i << "," << j << ")" << " " << ( B-A+2*j+1 )<<  endl;
					}
					proba += pr;
					if(proba > ans) break;
			}
			//cout << proba << " <" << j << ">" << endl;
			ans = min(proba,ans);
		}
		
		output(t,min(ans,2.0+B));
	}
	
}