
#include <iostream>
#include <vector>
using namespace std;

vector<long long> vc;
long long vc_size; 
bool is_palindromes(long long n)
{
	long long p,m;
	p=n;
	m=0;
	while(p)
	{
		m=m*10+p%10;
		p/=10;
	}
	return (m==n);
}
long long  binary_search(long long a)
{
	long long low,high,middle;
	long long index_a;
	low=0;high=vc_size;
	index_a=-1;
	while(low<high)
	{
		middle=low+(high-low)/2;
		if (vc[middle]>a)
		{
			high=middle;
		}
		else 
		{
			index_a=middle;
			low=middle+1;
		}
	}
	return index_a+1;
}
int main()
{
	int t;
	int ca=0;
	cin>>t;
	long long a,b;
	for (long long i=1;i<=10000000;i++)
	{
		if (is_palindromes(i)&&is_palindromes(i*i))
		{
			vc.push_back(i*i);
		}
	}
	vc_size=vc.size();
	while(t--)
	{
		ca++;
		cin>>a>>b;
		long long index_a,index_b;
		index_a=binary_search(a-1);
		index_b=binary_search(b);
		cout<<"Case #"<<ca<<": ";
		cout<<(index_b-index_a)<<endl;
	}
	return 0;
}
