#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iostream>

using namespace std;

int n, a, b, resp;

string invert(string s) {
	int k = s.size();
	string ret = "";
	
	for (int i = 0, j = k-1; i < k; i++, j--)
		ret.push_back(s[j]);
	
	return ret;

}

bool isRec(int x1, int y1) {
	char xx[20], yy[20];
	sprintf(xx, "%d", x1); sprintf(yy, "%d", y1); 
	
	string x(xx);
	string y(yy);
	
	string suf[10], pref[10];
	
	int xs = x.size();
	int ys = y.size();
	
	for (int i = 0; i < xs; i++)
		suf[i] = x.substr(i);
		
	for (int i = 0; i < ys; i++) {
		string tmp = "";
		for (int j = 0; j < x.size()-suf[i].size(); j++) {
			tmp.push_back(x[j]);
		}
		tmp = suf[i]+tmp;
		if (tmp == y) return true;
	}
			
	return false;
}

int main() {
	// freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	
	scanf("%d", &n);
	
	for (int caso = 1; caso <= n; caso++) {
		scanf("%d %d", &a, &b);
		resp = 0;
		
		for (int i = a; i <= b; i++)
			for (int j = i+1; j <= b; j++)
				if (isRec(i, j)) resp++;

		printf("Case #%d: %d\n", caso, resp);
	
	}

	return 0;
}
