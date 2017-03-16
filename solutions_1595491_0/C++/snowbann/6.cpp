#include<stdio.h>
int main()
{
	int n;
	int count;
	int N,S,p;
	int t;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&N,&S,&p);
		count=0;
		int ave,div;
		for(int j=0;j<N;j++){
			scanf("%d",&t);
			ave=t/3;
			div=t%3;
			if(ave >= p)
				count++;
			else if(div!=0 && ave+1>=p)
				count++;
			else if(S>0){
				if(((div>0||ave>0)&&ave+1>=p) || (div==2&&ave+2>=p) ){
					count++;
					S--;
				}
			}
		}

		printf("Case #%d: %d\n",i,count);
	}
	return 0;
}
