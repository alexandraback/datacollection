#define DEBUG 1

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=n-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x<0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }
string plural(string s) { return(Sz(s) && s[Sz(s)-1]=='x' ? s+"en" : s+"s"); }

const int INF = (int)1e9;
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

#if DEBUG
#define GETCHAR getchar
#else
#define GETCHAR getchar_unlocked
#endif

void Read(int &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=GETCHAR();
				if (c=='-')
					n=1;
				else
				if ((c>='0') && (c<='9'))
					x=x*10+c-'0',r=1;
				else
				if (r)
					break;
		}
		if (n)
			x=-x;
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,t;
	int N,K;
	int i,j,b;
	int cnt[201];
	int op[20],nk[20],key[20][40];
	static bool dyn[1<<20],good[1<<20];
	static vector <int> prv[1<<20];
	static vector <PR> nxt[1<<20];
	queue <int> Q;
	Read(T);
		Fox1(t,T)
		{
			printf("Case #%d:",t);
			Fill(cnt,0);
			//input
			Read(K),Read(N);
				Fox(i,K)
				{
					Read(j);
					cnt[j]++;
				}
				Fox(i,N)
				{
					Read(op[i]),Read(nk[i]);
						if (nk[i]>40)
						{
							printf("BAD\n");
							return(0);
						}
						Fox(j,nk[i])
							Read(key[i][j]);
				}
			//bitmask DP
				Fox(i,(1<<N))
				{
					prv[i].clear();
					nxt[i].clear();
				}
			Fill(dyn,0);
			dyn[0]=1;
				Fox(b,(1<<N))
					if (dyn[b])
					{
						//get keys
						Fox(i,N)
							if (b&(1<<i))
							{
								cnt[op[i]]--;
									Fox(j,nk[i])
										cnt[key[i][j]]++;
							}
						Fox(i,N)
							if (cnt[op[i]]<0)
							{
								printf("BAD\n");
								return(0);
							}
						//open a new chest
						Fox(i,N)
							if (!(b&(1<<i)))
								if (cnt[op[i]])
								{
									dyn[b|(1<<i)]=1;
									prv[b|(1<<i)].pb(b);
									nxt[b].pb(mp(b|(1<<i),i));
								}
						//undo keys
						Fox(i,N)
							if (b&(1<<i))
							{
								cnt[op[i]]++;
									Fox(j,nk[i])
										cnt[key[i][j]]--;
							}
					}
			//output
				if (!dyn[(1<<N)-1])
					printf(" IMPOSSIBLE\n");
				else
				{
					//trace backwards
					Fill(good,0);
					Q.push((1<<N)-1),good[(1<<N)-1]=1;
						while (!Q.empty())
						{
							b=Q.front(),Q.pop();
								Fox(i,Sz(prv[b]))
								{
									j=prv[b][i];
										if (!good[j])
											Q.push(j),good[j]=1;
								}
						}
					//reconstruct best solution
					b=0;
						if (!good[0])
						{
							printf("BAD\n");
							return(0);
						}
						while (b<(1<<N)-1)
							Fox(i,Sz(nxt[b]))
							{
								j=nxt[b][i].x;
									if (good[j])
									{
										printf(" %d",nxt[b][i].y+1);
										b=j;
										break;
									}
							}
					printf("\n");
				}
		}
	return(0);
}