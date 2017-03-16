//be naame khodaa

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cassert>
#include <iomanip>
typedef long long ll;

using namespace std;
typedef pair <int, int> pii;

string c, j;
ll mn, bstC, bstJ;
string ansC, ansJ;

void BT(int cur, int n, int ch = -1){
	if (cur == n){
		ll C = 0, J = 0;
		for (int i = 0; i < n; i++){
			C = C*10 + (c[i]-'0');
			J = J*10 + (j[i]-'0');
		}
		if (mn == -1 || (abs(J-C) < mn || (abs(J-C) == mn && C < bstC) || (abs(J-C) == mn && C == bstC && J < bstJ))){
			mn = abs(J-C);
			bstC = C;
			bstJ = J;
			ansC = c;
			ansJ = j;
		}
		return;
	}

/*	char lc = c[cur], lj = j[cur];
	for (char cc = '0'; cc <= '9'; cc++)
		for (char jj = '0'; jj <= '9'; jj++)
		{
			if (lc == '?') c[cur] = cc;
			if (lj == '?') j[cur] = jj;
			BT(cur+1, n);
		}
	c[cur] = lc, j[cur] = lj;

	return;*/

	if (ch == -1){
		if (c[cur] != '?' && j[cur] != '?')
			BT(cur+1, n, c[cur] == j[cur] ? -1 : cur);
		else if (c[cur] == '?' && j[cur] == '?'){
			c[cur] = j[cur] = '0';
			BT(cur+1, n, ch);
			c[cur] = '1';
			j[cur] = '0';
			BT(cur+1, n, cur);
			c[cur] = '0';
			j[cur] = '1';
			BT(cur+1, n, cur);
			c[cur] = j[cur] = '?';
		}
		else if (c[cur] == '?'){
			c[cur] = j[cur];
			BT(cur+1, n, ch);
			if (j[cur] < '9'){
				c[cur] = char(j[cur]+1);
				BT(cur+1, n, cur);
			}
			if (j[cur] > '0'){
				c[cur] = char(j[cur]-1);
				BT(cur+1, n, cur);
			}
			c[cur] = '?';
		}
		else{
			j[cur] = c[cur];
			BT(cur+1, n, ch);
			if (c[cur] < '9'){
				j[cur] = char(c[cur]+1);
				BT(cur+1, n, cur);
			}
			if (c[cur] > '0'){
				j[cur] = char(c[cur]-1);
				BT(cur+1, n, cur);
			}
			j[cur] = '?';
		}
	}
	else{
		char _c = c[cur], _j = j[cur];
		if (c[ch] < j[ch]){
			c[cur] = (c[cur] == '?' ? '9' : c[cur]);
			j[cur] = (j[cur] == '?' ? '0' : j[cur]);
		}
		else{
			c[cur] = (c[cur] == '?' ? '0' : c[cur]);
			j[cur] = (j[cur] == '?' ? '9' : j[cur]);
		}
		BT(cur+1, n, ch);
		c[cur] = _c, j[cur] = _j;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int it = 1; it <= t; it++){
		cin >> c >> j;
		int n = c.length();
		mn = bstC = bstJ = -1;
		BT(0, n);
		cout << "Case #" << it << ": " << ansC << ' ' << ansJ << endl;
	}
	return 0;
}
