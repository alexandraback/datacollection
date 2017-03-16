#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,m;
double a[1005];
double b[1005];
int mark[1005];
#define INF 1000000000
int path[2005];
int c[2005][2005], f[2005][2005];
int networkflow(int start,int end){
	int i,ret=0,flow; 
	for(i=0;i<m;i++)
		for(int j=0;j<m;j++)
			f[i][j]=0;
while(1){
		for(i=0;i<m;i++)
			path[i]=-1;
		path[start]=start;
		queue<int> q;
		q.push(start);
		while(!q.empty()){
			int qt=q.front();
			q.pop();
			for(i=0;i<m;i++)
				if(path[i]==-1 && c[qt][i]>f[qt][i])
					q.push(i),path[i]=qt;
		}
		if(path[end]==-1)
			break;
		flow=INF;
		int point=end;
		while(point!=start){
			if(flow>c[path[point]][point]-f[path[point]][point])
				flow=c[path[point]][point]-f[path[point]][point];
			point=path[point];
		}
		point=end;
		while(point!=start){
			f[path[point]][point]+=flow;
			f[point][path[point]]-=flow;
			point=path[point];
		}
		ret+=flow;
	}
	return ret;
}

int main()
{
	freopen("D-small-attempt1.in","rt",stdin);
	freopen("D-small-attempt1.out","wt",stdout);
	int t;
	scanf("%d",&t);
	int i, j, k;
	int tt=0;
	while(t--)
	{
		tt++;
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf",&a[i]);
		for(i=0;i<n;i++)
			scanf("%lf",&b[i]);
		for(i=0;i<n;i++)
			mark[i] = 0;
		sort(a,a+n);
		sort(b,b+n);
		if(b[n-1] > 0.999999999)
		{
			a[0] = 2;
			b[n-1] = 2;
			sort(a,a+n);
			sort(b,b+n);
			n--;
		}
		int p,q;
		p=0;q=0;
		m = 2*n+2;
		for(i=0;i<m;i++)
			for(j=0;j<m;j++)
				c[i][j] = 0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i]>b[j])
					c[i][n+j] = 1;
				else
					c[i][n+j] = 0;
			}
		}
		for(i=0;i<n;i++)
		{
			c[m-2][i] = 1;
			c[n+i][m-1] = 1;
		}

		p = networkflow(m-2,m-1);
		k=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				if(mark[j]==0)
					if(b[j] > a[i])
						break;
			if(j==n)
			{
				q++;
				mark[k++]=1;
			}
			mark[j] = 1;
		}
		printf("%d %d\n",p,q);
	}
}