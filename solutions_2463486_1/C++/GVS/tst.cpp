#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int tst, t  , j , k , n,  m , h;
long long i;
vector<long long> v;

bool pal(long long x)
{
	string s = "";
	long long z = x , y = 0;
	while (x)
	{
		y = y * 10 + x % 10;
		x /= 10;
	}

	return (z == y);
}

int main()
{

	

	freopen("C-large-1.in" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);

	for (i = 1; i * i <= 100000000000000LL; i++)
	{
		if (pal(i) && pal(i * i))
		{
			v.push_back(i * i);
			//cout<<i<<" "<<i * i<<endl;
		}
	}

	cin>>tst;
	for (int t = 1; t <= tst; t++)
	{
		cout<<"Case #"<<t<<": ";
		long long A , B;
		int ans = 0;
		cin>>A>>B;
		for (i = 0; i < v.size(); i++)
		{
			if (v[i] >= A && v[i] <= B)
				ans++;
		}
		cout<<ans<<endl;

	}
	return 0;
}