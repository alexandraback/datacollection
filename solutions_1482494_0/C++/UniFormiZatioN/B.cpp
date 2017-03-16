#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> Pair;
priority_queue<Pair,vector<Pair>,greater<Pair> > a,b;
bool used[1000];
int bstar[1000],v[1000],s;
main()
{
//	freopen("B.in","r",stdin);
//	freopen("B.txt","w",stdout);
	int T,t,n,i,j,k,star,count;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		while(a.size()) a.pop();
		while(b.size()) b.pop();
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&j,&k);
			used[i]=0;
			bstar[i]=k;
			a.push(Pair(j,i));
			b.push(Pair(k,i));
		}
		star=count=0;
		while(b.size()) 
		{
			if(b.top().first <=star)
			{
				star+=2;
				count++;
				used[b.top().second]=1;
				b.pop();
				continue;
			}
			while(a.size() && used[a.top().second]) a.pop();
			if(a.empty() || a.top().first>star)
			{
				count=-1;
				break;
			}
			for(s=0,k=a.top().first ; a.size() && a.top().first==k ; a.pop())
					v[s++]=a.top().second;
			for(j=0,i=1;i<s;i++) if(bstar[v[i]]>bstar[v[j]]) j=i;
			for(i=0;i<s;i++) if(i!=j) a.push(Pair(k,v[i]));
			used[v[j]]=1;
			star++;
			count++;
		}
		if(count<0) printf("Case #%d: Too Bad\n",t);
		else printf("Case #%d: %d\n",t,count);
	}
}
