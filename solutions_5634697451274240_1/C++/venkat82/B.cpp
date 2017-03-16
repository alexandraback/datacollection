#include <bits/stdc++.h>
using namespace std;
int main(){
	int test;
	scanf("%d", &test);
	for (int w = 1; w <= test; w++) {
		string s;
		cin>>s;
		int ans = 0;
		if(s[int(s.size()) - 1] == '+') ans--;
		s.push_back('$');
		for (int i = 1; i < int(s.size()); i++) if(s[i] != s[i - 1]) ans++;
		printf("Case #%d: %d\n", w, ans);
	}
}