#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define for0(i , N) for(int i = 0; i < (N); i++)
#define pb push_back

using namespace std;

struct l
{
	int a;
	int b;
	bool one;
};

bool mys(l A, l B)
{
	return A.b > B.b;
} 

bool mys2(l A, l B)
{
	if (A.a == B.a)
		return A.b < B.b;
	return A.a > B.a;
} 

int main()
{
	int kases;
	cin >> kases;

	for0(kase, kases)
	{
		int N;
		vector<l> lis;
		cin >> N;
		for0(n, N)
		{
			l tmp = {0, 0 , false};
			cin >> tmp.a >> tmp.b;
			lis.pb(tmp);
			//cout << tmp.a << " " << tmp.b << endl;
		}
		int stars = 0;
		int steps = 0;
		bool fail = false;
		while(!lis.empty() && !fail)
		{
			sort(lis.begin(), lis.end(), mys);
			
			
			
			while(!lis.empty() && lis.back().b <= stars)
			{
				if (lis.back().one)
					stars += 1;
				else
					stars += 2;
				lis.pop_back();				
				steps++;
				//cout << " 2 ";
			}			
			if (!lis.empty())
			{
				sort(lis.begin(), lis.end(), mys2);
				
				//for0(i, lis.size())
				//cout << lis[i].a << " " << lis[i].b << endl;
				//cout << endl;
				
				for(int i = lis.size() -1; i >=0; i--)
				{
					if(lis[i].a <= stars && !lis[i].one)
					{
						lis[i].one = true;
						stars += 1;
						steps++;
						//cout << " 1 ";
						break;
					}
					if (i == 0)
						fail = true;	
				}			
			}
		}
		//cout << stars << endl;
		if (!fail)
			cout << "Case #" << kase + 1 << ": " << steps << endl;
		else
			cout << "Case #" << kase + 1 << ": " << "Too Bad" << endl;
	}
	
}
