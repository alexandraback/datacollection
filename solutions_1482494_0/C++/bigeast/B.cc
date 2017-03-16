#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
vector< pair<int,int> > rat;
vector< pair<int,int> >::iterator it;
bool vis1[1002],vis2[1002];
int N;
int over()
{
	for(int i=0;i<N;++i)
		if(!vis2[i])return 0;
	return 1;
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int time,cnt,stars;
	bool flag;
	cin>>time;
	for(int k=1;k<=time;++k)
	{
		cin>>N;
		cnt=0;
		stars=0;
		flag=false;
		rat.clear();
		for(int i=0,a,b;i<N;++i)
		{
			cin>>a>>b;
			rat.push_back(pair<int,int>(b,a));
		}
		sort(rat.begin(),rat.end());
	//	for(it=rat.begin();it!=rat.end();++it)
	//		printf("%d\t%d\n",(*it).first,(*it).second);
		memset(vis1,false,sizeof(vis1));
		memset(vis2,false,sizeof(vis2));
		do
		{
			for(int i=0;i<N;++i)
			{
				if(stars>=rat[i].first&&!vis2[i])
				{
					vis2[i]=true;stars+=2;++cnt;break;
				}
				if(i==N-1)
				{
					for(int j=0;j<N;++j)
					{
						if(stars>=rat[j].second&&!vis1[j])
						{
							vis1[j]=true;stars++;++cnt;break;
						}
						if(j==N-1)
						{
							printf("Case #%d: Too Bad\n",k);
							flag=true;
							goto ret;
						}
					}
				}
			}
		}while(!over());
		if(!flag)printf("Case #%d: %d\n",k,cnt);
ret:	continue;
	}
	return 0;
}
