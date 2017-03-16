#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int main()
{
	int T,N,t,i,a[250],j;
	double sum,ans;
	cin>>T;
	t=T;
	while(T--)
	{
		cin>>N;
		sum=0;
		for(i=0;i<N;i++)
		{	cin>>a[i];sum=sum+a[i];}
		cout<<"Case #"<<t-T<<": ";	
		for(i=0;i<N;i++)
		{
			int number=0,s=0;
			for(j=0;j<N;j++)
			{
				if(a[j]>((2*sum)/N) && j!=i)
					{s+=a[j];number++;}
			}
			/*ans=(((2*sum-s)*100)/(N-number) - 100*a[i])/sum;*/
			double ach=((2*sum)-s)/(N-number);
			ans=(ach-a[i])*100/sum;
			if(ans<0)
				ans=0;
			printf("%.6lf ",ans);		
		}
		cout<<endl;
	}
return 0;
}
