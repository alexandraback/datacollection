#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

void proc(string &c, string &j, int i, int way, int n)
{
	if (c[i] == '?' && j[i] == '?') {
		if (way == 0) {
			c[i] = j[i] = '0';
		}
		else if (way == 1) {
			c[i] = '9';
			j[i] = '0';
		}
		else {
			c[i] = '0';
			j[i] = '9';
		}
	}
	if (c[i] == '?' && j[i] != '?') {
		if (way == 0) {
			c[i] = j[i];
		}
		else if (way == 1) {
			c[i] = '9';
		}
		else {
			c[i] = '0';
		}
	}
	if (c[i] != '?' && j[i] == '?') {
		if (way == 0) {
			j[i] = c[i];
		}
		else if (way == 1) {
			j[i] = '0';
		}
		else {
			j[i] = '9';
		}
	}
	if (c[i] != '?' && j[i] != '?' && way == 0 && c[i] != j[i]) {
		if (c[i] > j[i]) {
			way = -1;
		}
		else {
			way = 1;
		}
	}
	if (i + 1 < n)
		proc(c, j, i+1, way, n);
}

void process(string &c, string &j)
{
	int way = 0;
	for (int i=0;i<c.size();i++) {
		if (c[i] == '?' && j[i] == '?') {
			if (way == 0) {
				c[i] = j[i] = '0';
			}
			else if (way == 1) {
				c[i] = '9';
				j[i] = '0';
			}
			else {
				c[i] = '0';
				j[i] = '9';
			}
		}
		if (c[i] == '?' && j[i] != '?') {
			if (way == 0) {
				c[i] = j[i];
			}
			else if (way == 1) {
				c[i] = '9';
			}
			else {
				c[i] = '0';
			}
		}
		if (c[i] != '?' && j[i] == '?') {
			if (way == 0) {
				j[i] = c[i];
			}
			else if (way == 1) {
				j[i] = '0';
			}
			else {
				j[i] = '9';
			}
		}
		if (c[i] != '?' && j[i] != '?' && way == 0 && c[i] != j[i]) {
			if (c[i] > j[i]) {
				way = -1;
			}
			else {
				way = 1;
			}
		}
	}
}

long long conv(string s)
{
	long long result = 0;
	for (int i=0;i<s.size();i++) {
		result = result * 10 + (s[i] - '0');
	}
	return result;
}

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	int z;
	cin >> z;
	
	for (int q=0;q<z;q++) {
		string c,j;
		cin >> c >> j;

		int idx = -1;
		for (int i=0;i<c.size();i++) {
			if (c[i] != j[i] && c[i] != '?' && j[i] != '?') {
				idx = i;
				break;
			}
		}

		string c1=c,j1=j;
		string origc=c,origj=j;
		process(origc,origj);

		if (idx > 0) {
			proc(c1, j1, 0, 0, idx);
			if (c[idx] > j[idx]) {
				int pos;
				for (pos=idx-1;pos>=0;pos--) {
					if (j[pos] == '?' && j1[pos] != '9') {
						j1[pos]++;
						break;
					}
				}
				if (pos >= 0) {
					for (int i=pos+1;i<c.size();i++) {
						c1[i] = c[i];
						j1[i] = j[i];
					}
					proc(c1, j1, pos, 1, c.size());
				}
				else {
					proc(c1, j1, idx, -1, c.size());
				}
			}
			else {
				int pos;
				for (pos=idx-1;pos>=0;pos--) {
					if (c[pos] == '?' && c1[pos] != '9') {
						c1[pos]++;
						break;
					}
				}
				if (pos >= 0) {
					for (int i=pos+1;i<c.size();i++) {
						c1[i] = c[i];
						j1[i] = j[i];
					}
					proc(c1, j1, pos, -1, c.size());
				}
				else {
					proc(c1, j1, idx, 1, c.size());
				}
			}

			if (abs(conv(c1) - conv(j1)) == abs(conv(origc) - conv(origj))) {
				if (conv(c1) == conv(origc)) {
					if (conv(j1) < conv(origj)) {
						origc = c1;
						origj = j1;
					}
				}
				else if (conv(c1) < conv(origc)) {
					origc = c1;
					origj = j1;
				}
			}
			else if (abs(conv(c1) - conv(j1)) < abs(conv(origc) - conv(origj))) {
				origc = c1;
				origj = j1;
			}
		}

		c1 = c;
		j1 = j;
		if (idx > 0) {
			proc(c1, j1, 0, 0, idx);
			if (c[idx] < j[idx]) {
				int pos;
				for (pos=idx-1;pos>=0;pos--) {
					if (j[pos] == '?' && j1[pos] != '0') {
						j1[pos]--;
						break;
					}
				}
				if (pos >= 0) {
					for (int i=pos+1;i<c.size();i++) {
						c1[i] = c[i];
						j1[i] = j[i];
					}
					proc(c1, j1, pos, -1, c.size());
				}
				else {
					proc(c1, j1, idx, 1, c.size());
				}
			}
			else {
				int pos;
				for (pos=idx-1;pos>=0;pos--) {
					if (c[pos] == '?' && c1[pos] != '0') {
						c1[pos]--;
						break;
					}
				}
				if (pos >= 0) {
					for (int i=pos+1;i<c.size();i++) {
						c1[i] = c[i];
						j1[i] = j[i];
					}
					proc(c1, j1, pos, 1, c.size());
				}
				else {
					proc(c1, j1, idx, -1, c.size());
				}
			}

			if (abs(conv(c1) - conv(j1)) == abs(conv(origc) - conv(origj))) {
				if (conv(c1) == conv(origc)) {
					if (conv(j1) < conv(origj)) {
						origc = c1;
						origj = j1;
					}
				}
				else if (conv(c1) < conv(origc)) {
					origc = c1;
					origj = j1;
				}
			}
			else if (abs(conv(c1) - conv(j1)) < abs(conv(origc) - conv(origj))) {
				origc = c1;
				origj = j1;
			}
		}
		cout << "Case #" << (q + 1) << ": " << origc << " " << origj << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}