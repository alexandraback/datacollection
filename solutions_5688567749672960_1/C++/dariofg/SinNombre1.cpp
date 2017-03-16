#include <iostream>

using namespace std;

bool exito;
long long asdf;

long long reverse(long long n)
{
	long long res = 0;
	while(n>0)
	{
		res*=10;
		res+=n%10;
		n/=10;
	}
	return res;
}

long long num(long long n)
{
	if(!(n%10))
		n--;
	long long i=1,nd=1;
	while(i*10<n)
		i*=10,nd++;
	i=10;
	for(int j=1;j<nd/2;j++)
		i*=10;
	n/=i;
	n*=i;
	n++;
	return n;
}

void rec(long long n,long long t)
{
	if(asdf<t)
		return;
	if(n==0)
	{
		asdf = n+t;
		return;
	}
	if((n%10==1) && reverse(n)<n)
		rec(reverse(n),t+1);
	if(num(n)<n)
		rec(num(n),t+n-num(n));
	rec(n-1,t+1);
}

long long fun(long long n)
{
	int count = 0;
	while(n>0)
	{
		if(num(n)==n && reverse(n)<n)
			n = reverse(n),count++;
		else if(num(n)==n)
			n--,count++;
		else
			count+=n-num(n),n=num(n);
	}
	return count;
}

int main()
{
	int t;
	cin >> t;
	for(int I=0;I<t;I++)
	{
		cout << "Case #" << I+1 << ": ";
		long long n;
		cin >> n;
		long long count = 0;
		long long tmp = 0;
		if(n<=20)
			cout << n << endl;
		else
		{
			long long a=0;
			while(n>9)
			{
				if(num(n)==n)
				{
					if(reverse(n)>=n)
						a++,n--;
					else
						a++,n=reverse(n);
				}
				else
					a+=n-num(n),n=num(n);
			}
			cout << a+n << endl;
		}
	}
}
