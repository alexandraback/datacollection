#include <cstdio>
#include <climits>
#include <queue>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int guess(string start)
{
	int result = 0;
	for (int i = 0; i < start.length() - 1; ++i) {
		if (start[i] != start[i+1]) {
			result += 1;
		}
	}
	if (*start.rbegin() == '-') {
		return result + 1;
	} else {
		return result;
	}
}

string flip(const string &s, int p)
{
	string result = s;
	for (int i = 0; i < p; ++i) {
		result[i] = (s[p - i - 1] ^ '+' ^ '-');
	}
	return result;
}

void solve()
{
	static int casenr = 1;
	printf("Case #%d: ", casenr++);
	
	char buf[102]; scanf("%s", buf);
	printf("%d\n", guess(buf));
	return;
	printf("%s ", buf);
	string start(buf);
	if (start.find("-") == string::npos) {
		puts("0");
		return;
	}
	map<string,int> M;
	M[start] = 0;
	queue<string> Q;
	Q.push(start);
	
	while (Q.size() > 0) {
		string cur = Q.front(); Q.pop();
		int steps = M[cur];
		for (int i = 1; i <= cur.length(); ++i) {
			string next = flip(cur, i);
			if (next.find("-") == string::npos) {
				if (guess(start) != steps + 1) {
					puts("ERROR");
					return;
				}
				//printf("%d %d\n", steps + 1, guess(start));
				return;
			}
			if (M.find(next) == M.end()) {
				M[next] = steps + 1;
				Q.push(next);
			}
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T-- > 0) {
		solve();
	}
	return 0;
}
