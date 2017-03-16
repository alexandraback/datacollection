#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void test(int t)
{
	string s;
	cin >> s;
	s += '+';
	int ans = 0;
	for(int i=0;i<s.size()-1;i++)
		if(s[i]!=s[i+1])
			ans++;
	cout << "Case #" << t << ": " << ans << '\n';
}

int main()
{
	freopen("testin.txt","r",stdin);
	freopen("testout.txt","w",stdout);
	int T;
	cin >> T;
	for(int i=0;i<T;i++) test(i+1);
}