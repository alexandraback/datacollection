#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	int testnum;
	scanf("%d", &testnum);
	for (int testcase = 1; testcase <= testnum; testcase++) {
	
		int N;
		int sum = 0;
		vector <int> s;
		vector <double> ans;
		vector <double> p;
		scanf("%d", &N);
		
		for (int i = 0; i < N; i++) {
			int tmp;
			scanf("%d", &tmp);
			s.push_back(tmp);
			sum += tmp;
		}
		
			
		vector < pair <double, int> > S;
		vector <double> S_p;
		
		for (int i = 0; i < N; i++) {
			S.push_back(make_pair((double)s[i], i));
			p.push_back(0.0);
			ans.push_back(0.0);
		}
		sort(S.begin(), S.end());
		
		for (int i = 0; i < N; i++) {
			double sum_p = 0;
			for (int j = 0; j < i; j++) {
				sum_p += (S[i].first - S[j].first) / sum;
			}
			S_p.push_back(sum_p);
		}
		
		for (int i = 0; i < N; i++) {
			if (S_p[i] >= 1.0) {
				ans[S[i].second] = 0;
				continue;
			}
			bool is_done = false;
			for (int j = i + 1; j < N; j++) {
				if (S_p[j] >= 1.0) {
					ans[S[i].second] = (1 - S_p[j - 1]) / (double)j + (S[j - 1].first - S[i].first) / sum;
					is_done = true;
					break;
				}
			}
			if (is_done == false) {
				ans[S[i].second] = (1 - S_p[N - 1]) / (double)N + (S[N - 1].first - S[i].first) / sum;
			}
		}
		
		printf("Case #%d: ", testcase);	
		for (int i = 0; i < N; i++) {
			printf("%.6lf ", ans[i] * 100);
		}
		printf("\n");
	}

	return 0;
}