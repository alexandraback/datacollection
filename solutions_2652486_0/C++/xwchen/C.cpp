#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define X first
#define Y second
#define sqr(x) ((x)*(x))
using namespace std;
const double eps = 1e-8 ;


typedef long long LL ;
set<int> myset;
int R,N,M,K;
void gao(int cur,int n,int pro,vector<int> a)
{
	if(cur==n)
	{
		myset.insert(pro);
		return ;
	}
	gao(cur+1,n,pro*a[cur],a);
	gao(cur+1,n,pro,a);
}
vector<int> subset(vector<int> a)
{
	int n = a.size();
	vector<int> ret;
	myset.clear();
	gao(0,n,1,a);
	while(!myset.empty())
	{
	    //printf("%d\n",*(myset.begin()));
		ret.push_back(*(myset.begin()));
		myset.erase(myset.begin());
	}
	//printf("ok2\n");
	return ret;
}

bool isallinsubset(vector<int> A,vector<int> B)
{
	int i=0,j=0,n1=A.size(),n2=B.size();
	bool have[78126]={0};
	for(int i=0;i<n2;++i)
	{
		//printf("B = %d\t",B[i]);
		have[ B[i] ]=true;
	}
	//puts("");
	for(int i=0;i<n1;++i)
	{
		if(!have[ A[i] ])
		{
			return false;
		}
	}
	return true;
}
bool OK=false;
int A[8];
vector<int> res[78126];
vector<int> ret[78126];
int len;
void gao(int cur)
{
	if(cur==K)
	{
		ret[len].clear();
		for(int i=0;i<N;++i)
		{
			ret[len].push_back(A[i]);
		}
		//printf("ok1\n");
		res[len] = subset(ret[len]);
		++len;
		return ;
	}
	for(int i=2;i<=M;++i)
	{
		A[cur]=i;
		gao(cur+1);
	}
}
int main(int argc, char const *argv[])
{
	freopen("C-small-1-attempt1.in","r",stdin);
	freopen("C-small-1-attempt1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		scanf("%d%d%d%d",&R,&N,&M,&K);
		len=0;
		for(int i=0;i<78126;++i)res[i].clear();
        gao(0);
		printf("Case #%d:\n",t);
		vector<int> tmp;
		for(int i=0;i<R;++i)
		{
			int val;
			tmp.clear();
			for(int q=0;q<K;++q)
			{
				scanf("%d",&val);
				tmp.push_back(val);
			}
			
			bool found=false;
			for(int j=0;j<78126;++j)
			{
				if(isallinsubset(tmp,res[j]))
				{
					for(int k=0;k<ret[j].size();++k)
					{
						printf("%d",ret[j][k]);
					}
					puts("");
					found=true;
					break;
				}
			}
			if(!found)
			{
			    for(int k=0;k<ret[0].size();++k)
                {
                    printf("%d",ret[0][k]);
                }
                puts("");
			}
		}

	}
	return 0;
}
