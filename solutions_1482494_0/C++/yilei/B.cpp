#include <iostream>
#include <queue>
using namespace std;

class Req
{
public:
	int r1;
	int r2;
}req[1005];

int cmp1(const void * e1, const void * e2)
{
	Req * l1=(Req *)e1;
	Req * l2 = (Req *)e2;
	return (l1->r1)-(l2->r1);
}

int cmp2(const void * e1, const void * e2)
{
	Req * l1=(Req *)e1;
	Req * l2 = (Req *)e2;
	return (l1->r2)-(l2->r2);
}
bool flag1[1005];
bool flag2[1005];
int main()
{
	int n,t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		memset(flag1,0,sizeof(flag1));
		memset(flag2,0,sizeof(flag2));
		cin>>n;
		for (int j=0;j<n;j++)
		{
			cin>>req[j].r1>>req[j].r2;
			flag1[j]=false;
			flag2[j]=false;
		}
		int cur = 0;
		int cnt=0;
		int num=0;
		//qsort(req,n,sizeof(Req),cmp2);
		while(num<n)
		{
			bool f=false;
			for (int j=0;j<n;j++)
			{
				if (cur>=req[j].r2 && flag2[j]==false)
				{
					if (flag1[j]==false)
						cur+=2;
					else
						cur+=1;
					flag1[j]=flag2[j]=true;
					cnt++;
					f=true;
					num++;
				}
			}
			if (f==false)
			{
				int mini=100000000;
				int maxi=0;
				int pos=-1;
				for (int j=0;j<n;j++)
				{
					if (flag1[j]==false)
					{
						if (req[j].r2>maxi&&req[j].r1<=cur)
						{
							maxi=req[j].r2;
							pos=j;
						}
					}
				}
				if (pos!=-1)
				{
					cur+=1;
					flag1[pos]=true;
					cnt++;
					f=true;
				}
			}
			if (f==false)
				break;
		}
		if (num==n)
			cout<<"Case #"<<i<<": "<<cnt<<endl;
		else
			cout<<"Case #"<<i<<": "<<"Too Bad"<<endl;
	}
	return 0;
}