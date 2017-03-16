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

int f[1003][1003];

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	for(int P=1000;P>=1;--P)
		for(int q=0;q<=1000;++q)
		{
			if(q<=P) f[P][q]=0;
			else
			{
				int ans=123456;
				for(int r=1;r<=q/2;++r)
					ans=min(ans,f[P][r]+f[P][q-r]+1);
				f[P][q]=ans;
			}
		}
	int t,cas=1;
	cin>>t;
	while(t--)
	{
		cout<<"Case #"<<cas++<<": ";
		int d;
		cin>>d;
		vector<int> diner(d);
		for(int i=0;i<d;++i)
			cin>>diner[i];
		int answer=123456;
		for(int P=1000;P>=1;--P)
		{
			int cnt=0;
			for(int i=0;i<d;++i)
				cnt+=f[P][diner[i]];
			answer=min(answer,cnt+P);
		}
		cout<<answer<<'\n';
	}
    return 0;
}