//In the Name of Allah
#include <iostream>
#include <string>
#include <vector>
#include <set>
//#include <map>
//#include <algorithm>
using namespace std;

const double eps = 1e-12;
typedef long long ll;
typedef pair<unsigned int, unsigned int> pii;
#define For(i, a, b) for (unsigned int i = (a); i < (b); i++)
#define debug(x) { cerr << #x << " = _" << (x) << "_" << endl; }

int main(){
	//*
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	//*/

	unsigned int T;
	cin >> T;
	for(unsigned int tc=1; tc<=T; tc++){
		unsigned int a, b, k;
		cin >> a >> b >> k;
		unsigned int cnt = 0;
		for(unsigned int i=0; i<a; i++){
			for(unsigned int j=0; j<b; j++){
				if((i&j) < k) cnt++;
			}
		}
		cout << "Case #" << tc << ": ";
		cout << cnt << endl;
	}
}
/*
5
3 4 2
4 5 2
7 8 5
45 56 35
103 143 88

*/