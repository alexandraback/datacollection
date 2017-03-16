#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <list>
#include <sstream>
#include <map>
#include <limits>

using namespace std;

bool iseq(int _a, int _b)
{
	double a = _a;
	double b = _b;
	int c = floor(log10(a + 0.00000001));
	int d = floor(log10(b + 0.00000001));
	return c == d;
}

int main()
{
	int T, A, B;
	int V[2000000];
	int ans;
	cin>>T;
	for(int t=1; t<=T; t++)
	{
		memset((void*)(V), 0, sizeof(V));
		ans = 0;
		cin>>A>>B;
		for(int k=A; k<=B; k++)
		{
			stringstream ss;
			ss<<k;
			string str;
			ss>>str;
			string ts = str;
			set<int> s;
			for(int i=1; i<str.length(); i++)
			{
				rotate(ts.begin(), ts.begin()+1, ts.end());
//cout<<ts<<endl;
				ss.clear();
				ss<<ts;
				int j;
				ss>>j;
				if(j > k && j>= A && j<=B && iseq(k, j))
				{
					s.insert(j);
				}
			}
			ans += s.size();
		}
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	return 0;
}