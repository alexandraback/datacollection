#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

bool iscons(char c)
{
	return !(c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}


int main()
{
	freopen("input.in","r",stdin);
	freopen("out.txt","w",stdout);
	int TC;
	cin >> TC;
	for(int tc=  1; tc<=TC; ++tc)
	{
		string A;
		cin >> A;
		long long N;
		cin >> N;
		long long ans = 0;
		long long c = 0, p = -1, st = 0;
		for(int i = 0; i < A.size(); ++i)
		{
			if(iscons(A[i]))
				c++;
			else
				c = 0;
			if(c >= N)
			{
				st = i-N+1;
				long long a = st-p;
				long long b = A.size()-i;
				ans += a*b;
				p = st;
			}
		}
		cout <<"Case #"<<tc<<": "<< ans << endl;
	}
}
