#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int count(long long x)
{
	int num=0;
	while(x>0)
	{
		x=x/10;
		num++;
	}
	return num;
}

long long squ(int x,int y)
{
	if (y==0) return 1;
	int t=x;
	for (int i=1;i<y;i++) {t*=x;}
	return t;
}

bool palind(long long x)
{
	int  r[100]={-1};
	int num=0;
	while (x>0)
	{
		r[num]=x % 10;
		x=x/10;
		num++;
	}
	for (int i=0;i<(num/2);i++)
	{
		if (r[i] != r[num-i-1]) return false;
	}
	return true;
}
//
//bool square(long long  x)
//{
//	long long  m=sqrt (double(x));
//	
//	if (x==(m*m) && palind(m) ) return true; else return false;
//}

int inverse(int x)
{
	int a[10]={0};
	int num=0;
	while (x>0)
	{
		a[num]=x%10;
		x=x/10;
		num++;
	}
	int res=0;
	for (int i=0;i<num;i++)
	{
		res=res*10+a[i];
	}
	return res;
}

int main()
{
	freopen ("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int T;
	cin >> T;
	for (int qq=1;qq<=T;qq++)
	{
		long long a,b;
		cin >> a>>b;
		int total=0;
		/*int la=count(a);
		int lb=count(b);
		la=(1+la)/2;
		lb=(1+lb)/2;
		long long c,d;
		c=squ(10,la-1);
		d=squ(10,lb)-1;
		while ((c*c)<a) c++;
		while ((d*d)>b) d--;*/
		//long long c=sqrt(long double(a));
		//long long d=sqrt(long double(b));
		//int lc=count(c);
		//int ld=count(d);
		//for (long long i=c;i<=d;i++)
		//{
		//	if (palind(i) && palind(i*i))
		//	{
		//			cout<<i<<endl;
		//			total++;
		//	}
		//}



		if (a==1) total++;
		if (4>=a && 4<=b) total++;
		if (9>=a && 9<=b) total++;

		for (int i=1;i<1000;i++)
		{
			int len=count(i);
			long long temp=inverse(i);
			long long t=i*squ(10,len)+temp;
			long long tt=t*t;
			if (palind(tt) && tt>=a && tt<=b) {total++;}
			t=i*squ(10,len+1)+temp;
			for (int j=0;j<10;j++)
			{
				long long t0=t+squ(10,len)*j;
				tt=t0*t0;
				if (palind(tt) && tt>=a && tt<=b) {total++;}
			}
		}

		cout <<"Case #"<<qq<<": "<< total<<endl;
	}
	return 0;
}