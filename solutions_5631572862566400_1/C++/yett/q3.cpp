#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fornn(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vi_it;
typedef vector<vi> vvi;

typedef long long i64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
int t,a,b,c;

int dfs(vector<vector<int>> &child, int root) {
	int max_depth = 1;
	for (int nr : child[root]) {
		int l = dfs(child, nr);
		max_depth = max(max_depth, l + 1);
	}
	return max_depth;
}

int cal() {
	int n;
	int maxc = 0;
	cin>>n;
	vector<int> parent(n);
	vector<vector<int>> child(n);
	for (int i=0;i<n;++i) {
		int a;cin>>a;
		assert(a>=1 && a<=n);
		parent[i] = a-1;
		child[a-1].push_back(i);
	}
	vector<int> dual;
	vector<int> label(n, 0);
	int cl = 1;
	for(int i=0;i<n;++i){
		if (label[i]) continue;
		int p = i;
		label[p] = cl;	
		while(1) {
			p = parent[p];
			if (label[p] == 0) {
				label[p] = cl;
			} else if (label[p] == cl) {
				int q = p;
				int thisc = 1;
				while((q = parent[q]) != p) {
					thisc++;	
				}
				if (thisc == 2) {
					dual.push_back(p);
				}
				maxc = max(thisc, maxc);
				cl++;
				break;
			} else {
				cl++;
				break;
			}
		}
	}
	//fprintf(stderr, "number of dual %d\n", (int)dual.size());
	//fprintf(stderr, "number of max circle %d\n", maxc);
	int altc = 0;
	for (int d1 : dual) {
		int d2 = parent[d1];
		assert(parent[d2] == d1);
		int d1l = 0, d2l = 0;
		for (int d1c:child[d1]) {
			if (d1c == d2) continue;
			d1l = max(d1l, dfs(child, d1c));
		}
		for (int d2c:child[d2]) {
			if (d2c == d1) continue;
			d2l = max(d2l, dfs(child, d2c));
		}
		altc += d1l + d2l + 2;
	} 
	return max(altc, maxc);
}


int main(int argc, char* argv[]){
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<"Case #"<<i+1<<": "<<cal()<<endl;
    }
    return 0;
}
