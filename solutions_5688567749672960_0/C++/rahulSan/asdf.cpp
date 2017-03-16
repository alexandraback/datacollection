#include<iostream>
using namespace std;
int getReverse(int n)
{
	int rev=0,r;
	while(n!=0)
	{
		r= n%10;
		rev = rev*10 + r;
		n /= 10;
	}
	return rev;
}
int containsZero(int n)
{
	int count=0;
	while(n!=0)
	{
		int r = n%10;
		if(r!=0)
			break;
		count++;
		n/=10;
	}
	if(count>0)
		return 1;
	else
		return 0;
}
int a[1000001];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,n;
	int no=0;
	for(int i=1;i<=20;i++)
		a[i]=i;
	
	for(int i=21;i<=1000000;i++)
	{
		if(!containsZero(i))
		{
			int k = getReverse(i);
			if(k < i)
			{
				int temp = a[k]+1;
				a[i] = min(temp,a[i-1]+1);
			}
			else
				a[i] = a[i-1] + 1;
		}
		else
			a[i] = a[i-1]+1;
	}
	cin>>t;
	while(t--)
	{
		no++;
		cin>>n;
		cout<<"Case #"<<no<<": "<<a[n]<<endl;
	}
}
