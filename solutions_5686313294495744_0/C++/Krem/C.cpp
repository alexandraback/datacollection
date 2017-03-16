#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<cstring>

using namespace std;

enum {
	NMAX = 1010,
	BOLLOCKS = 100000
};

char buf[30];
std::pair<int,int> input[NMAX];
int occ[NMAX*2];
bool tick[NMAX];

int main () {
	int T; scanf("%d", &T);
	for (int _ = 0; _ < T; _++) {
		memset(occ, 0, sizeof(occ));
		memset(tick, 0, sizeof(tick));
		int N; scanf("%d", &N);
		std::map<std::string, int> dict;
		int words = 0;
		for (int i= 0 ; i < N; ++i) {
			std::pair<int,int> entry;
			scanf(" %s", buf);
			string s = string(buf);
			if (dict.find(s) == dict.end())
				dict[s] = words++;
			occ[dict[s]]++;
			entry.first = dict[s];
			scanf(" %s", buf);
			s = string(buf) + "#";
			if (dict.find(s) == dict.end())
				dict[s] = words++;
			occ[dict[s]]++;
			entry.second = dict[s];
			input[i] = entry;
		}
		for (int j = 0; j < N*2; ++j) {
			if(occ[j] == 1) {
				for (int i = 0; i < N; ++i)
					if(input[i].first == j || input[i].second == j) {
						tick[i] = 1;
						occ[input[i].first] = BOLLOCKS;
						occ[input[i].second] = BOLLOCKS;
					}
			}
		}
		int sc = 0;
		for (int __ = 0; __ < N; ++__) {
			for (int i = 0; i < N; ++i) {
				if (!tick[i] && occ[input[i].first] == BOLLOCKS && occ[input[i].second] == BOLLOCKS) {
					sc++;
					tick[i] = 1;
				}
			}
			bool found = 0;
			for (int i = 0; i < N; ++i) {
				if(occ[input[i].first] != BOLLOCKS && occ[input[i].second] != BOLLOCKS) {
					found = 1;
					tick[i] = 1;
					occ[input[i].first] = BOLLOCKS;
					occ[input[i].second] = BOLLOCKS;
					break;
				}
			}
			if (!found) {
				for (int i = 0; i < N; ++i) {
					if(occ[input[i].first] != BOLLOCKS || occ[input[i].second] != BOLLOCKS) {
						found = 1;
						tick[i] = 1;
						occ[input[i].first] = BOLLOCKS;
						occ[input[i].second] = BOLLOCKS;
						break;
					}
				}
			}
			if (!found) break;
		}
		printf("Case #%d: %d\n", _+1, sc);
	}
	return 0;
}
