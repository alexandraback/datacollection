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
			for(int i=1; i<str.length(); i++)
			{
				string ts = str, fs, ls;
				fs = ts.substr(0, i);
				ls = ts.substr(i);
				ts = ls + fs;
				ss.clear();
				ss<<ts;
				int j;
				ss>>j;
				if(ts.length() != str.length()) continue;
				if(ts[0] == '0') continue;
				if(j > k && j<=B && j>=A)
				{
					ans++;
				}
			}
		}
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	return 0;
}