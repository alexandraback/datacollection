#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int pow10[]={1,10,100,1000,10000,100000,1000000,10000000};
int main()
{
	freopen("C-small-attempt0.in","r",stdin);freopen("out.txt","w",stdout);
	int T,A,B,n,cas=0;
	cin>>T;
	while(T--)
	{
		cin>>A>>B;
		long long ans=0;
		cas++;
		printf("Case #%d: ",cas);
		bool used[2000000+5];
		memset(used,0,sizeof(used));
		int S;
		for(n=A;n<=B;n++)
		{
			S=1;used[n]=1;
			int num=0,temp=n;
			while(temp)
			{num++;temp/=10;}
			int i,j;
			int D[100];
			temp=n;
			for(i=num;i>=1;i--)
			{
				D[i]=temp%10;
				temp/=10;
			}
			for(i=1;i<=num;i++) D[num+i]=D[i];
			for(i=1;i<=num;i++)
			{
				if(D[i]==0) continue;
				int N=0;
				for(j=i;j<=i+num-1;j++) N=N*10+D[j];
				if(N>=A && N<=B && !used[N])
				{
					S++;
					used[N]=1;
				}
			}
			ans+=(long long)S*(S-1)/2;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
