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
	int t, n, aux;
	int asdf[2501];
	int sol[51];
	int cont;
	cin >> t;
	for (int i =0 ; i<t; i++){
		cin >> n;
		cont = 0;
		for (int j =0 ; j<2501; j++){
			asdf[j] = 0;
		}
		for (int j = 0; j < 2*n-1; j++){
			for (int k = 0; k < n; k++){
				cin >> aux;
				asdf[aux]++;
			}
		}
		for (int j =0 ; j<2501; j++){
			if (asdf[j] & 1) sol[cont++] = j;
		}
		sort(sol, sol+cont);
		cout << "Case #" << i+1  << ":";
		for (int j =0 ; j<cont; j++){
			cout << " " << sol[j];
		}
		 cout << endl;
	}
	return 0;
}
