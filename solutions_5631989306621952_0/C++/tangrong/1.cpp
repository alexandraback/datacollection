#include<stdio.h>
#include<string.h>


int main()
{
	int i,j, k, T;
	char s[1024], res[1024*2];
	scanf("%d", &T);
	for(int t=1; t<= T; t++) {
		scanf("%s", s);
		int len = strlen(s);
		char target = s[0];

		int mid = 1024;
		res[mid] = s[0];
		int beg = mid;
		int end = mid;
		for(int index=1; index<len; ++index) {
			if (s[index] >= res[beg]) {
				res[--beg] = s[index];
			} else {
				res[++end] = s[index];
			}
		}
		res[end+1] = 0;
		//printf("%s\n", s);
		//for(int jj=0; jj<2046; jj++) printf("%c", res[jj]);
		//printf("\nCase #%d: %s\n", t, res);
		printf("Case #%d: %s\n", t, &res[beg]);
	}



}
