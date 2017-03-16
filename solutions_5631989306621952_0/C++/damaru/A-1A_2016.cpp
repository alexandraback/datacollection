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

string s;

void rec(int ini, int fin){
	if (fin < ini) return;
	char max = s[fin];
	int ind = fin;
	for (int j = fin-1; j >= ini; j--){
		if (s[j] > max){
			max = s[j];
			ind = j;
		}
	}
	cout << max;
	rec(ini, ind-1);
	for (int j = ind+1; j <= fin; j++){
		cout << s[j];
	}
}

int main (){
	int t, n;

	cin >> t;
	for (int i =0 ; i<t; i++){
		cin >> s;
		cout << "Case #" << i+1  << ": ";
		rec(0, s.size()-1);
		cout << endl;
	}
	return 0;
}
