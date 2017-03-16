#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

set<string> dict[100];
int cases, cnt, last, ret;
string s;
int f[4444][5];

void search(string st, int dep, int pre, int c) {
	if (dep == st.length()) {
		if (dict[st.length()].count(st)) {
			if (c < ret || (c == ret && pre < last)) {
				ret = c;
				last = pre;
			}
		}
		return;
	}
	
	if (dep - pre > 4) {
		string tmp = st;
		for (int j = 0; j < 26; j++) {
			tmp[dep] = 'a' + j;
			if (tmp[dep] == st[dep])
				continue;
			search(tmp, dep + 1, dep, c + 1);				
		}
	}
	search(st, dep + 1, pre, c);
}

int check(string st, int k) {
	int len = st.length();
	ret = 12; last = 100;
	/*
	for (int i = 0; i != dict[len].size(); i++) {
		string tmp = dict[len][i];
		
		int pre = k;
		if (k == 0) pre = -10;
		else pre = -k;
		int sum = 0;
		for (int j = 0; j < len; j++)
			if (tmp[j] != st[j]) {
				++sum;
				if (j - pre < 5) {
					sum = -1;
					break;
				}					
				pre = j;
			}
		if (sum != -1)
			if (sum < ret || (sum == ret && pre < last)) {
			ret = sum;
			last = pre;
		}
	}
	*/
	
	int pre = k;
	if (!k) pre = -10;
	else pre = -k;
	search(st, 0, pre, 0);
	
	if (ret == 12) return -1;
	return ret;
}

int main() {
	FILE* fp = fopen("garbled_email_dictionary.txt", "r");	
	
	cnt = 0;
	char ch[100];
	int max = 0;
	while (fscanf(fp, "%s", ch) > 0) {
		++cnt;
		
		int len = strlen(ch);
		string tmp = "";
		for (int i = 0; i < len; i++)
			tmp = tmp + ch[i];
			
		dict[len].insert(tmp);			
	}
	fclose(fp);
	
	printf("done\n");
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);	

	scanf("%d", &cases);
	for (int ca = 1; ca <= cases; ca++) {
		printf("Case #%d: ", ca);
		cin >> s;
		
		memset(f, -1, sizeof f);
		
		f[0][0] = 0;
		for (int i = 0; i < s.length(); i++) 
			for (int k = 0; k <= 4; k++) 
				if (f[i][k] != -1) {
					string st = "";
					for (int j = 0; j <= min(9, (int)s.length() - i - 1); j++) {
						st += s[i + j];
						int ret = check(st, k);
						if (ret >= 0) {
							int nk = j + 1 - last;
							if (nk > 4) nk = 0;
							if (f[i + j + 1][nk] == -1 || f[i][k] + ret <= f[i + j + 1][nk])
								f[i + j + 1][nk] = f[i][k] + ret;
						}
					}
				}
		
		
		int ans = s.length() + 1;
		for (int i = 0; i <= 4; i++)
			if (f[s.length()][i] != -1 && f[s.length()][i] < ans)
				ans = f[s.length()][i];
		printf("%d\n", ans);
	}
    
    return 0;
}
