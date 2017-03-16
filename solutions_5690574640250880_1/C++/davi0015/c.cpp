#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>

using namespace std;

#define forn(I,N) for (int I=0; I<N; I++)
#define fornd(I,N) for (int I=N-1; I>=0; I--)
#define forab(I,A,B) for (int I=A; I<=B; I++)
#define forabd(I,A,B) for (int I=B, I>=A; I--)
#define FOREACH(I,A) for (__typeof__(A)::iterator I=A.begin(); I<A.end(); I++)
#define pb push_back
#define mp make_pair

typedef long long int ll;

int main()
{
	int T;
	cin >> T;
	
	forn (i, T)
	{
		int R, C, M;
		cin >> R >> C >> M;
		
		vector <vector <char> > mine(R, vector <char> (C));
		int free = R*C - M;
		
		int r = 0;
		int c = 0;
		
		int rest = M;
		while (rest > 0)
		{
			if (R-r > C-c || (R-r == C-c && R>=C))
			{
				if (rest >= C - c)
				{
					rest -= C - c;
					forab (j, c, C-1)
						mine[r][j] = '*';
					r++;
				}
				else
				{
					int lim = rest;
					rest = 0;
					if (lim == C - c - 1 && lim > 1)
					{
						lim--;
						mine[r+1][c] = '*';
					}
					forab (j, c, c + lim - 1)
						mine[r][j] = '*';
					r++;
				}
			}
			else
			{
				if (rest >= R - r)
				{
					rest -= R - r;
					forab (j, r, R-1)
						mine[j][c] = '*';
					c++;
				}
				else 
				{
					int lim = rest;
					rest = 0;
					if (lim == R - r - 1 && lim > 1)
					{
						lim--;
						mine[r][c+1] = '*';
					}
					forab (j, r, r + lim - 1)
						mine[j][c] = '*';
					c++;
				}
			}
		}
		mine[R-1][C-1] = 'c';
		int current = 1;
		int ind = 0;
		vector <int> nextr, nextc;
		vector <vector <bool> > taken (R, vector <bool> (C));
		taken[R-1][C-1] = true;
		nextr.pb(R-1);
		nextc.pb(C-1);
		while (ind < nextr.size())
		{
			int a = nextr[ind];
			int b = nextc[ind];
			bool isNull = true;
			forab (j, a-1, a+1) if (j>=0 && j<R)
			{
				forab (k, b-1, b+1) if (k>=0 && k<C)
				{
					if (j!=a || k!=b)
					{
						if (mine[j][k]=='*')
						{
							isNull = false;
							break;
						}
					}
				}
			}
			
			if (isNull)
			{
				forab (j, a-1, a+1) if (j>=0 && j<R)
				{
					forab (k, b-1, b+1) if (k>=0 && k<C)
					{
						if ((j!=a || k!=b) && !taken[j][k] && mine[j][k]!='*')
						{
							nextr.pb(j);
							nextc.pb(k);
							if (mine[j][k]==0)
							{
								mine[j][k] = '.';
								current++;
							}
							taken[j][k] = true;
						}
					}
				}
			}
			
			ind++;
		}
		cout << "Case #" << i+1 << ": " << endl;
		if (current < free)
			cout << "Impossible" << endl;
		else
		{
			forn (j, R)
			{
				forn (k, C)
				{
					cout << mine[j][k];
				}
				cout << endl;
			}
		}
	}
	
	return 0;
}