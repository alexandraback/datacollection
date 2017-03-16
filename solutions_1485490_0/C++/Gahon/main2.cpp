#include<stdio.h>
#include<fstream>
using namespace std;

struct done
{
	int type;
	long long num;
};
done a[4],b[101];
int aa,bb;
long long doit(int xa,int xb)
{
	if (xb>bb||xa>aa) return 0;
	if (a[xa].type==b[xb].type)
	{
		if (a[xa].num>b[xb].num)
		{
			long long t=b[xb].num;
			a[xa].num-=t;
			b[xb].num=0;
			return t+doit(xa,xb+1);
			//a[xa].num+=t;
			//b[xb].num=t;
		}

		if (a[xa].num==b[xb].num)
		{
			long long t=b[xb].num;
			a[xa].num-=t;
			b[xb].num=0;
			return t+doit(xa+1,xb+1);
			//a[xa].num+=t;
			//b[xb].num=t;
		}


		if (a[xa].num<b[xb].num)
		{
			long long t=a[xa].num;
			b[xb].num-=t;
			a[xa].num=0;
			return t+doit(xa+1,xb);
			//b[xb].num+=t;
			//a[xa].num=t;
		}
	}
	else
	{
		int i;
		done aaa[4],bbb[101];
		for (i=1;i<=aa;i++)
		{aaa[i].type=a[i].type;aaa[i].num=a[i].num;}
		for (i=1;i<=bb;i++)
		{bbb[i].type=b[i].type;bbb[i].num=b[i].num;}

		long long t1=doit(xa+1,xb);

		for (i=1;i<=aa;i++)
		{a[i].type=aaa[i].type;a[i].num=aaa[i].num;}
		for (i=1;i<=bb;i++)
		{b[i].type=bbb[i].type;b[i].num=bbb[i].num;}

		long long t2=doit(xa,xb+1);
		if (t1>=t2) return t1;
		else return t2;
	}
}
int main()
{
	ifstream in("D:/C-small-attempt0.in");
	ofstream out("D:/C-small-attempt0.out");

	long long i,tt,t,ans;
	in>>t;
	for (tt=1;tt<=t;tt++)
	{
		in>>aa>>bb;
		for (i=1;i<=aa;i++)
			in>>a[i].num>>a[i].type;
		for (i=1;i<=bb;i++)
			in>>b[i].num>>b[i].type;
		ans=doit(1,1); 
		out<<"Case #"<<tt<<": "<<ans<<endl;
	}

}