#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<sstream>
#include<set>
#include<hash_set>
using namespace std;


int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("b.out","w",stdout);
	int T;
	cin>>T;
	for(int cas=1;cas<=T;cas++)
	{
		int x,y,xt=0,yt=0;
		string s;
		cin>>x>>y;
		int step=1;
		if(x>0)
		{
			while(xt+step<=x)//x
			{
				xt+=step;
				s.push_back('E');
				step++;
			}
			while(x-xt)
			{
				xt-=step;
				s.push_back('W');
				step++;
				xt+=step;
				s.push_back('E');
				step++;
			}
		}
		else
		{
			while(xt-step>=x)//x
			{
				xt-=step;
				s.push_back('W');
				step++;
			}
			while(abs(x-xt))
			{
				xt+=step;
				s.push_back('E');
				step++;
				xt-=step;
				s.push_back('W');
				step++;
			}
		}
		if(y>0)
		{
			while(yt+step<=y)//y
			{
				yt+=step;
				s.push_back('N');
				step++;
			}
			while(y-yt)
			{
				yt-=step;
				s.push_back('S');
				step++;
				yt+=step;
				s.push_back('N');
				step++;
			}
		}
		else
		{
			while(yt-step>=y)//y
			{
				yt-=step;
				s.push_back('S');
				step++;
			}
			while(abs(y-yt))
			{
				yt+=step;
				s.push_back('N');
				step++;
				yt-=step;
				s.push_back('S');
				step++;
			}
		}
		cout<<"Case #"<<cas<<": "<<s<<endl;
	}
	return 0;
}
			