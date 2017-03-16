#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace::std;


int main() 
{
	FILE* file_in = fopen("c.in","r");
	FILE* file_out = fopen("c.out","w");
	int n_case;
	fscanf(file_in,"%d",&n_case);
	for (int i_case = 0; i_case < n_case; ++i_case) {
		printf("i%d\n", i_case);
		int n;
		vector<vector<int>> graph;
		map<string, int> w2i;
		vector<pair<string, string>> v;
		fscanf(file_in, "%d", &n);
		for (int i = 0; i < n; ++i) {
			char buf1[30];
			char buf2[30];
			fscanf(file_in, "%s%s", buf1, buf2);
			v.push_back(make_pair(buf1, buf2));
		}
		int r = 0;
		for (int i = 0; i < (1 << v.size()); ++i) {
			set<string> s;
			set<pair<string, string>> s_p;
			int cnt = 0;			bool flag = true;

			for (int j = 0; j < v.size(); ++j) {
				if (i & (1 << j)) {
					s.insert(v[j].first);
					s.insert(v[j].second);
					if (s.find(v[j].first) != s.end() && s.find(v[j].second) != s.end()) {
						flag = false;
						break;
					}
					s_p.insert(v[j]);
					s_p.insert(make_pair(v[j].second, v[j].first));
					cnt++;
				}
			}
			if (!flag) {
				continue;
			}
			for (int j = 0; j < v.size(); ++j) {
				if (!(i & (1 << j))) {
					if (!(s.find(v[j].first) != s.end() && s.find(v[j].second) != s.end() && s_p.find(v[j]) == s_p.end())) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				r = max(r, (int)v.size() - cnt);
			}
		}

		
		fprintf(file_out,"Case #%d: %d\n", i_case + 1, r);

	
	}


	
	fclose(file_out);
	fclose(file_in);

	system("pause");
	return 0;
}