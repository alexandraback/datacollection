#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>

#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm> //max...
#include <utility> //pair
#include <complex>
#include <climits> //int, ll...
#include <limits> //double...
#include <cmath> //abs, atan...

#include <cstring> //memset
#include <string>

using namespace std;

typedef long long ll;

typedef pair<int,int> ii;
typedef pair<ll, ll> ll_ll;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;


int main (){
	int t, k, c, s;
	const string IMP = "IMPOSSIBLE";
	cin >> t;
	for (int i =0 ; i<t; i++){
		cin >> k >> c >> s;
		cout << "Case #" << i+1  << ":";
		if (c == 1){
			if (s >= k){
				for (int j =1 ; j<=k; j++){
					cout << " " << j;
				}
				cout << endl;
			}
			else{
				cout << " " << IMP << endl;
			}
		}
		else{
			if (s >= (k+1)/2){
				for (int j = 1; j<= (k+1)/2; j++){
					if (2*j > k)
						cout << " " << k;
					else cout << " " << k*(2*(j-1)) +2*j;

				}
				cout << endl;
			}
			else{
				cout << " " << IMP << endl;
			}
		}
	}
	return 0;
}
