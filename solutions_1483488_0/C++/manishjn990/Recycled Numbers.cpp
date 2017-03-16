#include<cstdio>
#include<cstring>
#include<cstdlib>
int NOD(int D)
{
	int ans=0;
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
	int T,A,B,i,j,k,ca=0,ND,ans,p,q,r,r1;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		ca++;
		scanf("%d%d",&A,&B);
		for(i=A;i<=B;i++)
		{
			ND=NOD(i);
			if(ND==1)continue;
			if(ND==4)
			{
				if(A<=1)ans++;
				if(A<=10)ans++;
				if(A<=100)ans++;
				//printf("Hello\n");
			}
			if(ND==2)
			{
				j=i;
				r=j%10;
				j=j/10;
				j+=r*10;
				if(j<i && j>=A)ans++;
				//printf("Hello\n");
			}
			if(ND==3)
			{
				j=i;k=i;
				r=j%10;
				r1=j%100;
				j=j/10;
				j+=r*100;
				if(j<i && j>=A)ans++;
				k=k/100;
				k+=r1*10;
				if(k<i && k>=A)ans++;
				//printf("Hello\n");
			}
		}
		printf("Case #%d: %d\n",ca,ans);
	}
	return 0;
}