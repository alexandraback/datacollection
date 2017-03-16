#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int n, a, b, resp;

string invert(string s) {
	int k = s.size();
	string ret = "";
	
	for (int i = 0, j = k-1; i < k; i++, j--)
		ret.push_back(s[j]);
	
	return ret;

}

int exp(int bs, int e) {
	if (e == 0) return 1;
	else if (e%2 == 0) {
		int k = exp(bs, e/2);
		return k*k;
	}
	else return bs*exp(bs, e-1);
}

int many(int x1) {
	int ret = 0;
	char xx[20], yy[20];
	sprintf(xx, "%d", x1); 
	
	string x(xx), suf[15], tmp[15];
	int xs = x.size();
	
	int pot = exp(10, x.size()-1);
	
	for (int i = 0; i < xs; i++)
		suf[i] = x.substr(i);
		
	for (int i = 1; i < xs; i++) {
		tmp[i] = "";
		for (int j = 0; j < i; j++) tmp[i].push_back(x[j]);
		tmp[i] = suf[i]+tmp[i];
		int k;
		sscanf(tmp[i].c_str(), "%d", &k);
		if (k <= b && k >= pot && tmp[i] > x && k >= a) {
			bool aux = true;
			if (i) for (int j = i-1; j >= 0; j--) 
				if (tmp[i] == tmp[j]) aux = false;
			if (aux) ret++;
		}
	}
	return ret;
}

int main() {
	// freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	
	scanf("%d", &n);
	
	for (int caso = 1; caso <= n; caso++) {
		scanf("%d %d", &a, &b);
		resp = 0;
		
		for (int i = a; i <= b; i++)
				resp+=many(i);

		printf("Case #%d: %d\n", caso, resp);
	
	}

	return 0;
}
