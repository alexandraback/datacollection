#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

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

int main()
{
	v = vector<int> (10000000);
	for(int i=0;i<v.size();i++)
		v[i] = i;
	for(int i=1;i<v.size();i++)
		v[i] = min(v[i-1]+1,v[i]),v[reverse(i)] = min(v[i]+1,v[reverse(i)]);
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin >> n;
		cout << "Case #" << i+1 << ": " << v[n] << endl;
	}
}
