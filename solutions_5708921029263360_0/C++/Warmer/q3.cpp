#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, s, p,m, n, l;

class tmmm{
	public:
		t(){
			
		};
		int p, s, j;
};

vector<tmmm> findSolutionsA(){
	vector<tmmm> result;
	for (int a = j; a>=1;a--){
		for (int b = p; b>=1;b--){
			for (int c = s; c>=1;c--){
				tmmm newA;
				newA.j = a;
				newA.p = b;
				newA.s = c;
				
				int jp = 0, js = 0, ps = 0;
				bool fai = false;
				for (int tmp = 0; tmp < result.size(); tmp++){
					if (result[tmp].j==newA.j && result[tmp].p==newA.p){
						jp++;
						if (jp>=k){
							fai = true;
							break;
						}
					}
					if (result[tmp].s==newA.s && result[tmp].j==newA.j){
						js++;
						if (js>=k){
							fai = true;
							break;
						}
					}
					if (result[tmp].p==newA.p && result[tmp].s==newA.s){
						ps++;
						if (ps>=k){
							fai = true;
							break;
						}
					}
				}
				if (fai){
					continue;
				}
				result.push_back(newA);
			}
		}
	}
	return result;
}
vector<tmmm> findSolutionsB(){
	vector<tmmm> result;
	for (int b = p; b>=1;b--){
		for (int a = j; a>=1;a--){
			for (int c = s; c>=1;c--){
				tmmm newA;
				newA.j = a;
				newA.p = b;
				newA.s = c;
				
				int jp = 0, js = 0, ps = 0;
				bool fai = false;
				for (int tmp = 0; tmp < result.size(); tmp++){
					if (result[tmp].j==newA.j && result[tmp].p==newA.p){
						jp++;
						if (jp>=k){
							fai = true;
							break;
						}
					}
					if (result[tmp].s==newA.s && result[tmp].j==newA.j){
						js++;
						if (js>=k){
							fai = true;
							break;
						}
					}
					if (result[tmp].p==newA.p && result[tmp].s==newA.s){
						ps++;
						if (ps>=k){
							fai = true;
							break;
						}
					}
				}
				if (fai){
					continue;
				}
				result.push_back(newA);
			}
		}
	}
	return result;
}
vector<tmmm> findSolutionsC(){
	vector<tmmm> result;
	for (int c = s; c>=1;c--){
		for (int a = j; a>=1;a--){
			for (int b = p; b>=1;b--){
				tmmm newA;
				newA.j = a;
				newA.p = b;
				newA.s = c;
				
				int jp = 0, js = 0, ps = 0;
				bool fai = false;
				for (int tmp = 0; tmp < result.size(); tmp++){
					if (result[tmp].j==newA.j && result[tmp].p==newA.p){
						jp++;
						if (jp>=k){
							fai = true;
							break;
						}
					}
					if (result[tmp].s==newA.s && result[tmp].j==newA.j){
						js++;
						if (js>=k){
							fai = true;
							break;
						}
					}
					if (result[tmp].p==newA.p && result[tmp].s==newA.s){
						ps++;
						if (ps>=k){
							fai = true;
							break;
						}
					}
				}
				if (fai){
					continue;
				}
				result.push_back(newA);
			}
		}
	}
	return result;
}

int main() {
    //freopen("x.in", "r", stdin);

	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	//freopen("A-large.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
		//cerr << tt << endl;
		cin >> j >> p>>s>>k;
		vector<tmmm> sol;// = findSolutions();
		if (j <= p && j <= s){
			sol = findSolutionsA();
		}
		else if (p <= j && p <= s){
			sol = findSolutionsB();
		}
		else{
			sol = findSolutionsC();
		}
  		printf("Case #%d: ", tt);
  		cout << sol.size()<<endl;
  		for (int ddd = 0; ddd<sol.size();ddd++){
  			cout << sol[ddd].j<<" "<<sol[ddd].p<<" "<<sol[ddd].s<<endl;
		}
	}
	return 0;
}
