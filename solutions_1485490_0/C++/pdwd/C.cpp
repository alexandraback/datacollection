#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>		//UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>		//do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

#define MR 110

pair < LL, int > box[MR], toy[MR], box1[MR], toy1[MR];

int ile(int x)
{
	int res = 0;
	while(x)
	{
		res += x&1;
		x >>= 1;
	}
	return res;
}

int main()
{
	int T;
	scanf("%d", &T);
	REP(c,T)
	{
		int N, M;
		scanf("%d%d", &N, &M);
		REP(i,N) scanf("%lld%d", &box[i].ST, &box[i].ND);
		REP(i,M) scanf("%lld%d", &toy[i].ST, &toy[i].ND);
		int end = 1<<N;
		LL res = 0;
		FOR(mask,1,end)
		{									
			if(ile(mask) == 1)
			{
				REP(i,N) box1[i] = box[i];
				REP(i,M) toy1[i] = toy[i];	
				LL v = 0;
				int wsk;
				REP(i,N) if(mask&(1<<i)) wsk = i;
				REP(i,M)
					if(box1[wsk].ND == toy1[i].ND)
					{
						LL add = min(toy1[i].ST,box1[wsk].ST);
						v += add;
						box1[wsk].ST -= add;
					}
				res = max(res,v);
			}
			else if(ile(mask) == 2)
			{
				int wsk = -1, wsk2;
				REP(i,N) 
					if(mask&(1<<i)) 
					{
						if(wsk == -1)
							wsk = i;
						else
							wsk2 = i;
					}
				REP(i,M)
				{
					LL v = 0;
					REP(i,N) box1[i] = box[i];
					REP(i,M) toy1[i] = toy[i];	
					FORQ(j,0,i)
						if(box1[wsk].ND == toy1[j].ND)
						{
							LL add = min(toy1[j].ST,box1[wsk].ST);
							v += add;
							box1[wsk].ST -= add;
							toy1[j].ST -= add;
						}
					FOR(j,i,M)
						if(box1[wsk2].ND == toy1[j].ND)
						{
							LL add = min(toy1[j].ST,box1[wsk2].ST);
							v += add;
							box1[wsk2].ST -= add;
							toy1[j].ST -= add;
						}
					res = max(res,v);
				}
			}//2 bity
			else
			{				
				REP(i,M)FOR(j,i,M)
				{
					LL v = 0;
					REP(i,N) box1[i] = box[i];
					REP(i,M) toy1[i] = toy[i];	
					FORQ(k,0,i)
						if(box1[0].ND == toy1[k].ND)
						{
							LL add = min(toy1[k].ST,box1[0].ST);
							v += add;
							box1[0].ST -= add;
							toy1[k].ST -= add;
						}
					FORQ(k,i,j)
						if(box1[1].ND == toy1[k].ND)
						{
							LL add = min(toy1[k].ST,box1[1].ST);
							v += add;
							box1[1].ST -= add;
							toy1[k].ST -= add;
						}
					FOR(k,j,M)
						if(box1[2].ND == toy1[k].ND)
						{
							LL add = min(toy1[k].ST,box1[2].ST);
							v += add;
							box1[2].ST -= add;
							toy1[k].ST -= add;
						}
					res = max(res,v);
				}
			}			
		}
		printf("Case #%d: %lld\n", c+1, res);
	}
	return 0;
}