#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <assert.h>
#include <algorithm>
#include <math.h>
#include <ctime>
#include <functional>
#include <string.h>
#include <stdio.h>
#include <numeric>
#include <float.h>

using namespace std;

vector<string> vs1, vs2;
const long long linf = 0x7fffffffffffffff;

void solution(vector<string> &vs, int pos, string& s, string as) {
	if (pos >= s.size()) {
		vs.push_back(as);
		return;
	}

	if (s[pos] != '?') {
		as.push_back(s[pos]); 
		solution(vs, pos + 1, s, as); 
	}
	else {
		for (int i = 0; i < 10; i++) {
			string cas = as; 
			cas.push_back('0' + i); 
			solution(vs, pos + 1, s, cas); 
		}
	}
}

long long tolong(string &s) {
	long long n = 1;
	long long ans = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		ans += n * (s[i] - '0');
		n *= 10;
	}
	return ans;
}

int main(int argc, char* argv[]) {
	ifstream inf(argv[1]);
	int TC = 0; inf >> TC;

	for (int tc = 1; tc <= TC; tc++) {
		string s1, s2; 
		inf >> s1 >> s2;

		vs1.clear(), vs2.clear(); 

		solution(vs1, 0, s1, ""); 
		solution(vs2, 0, s2, ""); 


		long long diff = linf; 
		long long ll1 = linf, ll2 = linf;
		string ans1, ans2; 
		for (int i = 0; i < vs1.size(); i++) {
			for (int j = 0; j < vs2.size(); j++) {
				long long l1 = tolong(vs1[i]); 
				long long l2 = tolong(vs2[j]); 
				if (diff > abs(l1 - l2)) {
					diff = abs(l1 - l2); 
					ll1 = l1; 
					ll2 = l2; 
					ans1 = vs1[i]; 
					ans2 = vs2[j]; 
				}
				else if (diff == abs(l1 - l2)) {
					if (ll1 > l1 || (ll1 == l1 && ll2 > l2)) {
						ll1 = l1; 
						ll2 = l2; 
						ans1 = vs1[i];
						ans2 = vs2[j];
					}
				}
			}
		}

		cout << "Case #" << tc << ": " << ans1 << " " << ans2 << endl;
	}

	return 0;
}

