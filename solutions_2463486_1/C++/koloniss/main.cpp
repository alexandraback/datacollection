#include <iostream>
#include <string>
#include <memory.h>
#include <math.h>
using namespace std;

long long mas[100];
int count;
long long A,B;

bool is_palindrome(long long x) 
{
	long long temp = x;
	long long res = 0;
	while (temp > 0)
	{
		res = res*10 + temp%10;
		temp/=10;
	}
	return (res == x);
}

	
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	count = 0;
	for (long long i = 0; i < 10000015;i++)
	{
		if (is_palindrome(i)) 
		{
			if (is_palindrome(i*i))
				mas[count++] = i;
		}
	}
	int T;
	cin>>T;
	for (int t = 0;t < T;t++)
	{
		cout<<"Case #"<<t+1<<": ";
		cin>>A>>B;
		int res = 0;
		for (int i = 0; i< count;i++)
		{
			if (mas[i]*mas[i]>=A && mas[i]*mas[i]<=B) res++;
		}
		cout<<res<<endl;
	}
	return 0;
}