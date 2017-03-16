#include<iostream>
#include<cstdio>
using namespace std;

bool num[2000010]={false};

int cal(int a){
	if(a==1)
		return 0;
	return (a*(a-1))/2;
}
int ten(int a){
	int i,ret=10;
	for(i=0;i<a;i++)
		ret*=10;
	return ret;
}

int main(){
	int t,kase=1,a,b,i,count,count1,count2,count3,tmp;
	scanf("%d",&t);
	while(t--){
		count=0;
		scanf("%d %d",&a,&b);
		for(i=a;i<=b;i++){
			if(num[i]==true)
				continue;
			//printf("%d: ",i);
			count1=1;
			num[i]=true;
			tmp=i;
			count2=0;
			while(tmp/10){
				count2++;
				tmp/=10;
			}
			tmp=i;
			count3=count2;
			while(count3--){
				tmp=ten(count2-1)*(tmp%10)+tmp/10;
				//printf("%d ",tmp);
				if(tmp<=b && !num[tmp] && tmp>i){
					count1++;
					num[tmp]=true;
				}
			}
		//printf("\n");
			count+=cal(count1);
		}
		printf("Case #%d: %d\n",kase,count);
		kase++;
		for(i=a;i<=b;i++)
			num[i]=false;
	}
}
