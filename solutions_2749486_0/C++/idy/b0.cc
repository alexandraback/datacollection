#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
long long psum[1000005];

void init_psum() {
	for(int i=1; i<1000005; ++i)
		psum[i] = psum[i-1] + i;
}
bool go(int x, int maxi, vector<int>& oPath) {
	maxi = min(x, maxi);
	if(x == 0) return true;
	if(maxi == 0) return false;

	oPath.push_back(maxi);
	return go(x-maxi, maxi - 1, oPath);
}
void check(const string& s) {
	pair<int, int> coor = make_pair(0, 0);
	for(int i=0; i<s.size(); ++i)
		if(s[i] == 'N')
			coor.second += i+1;
		else if(s[i] == 'S')
			coor.second -= i+1;
		else if(s[i] == 'E')
			coor.first += i+1;
		else if(s[i] == 'W')
			coor.first -= i+1;
	cout << s << ": " << coor.first << " " << coor.second << endl;
}
void solve() {
	pair<int, int> coor, rev;
	cin >> coor.first >> coor.second;
	if(coor.first < 0) {
		coor.first = - coor.first;
		rev.first = true;
	}
	if(coor.second < 0) {
		coor.second = - coor.second;
		rev.second = true;
	}

	int tot = coor.first + coor.second;
	long long* pf = lower_bound(psum, psum + 1000, tot);
	int moves = int(pf - psum);

	vector<int> xPath, yPath, _yPath;
	go(coor.first, moves, xPath);
	sort(xPath.begin(), xPath.end());

	
	for(int i=1, j=0; i<=moves; ++i) {
		if(j >= xPath.size()) {
			yPath.push_back(i);
		}
		else {
			if(xPath[j] == i) {
				j++;
			}
			else {
				yPath.push_back(i);
			}
		}
		
	}
	

	int exceed = coor.second;
	for(int i=0; i<yPath.size(); ++i)
		exceed -= yPath[i];

	
	exceed =- exceed;

	for(int i=0; i<exceed; ++i) {
		moves ++;
		yPath.push_back(moves);
		moves++;
		_yPath.push_back(moves);
	}
	// cout << "exceed: " << exceed << endl;
	// cout << "moves: " << moves << endl;
	// cout << "xPath: "; for(int i=0; i<xPath.size(); ++i) cout << xPath[i] << " "; cout << endl;
	// cout << "yPath: "; for(int i=0; i<yPath.size(); ++i) cout << yPath[i] << " "; cout << endl;
	// cout << "y_Path: "; for(int i=0; i<_yPath.size(); ++i) cout << _yPath[i] << " "; cout << endl;

	map<int, int> belongs;
	for(int i=0; i<xPath.size(); ++i) {
		if(rev.first)
			belongs[xPath[i]] |= 8;
		else
			belongs[xPath[i]] |= 1;
	}
		
	for(int i=0; i<yPath.size(); ++i) {
		if(rev.second)
			belongs[yPath[i]] |= 4;
		else
			belongs[yPath[i]] |= 2;
	}
		
	for(int i=0; i<_yPath.size(); ++i) {
		if(rev.second)
			belongs[_yPath[i]] |= 2;
		else
			belongs[_yPath[i]] |= 4;
	}
	
	string ans;
	for(int i=1; i<=moves; ++i) {
		int belong = belongs[i];
		if(belong == 1) ans += 'E';
		else if(belong == 2) ans += 'N';
		else if(belong == 4) ans += 'S';
		else if(belong == 8) ans += 'W';
		else {
			cout << "Error: " << i << " " << belong << endl;
		}
	}
	if(ans.size() > 500)
		cerr << "Error" << endl;
	cout << ans;	
	// check(ans);
}
int main() {
	init_psum();
	int casn;
	cin >> casn;
	for(int casi = 1; casi <= casn; ++casi) {
		cout << "Case #" << casi << ": ";
		solve();
		cout << endl;
	}
	return 0;
}
