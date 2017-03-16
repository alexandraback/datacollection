#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long max_b = 0;
long long sum_b = 0;
long long n_patterns = 0;

void search(int K,int L,int S,int idx,char *keys, char *str, char *target)
{
	if (idx==S){
		n_patterns++;
		int i;
		long long b=0;
		for (i=0;i<(S-L+1);i++){
			if (memcmp(target,&str[i],L)==0){
				b++;
			}
		}
		sum_b+=b;
		if (b>max_b)max_b=b;
	}
	else{
		int i;
		for (i=0;i<K;i++){
			str[idx]=keys[i];
			search(K,L,S,idx+1,keys,str,target);
		}
	}
}

int main(void)
{
	int T;
	scanf("%d\n",&T);
	int t;
	for (t=1;t<=T;t++){
		int K,L,S;
		max_b=0;sum_b=0;
		n_patterns=0;
		scanf("%d %d %d\n",&K,&L,&S);
		char keys[K+1];
		char target[L+1];
		char str[S+1];
		memset(str,0,sizeof(str));
		scanf("%s\n",keys);
		scanf("%s\n",target);
		search(K,L,S,0,keys,str,target);
		double fM=max_b,fS=sum_b,fn=n_patterns;
		double ret = ((fM * fn) - fS) / fn;
		printf("Case #%d: %.10lf\n",t,ret);
	}
	return 0;
}
