#include <fstream>

using namespace std;

ifstream cin;
ofstream cout;

int search(int a, int b, int k)
{
	int count  = 0;
	for(int i=0; i<a; ++i)
	{
		for(int j=0; j<b; ++j)
		{
			if( (i&j) < k)
			{
				//cout<<i<<j<<(i&j)<<endl;
				count ++;
			}
		}
	}
	return count;
}

int main()
{
	cin.open("B-small-attempt0.in");
	cout.open("B-small-attempt0.out");
	int t;
	cin>>t;
	for(int i=1; i<=t; ++i)
	{
		int a, b, k;
		cin>>a>>b>>k;
		int res = search(a, b, k);
		cout<<"Case #"<<i<<": "<<res<<endl;
	}
	return 0;
}