/*
string s1, s2; 
string ans1, ans2;

const long long inf = 0x7fffffffffffffff; 

string getMaxString(int p, string& s) {
	string ans; 
	for (int i = p; i < s.size(); i++) {
		if (s[i] != '?') {
			ans.push_back(s[i]); 
		}
		else {
			ans.push_back('9'); 
		}
	}
	return ans; 
}

string getMinString(int p, string& s) {
	string ans;
	for (int i = p; i < s.size(); i++) {
		if (s[i] != '?') {
			ans.push_back(s[i]);
		}
		else {
			ans.push_back('0');
		}
	}
	return ans;
}

long long tolong(string &s) {
	long long n = 1; 
	long long ans = 0; 
	for (int i = s.size() - 1; i >= 0; i--) {
		ans += n * (s[i] - '0'); 
		n *= 10; 
	}
	return ans; 
}

string strsub(string& s1, string& s2) {
	string ans; 
	int i1 = s1.size() - 1, i2 = s2.size() - 1; 
	int jie = 0; 
	while (i1 >= 0 && i2 >= 0) {
		if (s1[i1] >= (s2[i2] + jie)) {
			ans.insert(ans.begin(), '0' + s1[i1] - s2[i2] - jie);
			jie = 0; 
		}
		else {
			ans.insert(ans.begin(), '0' + s1[i1] + 10 - s2[i2] - jie); 
			jie = 1; 
		}
		i1--; 
		i2--; 
	}
	if (i1 >= 0) {
		for (int i = i1; i >= 0; i--) {
			if (s1[i] - '0' - jie >= 0) {
				ans.insert(ans.begin(), s1[i] - jie); 
				jie = 0; 
			}
			else {
				ans.insert(ans.begin(), s1[i] + 10 - jie); 
				jie = 1; 
			}
		}
	}
	return ans; 
}

// whether str1 > str2
bool compstr(string& s1, string& s2) {
	if (s1.size() > s2.size()) {
		return true;
	}
	else if (s1.size() < s2.size()) {
		return false;
	}
	else if (s1 > s2) {
		return true;
	}
	else {
		return false;
	}
	return false; 
}

string absolutesub(string& ss1, string& ss2) {
	string s1, s2;
	bool iszero = true; 
	for (int i = 0; i < ss1.size(); i++) {
		if (ss1[i] != '0' || !iszero) {
			iszero = false;
			s1.push_back(ss1[i]); 
		}
		else {
			continue; 
		}
	}

	iszero = true;
	for (int i = 0; i < ss2.size(); i++) {
		if (ss2[i] != '0' || !iszero) {
			iszero = false;
			s2.push_back(ss2[i]);
		}
		else {
			continue;
		}
	}

	if (s1.size() > s2.size()) {
		return strsub(s1, s2); 
	}
	else if (s1.size() < s2.size()) {
		return strsub(s2, s1); 
	}
	else if (s1 > s2) {
		return strsub(s1, s2); 
	}
	else {
		return strsub(s2, s1); 
	}
}


// return minimum diff string, jiejin1 is string1's value, jiejin2 is string2's value
long long solution(int pos, string& jiejin1, string& jiejin2) {
	if (pos >= s1.size()) return 0; 

	if (s1[pos] == '?' && s2[pos] == '?') {
		// bigger case '1', '0'
		string bigts1 = getMinString(pos + 1, s1); 
		string bigts2 = getMaxString(pos + 1, s2); 
		bigts1.insert(bigts1.begin(), '1');
		bigts2.insert(bigts2.begin(), '0');

		long long l1 = tolong(bigts1), l2 = tolong(bigts2); 
		long long diff1 = abs(l1 - l2); 

		// smaller case '0', '1'
		string smallts1 = getMaxString(pos + 1, s1); 
		string smallts2 = getMinString(pos + 1, s2); 
		smallts1.insert(smallts1.begin(), '0');
		smallts2.insert(smallts2.begin(), '1');
		l1 = tolong(smallts1); l2 = tolong(smallts2); 
		long long diff2 = abs(l1 - l2); 
		
		long long diff; 
		if (diff1 < diff2) {
			diff = diff1; 
			jiejin1 = bigts1; 
			jiejin2 = bigts2; 
		}
		else {
			diff = diff2; 
			jiejin1 = smallts1; 
			jiejin2 = smallts2; 
		}

		// equal case '0', '0'
		string j1, j2; 
		long long diff3 = solution(pos + 1, j1, j2);
		j1.insert(j1.begin(), '0'); 
		j2.insert(j2.begin(), '0'); 

		if (diff < diff3) {

		}
		else {
			diff = diff3;
			jiejin1 = j1;
			jiejin2 = j2;
		}

		return diff; 
	}
	else if (s1[pos] == '?') {
		long long diff1 = inf; string bigts1; string bigts2; 
		if (s2[pos] != '9') {
			// bigger case '1', '0'
			bigts1 = getMinString(pos + 1, s1);
			bigts2 = getMaxString(pos + 1, s2);
			bigts1.insert(bigts1.begin(), s2[pos] + 1);
			bigts2.insert(bigts2.begin(), s2[pos]); 
			long long l1 = tolong(bigts1), l2 = tolong(bigts2); 
			diff1 = abs(l1 - l2);
		}

		long long diff2 = inf; string smallts1; string smallts2;
		if (s2[pos] != '0') {
			// smaller case '0', '1'
			smallts1 = getMaxString(pos + 1, s1);
			smallts2 = getMinString(pos + 1, s2);
			smallts1.insert(smallts1.begin(), s2[pos] - 1);
			smallts2.insert(smallts2.begin(), s2[pos]);
			long long l1 = tolong(smallts1), l2 = tolong(smallts2); 
			diff2 = abs(l1 - l2);
		}
		
		long long diff;
		if (diff1 < diff2) {
			diff = diff1; 
			jiejin1 = bigts1;
			jiejin2 = bigts2;
		}
		else {
			diff = diff2; 
			jiejin1 = smallts1;
			jiejin2 = smallts2;
		}

		// equal case '0', '0'
		string j1, j2;
		long long diff3 = solution(pos + 1, j1, j2);
		j1.insert(j1.begin(), s2[pos]);
		j2.insert(j2.begin(), s2[pos]);
		long long l1 = tolong(j1), l2 = tolong(j2); 
		if (diff3 > diff) {

		}
		else if (diff > diff3) {
			diff = diff3; 
			jiejin1 = j1; 
			jiejin2 = j2; 
		}
		else {
			long long l11 = tolong(jiejin1), l12 = tolong(jiejin2), l21 = tolong(j1), l22 = tolong(j2); 
			if (l11 < l21 || (l11 == l21 && l21 < l22)) {

			}
			else {
				diff = diff3;
				jiejin1 = j1;
				jiejin2 = j2;
			}
		}
		return diff;
	}
	else if (s2[pos] == '?') {
		long long diff1 = inf; string bigts1; string bigts2;
		if (s1[pos] != '9') {
			// bigger case '1', '0'
			bigts1 = getMinString(pos + 1, s1);
			bigts2 = getMaxString(pos + 1, s2);
			bigts1.insert(bigts1.begin(), s1[pos]);
			bigts2.insert(bigts2.begin(), s1[pos] + 1);
			long long l1 = tolong(bigts1), l2 = tolong(bigts2);
			diff1 = abs(l1 - l2);
		}

		long long diff2 = inf; string smallts1; string smallts2;
		if (s1[pos] != '0') {
			// smaller case '0', '1'
			smallts1 = getMaxString(pos + 1, s1);
			smallts2 = getMinString(pos + 1, s2);
			smallts1.insert(smallts1.begin(), s1[pos]);
			smallts2.insert(smallts2.begin(), s1[pos] - 1);
			long long l1 = tolong(smallts1), l2 = tolong(smallts2);
			diff2 = abs(l1 - l2);
		}

		long long diff;
		if (diff1 < diff2) {
			diff = diff1;
			jiejin1 = bigts1;
			jiejin2 = bigts2;
		}
		else {
			diff = diff2;
			jiejin1 = smallts1;
			jiejin2 = smallts2;
		}

		// equal case '0', '0'
		string j1, j2;
		long long diff3 = solution(pos + 1, j1, j2);
		j1.insert(j1.begin(), s1[pos]);
		j2.insert(j2.begin(), s1[pos]);
		long long l1 = tolong(j1), l2 = tolong(j2);
		if (diff3 > diff) {

		}
		else if (diff > diff3) {
			diff = diff3;
			jiejin1 = j1;
			jiejin2 = j2;
		}
		else {
			long long l11 = tolong(jiejin1), l12 = tolong(jiejin2), l21 = tolong(j1), l22 = tolong(j2);
			if (l11 < l21 || (l11 == l21 && l21 < l22)) {

			}
			else {
				diff = diff3;
				jiejin1 = j1;
				jiejin2 = j2;
			}
		}
		return diff;
	}
	else {
		if (s1[pos] > s2[pos]) {
			// bigger case '1', '0'
			string bigts1 = getMinString(pos + 1, s1);
			string bigts2 = getMaxString(pos + 1, s2);
			bigts1.insert(bigts1.begin(), s1[pos]);
			bigts2.insert(bigts2.begin(), s2[pos]);
			long long l1 = tolong(bigts1), l2 = tolong(bigts2);
			long long diff = abs(l1 - l2);
			jiejin1 = bigts1; 
			jiejin2 = bigts2; 
			return diff; 
		}
		else if (s1[pos] < s2[pos]) {
			string smallts1 = getMaxString(pos + 1, s1);
			string smallts2 = getMinString(pos + 1, s2);
			smallts1.insert(smallts1.begin(), s1[pos]);
			smallts2.insert(smallts2.begin(), s2[pos]);
			long long l1 = tolong(smallts1), l2 = tolong(smallts2);
			jiejin1 = smallts1;
			jiejin2 = smallts2;
			long long diff = abs(l1 - l2);
			return diff; 
		}
		else {
			string j1, j2; 
			long long diff = solution(pos + 1, j1, j2); 
			j1.insert(j1.begin(), s1[pos]);
			j2.insert(j2.begin(), s2[pos]); 
			jiejin1 = j1; 
			jiejin2 = j2; 
			return diff; 
		}
	}
}

int main(int argc, char* argv[]) {
	ifstream inf(argv[1]);
	int TC = 0; inf >> TC;

	for (int tc = 1; tc <= TC; tc++) {
		inf >> s1 >> s2;
		ans1.clear(); 
		ans2.clear(); 

		solution(0, ans1, ans2); 

		cout << "Case #" << tc << ": " << ans1 << " " << ans2 << endl;
	}

	return 0;
}
*/

