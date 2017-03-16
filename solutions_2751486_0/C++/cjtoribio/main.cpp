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
	int TC;
	cin >> TC;
	for(int tc=  1; tc<=TC; ++tc)
	{
		string A;
		cin >> A;
		int N;
		cin >> N;
		int ans = 0;
		int c = 0, p = -1, st = 0;
		for(int i = 0; i < A.size(); ++i)
		{
			if(iscons(A[i]))
				c++;
			else
				c = 0;
			if(c >= N)
			{
				st = i-N+1;
				int a = st-p;
				int b = A.size()-i;
				ans += a*b;
				p = st;
			}
		}
		cout <<"Case #"<<tc<<": "<< ans << endl;
	}
}
