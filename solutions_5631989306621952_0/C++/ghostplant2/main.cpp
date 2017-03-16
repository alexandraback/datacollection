#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
	int T, C;
	static char tmp[4010], line[4010], *mid = line+2000;
	scanf("%d", &T);
	for (C=1;C<=T;++C) {
		scanf("%s",tmp);
		memset(line, 0, sizeof(line));
		char *l = mid-1, *r = mid+1;
		mid[0]=tmp[0];
		for (int i=1; tmp[i]; ++i) {
			*l = *r = tmp[i];
			if (strncmp(l, l+1, i+1)<=0)
				r++;
			else
				l--;
		}
		*r = 0;
		printf("Case #%d: %s\n", C, l+1);
	}
	return 0;
}

