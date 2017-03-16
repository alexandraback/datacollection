#include<stdio.h>

char str[110][110];

int main() {

	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int t,num=0,ans,a,b,k;
	int i,j;

	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d", &a, &b, &k);

		for(i=0,ans=0 ; i<a ; i++)
			for(j=0 ; j<b ; j++)
				if((i&j)<k) ans++;

		printf("Case #%d: %d\n", ++num, ans);
	}

	return 0;
}