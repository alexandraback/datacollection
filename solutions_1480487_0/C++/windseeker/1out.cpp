#include<iostream>
#include<cmath>
using namespace std;
double org[1000];
const int L=100000000;
int n;
double sum;
double Exp=1e-8;

bool check(int x,double pri)
{
	int i,j;
	double cnt=pri;
	for(i=0;i<n;i++)
	{
		if(i!=x)
		{
			double temp=(org[x]+sum*pri-org[i])/sum;
			if(temp<0)
			temp=0;
			cnt+=temp;
		}
	}
	if(cnt<=1.0)
	return false;
	//cout<<cnt<<endl;
	return true;
}

double find(int x)
{
	int l=0;
	int r=L*2;
	while(l<=r)
	{
		int mid=(l+r)/2;
		double mval=mid/(double)L;
		//cout<<l<<" "<<r<<" "<<mval<<endl;
		if(check(x,mval))
		{
			if(mid==0||(!check(x,(mid-1)/(double)L)))
			{
				//cout<<endl<<" mid="<<mid<<endl;
				return mval;
			}
			r=mid-1;
		}
		else
			l=mid+1;
	}
	return -1.0;
}

int main()
{
	freopen("A-small-attempt0(1).in","r",stdin);
	freopen("A-small-attempt0(1).out","w",stdout);
	int i,j;
	int c;
	int tc=1;
	cin>>c;
	while(c--)
	{
		sum=0;
		cin>>n;
		bool flag=false;
		for(i=0;i<n;i++)
		{
			cin>>org[i];
			sum+=org[i];
		}
		printf("Case #%d:",tc++);
		for(i=0;i<n;i++)
		{
			double res=find(i);
			printf(" %.6lf",res*100);
		}
		puts("");
	}
}