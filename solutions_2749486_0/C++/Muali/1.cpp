#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
string solve()
{
	int x, y;
	cin>>x>>y;
	string ans;
	if(x>0)
	{
		for(int i=0; i<x; i++)
		ans+="WE";
	}
	else
	{
		for(int i=0; i>x; i--)
			ans+="EW";
	}
	if(y>0)
	{
		for(int i=0; i<y; i++)
			ans+="SN";
	}
	else
	{
		for(int i=0; i>y; i--)
			ans+="NS";
	}
	return ans;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int z=0; z<t; z++)
	{
		cout<<"Case #"<<z+1<<": "<<solve()<<'\n';
	}
}