/*
struct Rec {
	vector<int> line; 
};
bool operator<(Rec rec1, Rec rec2) {
	for (int i = 0; i < rec1.line.size(); i++) {
		if (rec1.line[i] < rec2.line[i]) return true; 
	}
	return false; 
}

vector<Rec> numbers; 
int n; 

bool solve(int pos, int recNum) {
	bool result = false; 
	if (pos == 0) {
		if (numbers[0].line[0] == numbers[1].line[0]) {
			for (int i = 0; i < n; i++) {
				arr[0][i] = numbers[0].line[i]; 
				arr[i][0] = numbers[1].line[i]; 
			}
			result = solve(1, 2); 
		}
		else {
			for (int i = 0; i < n; i++) {
				arr[i][0] = numbers[0].line[i]; 
			}
			result = solve(1, 1); 
		}
	}
	else {
		if (arr[0][pos] == -1) {

		}
		else {

		}
	}
}

int main(int argc, char* argv[]) {
	ifstream inf(argv[1]);
	int TC = 0; inf >> TC;

	for (int tc = 1; tc <= TC; tc++) {
		inf >> n; 
		memset(arr, -1, sizeof(arr)); 

		numbers.clear(); 
		for (int i = 0; i < n - 1; i++) {
			Rec rec; 
			for (int j = 0; j < n; j++) {
				int n = 0; inf >> n; 
				rec.line.push_back(n); 
			}
			numbers.push_back(rec);
		}

		sort(numbers.begin(), numbers.end()); 




		cout << "Case #" << tc << ": " << ans << endl; 
	}

	return 0;
}
*/

