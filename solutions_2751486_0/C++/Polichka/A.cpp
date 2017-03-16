#include <iostream>
#include <set>
#include <string>
#define forn(i, n) for(int i = 0; i < int(n); i++)
using namespace std;
string a;
int mn[2000000];
int cnt[2000000];
int ans[2000000];
set<char> s;
int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int tests;
	cin >> tests;
	s.insert('a');
	s.insert('e');
	s.insert('i');
	s.insert('o');
	s.insert('u');
	forn(test, tests){
		int n, len;
		cin >> a >> n;
		len = a.length();
		forn(i, len){
			ans[i] = 0;
			cnt[i] = 0;
			if (s.count(a[i])) continue;
			cnt[i] = ((i > 0)?(cnt[i-1]):(0))+1;
		}
		int idx = -1;
		forn(i, len)
			if(cnt[i] >= n){
				ans[i - n + 1] = 1;
			}
		long long res = 0;
		for(int i = len - 1; i >= 0; i--)
		{
			if(ans[i])
				idx = i + n - 1;
			if(idx >= 0)
				res += len - idx;
		}
		printf("Case #%d: ", test+1);
		cout << res << endl;
	}
	return 0;
}