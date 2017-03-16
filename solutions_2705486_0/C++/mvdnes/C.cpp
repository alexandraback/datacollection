#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
int numnodes;

class trienode {
public:
	vector<trienode*> children;
	bool isword;
	int mynum;
	trienode() {
		isword = false;
		mynum = numnodes++;
		children.resize(26, 0);
	}
	trienode *getchild(char kar) {
		if (children[kar - 'a'] == 0) {
			children[kar - 'a'] = new trienode();
		}
		return children[kar - 'a'];
	}
	bool childexists(char kar) {
		return children[kar - 'a'] != 0;
	}
};

trienode dictroot;

const int INF = 8000;

int mem[1125079][50];

int dfs(const string &s, int curpos, int tsincechange, trienode *pos) {
	if (s.size() == curpos) {
		return (pos->isword || pos == &dictroot) ? 0 : INF;
	}
	
	if (mem[pos->mynum][curpos] != -1) return mem[pos->mynum][curpos];
	
	int v0 = pos->isword ? dfs(s, curpos, tsincechange+1, &dictroot) : INF;
	int v1 = pos->childexists(s[curpos]) ? dfs(s, curpos+1, tsincechange+1, pos->getchild(s[curpos])) : INF;
	if (tsincechange >= 3) {
		int vmin = INF;
		for (int i = 'a'; i <= 'z'; ++i) {
			if (pos->childexists(i)) {
				vmin = min(vmin, dfs(s, curpos + 1, 0, pos->getchild(i)) + 1);
			}
		}
		mem[pos->mynum][curpos] = min(v0, min(v1, vmin));
		return mem[pos->mynum][curpos];
	} else {
		mem[pos->mynum][curpos] = min(v0, v1);
		return mem[pos->mynum][curpos];
	}
}

void doit(int casenum) {
	int ans = 0;
	
	memset(mem, -1, sizeof mem);
	
	string line;
	getline(cin, line);
	
	ans = dfs(line, 0, 5, &dictroot);

	
	cout << "Case #" << casenum << ": " << ans << endl;
}

void parsedict() {
	ifstream fin("garbled_email_dictionary.txt");
	string line;
	while (getline(fin, line)) {
		trienode *cur = &dictroot;
		for (unsigned i = 0; i < line.size(); i++) {
			cur = cur->getchild(line[i]);
		}
		cur->isword = true;
	}
}

int main() {
	parsedict();
	int T;
	cin >> T;
	cin.get();
	for (int i = 1; i <= T; ++i) {
		doit(i);
	}
	return 0;
}