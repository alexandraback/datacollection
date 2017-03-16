#include <stdio.h>
#include <vector>
#include <map>
#include <hash_map>
#include <algorithm>
#include <utility>
#include <string.h>

using namespace std;

char	s[10001];
int		l, x;

char mul(char a, char b, int& sign) {
	sign = 1;
	if (a=='1') {
		sign = 1;
		return b;
	}
	if (b=='1') {
		sign = 1;
		return a;
	}
	if (a==b) {
		sign = -1;
		return '1';
	}
	if (a=='i') {
		if (b=='j')
			return 'k';
		if (b=='k') {
			sign = -1;
			return 'j';
		}
	}
	if (a=='j') {
		if (b=='i') {
			sign = -1;
			return 'k';
		}
		if (b=='k')
			return 'i';
	}
	if (a=='k') {
		if (b=='i')
			return 'j';
		if (b=='j') {
			sign = -1;
			return 'i';
		}
	}
	return '1';
}


int main()
{
	int ncase;

	scanf("%d", &ncase);

	for (int icase=1; icase <= ncase; icase++) {
		memset(s, 0, sizeof(s));
		scanf("%d %d", &l, &x);
		scanf("%s", s);

		bool flag = false;

		int sign = 1;
		char c = '1';
		int i;
		for (i=0; i<l*x; i++) {
			
			char c2 = s[i%l];
			int s2;
			c = mul(c, c2, s2);
			sign *= s2;
			if (sign==1&&c=='i')
				break;
		}
		if (i < l*x)
			i++;
		else {
			printf("Case #%d: NO\n", icase);
			continue;
		}

		sign = 1;
		c = '1';
		for (; i<l*x; i++) {
			
			char c2 = s[i%l];
			int s2;
			c = mul(c, c2, s2);
			sign *= s2;
			if (sign==1&&c=='j')
				break;
		}
		if (i < l*x)
			i++;
		else {
			printf("Case #%d: NO\n", icase);
			continue;
		}
		sign = 1;
		c = '1';
		for (; i<l*x; i++) {
			char c2 = s[i%l];
			int s2;
			c = mul(c, c2, s2);
			sign *= s2;
		}
		if (sign==1 && c=='k') {
			printf("Case #%d: YES\n", icase);
		}
		else
			printf("Case #%d: NO\n", icase);
	}

	return 0;
}