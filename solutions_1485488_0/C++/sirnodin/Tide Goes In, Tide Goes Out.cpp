#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<list>
#include<stdio.h>
#include<sstream>
#include<set>
#include<deque>
#include<cmath>
#include<numeric>
#include<fstream>
#include <iomanip>

using namespace std;

typedef long long LInt;
typedef vector<int> intvec;
typedef vector<intvec> intvec2;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define DEC(i,k) for (int i=(k); i>=0; --i)
#define FORIT(i,c) for (decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())

const int MAXN = 101;
const int MAXM = 101;
const double MAX = 100000;

int H,N,M;
int C[MAXN][MAXM];
int F[MAXN][MAXM];

double DP[MAXN][MAXN];

double dp(int n,int m)
{
	double & ret = DP[n][m];
	if(ret<0)
	{
		ret = MAX;
		int c = C[n][m],f=F[n][m];
		if(n>0)
		{
			double t = dp(n-1,m);
			double h = H - t*10;
			int cf = C[n-1][m],ff=F[n-1][m];
			if(c-ff>=50 && cf-f>=50 && c-f>=50)
			{
				if(c-h>=50)
				{
					if(t>0)
					{
						double add = (h-ff)>=20?1:10;
						ret=t+add;
					}
					else
						ret = 0;
				}
				else
				{
					ret = t+(h-c+50)/10.0;
					h = c-50;
					double add = (h-ff)>=20?1:10;
					ret+=add;
				}
			}
		}
		if(m>0)
		{
			double t = dp(n,m-1);
			if(t<MAX)
			{
			double h = H - t*10;
			int cf = C[n][m-1],ff=F[n][m-1];
			if(c-ff>=50 && cf-f>=50 && c-f>=50)
			{
				if(c-h>=50)
				{
					if(t>0)
					{
						double add = (h-ff)>=20?1:10;
						t+=add;
					}
				}
				else
				{
					t = t+(h-c+50)/10.0;
					h = c-50;
					double add = (h-ff)>=20?1:10;
					t+=add;
				}
				ret = min(ret,t);
			}
			}
		}
	}
	return ret;
}

void BFS()
{
	int I[100000];
	int J[100000];
	int front = 0,rear = 1;
	I[front] = 0;
	J[front] = 0;
	while(front<rear)
	{
		int n = I[front],m = J[front];
		int c = C[n][m],f=F[n][m];
		double t = DP[n][m];
		double h = H - t*10;
		//
		if(n>0 && DP[n-1][m]>t)
		{
			int nn = n-1,mm=m;
			int ct = C[nn][mm],ft=F[nn][mm];
			double ret = MAX;
			if(ct-f>=50 && c-ft>=50 && ct-ft>=50)
			{
				if(ct-h>=50)
				{
					if(t>0)
					{
						double add = (h-f)>=20?1:10;
						ret=t+add;
					}
					else
						ret = 0;
				}
				else
				{
					ret = t+(h-ct+50)/10.0;
					double add = (ct-50-f)>=20?1:10;
					ret+=add;
				}
			}
			if(DP[nn][mm]>ret)
			{
				DP[nn][mm]=ret;
				I[rear] = nn;
				J[rear] = mm;
				rear++;
			}
		}//
		//
		if(m>0 && DP[n][m-1]>t)
		{
			int nn = n,mm=m-1;
			int ct = C[nn][mm],ft=F[nn][mm];
			double ret = MAX;
			if(ct-f>=50 && c-ft>=50 && ct-ft>=50)
			{
				if(ct-h>=50)
				{
					if(t>0)
					{
						double add = (h-f)>=20?1:10;
						ret=t+add;
					}
					else
						ret = 0;
				}
				else
				{
					ret = t+(h-ct+50)/10.0;
					double add = (ct-50-f)>=20?1:10;
					ret+=add;
				}
			}
			if(DP[nn][mm]>ret)
			{
				DP[nn][mm]=ret;
				I[rear] = nn;
				J[rear] = mm;
				rear++;
			}
		}//
		//
		if(n<N-1 && DP[n+1][m]>t)
		{
			int nn = n+1,mm=m;
			int ct = C[nn][mm],ft=F[nn][mm];
			double ret = MAX;
			if( ct-f>=50 && c-ft>=50 && ct-ft>=50)
			{
				if(ct-h>=50)
				{
					if(t>0)
					{
						double add = (h-f)>=20?1:10;
						ret=t+add;
					}
					else
						ret = 0;
				}
				else
				{
					ret = t+(h-ct+50)/10.0;
					double add = (ct-50-f)>=20?1:10;
					ret+=add;
				}
			}
			if(DP[nn][mm]>ret)
			{
				DP[nn][mm]=ret;
				I[rear] = nn;
				J[rear] = mm;
				rear++;
			}
		}//
		//
		if(m<M-1 && DP[n][m+1]>t)
		{
			int nn = n,mm=m+1;
			int ct = C[nn][mm],ft=F[nn][mm];
			double ret = MAX;
			if( ct-f>=50 && c-ft>=50 && ct-ft>=50)
			{
				if(ct-h>=50)
				{
					if(t>0)
					{
						double add = (h-f)>=20?1:10;
						ret=t+add;
					}
					else
						ret = 0;
				}
				else
				{
					ret = t+(h-ct+50)/10.0;
					double add = (ct-50-f)>=20?1:10;
					ret+=add;
				}
			}
			if(DP[nn][mm]>ret)
			{
				DP[nn][mm]=ret;
				I[rear] = nn;
				J[rear] = mm;
				rear++;
			}
		}//
		front++;
	}
}

int main()
{
	ifstream fin("B-small-attempt1.in");
	ofstream fout("B-small-attempt1.out");
	
	int T,ans = 0;
	fin>>T;

	REP(TEST,T)
	{
		fin>>H>>N>>M;
		REP(i,N)REP(j,M)
		{
			fin>>C[i][j];
		}
		REP(i,N)REP(j,M)
		{
			fin>>F[i][j];
			DP[i][j] = MAX;
		}
		if(TEST == 6)
		{
			REP(i,N){REP(j,M)
		{
			cout<<C[i][j]<<" ";
		}
			cout<<endl;
			}
		REP(i,N){REP(j,M)
		{
			cout<<F[i][j]<<" ";
		}
			cout<<endl;
			}
		}
		DP[0][0] = 0;
		BFS();
		fout<<"Case #"<<TEST+1<<": "<<DP[N-1][M-1]<<endl;
	}
	system("pause");
	return 0;
}