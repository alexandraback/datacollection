#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;

char buf[100];
int best[4400][6];
char in[4400];
unordered_multimap<string, string> m[6];
const int oo = 0x3f3f3f3f;

pair<int, int> test(string s, int f, int idx){
	int c = 0;
	for(int i=0; i<(int)s.size(); ++i){
		if(s[i] != in[idx+i]){
			if(f < 5)
				return make_pair(-1, -1);
			f = 0;
			++c;
		}
		++f;
	}
	f = min(5, f);
	return make_pair(f, c);
}

int main(){
	FILE *f = fopen("garbled_email_dictionary.txt", "r");
	while(fscanf(f, "%s", buf) == 1){
		string a = string(buf);
		int l = min(5, (int)strlen(buf));
		string s = string(buf, l);
		m[l].insert(make_pair(s, a));
	}
	
	int tc, tcn;
	scanf("%d", &tcn);
	for(tc=0; tc<tcn; ++tc){
		printf("Case #%d: ", tc+1);
		memset(best, 0x3f, sizeof(best)); 
		best[0][5] = 0;
		scanf("%s", in);
		int n = strlen(in);
		for(int i=0; i<n; ++i){
			for(int j=1; j<=5; ++j){
				if(best[i][j] == oo)
					continue;
				for(int l=1; l<=min(5, n-i); ++l){
					string k = string(in + i, l);
					auto p = m[l].equal_range(k);
					for(auto iter = p.first; iter != p.second; ++iter){
						auto r = test(iter->second, j, i);
						if(r.first != -1){
							best[i+iter->second.size()][r.first] = min(best[i+iter->second.size()][r.first], best[i][j] + r.second);
						}
					}
				}
				for(int k=max(0, 5-j); k<min(5, n-i); ++k){
					for(char c='a'; c<='z'; ++c){
						for(int l=k+1; l<=min(5, n-i); ++l){
							string ky = string(in + i, l);
							ky[k] = c;
							auto p = m[l].equal_range(ky);
							for(auto iter = p.first; iter != p.second; ++iter){
								auto r = test(iter->second, j, i);
								if(r.first != -1){
									best[i+iter->second.size()][r.first] = min(best[i+iter->second.size()][r.first], best[i][j] + r.second);
								}
							}
						}
					}
				}
			}
		}
		int b = best[n][1];
		for(int i=2; i<=5; ++i)
			b = min(b, best[n][i]);
		printf("%d\n", b);
	}
}
