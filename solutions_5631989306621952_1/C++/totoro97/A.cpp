#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int T,t;
int main() {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int t = 0;
	for (scanf("%d",&T); T; T--) {
		t++; printf("Case #%d: ",t);
		string s;
		cin >> s;
		string u = "";
		for (int i = 0; i < (int) s.length(); i++) {
			if (u + s[i] > s[i] + u) u = u + s[i];
			else u = s[i] + u;			
		}
		cout << u << endl;
	}
	return 0;
}
   
