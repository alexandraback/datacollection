#include<iostream>
#include<set>
#include<map>

using namespace std;
set < pair<int , int> > S;

void num(int n , int a , int b)
{
	long long ans = 0;
	int q = n;
	int l = 0;
	int arrey[10];
	while(q)
	{
		arrey[l] = q%10;
		q/=10;
		l++;
	}
	for(int i=0 ; i<(l/2) ; i++)
		swap(arrey[i] , arrey[l-i-1]);
	if(l > 1)
	{
		for(int i = 0 ; i < l-1 ; i++)
		{
			int p = arrey[l-1];
			for(int j = l-2 ; j >= 0 ; j--)
				arrey[j+1] = arrey[j];
			arrey[0] = p;
			int nu = 0;
			for(int j=0 ; j<l ; j++)
			{
				nu*=10;
				nu+=arrey[j];
			}
			if( a <= nu && nu <= b)
				if( nu != n)
					S.insert(make_pair(n , nu));
		}
	}
}
int main()
{
	int t;
	cin >> t;
	int test = 1;
	while(t -- )
	{
		S.clear();
		int a , b;
		cin >> a >> b;
		long long ans = 0;
		for(int i=a ; i <= b ; i++)
			num(i , a , b);
		cout << "Case #" << test << ": " << S.size()/2 << endl;
		test++;
	}
}
