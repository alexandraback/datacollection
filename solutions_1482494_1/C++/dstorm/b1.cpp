#include <iostream>
using namespace std;
int main ()
{	bool b[1001][2],flag;
	int T,N,level[1001][2],stars,total,max,temp,i,j;
	cin>>T;
	i=1;
	while(i<=T)
	{	cin>>N;
		for (j=0;j<N;j++)
		{	cin>>level[j][0]>>level[j][1];
			b[j][0]=0;
			b[j][1]=0;
		}
		stars=0;
		total=0;
	while (stars!=2*N)
	{
		flag=0;
		for (j=0;j<N;j++)
		{
			if (b[j][1]==0 && stars>=level[j][1])
			{
				if (b[j][0]==1)
					stars++;
				else 
					stars+=2;
				b[j][0]=1;
				b[j][1]=1;
				flag=1;
				total++;
			}
		}
		if (flag==0)
		{	max=-1;
			for (j=0;j<N;j++)
			{
				if (b[j][0]==0 && stars>=level[j][0])
				{
					if (level[j][1]>max)
					{
						max=level[j][1];
						temp=j;
					}
					flag=1;
				}
			}
			if (flag==1)
			{
				stars++;
				total++;
				b[temp][0]=1;
			}
		}
		if (flag==0)
		{	total=-1;
			stars=2*N;
		}
	}
	if (total==-1)
		cout<<"Case #"<<i<<": Too Bad\n";
	
	else 
		cout<<"Case #"<<i<<": "<<total<<endl;
	i++;
	}
	return 0;
}