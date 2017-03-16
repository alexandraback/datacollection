#include "sstream"
#include "iostream"
#include "fstream"
#include "cstdio"
#include "cstring"
#include "cmath"
#include "algorithm"
#include "vector"
#include "map"
#include "set"
#include "queue"
#include "deque"
#include "list"
#include "string"
#include "cassert"

using namespace std;

const int INF = 0x3f3f3f3f;

int cost(vector<vector<string> > &vs, const string &word)
{
	if (word.length() >= vs.size()) {
		return INF;
	}
	int ans = INF, n = word.length();
	for (vector<string>::iterator it = vs[n].begin(); 
		it != vs[n].end(); it++) {
		int c = 0, last = -10;
		for (int i = 0; i < n; i++) {
			if (word[i] == (*it)[i]) {
				continue;
			}
			if (i - last < 5) {
				c = INF;
				break;
			}
			last = i;
			c ++;
		}
		ans = min(ans, c);
	}
	return ans;
}

int main(int argc, char ** argv)
{
	ifstream fin;
	fin.open(argv[1], ifstream::in);
	vector<vector<string> > vs;
	for (string word; fin>>word; ) {
		if (vs.size() <= word.length()) {
			vs.resize(word.length() + 1);
		}
		vs[word.length()].push_back(word);
	}
	fin.close();
	
	int T, t = 1;
	for (scanf("%d", &T); T--; ) {
		printf("Case #%d: ", t++);
		string line;
		cin>>line;
		int dp[100][6];
		fill(dp[0], dp[line.length()+2], INF);
		dp[0][5] = 0;
		for (int i = 1; i <= line.size(); i++) {
			for (int j = i; j > 0 && (i-j+1) <= vs.size() - 1; j--) {
				int n = i - j + 1;
				string word = line.substr(j-1, i - j + 1);
				for (vector<string>::iterator it = vs[n].begin(); it != vs[n].end(); it++) {
					int c = 0, first = INF, last = -100;
					for (int ii = 0; ii < n; ii++) {
						if (word[ii] == (*it)[ii]) {
							continue;
						}
						if (ii - last < 5) {
							c = INF;
							break;
						}
						last = ii;
						if (first == INF) {
							first = ii;
						}
						c ++;
					}
					//if (c != INF) {
					if (c == 1 && first == 0 || c == 0) {
						//cout<<i<<" "<<j<<" "<<first<<" "<<last<<endl;
						for (int k = 0; k <= 5; k++) {
							if (j + first - (j - 1 - k) >= 5) {
								dp[i][min(5, i-(j+last))] = min(dp[i][min(5, i-(j+last))], dp[j-1][k] + c);
							}
						}
					}
				}
			}
		}
		printf("%d\n", *min_element(dp[line.size()], dp[line.size()]+6));
	}
	return 0;
}

