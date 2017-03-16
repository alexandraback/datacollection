#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

char code[22], jam[22];

void solve_small() {
	int n = strlen(code);
	int m = strlen(jam);

	vector<int> score1, score2;

	for(int i=0 ; i<10 ; i++) {
		for(int j=0 ; j<10 ; j++) {
			for(int k=0 ; k<10 ; k++) {
				int a[3], b[3];

				for(int kk=0 ; kk<3 ; kk++) {
					a[kk] = b[kk] = -1;
				}

				if (n > 0) {
					a[0] = (code[0] == '?') ? i : (code[0] - '0');
					b[0] = (jam[0] == '?') ? i : (jam[0] - '0');
				}
				if (n > 1) {
					a[1] = (code[1] == '?') ? j : (code[1] - '0');
					b[1] = (jam[1] == '?') ? j : (jam[1] - '0');
				}
				if (n > 2) {
					a[2] = (code[2] == '?') ? k : (code[2] - '0');
					b[2] = (jam[2] == '?') ? k : (jam[2] - '0');
				}

				int scorea = 0, scoreb=0;

				for(int kk=0 ; kk<3 ; kk++) {
					if (a[kk] != -1) scorea = scorea*10 + a[kk];
					if (b[kk] != -1) scoreb = scoreb*10 + b[kk];
				}

				score1.push_back(scorea);
				score2.push_back(scoreb);
			}
		}
	}

	int ans1=987654321, ans2=123456789;

	for(int i=0 ; i<score1.size() ; i++) {
		for(int j=0 ; j<score2.size() ; j++) {
			int s1 = score1[i], s2 = score2[j];
			if (abs(s1-s2) < abs(ans1-ans2)) {
				ans1 = s1, ans2 = s2;
			}
			else if (abs(s1-s2) == abs(ans1-ans2)) {
				if (s1 < ans1) {
					ans1 = s1, ans2 = s2;
				}
				else if (s1 == ans1) {
					if (s2 < ans2) {
						ans1 = s1, ans2 = s2;
					}
				}
			}
		}
	}

	int p=0, x = ans1, p2=0, x2=ans2;
	if (x == 0) p = 1;
	if (x2 == 0) p2 = 1;
	while(x) {
		p++, x/=10;
	}
	while(x2) {
		p2++, x2/=10;
	}

	for(int i=0 ; i<n-p ; i++)
		printf("0");
	printf("%d ", ans1);
	for(int i=0 ; i<m-p2 ; i++)
		printf("0");
	printf("%d\n", ans2);

	return;
}

int main() {

	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int tc=1 ; tc<=T ; tc++) {
		scanf("%s %s", code, jam);



		printf("Case #%d: ", tc);
		solve_small();
	}

	return 0;
}