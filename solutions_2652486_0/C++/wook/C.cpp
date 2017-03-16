#include <stdio.h>
#include <string>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i=0; i<(int)(n); ++ i) 
#define uniquify(v) {sort(all(v));(v).erase(unique(all(v)), (v).end());}

int R, N, M, K;	//3 5 7 

int prods[8];

int h[8];
double guessProbability(int a, int b, int c) {
	set<int> cd;
	for(int i=0; i<K; ++i) {
		for(int j=i+1; j<K; ++j) {
			if(prods[j] % prods[i] == 0) {
				int v = prods[j] / prods[i];
				if(v == 9) {
					cd.insert(3);
				}
				else cd.insert(v);
			}
		}
	}
	int corr = 0;
	for(int v : cd) {
		if(v == 3 && v == 5 && v != a && v != b && v != c)
			return 0;
	}


	// guess
	memset(h, 0, sizeof(h));
	int f[8] = {1, a, b, c, a*b, a*c, b*c, a*b*c};
	int hit = 0;
	REP(iter, 300) {
		int sampled = f[ rand() % 8 ];
		int pos = find(prods, prods+K, sampled) - prods;
		
		if(pos != K) {
			hit ++;
			h[pos] ++;
		}
	}
	return hit;
}

string guess() {
	double best = 0;
	string ans = "234";
	for(int a=2; a<=5; ++a) for(int b=2; b<=5; ++b) for(int c=2; c<=5; ++c) {
		double p = guessProbability(a, b, c);
		if(best < p) {
			ans = string("") + char(a + '0') + char(b + '0' ) + char(c + '0');
			best = p;
		}
	}
	return ans;
}

int main() {
	int T;
	freopen("C-small.in","r",stdin);
	freopen("C-small.out","w",stdout);
	cin >> T;
	cin >> R >> N >> M >> K;

	cout << "Case #1:"<<endl;
	for(int tt=1;tt<=R;++tt) {
		for(int k=0; k<K; ++k) {
			cin >> prods[k];
//			fprintf(stderr, "%2d ", prods[k]);
		}
		string g = guess();
//		fprintf(stderr, ": %s\n", g.c_str());
		cout << g << endl;
	}
	return 0;
}
