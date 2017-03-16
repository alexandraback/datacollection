#include <iostream>
using namespace std;

void q1(int num)
{
	int a[1001];
	int cmax;
	cin >> cmax;
	char x;
//	cin >>x;
	int sum=0;
	int max_sum=0;
	for (int i=0;i<=cmax;++i)
	{
		if (i>sum)
			max_sum=max(max_sum,i-sum);

		cin >>x;
		a[i]=x-'0';
		sum+=a[i];
	}
	cout <<"Case #"<<num <<": " << max_sum << endl;
}

void q2(int num)
{
	int a[1001];
	int D;
	int i,j;
	cin >> D;
	for ( i=0;i<=1000;++i)
		a[i]=0;

	int tmp;
	for (i=0;i<D;++i)
	{
		cin>>tmp;
		a[tmp]++;
	}
	int res=1000;
	
	for (i=1;i<1000;++i)
	{
		tmp=i;
		for (j=1;j<=1000;++j)
		{
			tmp+=(a[j]*((j-1)/i));
		}
		if (tmp<res)
			res=tmp;
	}
	cout <<"Case #"<<num <<": " << res << endl;

}

int mul(int a,int b)
{
	int sign=0;
	if (a>=4)
		sign++;
	if (b>=4)
		sign++;
	if (a>=4)
		a-=4;
	if (b>=4)
		b-=4;

	if (sign==1)
		sign=4;
	if (sign==2)
		sign=0;
	if ((a==0)||(b==0))
		return (a+b+sign)%8;
	if (a==b)
		return (4+sign)%8;
	if ((a==1)&&(b==2))
		return (3+sign)%8;
	if ((a==1)&&(b==3))
		return (6+sign)%8;
	if ((a==2)&&(b==1))
		return (7+sign)%8;
	if ((a==2)&&(b==3))
		return (1+sign)%8;
	if ((a==3)&&(b==1))
		return (2+sign)%8;
	if ((a==3)&&(b==2))
		return (5+sign)%8;
	return 8;
}
int convert(char x)
{
	if (x=='i')
		return 1;
	if (x=='j')
		return 2;
	return 3;
}

void q3(int num)
{
	long long L,X;
	cin >> L >> X;
	int res=0;
	char tmp;
	int a[10001];
	int b[8];
	int c[8];
	int i;
	for (i=0;i<8;++i)
	{
		b[i]=-1;
		c[i]=-1;
	}for (i=0;i<L;++i)
	{
		cin  >> tmp;
		a[i]=convert(tmp);
		res =mul(res,a[i]);
		if (b[res]==-1)
			b[res]=i;
		c[res]=i;
	}
	if (res==0)
	{
		cout <<"Case #"<<num <<": " << "NO" << endl;
		return;
	}
	if ((res==4)&&((X%2)==0))
	{
		cout <<"Case #"<<num <<": " << "NO" << endl;
		return;
	}
	if (((res%4)!=0)&&((X%4)!=2))
	{
		cout <<"Case #"<<num <<": " << "NO" << endl;
		return;
	}
	int ans=0;
	if (X>=10)
	{
		for (i=0;i<8;++i)
			if (b[i]!=-1)
				if ((i==1)||(mul(res,i)==1)||(mul(res,mul(res,i))==1)||(mul(res,mul(res,mul(res,i)))==1))
					ans=1;
		if (ans==0)
			{
				cout <<"Case #"<<num <<": " << "NO" << endl;
				return;
			}
		ans=0;
		for (i=0;i<8;++i)
			if (b[i]!=-1)
				if ((i==3)||(mul(i,res)==3)||(mul(i,mul(res,res))==3)||(mul(i,mul(res,mul(res,res)))==3))
					ans=1;
		if (ans==0)
			{
				cout <<"Case #"<<num <<": " << "NO" << endl;
				return;
			}
		cout <<"Case #"<<num <<": " << "YES" << endl;
				return;

	}
	res=0;
	int ph=0;
	for (i=0;i<X*L;++i)
	{
		res=res*a[i%L];
		if (ph==0)
			if (res==1)
				ph++;
		if (ph==1)
			if (res==3)
			{
				cout <<"Case #"<<num <<": " << "YES" << endl;
				return;
			}
	}
	cout <<"Case #"<<num <<": " << "NO" << endl;
	return;
}


void q4(int num)
{
	int x,r,c;
	cin >> x >> r >>c;
	if (x>6)
	{
		cout <<"Case #"<<num <<": " << "RICHARD" << endl;
		return;
	}
	if (((r*c/x)*x)!=(r*c))
	{
		cout <<"Case #"<<num <<": " << "RICHARD" << endl;
		return;
	}
	if ((x>r)&&(x>c))
	{
		cout <<"Case #"<<num <<": " << "RICHARD" << endl;
		return;
	}
	if (x>(2*c))
	{
		cout <<"Case #"<<num <<": " << "RICHARD" << endl;
		return;
	}
	if (x>(2*r))
	{
		cout <<"Case #"<<num <<": " << "RICHARD" << endl;
		return;
	}
	if ((x==4)&&(r==2))
	{
		cout <<"Case #"<<num <<": " << "RICHARD" << endl;
		return;
	}
	if ((x==4)&&(c==2))
	{
		cout <<"Case #"<<num <<": " << "RICHARD" << endl;
		return;
	}
	if (x==5)
	{
		if ((c==3)&&(r<10))
		{
			cout <<"Case #"<<num <<": " << "RICHARD" << endl;
			return;
		}
		if ((r==3)&&(c<10))
		{
			cout <<"Case #"<<num <<": " << "RICHARD" << endl;
			return;
		}
	}
	if (x==6)
	{	
		if((c==3)||(r==3))
		{
		cout <<"Case #"<<num <<": " << "RICHARD" << endl;
		return;
		}

	}
		cout <<"Case #"<<num <<": " << "GABRIEL" << endl;
		return;
	
}
int main()
{
	int T;
	cin >> T;
	for (int i=0;i<T;++i)
		q2(i+1);
}