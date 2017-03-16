#include <stdio.h>

char str[105];

int main()
{
	int cas;
	scanf("%d",&cas);
	for(int T=1; T<=cas; T++){
		scanf("%s",str);
		char now='1';
		int cnt=0;
		for(int i=0; str[i]; i++){
			if(now!=str[i]){
				cnt++;
				now=str[i];
			}
		}
		if(now=='+')
			cnt--;
		printf("Case #%d: %d\n",T,cnt);
	}
	return 0;
}
