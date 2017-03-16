#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int k,t,cnt,z,num_dig;
	long long int num,a,b,j,n,dig,tmp;
	long long int tot;
	
	//int hash[2000001];
	cin>>t;
	for(k=1;k<=t;k++)
	{
		cout<<"Case #"<<k<<": ";
		//for(int x=0;x<=2000000;x++)
		//hash[x]=0;
		tot=0;
		
		cin>>a>>b;
		for(j=a;j<b;j=n+1)
		{
			//cout<<'\n'<<j<<" ";
			cnt=0;
			n = j;
			num=j;
			num_dig=0;
			
			while(num)
			{
				num_dig++;
				num/=10;
			}
			
			for(z=0;z<num_dig;z++)
			{
				dig = j%10;
				num = j/10;
				if(dig>0)
				{
					while(num)
					{
						num/=10;
						dig*=10;
					}
					j = dig + j/10;
					if(j>n && j<=b) { cnt++; /*cout<<j<<" ";*/}
					if(j==n) break;
				}
				else
				{
					tmp=100;
					while(j%tmp==0)
					{
						tmp*=10;
					}
					dig = j%tmp;
					num=j/tmp;
					while(num)
					{
						num/=10;
						dig*=10;
					}
					j = dig + j/tmp;
					if(j>n && j<=b) { cnt++; /*cout<<j<<" ";*/}
					if(j==n) break;
				}
			}
			
			tot +=cnt;
		}
		cout<<tot<<'\n';
	}
	
	
	return(0);
}
