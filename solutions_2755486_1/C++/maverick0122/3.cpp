#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1


const int M = 1000100;
const int N= 10001000<<1;
const int add= N>>1;
const int maxn = N;

/*
typedef struct 
{
	int d, n, w, e, s, delta_d, delta_p, delta_s;
}tribe;*/

typedef struct
{
	int d,st,en,h;
}attack;

//tribe tb[20];
int w[maxn<<2],col[maxn<<2],rec[M][3];
attack att[M];
int n;

int cmp(const void *a, const void *b)
{
	return ((attack*)a)->d - ((attack*)b)->d;
}

int query(int L,int R,int l,int r,int rt) {	//区间最值
	if (L <= l && r <= R) {
		return w[rt];
	}
	int m = (l + r) >> 1;
	int ret = 0;
	if (L <= m) ret = min(ret , query(L , R , lson));
	if (R > m) ret = min(ret , query(L , R , rson));
	return ret;
}

void PushDown(int rt,int m) {		//把当前结点的信息更新给儿子结点
	if (col[rt]) {
		w[rt<<1] = w[rt];
		w[rt<<1|1] = w[rt];
		col[rt] = 0;
	}
}

void PushUp(int rt) {		//是把当前结点的信息更新到父结点 
	w[rt] = min(w[rt<<1],w[rt<<1|1]);
}

void update(int L,int R,int c,int l,int r,int rt) {		//成段替换
	if (L <= l && r <= R) {
		w[rt] = c;
		return ;
	}
	PushDown(rt , r - l + 1);
	int m = (l + r) >> 1;
	if (L <= m) update(L , R , c , lson);
	if (R > m) update(L , R , c , rson);
	PushUp(rt);
}


int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	for(int cnt=1;cnt<=t;cnt++)
	{
		scanf("%d",&n);
		int i,j,ai=0;
		for(i=0;i<n;i++)
		{
			int di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
			//scanf("%d%d%d%d%d%d%d%d",&tb[i].d,&tb[i].n,&tb[i].w,&tb[i],e,&tb[i].s,&tb[i].delta_d,&tb[i].delta_p,&tb[i].delta_s);
			scanf("%d%d%d%d%d%d%d%d",&di,&ni,&wi,&ei,&si,&delta_di,&delta_pi,&delta_si);
			for(j=0;j<ni;j++)
			{
				att[ai].d = di + j*delta_di;
				att[ai].st = wi + j*delta_pi;
				att[ai].en = ei + j*delta_pi;
				att[ai].h = si + j*delta_si;
				ai++;
			}
		}
		qsort(att,ai,sizeof(attack),cmp);
		memset(w,0,sizeof(w));
		memset(col,0,sizeof(col));
		int ans=0;
		int pred=att[0].d;
		int reccnt = 0;
		for(i=0;i<ai;)
		{
			if(att[i].d==pred)
			{
				int tmp = query(att[i].st+add,att[i].en-1+add,1,maxn,1);
					if(tmp<att[i].h)
					{
						ans++;
						rec[reccnt][0]=att[i].st;
						rec[reccnt][1]=att[i].en;
						rec[reccnt][2]=att[i].h;
						reccnt++;
						break;
					}
				i++;
			}
			else
			{
				
				for(j=0;j<reccnt;j++)
				{
					update(rec[j][0]+add,rec[j][1]-1+add,rec[j][2],1,maxn,1);
				}
				pred = att[i].d;
				reccnt = 0;
			}
		}
		
		printf("Case #%d: %d\n",cnt,ans);
	} 
} 
