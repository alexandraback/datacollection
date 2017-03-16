#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

void solve()
{
	int num[10] = {0};
	int letter[500] = {0};
	
	char s[2001];
	scanf("%s", s);

	for(int i = 0; i < strlen(s); i++){
		letter[s[i]]++;
	}
	num[0] = letter['Z'];
	num[2] = letter['W'];
	num[4] = letter['U'];
	num[6] = letter['X'];
	num[8] = letter['G'];

	num[1] = letter['O'] - num[0] - num[2] - num[4];
	num[3] = letter['H'] - num[8];
	num[5] = letter['F'] - num[4];
	num[7] = letter['V'] - num[5];
	num[9] = (letter['N'] - num[1] - num[7]) / 2;

	for(int i = 0; i<10;i++){
		for(int j = 0; j<num[i];j++)
			printf("%d", i);
	}

}

int main(void)
{
	int T;
	cin >> T;
	for(int tt = 1; tt <= T; tt++)
	{
		printf("Case #%d: ", tt);
		solve();
		printf("\n");
	}
}