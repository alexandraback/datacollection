#include <stdio.h>
#include <vector>
#include <map>
#include <hash_map>
#include <algorithm>
#include <utility>

using namespace std;

int smax;
int v[1001];
int ans;
char s[1001];
int main()
{
	int ncase;
	scanf("%d\n", &ncase);

	for (int icase=1; icase<=ncase; icase++) {
		scanf("%d", &smax);
		scanf("%s", s);
		for (int i=0; i<=smax; i++)
			v[i] = s[i]-'0';

		ans = 0;
		int nbefore = 0;
		for (int i=0; i<=smax; i++) {
			if (v[i] == 0) continue;
			if (i <= nbefore) 
				nbefore += v[i];
			else {
				ans += i-nbefore;
				nbefore = i + v[i];
			}
		}
		printf("Case #%d: %d\n", icase, ans);
	}
	return 0;
}