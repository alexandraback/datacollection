#include<iostream>
using namespace std;
int main()
{
	long long int n;
	cin>>n;
	for(long long int ttt=1;ttt<=n;ttt++)
	{
		long long int n1,n2;
		cin>>n1>>n2;
		long long int total_count=0;
		for(long long int i=n1;i<=n2;i++)
		{
			long long int len=0;
			long long int temp=i;
			long long int power=1;
			while(temp)
			{
				temp=temp/10;
				len++;
				power=power*10;
			}
			power=power/10;
			long long int count=0;
			temp=i;
			long long int flag=1;
			long long int temp_check[10];
			long long int temp_check_size=1;
			temp_check[0]=i;
			for(long long int j=0;j<len;j++)
			{
				long long int x=temp%10;
				temp=x*power+temp/10;
		//		cout<<temp<<endl;
				long long int f=1;
				for(long long int k=0;k<temp_check_size;k++)
				{
					if(temp_check[k]==temp){f=0;break;}
				}
				if(f==1)
				{
					if(temp < i && temp>=n1){flag=0;break;}
					else if (temp > i && temp<=n2 )count++;
					temp_check[temp_check_size++]=temp;
				}
			}
			if(flag==1 && count>0){ total_count+=(count*(count+1))/2; }
		}
		cout<<"Case #"<<ttt<<": "<<total_count<<endl;
	}
}
