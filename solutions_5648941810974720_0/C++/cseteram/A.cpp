#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char buf[2222];
int cnt[256], ans[11];

int main() {

	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int tc=1 ; tc<=T ; tc++) {
		scanf("%s", buf);
		memset(cnt, 0, sizeof(cnt));
		memset(ans, 0, sizeof(ans));

		int n = strlen(buf);
		for(int i=0 ; i<n ; i++)
			cnt[buf[i]]++;

		while (cnt['Z']) { // 0
			cnt['Z']--, cnt['E']--, cnt['R']--, cnt['O']--;
			ans[0]++;
		}
		while (cnt['W']) { // 2
			cnt['T']--, cnt['W']--, cnt['O']--;
			ans[2]++;
		}
		while (cnt['U']) { // 4
			cnt['F']--, cnt['O']--, cnt['U']--, cnt['R']--;
			ans[4]++;
		}
		while (cnt['O']) { // 1
			cnt['O']--, cnt['N']--, cnt['E'];
			ans[1]++;
		}
		while (cnt['R']) { // 3
			cnt['T']--, cnt['H']--, cnt['R']--, cnt['E']--, cnt['E']--;
			ans[3]++;
		}
		while (cnt['F']) { // 5
			cnt['F']--, cnt['I']--, cnt['V']--, cnt['E']--;
			ans[5]++;
		}
		while (cnt['X']) { // 6
			cnt['S']--, cnt['I']--, cnt['X']--;
			ans[6]++;
		}
		while (cnt['G']) { // 8
			cnt['E']--, cnt['I']--, cnt['G']--, cnt['H']--, cnt['T']--;
			ans[8]++;
		}
		while (cnt['I']) { // 9
			cnt['N']--, cnt['I']--, cnt['N']--, cnt['E']--;
			ans[9]++;
		}
		while (cnt['S']) { // 7
			cnt['S']--, cnt['E']--, cnt['V']--, cnt['E']--, cnt['N']--;
			ans[7]++;
		}

		printf("Case #%d: ", tc);
		for (int i=0 ; i<10 ; i++) {
			for(int j=0 ; j<ans[i] ; j++)
				printf("%d", i);
		}
		printf("\n");
	}

	return 0;
}