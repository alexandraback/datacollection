#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int count = 0;

int n, j;	

long long to_base(vector <int> inp, int b)
{
	long long num = 0;
	long long pow = 1;
	for(int i=inp.size()-1;i>=0;i--)
	{
		num+=inp[i]*pow;
		pow*=b;
	}
	return num;
}

int is_prime(long long num)
{
	for(int i=2;i<sqrt(num);i++)
		if(num%i==0)
			return i;
	return -1;
}

void rec(vector<int> &s, int p, int n)
{
	if(count>=j)
		return;
	if(p==n-1)
	{
		for(int i=2;i<=10;i++)
		{
			long long num = to_base(s, i);
			if(is_prime(num)<0)
				return;
		}		
		
		
		for(int i=0;i<n;i++)
			cout << s[i];
		cout << " ";
		
		for(int i=2;i<=10;i++)
		{
			long long num = to_base(s, i);
			cout << is_prime(num);
			if(i<10)
				cout << " ";
		}
		
		cout << endl;
		
		count++;
		
		
		long long k = to_base(s, 3);
		//cout << k << " -- " << is_prime(k) << endl;
		return;	
	}
	
	s[p] = 0;
	rec(s, p+1, n);
	s[p] = 1;
	rec(s, p+1, n);
}



int solve_print(int n, int j)
{	

	vector<int> inp(n);
	inp[0] = 1;
	inp[n-1] = 1;	
	rec(inp, 1, n);
}


int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		
		cin >> n >> j;
		cout << "Case #" << i+1 << ":" << endl;
		solve_print(n,j);
	}
	return 0;
}

