#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long tbl[60];
int tlen;

int main(void)
{
	int T;
	long long A,B;

	long long i;
	int j;
	char tmp[20];
	tlen = 0;

	// generate table
	for(i=0;i<10000000;i++){
		int flag=1;
		int len;
		sprintf(tmp, "%lld", i);
		len=strlen(tmp);
		for(j=0;j<len;j++){ // len/2 -> sppedup?
			if(tmp[j]!=tmp[len-j-1]) {
				flag = 0;
				goto out_gentbl;
			}
		}

		sprintf(tmp, "%lld", i*i);
		len=strlen(tmp);
		for(j=0;j<len;j++){ // len/2 -> sppedup?
			if(tmp[j]!=tmp[len-j-1]) {
				flag = 0;
				goto out_gentbl;
			}
		}
		if(flag > 0){
			//printf("%lld: %s\n", i, tmp);
			tbl[tlen++]=i*i;
		}
out_gentbl:
		;
	}

	scanf("%d", &T);
	for(j=0;j<T;j++){
		int k;
		int cnt=0;
		scanf("%lld%lld", &A,&B);

		for(k=0;k<tlen;k++){
			if(tbl[k] >= A && tbl[k] <= B){
//				printf("%lld\n", tbl[k]);
				cnt++;
			}
		}

		printf("Case #%d: %d\n",j+1,cnt);

	}
	




}
