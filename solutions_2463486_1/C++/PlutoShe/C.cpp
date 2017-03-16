#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
//string t[300000];
int ans, test, n;
string s, s1;
long long a[39] = {
	1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,
400080004,
404090404,
10000200001LL,
10221412201LL,
12102420121LL,
12345654321LL,
40000800004LL,
1000002000001LL,1002003002001LL,
1004006004001LL,
1020304030201LL,
1022325232201LL,
1024348434201LL,
1210024200121LL,
1212225222121LL,
1214428244121LL,
1232346432321LL,
1234567654321LL,
4000008000004LL,
4004009004004LL};
/*void dfs(int i, int l) {
	if (i > 25) return;
	//ans++; t[ans] = s + s;
	//ans++; t[ans] = s + s; delete(t[ans], i, 1);
	for (int j = 0; j <= 2; j++) {
		
		if (i == 1 && j == 0) continue;
		if (l + j * j <= 9) {
			ans++;c
			//t[ans] = s + char(j + 48);
			//t[ans] += s1;
			//cout << s << char(j + 4			8) << s1  << endl;
		}
		//s = s + char(j + 48);
		//s1 = char(j + 48) + s1;
		if (l + j * j > 9) break;
		ans++; 
		//t[ans] = s + s1;
		//cout << s << s1  << endl;
		//cout << t[ans] << endl;
		dfs(i + 1, l + j * j);
		//s.erase(i-1,1);
		//s1.erase(0,1);
	}
}*/
/*
bool cmp(string a, string b) {
	if (a.size() < b.size() || ((a.size() == b.size()) && (a <= b)))
		return true;
	else return false;
}

int check(char s[]) {
	memset(f, 0, sizeof(f));
	f[0][0][0][0] = 1;
	for (int i = 1; i <= 25; i++) {
		for (int j = 0; j <= 2; j++) {
			if (i == 1 && j == 0) continue;
			for (int k = j * j; k <= 9; k++) {
				//for (int l = 0; l <= 2; l++) f[i][j][k][l] = 0;
				if (j == s[i - 1] - 48) {
					for (int l = 0; l <= 2; l++) {
						f[i][j][k][0] += f[i - 1][l][k - j * j][0]
					}
				}
				if (j > s[i - 1] - 48) {
					for (int l = 0; l <= 2; l++) {
						
					}
				}
				
			}
		}
	}
}*/

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> test;
	long long ll, rr;
	for (int tt = 1; tt <= test; tt++) {
		scanf("%I64d%I64d", &ll, &rr);
		int temp_ans = 0;
		for (int i = 0; i <= 38; i++) {
			if (a[i] >= ll && a[i] <= rr) temp_ans++;
		}
		printf("Case #%d: %d\n", tt, temp_ans);
	}
	//for (int i = 1; i <= ans; i++)
		//printf
}
