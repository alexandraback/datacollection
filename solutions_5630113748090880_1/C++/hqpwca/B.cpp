#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <queue>
#include <functional>
#include <list>
#include <set>
#include <sstream>
#define ll long long

using namespace std;

int vis[3000];

int main()
{
	ios::sync_with_stdio(false);

	//while(cin>>n)

	int T;
	cin>>T;
	for(int cas=1;cas<=T;cas++)
	{
		int t,n;
		memset(vis,0,sizeof(vis));
		cin>>n;
		for(int i=0;i<2*n-1;i++)
			for(int j=0;j<n;j++)
			{
				cin>>t;
				vis[t]++;
			}
		cout<<"Case #"<<cas<<":";
		for(int i=0;i<3000;i++)
			if(vis[i]&1)cout<<' '<<i;
		cout<<endl;
		//cout<<"Case "<<cas<<": ";
	}

	return 0;
}
