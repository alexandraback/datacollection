#include<stdio.h>

FILE *input=freopen("input.txt","r",stdin);
FILE *output=freopen("output.txt","w",stdout);

long long int gcd(long long int a,long long int b){
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
	long long int i;
	long long int t,tc=1;
	long long int s,e,k;
	long long int cnt;
	long long int cnt2;
	bool flag;
	scanf("%lld",&t);
	for(;t>0;t--){
		printf("Case #%lld: ",tc++);
		scanf("%lld/%lld",&s,&e);
		k=gcd(s,e);
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
			printf("%lld\n",cnt2);
			continue;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}