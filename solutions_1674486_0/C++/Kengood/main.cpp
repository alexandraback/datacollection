//compiled in vc
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
// C++
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>
using namespace std;

#define IN_THE_SET(_set,_val) (_set.find(_val) != _set.end())

int cases , Case = 1;
////////////

//copy somewhere in internet...
const long maxn=1024*2 +10; //n node
const long maxm=maxn*4 +4; //n edge
const long inf=0x7fffffff;
struct node
{
	long v,next;
	long val;
}s[maxm*2];
long level[maxn],p[maxn],que[maxn],out[maxn],ind;
void init()
{
	ind=0;
	memset(p,-1,sizeof(p));
}
inline void insert(long x,long y,long z) {
	s[ind].v=y;
	s[ind].val=z;
	s[ind].next=p[x];
	p[x]=ind++;
	s[ind].v=x;
	s[ind].val=0;
	s[ind].next=p[y];
	p[y]=ind++;
}

long max_flow(long n,long source,long sink) {
	long ret=0;
	long h=0,r=0;
	while(1)
	{
		long i;
		for(i=0;i<n;++i)
			level[i]=0;
		h=0,r=0;
		level[source]=1;
		que[0]=source;
		while(h<=r)
		{
			long t=que[h++];
			for(i=p[t];i!=-1;i=s[i].next)
			{
				if(s[i].val&&level[s[i].v]==0)
				{
					level[s[i].v]=level[t]+1;
					que[++r]=s[i].v;
				}
			}
		}
		if(level[sink]==0)break;
		for(i=0;i<n;++i)out[i]=p[i];
		long q=-1;
		while(1)
		{
			if(q<0)
			{
				long cur=out[source];
				for(;cur!=-1;cur=s[cur].next)
				{
					if(s[cur].val&&out[s[cur].v]!=-1&&level[s[cur].v]==2)
					{
						break;
					}
				}
				if(cur>=0)
				{
					que[++q]=cur;
					out[source]=s[cur].next;
				}
				else
				{
					break;
				}
			}
			long u=s[que[q]].v;
			if(u==sink)
			{
				long dd=inf;
				long index=-1;
				for(i=0;i<=q;i++)
				{
					if(dd>s[que[i]].val)
					{
						dd=s[que[i]].val;
						index=i;
					}
				}
				ret+=dd;
				//cout<<ret<<endl;
				for(i=0;i<=q;i++)
				{
					s[que[i]].val-=dd;
					s[que[i]^1].val+=dd;   
				}
				for(i=0;i<=q;i++)
				{
					if(s[que[i]].val==0)
					{
						q=index-1;
						break;
					}
				}
			}
			else
			{
				long cur=out[u];
				for(;cur!=-1;cur=s[cur].next)
				{
					if(s[cur].val&&out[s[cur].v]!=-1&&level[u]+1==level[s[cur].v])
					{
						break;
					}
				}
				if(cur!=-1)
				{
					que[++q]=cur;
					out[u]=s[cur].next;
				}
				else
				{
					out[u]=-1;
					q--;
				}
			}
		}
	}
	return ret;
}


int graph[1024][1024];
int inD[1024];
int outD[1024];

void allG(int n )
{
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < outD[i];++j)
		{
			insert( i , graph[i][j] , 1);
		}
	}
}

int main()
{	
	scanf("%d" , &cases);

	
	while( cases-- )
	{
		printf("Case #%d: " , Case++);   

		int n;

		
		memset( graph , 0 , sizeof(graph));

		cin >> n;
		for(int i = 0; i < n; ++i)
		{
			int t;
			cin >> t;
			outD[i] = t;
			for(int j = 0; j < t;++j)
			{
				int ne;
				cin >> ne;
				ne--;

				inD[ne]++;
				graph[i][j] = ne;
			}
		}

		vector<int> ins;
		vector<int> outs;
		for(int i = 0 ; i < n; ++i)
		{
			if( inD[i] == 0 )
				ins.push_back(i);
			else if( outD[i] == 0 )
				outs.push_back(i);
		}

		/*if( ins.empty() || outs.empty() )
			puts("No");
		else*/
		{
			char ans = 0;
			//for(int i = 0 ; i < ins.size(); ++i)
			for(int i = 0 ; i < n; ++i)
			{
				//for(int j = 0 ; j < outs.size(); ++j)
				for(int j = 0 ; j < n; ++j)
				{
					if( i == j ) continue;

					init();
					allG(n);

					insert(n ,  i , 2);
					insert( j, n+1 , 2);
					
					if( max_flow( n+2 , n , n+1) == 2 )
					{
						ans = 1;
						goto next_case;
					}

				}
			}
next_case:;
				puts(ans?"Yes":"No");

		}
	}


	return 0;
}
