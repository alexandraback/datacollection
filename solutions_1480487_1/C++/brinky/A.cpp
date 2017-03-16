#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

pair<double, int> s[200];

int main(){
	int tc, tcn, n;
	scanf("%d", &tcn);
	for(tc=0; tc<tcn; ++tc){
		scanf("%d", &n);
		double sum = 0;
		for(int i=0; i<n; ++i){
			int t;
			scanf("%d", &t);
			s[i].first = t;
			s[i].second = i;
			sum += t;
		}
		for(int i=0; i<n; ++i)
			s[i].first /= sum;
		sort(s, s+n);

		printf("Case #%d:", tc+1);

		for(int i=0; i<n; ++i){
			double r = 1;
			double v = 0;
			bool use = false;
			for(int j=0; j<n-1; ++j){
				if(s[j].second == i)
					use = true;
				double st = min(r, (s[j+1].first - s[j].first) * (j+1));
				if(use)
					v += st / (j+1);
				r -= st;
			}
			v += r / n;
			printf(" %.20lf", v*100);
		}
		puts("");
	}
}
