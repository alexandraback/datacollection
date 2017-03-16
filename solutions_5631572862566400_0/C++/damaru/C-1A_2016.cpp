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

set<int> ss;
map<int, int> mm;

int main (){
	int t, n, max, aux, cha;
	int asdf[1000], cont;
	bool isch;
	int ch[1000];
	cin >> t;
	for (int i =0 ; i<t; i++){
		cin >> n;
		for (int j = 0; j < n; j++){
			ch[j] = 0;
		}
		for (int j = 0; j < n; j++){
			cin >> asdf[j];
		}
		max = 0;
		ss.clear();
		mm.clear();
		cha = 0;
		for (int j = 0; j < n; j++){
			aux = asdf[j];
			ss.clear();
			mm.clear();
			cont = 1;

			mm.insert(ii(j+1, cont-1));
			while (mm.find(aux) == mm.end()){
				mm.insert(ii(aux, cont));
				cont++;
				if (asdf[asdf[aux-1]-1] == aux) isch = true;
				else isch = false;
				aux = asdf[aux-1];
			}
			if (cont-mm[aux] > max) max = cont -mm[aux];
			if (isch && (asdf[asdf[aux-1]-1] == aux)){
				if (cont > ch[asdf[aux-1]-1]) ch[asdf[aux-1]-1] = cont;
			}
		}
		cha = 0;
		for (int j = 0; j < n; j++){
			if (asdf[asdf[j]-1] == j+1  && ch[j] != 0 && ch[asdf[j]-1] != 0 && j+1 < asdf[j] ) cha-=2;
			cha += ch[j];
		}
		if (cha > max) max = cha;
		cout << "Case #" << i+1  << ": " << max << endl;
	}
	return 0;
}
