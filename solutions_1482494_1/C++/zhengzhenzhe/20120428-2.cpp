
#include <iostream>
#include <fstream>
using namespace std;

struct node
{
	int a1,a2;
};
bool cmp(node a,node b)
{
	if(a.a2<b.a2)
		return true;
	if(a.a2==b.a2)
		if(a.a1<b.a1)
			return true;
	return false;
}
int main()
{
	freopen("b_large1.in","r",stdin);
	freopen("b_l_2.out","w",stdout);
	int T;
	int n;
	node a[1001];

	cin>>T;
	for(int t=0;t<T;t++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i].a1>>a[i].a2;
		int nowrate=0;
		sort(a,a+n,cmp);
		int tnum=0;
		bool isok2[1001]={0};
		int ok2num=0;
		bool isok1[1001]={0};		
		while(1)
		{
			int tmprate=nowrate;
			for(int i=0;i<n;i++)
				if(a[i].a2<=nowrate&&!isok2[i])
				{
					isok2[i]=true;
					tnum++;
					if(!isok1[i])
						nowrate+=2;
					else 
						nowrate++;
					ok2num++;
				}
			if(ok2num==n)
				break;
			for(int i=n-1;i>=0;i--)
			{
				if(a[i].a1<=nowrate&&!isok1[i]&&!isok2[i])
				{
					isok1[i]=true;
					tnum++;
					nowrate+=1;
					break;
				}
			}
			if(tmprate==nowrate)
				break;

		}
		cout<<"Case #"<<t+1<<": ";
		if(ok2num==n)
			cout<<tnum<<endl;
		else 
			cout<<"Too Bad"<<endl;
	}
	return 0;
}
