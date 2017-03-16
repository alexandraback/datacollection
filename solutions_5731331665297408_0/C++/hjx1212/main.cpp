#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;

struct node{
	int z,n;
	node(int z=0,int n=0):z(z),n(n){}
	bool operator<(const node& a)const
	{
		return z<a.z;
	}
}a[55];
int n;
bool v[55][55];
stack<int> s;

bool judge()
{
	int i;
	s.push(a[0].n);
	for(i=1;i<n;i++)
	{
		while(!s.empty()&&!v[s.top()][a[i].n])
			s.pop();
		if(s.empty())
			return 0;
		s.push(a[i].n);
	}
	while(!s.empty())
		s.pop();
	return 1;
}

int main()
{
	freopen("E:/in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,t,m,i,j,x,y;
	for(scanf("%d",&T),t=1;t<=T;t++)
	{
		memset(v,0,sizeof(v));
		printf("Case #%d: ",t);
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			a[i-1]=node(x,i);
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			v[x][y]=v[y][x]=1;
		}
		sort(a,a+n);
		do
		{
			if(judge())
				break;
		}while(next_permutation(a,a+n));
		for(i=0;i<n;i++)
			printf("%d",a[i].z);
		puts("");
	}
	return 0;
}
