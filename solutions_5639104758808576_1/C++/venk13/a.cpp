#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,cas=1;
	cin>>t;
	while(t--)
	{
		cout<<"Case #"<<cas++<<": ";
		int s;
		cin>>s;
		string p;
		cin>>p;
		int have=p[0]-'0';
		int need=0;
		for(int i=1;i<s+1;++i)
		{
			need+=max(0,i-have);
			have=max(i,have)+p[i]-'0';
		}
		cout<<need<<'\n';
	}
    return 0;
}