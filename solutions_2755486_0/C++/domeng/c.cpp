#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>
#define debug(x) 
using namespace std;
struct _node
{
	long long attack;
	long long lowest;
} Node[1<<22];
const int kBase = 1<<21;

void update(long long& a, long long b)
{
	if (a<0 || b<a) a=b;
}

long long getLowest(int n)
{
	long long ret = Node[n].lowest;
	for (;n;n>>=1) ret = max( Node[n].attack, ret );
	return ret;
}

long long getLowestInterval(int a,int b)
{
	long long ret = -1; //10**6 + 10**5 * 1000
	a+=kBase, b+=kBase;
	while (a<b)
	{
		if (a&1) update(ret, getLowest(a++));
		if (~b&1) update(ret, getLowest(b--));
		if (a>=b) break;
		a>>=1;
		b>>=1;
	}
	if (a==b) update(ret, getLowest(a));
	return ret;
}

void setAttack(int n,long long s)
{
	Node[n].attack = max(Node[n].attack,s);
	for (;n;n>>=1)
		Node[n].lowest = max(Node[n].attack, min(Node[n*2].lowest, Node[n*2+1].lowest));
}

void setAttackInterval(int a,int b,long long s)
{
	a+=kBase, b+=kBase;
	while (a<b)
	{
		if (a&1) setAttack(a++,s);
		if (~b&1) setAttack(b--,s);
		if (a>=b) break;
		a>>=1;
		b>>=1;
	}
	if (a==b) setAttack(a,s);
}

struct _info
{
	int time;
    long long west;
	long long east;
	long long power;
	bool operator<(const _info& obj) const
	{
		return time<obj.time;
	}
};


int main()
{
	//freopen("C:\\ps\\gcj\\2013\\2013-05-12\\c.in","r",stdin);
	int T;scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		memset(Node,0,sizeof(Node));
		int N;
		scanf("%d",&N);
		vector<_info> attacks;
		vector<long long> points;
		for (int i=0;i<N;++i)
		{
			int t0,n,w0,e0,s0,dt,dx,ds;
			scanf("%d %d %d %d %d %d %d %d",
					&t0,
					&n,
					&w0,
					&e0,
					&s0,
					&dt,
					&dx,
					&ds);
			for (long long j=0;j<n;++j)
			{
				_info tmp;
				tmp.time = t0 + j * dt;
				tmp.west = w0 + j * dx;
				tmp.east = e0 + j * dx;
				tmp.power = s0 + j * ds;
				//tmp.east --;
				points.push_back(tmp.east);
				points.push_back(tmp.west);
				attacks.push_back(tmp);
			}
		}
		sort(attacks.begin(),attacks.end());
		sort(points.begin(),points.end());
		points.erase(unique(points.begin(),points.end()),points.end());
		for (int i=0;i<attacks.size();++i)
		{
			attacks[i].west = lower_bound(points.begin(),points.end(),attacks[i].west)-points.begin();
			attacks[i].east = lower_bound(points.begin(),points.end(),attacks[i].east)-points.begin();
			attacks[i].west *= 2;
			attacks[i].east *= 2;
		}
		int ret = 0;
		for (int i=0;i<attacks.size();)
		{
			int j = i;
			debug(printf("@ day %d\n",attacks[i].time));
			if (attacks[i].time==4)
			{
				debug(printf("rr %lld\n",getLowest(11+kBase)));
				debug(printf("rr %lld\n",getLowestInterval(8,11)));

			}
			while (j < attacks.size() && attacks[j].time == attacks[i].time) j++;
			for (int k = i; k < j; ++k) 
			{
				const _info& obj = attacks[k];
				long long resist = getLowestInterval(obj.west,obj.east);
				if (resist < obj.power) ret++;
				debug(printf("attack [%lld,%lld][%lld,%lld] with power %lld ",obj.west,obj.east,points[obj.west/2],points[obj.east/2],obj.power));
				debug(printf("is %s (cuz resist was %lld)\n", (resist<obj.power)?"success":"fail",resist));
			}
			for (int k = i; k < j; ++k) 
			{
				const _info& obj = attacks[k];
				setAttackInterval(obj.west,obj.east,obj.power);
			}
			i = j;
		}
		printf("Case #%d: %d\n",kase,ret);
				
	}
	return 0;
}
