#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int get(int a)
{
	vector <int> z;
	int x=a;
	while (x!=0)
	{
		z.push_back(x%10);
		x/=10;
	}
	//reverse(z.begin(),z.end());
	int y=0;
	for (int i=0;i<z.size();i++)
	{
		y*=10;
		y+=z[i];
	}
	return y;
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int q;
	cin>>q;
	for (int qq=0;qq<q;qq++)
	{
		cout<<"Case #"<<qq+1<<": ";
		int n;
		cin>>n;
		vector <int> dp(n+1,2e9);
		dp[1]=1;
		for (int i=1;i<n;i++)
		{
			dp[i+1]=min(dp[i+1],dp[i]+1);
			int f=get(i);
			if (f<=n)
			{
				dp[f]=min(dp[f],dp[i]+1);
			}
		}
		cout<<dp[n]<<endl;
	}
		
	return 0;
}



