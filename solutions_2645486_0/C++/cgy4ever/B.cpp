#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>
using namespace std;

int n;
long long R, E;
long long x[10001];
long long firstDayLimit[10001];
long long lastDayLimit[10001];

struct activ
{
	long long v;
	long long day;
	bool operator <(activ u) const
	{
		return v > u.v;
	}
}A[10001];



#define MAXN 200001

long long maxint= 1000000000000000000LL;
long long flow , cost;
long long pi[MAXN+1],v[MAXN+1];
int S , T;

struct etype
{
 int t;
 long long c,u;
 etype* next;
 etype* pair;
 etype(){next=0;}
 etype(int _t,long long _c,long long _u,etype* _n){t=_t,c=_c,u=_u,next=_n;}
}*e[MAXN+1],*eb[MAXN+1],*Pe, *Pool;

long long aug(int w,long long lim)
{
 long long t;
 v[w]=1;
 if(w==T)
 {
     flow += lim;
     cost += (long long)pi[1] * lim;
     return lim;
 }
 for(etype *& i=e[w];i;i=i->next)
   if(i->c && !v[i->t] && pi[w]==pi[i->t]+i->u)
     if(t=aug(i->t,min(lim,i->c)))
       return i->c-=t,i->pair->c+=t,t;
 return 0;
}

bool fix()
{
 long long t=maxint;
 for(int i=S;i<=T;i++)
   if(v[i])
   {
     for(etype *j=eb[i];j;j=j->next)
       if(j->c && !v[j->t])
         t=min(t,pi[j->t]+j->u-pi[i]);
   }
 if(t==maxint)
   return 0;

 for(int i=S;i<=T;i++)
   if(v[i])
     e[i]=eb[i],pi[i]+=t;
 return 1;
}

void addedge(int s,int t,long long c,long long u)
{
   //cout << s << " " << t << " " << c << endl;
   ++Pe;
   Pe = new etype(t,c,u,e[s]);
   e[s] = Pe;
   ++Pe;
   Pe = new etype(s,0,-u,e[t]);
   e[t] = Pe;
 e[s]->pair=e[t];
 e[t]->pair=e[s];
}

void prepare()
{
 if(Pool == NULL)
     Pool = new etype[1000001];
   Pe = Pool;
   memset(e , 0 , sizeof(e));
}


int MinCostMaxFlow()
{
   flow = 0, cost = 0;
   memcpy(eb,e,sizeof(e));
   memset(pi,0,sizeof(pi));
   do
   {
     do
     memset(v,0,sizeof(v));
     while(aug(S,maxint));
   }
   while(fix());
   return cost;
}

void solve()
{
	memset(x, 0, sizeof(x));
	cin >> E >> R >> n;
	R = min(R, E);
	for(int i = 1; i <= n; i++)
	{
		A[i].day = i;
		cin >> A[i].v;
		A[i].v = 10000000 - A[i].v;
	}
	//sort(A + 1, A + 1 + n);
	//memset(already, 0, sizeof(already));
	for(int i = 1; i <= n; i++)
	{
		firstDayLimit[i] = n*R + (E-R) - R * (n - i);
		lastDayLimit[i] = n*R + (E-R) - R * (i-1);
	}
	prepare();
	S = 1;
	int leftNode[10001], rightNode[10001];
	int u = 1;
	for(int i = 1; i <= n; i++)
	{
		leftNode[i] = u + 1;
		rightNode[i] = u + 2;
		u += 2;
		if(i == 1 || i == n)
			addedge(leftNode[i], rightNode[i], firstDayLimit[1], A[i].v);
		else
			addedge(leftNode[i], rightNode[i], E, A[i].v);
	}
	for(int i = 2; i <= n; i++)
	{
		addedge(u+1, leftNode[i-1], lastDayLimit[1], 0);
		addedge(u+1, leftNode[i], lastDayLimit[1], 0);
		addedge(u+2, u+1, firstDayLimit[i], 0);
		u += 2;
		leftNode[i] = u;
	}
	addedge(S, leftNode[n], lastDayLimit[1], 0);
	for(int i = n-1; i >= 1; i--)
	{
		addedge(rightNode[i+1], u+1, lastDayLimit[1], 0);
		addedge(rightNode[i], u+1, lastDayLimit[1], 0);
		addedge(u+1, u+2, lastDayLimit[i], 0);
		u += 2;
		rightNode[i] = u;
	}
	T = rightNode[1];
	//cout << S << " " << T << endl;
	cout << 10000000LL * lastDayLimit[1] - MinCostMaxFlow() << endl;
	


}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int CaseID = 1; CaseID <= TestCase; CaseID ++)
	{
		cout << "Case #" << CaseID << ": ";
		solve();
	}
	return 0;
}

int main()
{
	//srand((unsigned)time(NULL));
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}

