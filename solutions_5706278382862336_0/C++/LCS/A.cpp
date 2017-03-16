#include<stdio.h>

FILE *input=freopen("input.txt","r",stdin);
FILE *output=freopen("output.txt","w",stdout);

int gcd(int a,int b){
	if(a==0)
		return b;
	if(b==0)
		return a;
	if(a>b)
		return gcd(b,a%b);
	if(a<b)
		return gcd(a,b%a);
}

int main(){
	int i;
	int t,tc=1;
	int s,e,k;
	int cnt;
	int cnt2;
	bool flag;
	scanf("%d",&t);
	for(;t>0;t--){
		printf("Case #%d: ",tc++);
		scanf("%d/%d",&s,&e);
		k=gcd(s,e);
		if(k!=1)
			int sp=1;
		s/=k;
		e/=k;
		cnt=0;
		cnt2=0;
		flag=0;
		while(1){
			if(e%2==1)
				break;
			e/=2;
			cnt++;
			if(s>e)
			{
				if(!flag)
					cnt2=cnt;
				flag=1;
				s-=e;
			}
		}
		if(e!=1||e==1&&s!=1)
		{
			printf("impossible\n");
			continue;
		}
		if(flag)
		{
			printf("%d\n",cnt2);
			continue;
		}
		printf("%d\n",cnt);
	}
	return 0;
}