#include <iostream>

#include <vector>
#include <string>
#include <sstream>

#include <functional>
#include <queue>
#include <utility>

using namespace std;

template< typename T >
std::string ToString( const T& v )
{
  std::ostringstream oss;
  oss << v;
  return oss.str();
}

#define MIN(l,r) ( l<r ? l : r )
#define MAX(l,r) ( l>r ? l : r )
int DX[] ={ 1, 0, -1, 0 };
int DY[] ={ 0, 1, 0, -1 };

int AX[] ={ 1, 1, 1, 0, 0, -1, -1, -1 };
int AY[] ={ 1, 0, -1, 1, -1, 1, 0, -1 };

int tests;

int main()
{
	int tab[51][51];
	int dp[51][51];

	cin >> tests;

	for( int curTest=0; curTest<tests; ++curTest )
	{
		int R, C, M;
		cin >> R >> C >> M;
		const int X =R*C -M;

		bool rev =false;
		if ( R > C )
		{
			int kR = R;
			R = C;
			C = kR;
			rev = true;
		}

		cout << "Case #" << (curTest+1) << ":" << endl;
		auto disp_tab = [&]()
		{
				// print it
			if ( rev )
			{
				for( int c=0; c<C; ++c )
				{
					for( int r=0; r<R; ++r )
					{
						cout << (char)tab[r][c];
					}
					cout << endl;
				}
			}
			else
			{
				for( int r=0; r<R; ++r )
				{
					for( int c=0; c<C; ++c )
					{
						cout << (char)tab[r][c];
					}
					cout << endl;
				}
			}
		};

		if ( M==0 )
		{
			for( int r=0; r<R; ++r ) for( int c=0; c<C; ++c ) tab[r][c] = '.';
			tab[0][0] = 'c';
			disp_tab();
			continue;
		}
		if ( X==1 )
		{
			for( int r=0; r<R; ++r ) for( int c=0; c<C; ++c ) tab[r][c] = '*';
			tab[0][0] = 'c';
			disp_tab();
			continue;
		}

		for( int r=0; r<R; ++r ) for( int c=0; c<C; ++c ) tab[r][c] = '*';
		if ( R>=3 && C>=3 )
		{
				// greedy
			if ( X<4 || X==7 || X==5 )
			{
				cout << "Impossible" << endl;
			}
			else
			{
					// make 4
				tab[0][0] = tab[0][1] = tab[1][0] = tab[1][1] = '.';
				if ( X%C==0 && X>C*2 )
				{
					for( int r=0; r<(X/C); ++r ) for( int c=0; c<C; ++c ) tab[r][c]='.';
					tab[0][0] = 'c';
					disp_tab();
					continue;
				}
				if ( X < C*2 )
				{
						// make 2 greedy row
					if ( X%2 )
					{
						for( int i=0; i<X/2 -1; ++i ) tab[0][i]=tab[1][i]='.';
						tab[2][0] = tab[2][1] = tab[2][2] = '.';
						tab[0][0]='c';
						disp_tab();
					}
					else
					{
						for( int i=0; i<X/2; ++i ) tab[0][i]=tab[1][i]='.';
						tab[0][0]='c';
						disp_tab();
					}
				}
				else if ( X < C*3 )
				{
					if ( X < C*2+2 )
					{
						for( int i=0; i<C-1; ++i ) tab[0][i]=tab[1][i]='.';
						for( int i=0; i<X-C*2+2; ++i ) tab[2][i]='.';
						tab[0][0]='c';
						disp_tab();
					}
					else
					{
						for( int i=0; i<C; ++i ) tab[0][i]=tab[1][i]='.';
						for( int i=0; i<X-C*2; ++i ) tab[2][i]='.';
						tab[0][0]='c';
						disp_tab();
					}
				}
				else
				{
					const int S = X/C;
					if ( X%C < 2 )
					{
						for( int r=0; r<S-1; ++r ) for( int c=0; c<C; ++c ) tab[r][c]='.';
						for( int r=0; r<1; ++r ) for( int c=0; c<C-1; ++c ) tab[S-1+r][c]='.';
						for( int c=0; c<X%C+1; ++c ) tab[S][c]='.';
						tab[0][0]='c';
						disp_tab();
					}
					else
					{
						for( int r=0; r<S; ++r ) for( int c=0; c<C; ++c ) tab[r][c]='.';
						for( int c=0; c<X%C; ++c ) tab[S][c]='.';
						tab[0][0]='c';
						disp_tab();
					}
				}
			}
		}
		else if ( R==2 || C==2 )
		{
			for( int r=0; r<R; ++r ) for( int c=0; c<C; ++c ) tab[r][c] = '*';
				// 2 greedy
			if ( X>=4 && X%2==0 )
			{
				for( int i=0; i<X/2; ++i )
				{
					if ( R==2 )
					{
						tab[0][i]=tab[1][i]='.';
					}
					else
					{
						tab[i][0]=tab[i][1]='.';
					}
				}
				tab[0][0] = 'c';
				disp_tab();
			}
			else
			{
				cout << "Impossible" << endl;
			}
		}
		else
		{
			// MIN =1
			if ( X >= 2 )
			{
				for( int r=0; r<R; ++r )
				{
					for( int c=0; c<C; ++c )
					{
						if ( MAX(r,c) == ( X -2 ) ) tab[r][c] = 'c';
						else if ( MAX(r,c) < X ) tab[r][c] = '.';
					}
				}
				disp_tab();
			}
			else
			{
				cout << "Impossible" << endl;
			}
		}
	}

	return 0;
}

