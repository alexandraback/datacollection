#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

typedef long long lint;

int a, b;
double p[100], ip[100];
double ex, tmp;

double cal(vector<int> cnt, vector<double> pro) {
	double e = 0;
	for (int i=0; i<cnt.size(); i++)
		e += cnt[i] * pro[i];
	return e;
}

int main() {
	freopen("a-small-attempt1.in", "r", stdin);
	freopen("a-small.out", "w", stdout);
	//freopen("a-large.in", "r", stdin);
	//freopen("a-large.out", "w", stdout);

	vector<int> cnt;
	vector<double> pro;

	int T; cin>>T;
	for (int t=1; t<=T; t++) {
		cin>>a>>b;
		for (int i=0; i<a; i++) {
			cin>>p[i];
			ip[i] = 1-p[i];
		}

		ex = tmp = b+2;
		if (a==1) {
			cnt.clear(); pro.clear();
			cnt.push_back(b); cnt.push_back(2*b+1);
			pro.push_back(p[0]); pro.push_back(ip[0]);
			ex = min( cal(cnt, pro), ex );
		}
		else if (a==2) {
			pro.clear();
			pro.push_back(p[0]*p[1]); pro.push_back(p[0]*ip[1]); pro.push_back(ip[0]*p[1]); pro.push_back(ip[0]*ip[1]);
			cnt.clear(); 
			cnt.push_back(b-1); cnt.push_back(2*b); cnt.push_back(2*b); cnt.push_back(2*b);
			ex = min( cal(cnt, pro), ex);
			cnt.clear();
			cnt.push_back(b+1); cnt.push_back(b+1); cnt.push_back(2*b+2); cnt.push_back(2*b+2);
			ex = min( cal(cnt, pro), ex);
		}
		else if (a==3) {
			pro.clear();
			pro.push_back(p[0]*p[1]*p[2]); pro.push_back(p[0]*p[1]*ip[2]); pro.push_back(p[0]*ip[1]*p[2]); pro.push_back(p[0]*ip[1]*ip[2]); 
			pro.push_back(ip[0]*p[1]*p[2]); pro.push_back(ip[0]*p[1]*ip[2]); pro.push_back(ip[0]*ip[1]*p[2]); pro.push_back(ip[0]*ip[1]*ip[2]); 

			cnt.clear();
			cnt.push_back(b-2); cnt.push_back(2*b-1); cnt.push_back(2*b-1); cnt.push_back(2*b-1); cnt.push_back(2*b-1); cnt.push_back(2*b-1); cnt.push_back(2*b-1); cnt.push_back(2*b-1);
			ex = min( cal(cnt, pro), ex );
			cnt.clear();
			cnt.push_back(b); cnt.push_back(b); cnt.push_back(2*b+1); cnt.push_back(2*b+1); cnt.push_back(2*b+1); cnt.push_back(2*b+1); cnt.push_back(2*b+1); cnt.push_back(2*b+1);
			ex = min( cal(cnt, pro), ex );
		}

		printf("Case #%d: %.7lf\n", t, ex);
	}

	return 0;
}
