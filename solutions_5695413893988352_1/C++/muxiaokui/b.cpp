#include <stdio.h>

int main(void)
{
	char a;
	int val[1001];
	int ti=0;
	int in;
	int n,m;
	for(int i=0;i<1001;i++){
		val[i] = 0;
	}
		a = getchar();
		while(1){
			a = getchar();
			if(a!=']'){
					scanf("%d",&in);
					val[ti] += in;
					ti++;
			}
			else{
				ti=0;
				a = getchar();
				if(a==']'){
					getchar();
					scanf("%d",&n);
					getchar();
					scanf("%d",&m);
					break;
				}
			}
		}


		int ans =0;
		int maxval =0;
		for(int i=0;i<n;i++){
			maxval +=(m-val[i]);
		}


		int now = maxval;
		for(int i=1;i<=n;i++){
			now = now+val[i-1]-(m-val[i-1]);

			if(now<maxval){
				maxval = now;
				ans = i;
			}
		}
		printf("[%d,%d]\n",ans,ans+1);
	return 0;
}
