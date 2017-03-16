#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
#define MAXN 11000

int T;
long long E,R,N;
struct node
{
	int pos,v;
	bool operator < (const node &a) const
	{
		return v > a.v;
	}
}A[MAXN];
long long Ans;

struct Tnode
{
	long long left;
	int need,pos;
	Tnode(long long __left=0,int __need=0,int __pos=0)
	{
		left = __left;
		need = __need;
		pos = __pos;
	}
	bool operator < (const Tnode &a) const
	{
		return pos < a.pos;
	}
};

set<Tnode> S;

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int i,k;
	scanf("%d",&T);
	for (int cases=1;cases<=T;cases++)
	{
		scanf("%I64d%I64d%I64d",&E,&R,&N);
		for (i=0;i<N;i++)
		{
			scanf("%d",&A[i].v);
			A[i].pos = i+1;
		}
		sort(A,A+N);
		S.clear();
		S.insert(Tnode(E-R,0,0));
		S.insert(Tnode(0,0,N+1));
		Ans = 0LL;
		for (k=0;k<N;k++)
		{
			i = A[k].pos;
			set<Tnode>::iterator 
			pk = S.upper_bound(Tnode(0,0,i)),
			pj = pk;
			--pj;
			Tnode pi;
			pi.left = max(0LL,pk->need - R*(pk->pos-i));
			pi.need = min(E - pi.left,pj->left+R*(i-pj->pos) - pi.left);
			Ans += (long long)A[k].v * pi.need;
			pi.need += pi.left;
			pi.pos = i;
			S.insert(pi);
		}
		printf("Case #%d: %I64d\n",cases,Ans);
	}
	return 0;
}
