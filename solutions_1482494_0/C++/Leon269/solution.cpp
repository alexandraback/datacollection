#include<stdio.h>
#include<memory.h>







int a[3000];
int b[3000];
int c[3000];


int main()
{
	//freopen("A-large.in", "r", stdin);
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("sample.out", "w", stdout);
	
	int s,pc;
	int i,j,k,i1,i2,j1,j2;
	int t,n;
	bool flag;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d%d",&a[j],&b[j]);
			c[j]=2;
		}
		
		i1=i2=0;
		s=0;
		pc=0;
		while(true){
			
			flag =false;
			for(j=0;j<n;j++){
				if(b[j]<=pc&&c[j]!=0){
					pc += c[j];
					s++;
					c[j]=0;
					flag = true;
					break;
				}
			}
			if(flag)continue;

			j1=0;
			j2=-1;
			for(j=0;j<n;j++){
				if(a[j]<=pc&&c[j]==2){
					if(j2==-1)j2=j;
					else if(b[j]>b[j2])
						j2 = j;
				}
			}
			if(j2==-1)break;
			else{
				flag = true;
				pc++;
				s++;
				c[j2]--;
			}
		}
		if(pc==n*2)
			printf("Case #%d: %d\n",i+1,s);
		else
			printf("Case #%d: Too Bad\n",i+1);
	}
//	scanf("%d",&i);
	return 0;
}