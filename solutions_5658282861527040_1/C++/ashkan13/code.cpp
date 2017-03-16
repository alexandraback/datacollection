//In the Name of Allah
#include <iostream>
#include <string>
#include <vector>
#include <set>
//#include <map>
//#include <algorithm>
using namespace std;

const double eps = 1e-12;
typedef unsigned long long ull;
typedef pair<unsigned int, unsigned int> pii;
#define For(i, a, b) for (unsigned int i = (a); i < (b); i++)
#define debug(x) { cerr << #x << " = _" << (x) << "_" << endl; }

int main(){
	//*
	freopen("bb.in", "r", stdin);
	freopen("bb.out", "w", stdout);
	//*/

	unsigned int T;
	cin >> T;
	for(unsigned int tc=1; tc<=T; tc++){
		ull a, b, k;
		cin >> a >> b >> k;
		ull cnt = 0;
		cnt += min(a,k) * b;
		cnt += a * min(b,k);
		cnt -= min(a,k) * min(b,k);
		for(unsigned int i=k; i<a; i++){
			for(unsigned int j=k; j<b; j++){
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