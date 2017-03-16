#include <cstdio>
#include <algorithm>
#define int64 long long

using namespace std;

const int Maxn=10100;

int tree[Maxn*4];
int v[Maxn];
int E,R,N,Test;
int64 ans;

void Build(int j,int l,int r)
{
	if (l==r)
	{
		tree[j]=v[l];
		return;
	}
	Build(j*2,l,(l+r)/2);
	Build(j*2+1,(l+r)/2+1,r);
	tree[j]=max(tree[j*2],tree[j*2+1]);
}

int Get_Max(int j,int l,int r,int x,int y)
{
	if (l==r) return l;

	int mid=(l+r)/2;
	if (mid>=y) return Get_Max(j*2,l,mid,x,y);
	else if (mid<x) return Get_Max(j*2+1,mid+1,r,x,y);
	else
	{
		int L=Get_Max(j*2,l,mid,x,mid);
		int R=Get_Max(j*2+1,mid+1,r,mid+1,y);
		if (v[L]>=v[R]) return L;
		else return R;
	}
}

int64 Work(int l,int r,int64 init_E,int64 E_final)
{
	if (l>r) return 0;

	int mid=Get_Max(1,1,N,l,r);
	int64 E_mid=min((int64)E,init_E+(int64)R*(mid-l));
	int64 res=Work(l,mid-1,init_E,E_mid);

	int64 use;
	if ((int64)R*(r-mid+1)>=E_final) use=E_mid;
	else use=E_mid+(int64)R*(r-mid+1)-E_final;
	res+=use*v[mid];

	res+=Work(mid+1,r,E_mid-use+R,E_final);
	return res;
}

int main()
{
	freopen("B1.in","r",stdin);
	freopen("B.out","w",stdout);

	scanf("%d",&Test);
	for (int ii=0;ii<Test;++ii)
	{
		scanf("%d%d%d",&E,&R,&N);
		for (int i=1;i<=N;++i)
			scanf("%d",&v[i]);

		Build(1,1,N);

		printf("Case #%d: %I64d\n",ii+1,Work(1,N,E,0));
	}

	return 0;
}
			
