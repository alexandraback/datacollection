#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int inf = 10000000;

struct Node {
	Node(): leaf(false) {}
	map<char, Node> c;
	bool leaf;
};

void add(Node& node, const char* s) {
	if (*s == '\0') {
		node.leaf = true;
	} else {
		add(node.c[*s], s + 1);
	}
}

void rec(int i, int j, int nc, vector<int>& c, vector<vector<int> >& t, const Node& d, const Node& cur, char* s) {
	if (t[i][0] == -1) {
		t[i].assign(5, inf);
	}


	if (cur.leaf) {
		if (t[j][0] == -1) {
			rec(j, j, 0, c, t, d, d, s);
		}

		if (nc > 0) {
			int posj = max(0, 5 - (j - c.back()));
			int result = nc + t[j][posj];

			int dist = min(4, c[c.size() - nc] - i);
			for (int k = 0; k <= dist; ++k) {
				t[i][k] = min(t[i][k], result);
			}
		} else {
			for (int k = 0; k <= 4; ++k) {
				int posj = max(0, k - j + i);
				t[i][k] = min(t[i][k], t[j][posj]);
			}
		}
		//cout << (s - (j - i)) << ": nc=" << nc;
		//for (int k = 0; k <= 4; ++k) {
		//	cout << " " << t[i][k];
		//}
		//cout << endl;
	}

	if (j >= t.size() - 1) {
		return;
	}

	map<char, Node>::const_iterator it = cur.c.find(*s);
	if (it != cur.c.end()) {
		//cout << "Trying: " << (s - (j - i)) << endl;
		rec(i, j + 1, nc, c, t, d, it->second, s + 1);
	}

	if (nc == 0 || j - c.back() > 4) {
		for (it = cur.c.begin(); it != cur.c.end(); ++it) {
			if (it->first != *s) {
				c.push_back(j);
				char prev = *s;
				//cout << "Trying change: " << (s - (j - i)) << " -> ";
				*s = it->first;
				//cout << (s - (j - i)) << endl;
				rec(i, j + 1, nc + 1, c, t, d, it->second, s + 1);
				c.pop_back();
				*s = prev;
			}
		}
	}
}

int main() {
	Node root;

	ifstream dict("garbled_email_dictionary.txt", ios::in);
	string s;
	do {
		getline(dict, s);
		if (s.size() != 0) {
			add(root, s.c_str());
		}
	} while (s.size() != 0);
	dict.close();

	int tests;
	cin >> tests;
	getline(cin, s);
	for (int test = 1; test <= tests; ++test) {
		getline(cin, s);

		vector<vector<int> > t(s.size() + 1);
		for (size_t i = 0; i <= s.size(); ++i) {
			t[i].resize(5, -1);
		}
		for (int j = 0; j <= 4; ++j) {
			t[s.size()][j] = 0;
		}

		vector<int> changes;
		rec(0, 0, 0, changes, t, root, root, const_cast<char*>(s.c_str()));

		cout << "Case #" << test << ": " << t[0][0] << endl;
	}
}
