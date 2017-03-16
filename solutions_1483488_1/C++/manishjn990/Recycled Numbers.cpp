#include<cstdio>
#include<cstring>
#include<cstdlib>
long long int RU2(long long int D,long long int A)
{
	long long int ans=0,i,j,k;
	j=D;
	i=j%10;
	j=j/10;j+=i*10;
	if(j<D && j>=A)ans++;
	return ans;
}
long long int RU3(long long int D,long long int A)
{
	long long int ans=0,i,j,k;
	j=D;
	i=j%10;
	j=j/10;j+=i*100;
	if(j<D && j>=A)ans++;k=j;
	j=D;
	i=j%100;
	j=j/100;
	j+=i*10;
	if(j<D && j>=A && k!=j)ans++;
	return ans;
}
long long int RU4(long long int D,long long int A)
{
	long long int ans=0,i,j,k,l;
	j=D;
	i=j%10;
	j=j/10;j+=i*1000;
	if(j<D && j>=A)ans++;k=j;
	j=D;
	i=j%100;
	j=j/100;
	j+=i*100;if(j<D && j>=A && k!=j)ans++;l=j;
	j=D;
	i=j%1000;
	j=j/1000;
	j+=i*10;if(j<D && j>=A && k!=j && l!=j)ans++;
	return ans;
}
long long int RU5(long long int D,long long int A)
{
	long long int ans=0,i,j,k,l,m;
	j=D;
	i=j%10;
	j=j/10;j+=i*10000;
	if(j<D && j>=A)ans++;k=j;
	j=D;
	i=j%100;
	j=j/100;
	j+=i*1000;if(j<D && j>=A && k!=j)ans++;l=j;
	j=D;
	i=j%1000;
	j=j/1000;
	j+=i*100;if(j<D && j>=A && k!=j && l!=j)ans++;m=j;
	j=D;
	i=j%10000;
	j=j/10000;
	j+=i*10;if(j<D && j>=A && k!=j && m!=j && l!=j)ans++;
	return ans;
}
long long int RU6(long long int D,long long int A)
{
	long long int ans=0,i,j,k,l,m,n;
	j=D;
	i=j%10;
	j=j/10;j+=i*100000;
	if(j<D && j>=A)ans++;k=j;
	j=D;
	i=j%100;
	j=j/100;
	j+=i*10000;if(j<D && j>=A && k!=j)ans++;l=j;
	j=D;
	i=j%1000;
	j=j/1000;
	j+=i*1000;if(j<D && j>=A && l!=j && k!=j)ans++;m=j;
	j=D;
	i=j%10000;
	j=j/10000;
	j+=i*100;if(j<D && k!=j && l!=j && m!=j && j>=A)ans++;n=j;
	j=D;
	i=j%100000;
	j=j/100000;
	j+=i*10;if(j<D && k!=j && l!=j && m!=j && n!=j && j>=A)ans++;
	return ans;
}
long long int RU7(long long int D,long long int A)
{
	long long int ans=0,i,j,k,l,m,n,o;
	j=D;
	i=j%10;
	j=j/10;j+=i*1000000;
	if(j<D && j>=A)ans++;k=j;
	j=D;
	i=j%100;
	j=j/100;
	j+=i*100000;if(j<D && k!=j && j>=A)ans++;l=j;
	j=D;
	i=j%1000;
	j=j/1000;
	j+=i*10000;if(j<D && k!=j && l!=j && j>=A)ans++;m=j;
	j=D;
	i=j%10000;
	j=j/10000;
	j+=i*1000;if(j<D && k!=j && l!=j && m!=j && j>=A)ans++;n=j;
	j=D;
	i=j%100000;
	j=j/100000;
	j+=i*100;if(j<D && k!=j && m!=j && n!=j && l!=j && j>=A)ans++;o=j;
	j=D;
	i=j%1000000;
	j=j/1000000;
	j+=i*10;if(j<D && j>=A && k!=j && m!=j && n!=j && o!=j && l!=j)ans++;
	return ans;
}
long long int NOD(long long int D)
{
	long long int ans=0;
	while(D>0)
	{
		D=D/10;
		ans++;
	}
	if(ans==0)ans=1;
	return ans;
}
int main()
{
	long long int T,A,B,i,j,k,ca=0,ND,ans,p,q,r,r1;
	scanf("%lld",&T);
	while(T--)
	{
		ans=0;
		ca++;
		scanf("%lld%lld",&A,&B);
		for(i=A;i<=B;i++)
		{
			ND=NOD(i);
			if(ND==1)continue;
			if(ND==2)
			{
				ans+=RU2(i,A);continue;
			}
			if(ND==3)
			{
				ans+=RU3(i,A);continue;
			}
			if(ND==4)
			{
				ans+=RU4(i,A);continue;
			}
			if(ND==5)
			{
				ans+=RU5(i,A);continue;
			}
			if(ND==6)
			{
				ans+=RU6(i,A);continue;
			}
			if(ND==7)
			{
				ans+=RU7(i,A);continue;
			}
			
		}
		printf("Case #%lld: %lld\n",ca,ans);
	}
	return 0;
}