#include <stdio.h>

int main(){
	int t=0, c=0, sm=0, n=0, f=0, i=0;
	char sl[2048]={0};

	scanf("%d",&t);

	for(c=1;c<=t;c++){
		sm = n = f = 0;
		scanf("%d %s",&sm,sl);

		for (i=0;i<=sm;i++){
			int sli = sl[i]-'0';
			if (n>=i) {
				n += sli;
			} else if (sli != 0) {
				f += i-n;
				n += i-n+sli;
			}
		}
		printf("Case #%d: %d\n", c, f);
	}

	return 0;
}
