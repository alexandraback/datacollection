#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXHN  = 100000;
const int MAXN = 110;

struct node
{
	int x,y,t;
	node(int __x=0,int __y=0,int __t=0):x(__x),y(__y),t(__t){}
	bool operator < (const node &a) const
	{
		return t < a.t;
	}
}H[MAXHN];
int Hn;

void cccc(int i)
{
	int j ;
	while (i > 1 && H[i] < H[i >> 1])
	{
		swap(H[i],H[i>>1]);
		i >>= 1;
	}
	while (i*2 <= Hn)
	{
		if (i*2 == Hn || H[i*2] < H[i*2+1])
			j = i*2;
		else
			j = i*2 +1 ;
		if (H[j] < H[i])
		{
			swap(H[i],H[j]);
			i = j;
		}
		else
			break;
	}
}

node getp()
{
	node ret = H[1];
	swap(H[1],H[Hn--]);
	cccc(1);
	return ret;
}

void push(const node &a)
{
	H[++Hn] = a;
	cccc(Hn);
}

int T,Hei,N,M;
int C[MAXN][MAXN],F[MAXN][MAXN];
bool Vis[MAXN][MAXN];

inline bool inside(int x,int y)
{
	return x>=0 &&  x<N && y>=0 && y<M;
}

const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int Ans[MAXN][MAXN];

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.out","w",stdout);
	
	int i,j,k,u,v;
	int t0;
	node p;
	cin >> T;
	for (int t=1;t<=T;t++)
	{
		cin >> Hei >> N >> M;
		for (i=0;i<N;i++)	
			for (j=0;j<M;j++)
				cin >> C[i][j];
		for (i=0;i<N;i++)	
			for (j=0;j<M;j++)
				cin >> F[i][j];
		Hn = 0;
		memset(Vis,0,sizeof Vis);
		memset(Ans,255,sizeof Ans);
		if (C[0][0] - Hei >= 50)
			push(node(0,0,0));
		else
			push(node(0,0,Hei - (C[0][0]-50)));
		while (1)
		{
			p = getp();
			i = p.x;
			j = p.y;
			if (Vis[i][j])
				continue;
			Vis[i][j] = 1;
			Ans[i][j] = p.t;
			if (i == N-1 && j== M-1)
				break;
			t0 = p.t;
			for (k=0;k<4;k++)
			{
				u = i+step[k][0];
				v = j+step[k][1];
				if (!inside(u,v))
					continue;
				if (C[i][j] - F[u][v] < 50 || C[u][v] - F[i][j] < 50
					|| C[u][v] - F[u][v] < 50)
					continue;
				int t;
				t = max(Hei - ( min(C[i][j],C[u][v]) - 50),t0 );
				if (t0 == 0 && C[u][v] - Hei >= 50)
					push(node(u,v,0));
				else if (Hei - t >= F[i][j] + 20)
					push(node(u,v,t+10));
				else
					push(node(u,v,t+100));
				
			}
		}
		printf("Case #%d: %.1f\n",t,p.t/10.);
	}
	return 0;
}
