#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
using namespace std;

#define debug(x) cout << #x << "=" << x << endl
#define sqr(x) ((x)*(x))

typedef long long ll;

int tests,n;
ll e,r,ans;
map<int,int> mp;
ll sum[10010];
int lef[10010], rig[10010];

int find(int x)
{
	if (mp[x]==0) return x;
	return mp[x] = find(mp[x]);
}

struct node
{
	int v,id;
}a[10010];

int cmp(node a, node b)
{
	return a.v>b.v;
}

void merge(int i, int j)
{
	//printf("merge %d %d\n",i,j);
	if (i>j) swap(i,j);
	i = find(i);
	j = find(j);
	if (i==j) return;
	mp[j] = i;
	lef[i] = min(lef[i], lef[j]);
	rig[i] = max(rig[i], rig[j]);
	sum[i] += sum[j];
}

void writemap()
{
	printf("<<<<<<<<<<<<<<<<<<<<\n");
	for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++) if (abs(it->first)!=100000000)
		printf("%d %d  [%d, %d] %d\n",
		  it->first,find(it->first),lef[it->first],rig[it->first],sum[it->first]);
	printf(">>>>>>>>>>>>>>>>>>>>\n");
}

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	
	scanf("%d",&tests);
	for (int test=1;test<=tests;test++)
	{
		cin >> e >> r >> n;
		for (int i=1;i<=n;i++) scanf("%d",&a[i].v), a[i].id = i;
		sort(a+1,a+n+1,cmp);
		memset(sum,0,sizeof sum);
		mp.clear();
		mp[-100000000] = 0; mp[100000000] = 0;
		ans = 0;
		for (int i=1;i<=n;i++)
		{
			//printf("\n");
			//debug(i);
			//printf("id=%d v=%d\n",a[i].id , a[i].v);
			//writemap();
			//debug(ans);
			
			int k = a[i].id, fa;
			mp[k] = 0;
			sum[k] = 0;
			lef[k] = rig[k] = k;
			map<int,int>::iterator it = mp.find(k);
			it--;
			if ((k - it->first) * r <= e)
				merge(k, it->first);
			it++; it++;
			if ((it->first - k) * r <= e)
				merge(k, it->first);
			fa = find(k);
			//debug((e+(rig[fa]-lef[fa])*r - sum[fa]));
			ans += (e+(ll)(rig[fa]-lef[fa])*r - sum[fa]) * a[i].v;
			sum[fa] = e+(ll)(rig[fa]-lef[fa])*r;
			//debug(ans);
		}
		
		
		printf("Case #%d: ",test);
		cout << ans << endl;
	}
	
	return 0;
}
