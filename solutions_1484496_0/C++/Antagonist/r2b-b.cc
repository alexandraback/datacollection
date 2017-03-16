#include <iostream>
#include <map>

using namespace std;

void process()
{
	int n;
	cin >> n;
	int s[20];
	map<int, int> v;
	for(int i = 0; i < n; i++)
		cin >> s[i];	
	for(int i = 1; i < (1<<20); i++)
	{
		int sum = 0;
		for(int j = 0; j < 20; j++)
			sum += ((i >> j) & 1) ? s[j] : 0;
		if( v.find(sum) != v.end() )
		{
			auto p = v.find(sum);
			for(int j = 0; j < 20; j++)
				if( (p->second >> j) & 1 )
					cout << s[j] << " ";
			cout << endl;
			for(int j = 0; j < 20; j++)
				if( (i >> j) & 1 )
					cout << s[j] << " ";
			cout << endl;
			return;
		}
		else
			v[sum] = i;
	}
	cout << "Impossible" << endl;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		printf("Case #%d:\n", i+1);
		process();
	}
}
