#include <bits/stdc++.h>
using namespace std;
bool visited[50];
int in[50][50], out[50][50];
void follow(int j) {
	if (visited[j]) return;
	visited[j] = 1;
	for (int i = 0; i < 26; i++) {
		if (j == i) continue;
		if (out[j][i] == 1) {
			follow(i);
		}
	}
}
int main() {
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	int tc;
	scanf("%d", &tc);
	for (int q= 1; q <= tc; q++){ 
		
		for (int i = 0; i < 50; i++) {
			visited[i] = false;
			for (int j = 0; j < 50; j++) {
				in[i][j] = 0;
				out[i][j] = 0;
			}
		}
		int l;
		bool finish = false;
		scanf("%d", &l);
		char dummy;
		map<char,int> s;
	//	scanf("%c", &dummy);
		string temp;
		for (int i = 0; i < l; i++) {
			temp = "";
			cin >> temp;
		//	cout << temp;
			bool flag = true;
			char first = temp[0];
			for (int j = 0; j < temp.length(); j++) {
				if (temp[j] != first) {
					flag = false;
					break;
				}
			}
			if (flag) {
				if (s.find(temp[0]) != s.end()) {
					s[temp[0]] += 1;
				}
				else {
					s.insert(make_pair(temp[0],1));
				}
			}
			for (int j = 1; j < temp.length(); j++) {
				in[temp[j-1]-'a'][temp[j]-'a'] += 1;
				out[temp[j-1]-'a'][temp[j]-'a'] += 1;
			}
		}
		int sep = 0;
		for (int i = 0; i < 26; i++) {
			//Check
			int runsum = 0;
			for (int j = 0; j < 26; j++) {
				if (j == i) continue;
				runsum += in[j][i];
			}
			if (runsum > 1) {
				printf("Case #%d: 0\n", q);
				finish = true;
				break;
			}
			runsum = 0;
			for (int j = 0; j < 26; j++) {
				if (j == i) continue;
				runsum += out[i][j];
			}
			if (runsum > 1) {
				printf("Case #%d: 0\n", q);
				finish = true;
				break;
			}
		}
		if (finish) continue;
		for (int i = 0; i < 26; i++) {
			//Follow
			
			if (visited[i]) continue;
			visited[i] = true;
			bool followed = false;
			
			for (int j = 0; j < 26; j++) {
				if (out[i][j] >= 1) { sep++; break; }
			}
			
			for (int j = 0; j < 26; j++) {
				if (i == j) continue;
				if (out[i][j] == 1) {
					follow(j);
					followed = true;
	//				cout << i << " " << j << endl;
				}
			}
	//		if (followed) sep++;
			
		}
	//	cout << sep << endl;
		long long ans = 1;
		for (int i = 0; i < 26; i++) {
			if (s.find('a' + i) != s.end()) {
	//			cout << s['a' + i] << endl;
				for (int j = 1; j <= s['a'+i]; j++) {
					ans *= j;
					ans %= 1000000007;
				}
			}
		}
		for (int i = 1; i <= sep; i++) {
			ans *= i;
			ans %= 1000000007;
		}
		printf("Case #%d: %lld\n", q, ans);
	}
}
