#include <bits/stdc++.h>
using namespace std;
long long reverse(long long n)
{
	long long k = 0;
	while(n)
	{
		k = 10*k + n%10;
		n = n/10;
	}
	return k;
}
int main()
{
	freopen("A-small-attempt0.in" , "r" , stdin);
	freopen("outputfirst.out" ,"w",stdout);
	int t , count;
	cin >> t;
	for(count = 1;count <= t;count++)
	{
		long long int n , a , b;
		map <int , bool> m;
		cin >> n;
		queue <pair <long long , int > > q;
		q.push(make_pair(1 , 1));
		m[1] = 1;
		while(!q.empty())
		{
			a = q.front().first;
			b = q.front().second;
			q.pop();
			if(a == n)
			{
				cout << "Case #" << count << ": " << b << endl;
				break;
			}
			if(!m[a+1] && a+1 <= n)
			{
				m[a+1] = 1;
				q.push(make_pair(a+1 , b+1));
			}
			a = reverse(a);
			if(!m[a] && a <= n)
			{
				m[a] = 1;
				q.push(make_pair(a , b+1));
			}
		}
	}
	return 0;
}