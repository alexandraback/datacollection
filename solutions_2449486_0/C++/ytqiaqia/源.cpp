#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <ctime>
#include <set>
#include <queue>

using namespace std;
const int MAXN = 1e5+10;
int N,M;
int num[101][101];
bool jd2(int k, int a[],int n)
{
	for(int i=0;i < n; ++i)
		if(a[i]>k)return false;
	return true;
}
bool judge()
{
	for(int i = 0; i < N; ++i)
	{
		int tmp[101];
		for(int j = 0; j < M; ++j)
		{
			if(!jd2(num[i][j], num[i], M))
			{
				for(int k = 0; k < N; ++k)
					tmp[k] = num[k][j];
				if(!jd2(num[i][j],tmp,N))
				{
					//cout<<"test: "<<num[i][j]<<" "<<i<<" "<<j<<endl;
					return false;
				}
			}
		}
	}
	return true;
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.out","w",stdout);
	int T;
	string str;
	scanf("%d",&T);
	for(int i = 1; i <= T; ++i)
	{
		scanf("%d%d",&N,&M);
		for(int k=0; k<N;++k)
			for(int j =0; j<M;++j)
				scanf("%d",&num[k][j]);
		if(judge())cout<<"Case #"<<i<<": YES"<<endl;
		else cout<<"Case #"<<i<<": NO"<<endl;
	}
	return 0;
}
