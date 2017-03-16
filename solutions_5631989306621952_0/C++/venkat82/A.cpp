#include <bits/stdc++.h>
using namespace std;
int main(){
	int test;
	scanf("%d", &test);
	for (int w = 1; w <= test; w++) {
		string s;
		cin>>s;
		int len = s.length();
		map<int, char> m;
		m.clear();
		m[0] = s[0];
		int start = 0, end = 0;
		for (int i = 1; i < len; i++) {
		 	if(s[i] >= m[start]) {
		 		start--;
		 		m[start] = s[i];
		 	}
		 	else {
		 		end++;
		 		m[end] = s[i];
		 	}
		} 
		printf("Case #%d: ", w);
		map<int, char> :: iterator it = m.begin();
		while (it != m.end()){
			cout<<(it -> second);
			it++;
		} 
		cout<<endl;
	}
}