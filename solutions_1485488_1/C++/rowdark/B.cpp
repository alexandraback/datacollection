/*
ID: rowdark1
LANG: C++
PROG:
*/

#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<bitset>
#include<iomanip>
#include<complex>

#define X first
#define Y second
#define REP_0(i,n)for(int i=0;i<(n);++i)
#define REP_1(i,n)for(int i=1;i<=(n);++i)
#define REP_2(i,a,b)for(int i=(a);i<(b);++i)
#define REP_3(i,a,b)for(int i=(a);i<=(b);++i)
#define REP_4(i,a,b,c)for(int i=(a);i<(b);i+=(c))
#define DOW_0(i,n)for(int i=(n)-1;-1<i;--i)
#define DOW_1(i,n)for(int i=(n);0<i;--i)
#define DOW_2(i,a,b)for(int i=(b);(a)<i;--i)
#define DOW_3(i,a,b)for(int i=(b);(a)<=i;--i)
#define FOREACH(a,b)for(a=(b).begin();a!=(b).end();++a)
#define RFOREACH(a,b)for(a=(b).rbegin();a!=b.rend();++a)
#define PB push_back
#define PF push_front
#define MP make_pair
#define IS insert
#define ES erase
#define IT iterator
#define RI reserve_iterator
#define PQ priority_queue
#define LB lower_bound
#define UB upper_bound

#define PI 3.1415926535897932384626433832795
#define EXP 2.7182818284590452353602874713527

using namespace std;

typedef long long LL;
typedef long double LD;
typedef double DB;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef pair<int,PII> PIII;
typedef pair<LD,int> PLDI;
typedef vector<PII> VII;

template<class T>
T By(T x,T y,T P){
	T F1=0;
	while(y)
	{
		if(y&1)
		{
			F1+=x;
			if(F1<0||F1>=P)F1-=P;
		}
		x<<=1;
		if(x<0||x>=P)x-=P;
		y>>=1;
	}
	return F1;
}

template<class T>
T Mul(T x,T y,T P){
	T F1=1;x%=P;
	while(y)
	{
		if(y&1)
		{
			F1=By(F1,x,P);
		}
		x=By(x,x,P);
		y>>=1;
	}
	return F1;
}

template<class T>
T Gcd(T x,T y){
	if(y==0)return x;
	T z;
	while(z=x%y){
		x=y,y=z;
	}
	return y;
}

struct EDGE{
	int T;EDGE *Nxt;
};

template<class T>
void UpdataMin(T &x,T y){
	if(y<x)
	{
		x=y;
	}
}

template<class T>
void UpdataMax(T &x,T y){
	if(x<y)
	{
		x=y;
	}
}

int Time[101][101];

bool In[101][101];

int F[101][101];

int C[101][101];

int N,M,H,T,FT;

int Fx,Fy,Gx,Gy,Lx,Ly,FH,GT;

const int Dx[]={0,1,0,-1};

const int Dy[]={1,0,-1,0};

deque<pair<int,int> > Q1,Q2;

int main(){
	freopen("B-large.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>T;
	REP_1(TT,T)
	{
		cin>>H>>N>>M;
		REP_1(i,N)
		{
			REP_1(j,M)
			{
				cin>>C[i][j];
			}
		}
		REP_1(i,N)
		{
			REP_1(j,M)
			{
				cin>>F[i][j];
			}
		}
		memset(Time,127,sizeof(Time));
		memset(In,0,sizeof(In));
		Q2.PB(MP(1,1)),Q1.PB(MP(1,1));
		Time[1][1]=0;
		In[1][1]=1;
		while(!Q2.empty())
		{
			Fx=Q2.front().X;
			Fy=Q2.front().Y;
			Q2.pop_front();
			REP_0(i,4)
			{
				Gx=Fx+Dx[i],Gy=Fy+Dy[i];
				if(Gx>0&&Gx<=N&&Gy>0&&Gy<=M&&!In[Gx][Gy])
				{
					if(C[Gx][Gy]-F[Gx][Gy]>=50&&C[Gx][Gy]-F[Fx][Fy]>=50&&C[Gx][Gy]-H>=50&&C[Fx][Fy]-F[Gx][Gy]>=50)
					{
						In[Gx][Gy]=1;
						Time[Gx][Gy]=0;
						Q2.PB(MP(Gx,Gy));
						Q1.PB(MP(Gx,Gy));
					}
				}
			}
		}
		while(!Q1.empty())
		{
			Fx=Q1.front().X;
			Fy=Q1.front().Y;
			Q1.pop_front();
			int NH=H-Time[Fx][Fy];
			REP_0(i,4)
			{
				Gx=Fx+Dx[i],Gy=Fy+Dy[i];
				if(Gx>0&&Gx<=N&&Gy>0&&Gy<=M)
				{
					if(C[Gx][Gy]-F[Gx][Gy]<50||C[Gx][Gy]-F[Fx][Fy]<50||C[Fx][Fy]-F[Gx][Gy]<50)
					{
						continue;
					}
					if(C[Gx][Gy]-F[Gx][Gy]>=50&&C[Gx][Gy]-NH>=50&&C[Gx][Gy]-F[Fx][Fy]>=50&&C[Fx][Fy]-F[Gx][Gy]>=50)
					{
						if(NH-F[Fx][Fy]>=20)
						{
							FT=Time[Fx][Fy]+10;
							if(Time[Gx][Gy]>FT)
							{
								Time[Gx][Gy]=FT;
								if(!In[Gx][Gy])
								{
									In[Gx][Gy]=1;
									if(!Q1.empty()&&Time[Q1.front().X][Q1.front().Y]>=FT)
									{
										Q1.push_front(MP(Gx,Gy));
									}
									else
									{
										Q1.PB(MP(Gx,Gy));
									}
								}
							}
						}
						else
						{
							FT=Time[Fx][Fy]+100;
							if(Time[Gx][Gy]>FT)
							{
								Time[Gx][Gy]=FT;
								if(!In[Gx][Gy])
								{
									In[Gx][Gy]=1;
									if(!Q1.empty()&&Time[Q1.front().X][Q1.front().Y]>=FT)
									{
										Q1.push_front(MP(Gx,Gy));
									}
									else
									{
										Q1.PB(MP(Gx,Gy));
									}
								}
							}
						}
					}
					else
					{
						GT=Time[Fx][Fy]+NH-(C[Gx][Gy]-50);
						FH=H-GT;
						if(FH-F[Fx][Fy]>=20)
						{
							FT=GT+10;
							if(Time[Gx][Gy]>FT)
							{
								Time[Gx][Gy]=FT;
								if(!In[Gx][Gy])
								{
									In[Gx][Gy]=1;
									if(!Q1.empty()&&Time[Q1.front().X][Q1.front().Y]>=FT)
									{
										Q1.push_front(MP(Gx,Gy));
									}
									else
									{
										Q1.PB(MP(Gx,Gy));
									}
								}
							}
						}
						else
						{
							FT=GT+100;
							if(Time[Gx][Gy]>FT)
							{
								Time[Gx][Gy]=FT;
								if(!In[Gx][Gy])
								{
									In[Gx][Gy]=1;
									if(!Q1.empty()&&Time[Q1.front().X][Q1.front().Y]>=FT)
									{
										Q1.push_front(MP(Gx,Gy));
									}
									else
									{
										Q1.PB(MP(Gx,Gy));
									}
								}
							}
						}
					}
				}
			}
			In[Fx][Fy]=0;
		}
		cout<<"Case #"<<TT<<": "<<Time[N][M]/10<<'.'<<Time[N][M]%10<<endl;
	}
	cin>>N;
	return 0;
}
