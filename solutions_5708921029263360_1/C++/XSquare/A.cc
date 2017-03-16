#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector <ll> VI;
typedef vector <VI> VVI;
typedef vector <VVI> VVVI;
typedef vector <ld> VD;
typedef vector <VD> VVD;
typedef vector <string> VS;
typedef vector <char> VC;
typedef vector <VC> VVC;
typedef pair <ll, ll> PII;
typedef pair <ll, PII> PIII;
typedef pair <ld, ld> PD;
typedef map <ll, ll> MII;
typedef map <string, int> MSI;
typedef queue <int> QI;
typedef queue <PII> QPI;
typedef set <ll> SI;
typedef SI::iterator IT;

#define F first
#define S second
#define pb push_back

int main(){
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t){
		cout << "Case #" << t << ": ";
		int a,b,c,k;
		cin >> a >> b >> c >> k;
		if (k >= c){
			cout << a*b*c << endl;
			for (int i = 1; i <= a; ++i){
				for (int j = 1; j <=b ; ++j){
					for (int l = 1; l <= c; ++l){
						cout << i << " " << j << " " << l << endl;
					}
				}
			}
		}
		else{
			cout << a*b*k << endl;
			for (int i = 1; i <= a; ++i){
				for (int j = 1; j <= b; ++j){
					for (int l = 1; l <= k; ++l){
						cout << i << " " << j << " " << (i+j+l)%c + 1 << endl;
					}
				}
			}
		}
	}
					
    
}
