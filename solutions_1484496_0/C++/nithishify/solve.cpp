#include<iostream>
#include<fstream>
using namespace std;
int count;
long x[20],w[20],d;
long sol1[20],sol2[20];
int j1,j2;

void subset(int cs,int k,int r)
{
   int i;
   x[k]=1;
   if(cs+w[k]==d)
    { 
       if(count!=2)
		count++;
       if(count==1)
	{
		for(i=0;i<=k;i++)
		{
			if(x[i]==1)
			{
				sol1[j1]=w[i];
				j1++;
			}
		}
	}
	else if(count==2)
	{
		for(i=0;i<=k;i++)
		{
			if(x[i]==1)
			{
				sol2[j2]=w[i];
				j2++;
			}
		}
	}
   }
  else if(cs+w[k]+w[k+1] <=d)
        subset(cs+w[k],k+1,r-w[k]);
    if((cs+r-w[k]>=d)&&(cs+w[k+1])<=d)
    {               
      x[k]=0;
      subset(cs,k+1,r-w[k]);
    }
}


int main()
{
	int N,i,j,k,T,l;
	long sum;
		
	ifstream ip("C-small-attempt0.in");
	ofstream op("write.txt");
	ip>>T;
	for(i=0;i<T;i++)
	{
		ip>>N;
		sum=0;
		for(j=0;j<N;j++)
		{
			ip>>w[j];
		}
		for(j=0;j<N;j++)
		{
			sum+=w[j];
		}
		cout<<sum<<"\n";
		for(j=1;j<sum;j++)
		{
			count=0;
			j1=j2=0;
			d=j;
			for(k=0;k<N;k++)
				x[k]=0;
			subset(0,0,sum);
			//cout<<j<<"\t"<<count<<"\n";
			if(count==2)
				break;
		}
		if(count==2)
		{
		op<<"Case #"<<i+1<<": ";
		for(j=0;j<j1;j++)
			op<<sol1[j]<<" ";
		op<<"\n";
		for(j=0;j<j2;j++)
			op<<sol2[j]<<" ";
		op<<"\n";
		}
		else
			op<<"Case #"<<i+1<<": Impossible\n";

	}
	ip.close();
	op.close();
	return 0;
}