/*
string add(string& s1, string& s2) {
	string result; 

	int over = 0; 
	for (int i = 0; i < max(s1.size(), s2.size()); i++) {
		int a = 0, b = 0; 
		if (i < s1.size()) {
			a = s1[s1.size() - i - 1] - '0'; 
		}
		if (i < s2.size()) {
			b = s2[s2.size() - i - 1] - '0'; 
		}

		int tr = a + b + over; 
		result.insert(result.begin(), '0' + (tr % 10)); 
		over = tr / 10; 
	}
	if (over > 0) result.insert(result.begin(), '0' + over); 
	return result; 
}

int main(int argc, char* argv[]) {
	ifstream inf(argv[1]);
	int TC = 0; inf >> TC; 

	for (int tc = 1; tc <= TC; tc++) {
		string s; inf >> s; 
		if (s == "0") {
			cout << "Case #" << tc << ": INSOMNIA" << endl; 
		}
		else {
			vector<bool> digits(10, false); 
			string now = s; 
			while (true) {
				for (int i = 0; i < now.size(); i++) {
					digits[now[i] - '0'] = true; 
				}

				bool allVisited = true;
				for (int i = 0; i < digits.size(); i++) {
					if (!digits[i]) {
						allVisited = false;
						break;
					}
				}
				if (allVisited) {
					cout << "Case #" << tc << ": " << now << endl;
					break;
				}

				now = add(now, s); 
			}
		}
	}

	return 0;
}
*/

/*
int main(int argc, char* argv[]) {
	ifstream inf(argv[1]); 

	int T = 0; inf >> T;
	for (int t = 1; t <= T; t++) {
		int row, col; inf >> row >> col; 
		vector<string> grid; 
		for (int i = 0; i < row; i++) {
			string str; inf >> str; 
			grid.push_back(str);
		}

		bool impossible = false; 
		int ans = 0; 
		for (int r = 0; r < row && !impossible; r++) {
			for (int c = 0; c < col && !impossible; c++) {
				if (grid[r][c] == '.') continue;
				bool b1 = false, b2 = false, b3 = false, b4 = false; 
				for (int i = 0; i < c; i++) {
					if (grid[r][i] != '.') {
						b1 = true;
						break;
					}
				}
				for (int i = c + 1; i < col; i++) {
					if (grid[r][i] != '.') {
						b2 = true;
						break;
					}
				}
				for (int i = 0; i < r; i++) {
					if (grid[i][c] != '.') {
						b3 = true;
						break;
					}
				}
				for (int i = r + 1; i < row; i++) {
					if (grid[i][c] != '.') {
						b4 = true;
						break;
					}
				}

				if (!b1 && !b2 && !b3 && !b4) {
					impossible = true;
				}
				else if (!b1 && grid[r][c] == '<') {
					ans++; 
				}
				else if (!b2 && grid[r][c] == '>') {
					ans++;
				}
				else if (!b3 && grid[r][c] == '^') {
					ans++;
				}
				else if (!b4 && grid[r][c] == 'v') {
					ans++;
				}
			}
		}


		cout << "Case #" << t << ": ";
		if (impossible) cout << "IMPOSSIBLE" << endl;
		else cout << ans << endl; 
	}

	return 0;
}
*/


