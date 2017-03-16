#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

int main()
{
	int T; cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";
		int a, b; cin >> a >> b;
		int co = 0;
		for(int i = a; i <= b; i++)
		{
			int m = i;
			int k = 1;
			while((m/=10)>0) k*=10;
			set<int> s;
			int t = 0;
			for(int j = 10; j <= k; j*=10)
			{
				m = i / j;
				int d = i % j;
				int n = d*(k/j*10)+m;
				if(s.find(n) != s.end()) continue;
				if(n > i && n <= b && n >= a) 
				{
					s.insert(n);
					co++;
				}
			}
		}
		cout << co << endl;
	}
}
