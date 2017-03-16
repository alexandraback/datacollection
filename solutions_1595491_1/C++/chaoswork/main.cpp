#include<iostream>
#include<sstream>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<numeric>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<limits>
using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
#ifdef CHAOS
	freopen("data.in","r",stdin);
#endif
	int T;
	cin>>T;
	int t;
	for(t=1;t<=T;++t)
	{
		cout<<"Case #"<<t<<": ";
		int ans=0;
		int dt=0;
		int N,S,p;
		cin>>N>>S>>p;
		int i,x;
		for(i=0;i<N;++i)
		{
			cin>>x;
			if(x%3==0)
			{
				if(x/3>=p) ++ans;
				else if(x/3-1>=0 && x/3+1>=p) ++dt;
			}
			else if(x%3==1)
			{
				if(x/3+1>=p) ++ans;
			}
			else
			{
				if(x/3+1>=p) ++ans;
				else if(x/3+2>=p) ++dt;
			}
		}
		cout<<ans+min(S,dt)<<endl;
	}

	return 0;
}