/*
int main(int argc, char* argv[]) {
	long long *l = new long long();


	return 0;
}
*/

/*
4.6.3
*/
/*
int totalUsedTime = 0; 
vector<string> process; 

struct Rec {
	int id = 0, times = 0; 
	Rec(int aid, int atimes) : id(aid), times(atimes) {}
};
bool operator<(Rec &rec1, Rec &rec2) {
	return rec1.times < rec2.times;
}1

void solution(vector<Rec> times) {
	sort(times.begin(), times.end());
	int n = times.size(); 
	vector<bool> overRiver(n, false); 
	while (n > 0) {
		if (n == 1 || n == 2) {
			int usedTime = 0; 
			string pro; 
			for (int i = 0; i < times.size(); i++) {
				if (!overRiver[i]) {
					usedTime = max(usedTime, times[i].times);
					if (!pro.empty()) pro.push_back(' ');
					char buf[10] = { 0 };
					sprintf(buf, "%d", times[i].times);
					pro += buf;
					overRiver[i] = true;
				}
			}
			n = 0; 
			totalUsedTime += usedTime;
			process.push_back(pro);
		}
		else {
			if (overRiver[0] == false && overRiver[1] == false) {
				// go
				totalUsedTime += times[1].times;
				char buf[100] = { 0 };
				sprintf(buf, "%d %d", times[0].times, times[1].times);
				process.push_back(buf);
				overRiver[0] = true;
				overRiver[1] = true;
				// back
				totalUsedTime += times[0].times;
				memset(buf, 0, sizeof(buf));
				sprintf(buf, "%d", times[0].times);
				process.push_back(buf);
				overRiver[0] = false;
			}
			else {
				bool gotSlowest = false;
				int p1 = 0, p2 = 0;
				for (int i = times.size() - 1; i >= 0; i--) {
					if (!overRiver[i]) {
						if (gotSlowest) {
							p2 = i; 
							break;
						}
						else {
							gotSlowest = true;
							p1 = i; 
						}
					}
				}
				if (2 * times[1].times > times[p2].times + times[0].times) {
					// go 
					char buf[100] = { 0 };
					sprintf(buf, "%d %d", times[0].times, times[p1].times);
					process.push_back(buf);
					overRiver[p1] = true;
					overRiver[0] = true;
					totalUsedTime += times[p1].times;
					// back
					memset(buf, 0, sizeof(buf));
					sprintf(buf, "%d", times[0].times);
					process.push_back(buf);
					overRiver[0] = false;
					totalUsedTime += times[0].times;
				}
				else {
					// go 
					char buf[100] = { 0 };
					sprintf(buf, "%d %d", times[p2].times, times[p1].times);
					process.push_back(buf);
					overRiver[p1] = true;
					overRiver[p2] = true;
					totalUsedTime += times[p1].times;
					// back
					memset(buf, 0, sizeof(buf));
					sprintf(buf, "%d", times[1].times);
					process.push_back(buf);
					overRiver[1] = false;
					totalUsedTime += times[1].times;
				}
			}
			n -= 1;
		}
	}
}

int main() {
	int TC = 0; cin >> TC;
	bool blank = false; 
	for (int tc = 1; tc <= TC; tc++) {
		int num = 0; cin >> num; 
		vector<Rec> times; 
		for (int i = 0; i < num; i++) {
			int d = 0; cin >> d; 
			times.push_back(Rec(i+1, d)); 
		}

		if (blank) cout << endl; 
		blank = true;

		solution(times);
		cout << totalUsedTime << endl; totalUsedTime = 0; 
		for (int i = 0; i < process.size(); i++) cout << process[i] << endl; 
		process.clear();
	}
	return 0; 
}
*/