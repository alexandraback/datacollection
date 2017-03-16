#include <iostream>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif

#define mp make_pair
#define pb push_back
#define put(x) { cout << #x << " = "; cout << (x) << endl; }

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef double db;

const int M = 1020;
const ll Q = 1e18 + 7;

int a[20];
vector<int> g, dd;
bool is[40];
int ans;
bool gen(int pos, int dl, int nn, int v){
	if (nn == dl){
		vector<int> cur;
		for (int i = 0; i < (int)dd.size(); i++)
			cur.pb(dd[i]);
		for (int i = 0; i < dl; i++)
			cur.pb(a[i]);
		for (int i = 1; i <= v; i++)
			is[i] = false;
		is[0] = true;
	   	for (int i = 0; i < (int)cur.size(); i++){
	   		for (int j = v; j >= 0; j--)
	   			if (is[j] && j + cur[i] <= v)
	   				is[j +cur[i]] = true;
	   	}
	   	bool ok = true;
	   	for (int i = 1; i <= v; i++)
	   		if (!is[i])	
	   			ok = false;
	   	 if (ok){
	   	 	ans = dl;
	   	 	return true;
	   	 }
	   	 return false;
	}
	if ((int)g.size() - (pos + 1) >= nn - dl){
		bool ok = gen(pos + 1, dl, nn, v);
		if (ok)
			return true;
	}
	a[dl] = g[pos];
	bool ok = gen(pos + 1, dl + 1, nn, v);
	if (ok)
		return true;
	return false;	
	
}
int main(){
	srand(time(NULL));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
   	for (int tq = 1; tq <= t; tq++){
    	int c, d, v;
    	cin >> c >> d >> v;
    	dd.resize(0);
    	for (int i = 1; i <= v; i++)
    		is[i] = false;
    	for (int i = 0; i < d; i++){
    		int x;
    		cin >> x;
    		is[x] = true;
    		dd.pb(x);
    	}
    	g.resize(0);
    	for (int i = 1; i <= v; i++)
    		if (!is[i])
    			g.pb(i);

       	for (int dl = 0;; dl++){
       		if (gen(0, 0, dl, v)){
       			printf("Case #%d: %d\n", tq, ans);
       			break;
       		}
       	}
       	cerr << tq << endl;

    }  	

	return 0;
}