#include<iostream>
#include<fstream>
#include<stdio.h>
#include <iomanip>
#include<algorithm>
struct point{
	int x,y;
};
using namespace std;
point a[10000],b[10000];
int flag1[10000];
bool cmp(point a,point b)
{
	if (a.x<b.x) return true;
	return false;
}
int main()
{
	int t,ii,i,j,n,m,p,t1,t2,tt;
	bool flag;
	ifstream ifile;
	ifile.open("B-small-attempt1.in");
	ofstream ofile;
	ofile.open("2.txt");

	ifile>>t;
	//scanf("%d",&t);
	//ofile<<t<<endl;
	for(ii=1;ii<=t;ii++)
	{
		ifile>>n;
		//scanf("%d",&n);
		//ofile<<n<<endl;
		for(i=1;i<=n;i++)
		{
			ifile>>a[i].x>>b[i].x;
			a[i].y=i;
			b[i].y=i;
			//scanf("%d%d",&a[i],&b[i]);
		//	ofile<<a[i]<<" "<<b[i]<<endl;
		}
		sort(b+1,b+1+n,cmp);
		sort(a+1,a+1+n,cmp);
		t1=1;
		t2=1;
		tt=0;
		p=0;
		flag=true;
		for(i=1;i<=n;i++)
			flag1[i]=0;
		while(1)
		{
			if (t2>n) break;
			if (tt>=b[t2].x)
			{
				
				tt=tt+2-flag1[b[t2].y];
				flag1[b[t2].y]=1;
				t2++;
				
				p++;
				continue;
			}
			if (t1>n) 
			{
				flag=false;
				break;
			}
			if (tt>=a[t1].x)
			{
				tt=tt+1-flag1[a[t1].y];
				flag1[a[t1].y]=1;
				t1++;
				
				p++;
				continue;
			}
			flag=false;
			break;
		}
		if (flag) ofile<<"Case #"<<ii<<": "<<p<<endl;//3
		else
			ofile<<"Case #"<<ii<<": Too Bad"<<endl;
	}
	ifile.close();
	ofile.close();
	return 0;
}

