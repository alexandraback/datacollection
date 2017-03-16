#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
string s;
int main() {
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas) {
		cin >> s; 
		string ans = "";
		for(int i = 0; i < s.size(); ++i) {
			string front = ans;
			string end = ans;
			front = s[i] + front;
			end = end + s[i];
			if(front < end)
				ans = end;
			else
				ans = front;
		}
		printf("Case #%d: ",cas);
		cout << ans << endl;
	}
}