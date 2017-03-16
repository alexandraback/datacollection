#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstdlib>

#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <fstream>
#include <algorithm>

#define pb push_back
#define fi(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define fit(v) fi(it, v)
#define f(i,n) for(int i = 0; i < (n); ++i)

#define fs first
#define sc second
#define mp make_pair

#define all(v) (v).begin(), (v).end()
#define ll long long int
#define vi vector<int>
#define vii vector<vi >
using namespace std;

int main(){
	int t; cin >> t;
	ofstream myfile;
  	myfile.open ("out.txt");
	f(i,t){
		int x, n; cin >> x >> n;
		vi v, t;
		f(j,n){
			int k; cin >> k;
			v.pb(k);
		}
		sort(all(v));
		int sol = 0;
		f(j,v.size()){
			int ins = 0;
			if (x-1 > 0)
			while (x <= v[j]){
				ins++;
				x += x-1;
			}
			else ins = 100000000;
			t.pb(ins);
			x += v[j];
		}
		int k = 0, b = 1;
		fit(t) cout << *it << " ";
		cout << endl;
		for (int j = t.size()-1; j >= 0; j--){
			k+= t[j];
			if (k > b){
				sol += b;
				b = 1;
				k = 0;
			} else
			b++;
		}
		sol += k;
		myfile << "Case #" << i+1 << ": " << sol << endl;
	}
	return 0;
}
