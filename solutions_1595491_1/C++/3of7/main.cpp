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

int main()
{
	int T, N, S, P, ans;
	vector<int> A;
	int tmp;
	cin>>T;
	for(int t=1; t<=T; t++)
	{
		ans = 0;
		A.clear();
		cin>>N>>S>>P;
		for(int n=0; n<N; n++)
		{
			cin>>tmp;
			A.push_back(tmp);
		}
		sort(A.begin(), A.end());
		reverse(A.begin(), A.end());
		for(int i=N; i>=0; i--)
		{
			bool possible = true;
			int tS = S;
			int numpos = 0;
			for(int n=0; n<N; n++)
			{
				int a,b,c;
				a = P;
				b = max(P-1, 0);
				c = max(P-1, 0);
				if(a+b+c > A[n])
				{
					tS--;
					if(tS < 0)
					{
						break;
					}
					if(b>0) b--;
					if(c>0) c--;
					if(a+b+c > A[n])
					{
						break;
					}
				}
				numpos++;
			}
			if(numpos >= i)
			{
				ans = i;
				break;
			}
		}
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	return 0;
}