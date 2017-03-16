#include <iostream>
#include <vector>
using namespace std;


int count(const string &s, char ch)
{
	int result = 0;
	for(int i = 0; i < s.size(); ++i) if(s[i] == ch) {
		++result;
	}
	return result;

}

void solve()
{
	string s;
	cin >> s;
	vector<int> res(10, 0);
	res[0] = count(s, 'Z');
	res[2] = count(s, 'W');
	res[8] = count(s, 'G');
	res[3] = count(s, 'T') - res[2] - res[8];
	res[4] = count(s, 'R') - res[0] - res[3];
	res[5] = count(s, 'F') - res[4];
	res[1] = count(s, 'O') - res[2] - res[4] - res[0];
	res[6] = count(s, 'X');
	res[7] = count(s, 'V') - res[5];
	res[9] = count(s, 'I') - res[5] - res[6] - res[8];
	for(int i = 0; i <= 9; ++i)
		for(int j = 0; j < res[i]; ++j)
			cout << i;
	cout << endl;
}

int main() 
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
