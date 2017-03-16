#include<stdio.h>
int main()
{
	int T;
	int count;
	int s[201];
	int f[201];
	int N;
	double total;
	double ttl;
	double ave;
	int cc;
	int occ;
	scanf("%d",&T);
	for(count=1;count<=T;count++){
		scanf("%d",&N);
		total=0;
		for(int i=0;i<N;i++){
			scanf("%d",&s[i]);
			f[i]=1;
			total+=s[i];
		}
		ttl=total*2;
		ave=ttl/N;
		cc=N;
		occ=cc;
		while(1){
			occ=cc;
			for(int i=0;i<N;i++){
				if(s[i]>ave&&f[i]==1){
					ttl-=s[i];
					f[i]=0;
					cc--;
				}
			}
			ave=ttl/cc;
			if(occ==cc)
				break;
		}
		printf("Case #%d:",count);
		for(int i=0;i<N;i++){
			if(s[i]>=ave)
				printf(" 0.00000");
			else
				printf(" %.5lf",(ave-s[i])/total*100);
		}
		printf("\n");
	}
	return 0;
}
