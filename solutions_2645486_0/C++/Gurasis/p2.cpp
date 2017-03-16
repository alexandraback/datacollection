#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{int e,r,n,ar[20],i,m,t,ga;
cin>>t;
for(m=0;m<t;m++)
	{cin>>e;
cin>>r;
cin>>n;
ga=0;
if(n!=0) cin>>ar[0];
int temp=0;
for(i=1;i<n;i++)
	{cin>>ar[i];
	if(ar[i]>ar[temp]) temp=i;
	}

for(i=0;i<n;i++)
	{if(i==temp)
		{ga+=ar[i]*e;

		}

	else
		{ga+=ar[i]*r;}
	}

cout<<"Case #"<<m+1<<": "<<ga<<endl;


	}

}
