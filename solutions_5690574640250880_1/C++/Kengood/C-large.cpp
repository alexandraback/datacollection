#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>

#include<unordered_map>
#include<unordered_set>
using namespace std;

int cases , Case = 1;
////////////


char o[128][128];
int cnt[128][128];

char isBomb(int i,int j,int r, int c)
{
	return !( i < 0 || i >= r ||
		j < 0 || j >= c ||
		o[i][j] != '*' );

	
}

char isZero(int i,int j,int r, int c)
{
	return !( i < 0 || i >= r ||
		j < 0 || j >= c ||
		cnt[i][j] || o[i][j]=='*' );
}

char v[128][128];
int dfs(int i,int j,int r, int c)
{
	if( i < 0 || i >= r ||
		j < 0 || j >= c || v[i][j] || o[i][j] == '*') return 0;
	v[i][j] = 1;
	if( cnt[i][j] ) return 1;

	int ans = 1;
	
	for(int a = -1; a<2; ++a)
	{
		for(int b = -1; b<2; ++b)
		{
			ans += dfs(i+a,j+b,r,c); 
		}
	}

	return ans;
}

char isOK(int r, int c , int m )
{
	for(int i = 0 ; i < r; ++i)
	{			
		for(int j = 0 ; j < c; ++j)
		{
			cnt[i][j] = 0;
			v[i][j] = 0;
			if( o[i][j] == '.' )
			{
				for(int a = -1; a<2; ++a)
					for(int b = -1; b<2; ++b)
						cnt[i][j]+= isBomb(i+a,j+b,r,c);
			}
		}
	}
	for(int i = 0 ; i < r; ++i)
	{			
		for(int j = 0 ; j < c; ++j)
		{
			if( o[i][j] == 'c' )
			{
				return dfs(i,j,r,c) == r*c -m ;
			}

		}
	}
	return 0;

}

char brute(int r, int c , int m )
{
	int total = r*c;

	memset(o,0,sizeof(o));
	if( total-1 == m )
	{

		for(int i = 0 ; i < r; ++i)					
			for(int j = 0 ; j < c; ++j)
				o[i][j] = '*';
		o[0][0] = 'c';

		for(int i = 0 ; i < r; ++i)
			puts(o[i]);
		return 1;
	}


	vector<char> allchoice(total);
	for(int i = 0 ; i < m; ++i)
	{
		allchoice[i] = 1;
	}
	sort(allchoice.begin(), allchoice.end() );
	
	char aas = 0;
	
	do
	{
		for(int i = 0 ; i < total; ++i)
		{
			//cout << (int)allchoice[i] << " ";
			if( r >= c)
				o[i/c][i%c] = allchoice[i]?'*':'.';
			else
				o[i%r][i/r] = allchoice[i]?'*':'.';
		}

		for(int i = 0 ; i < r; ++i)
		{			
			for(int j = 0 ; j < c; ++j)
			{
				cnt[i][j] = 0;
				v[i][j] = 0;
				if( o[i][j] == '.' )
				{
					for(int a = -1; a<2; ++a)
						for(int b = -1; b<2; ++b)
							cnt[i][j]+= isBomb(i+a,j+b,r,c);
				}
			}

		}

		char cc = 0;
		for(int i = 0 ; i < r; ++i)
		{			
			for(int j = 0 ; j < c; ++j)
			{
				if( o[i][j] == '.'  && cnt[i][j] == 0 && cc == 0 )
				{
					o[i][j] = 'c';
					cc = 1;
					
					if( dfs(i,j,r,c) != total -m )
					{
						goto trynext;
					}
				}
							
			}
		}
		
		if(cc)
		{
			if( o[0][0] == 'c' ) { 
			for(int i = 0 ; i < r; ++i)
				puts(o[i]);
			aas = 1;
			}
			return 1;

		}

		trynext:;
	}while( next_permutation( allchoice.begin(), allchoice.end() ) );


	return aas;
}

void add(int i , int j,int r,int c, char a)
{
	if( i < 0 || i >= r ||
		j < 0 || j >= c ) return;

	o[i][j] = a;
}


void simpleFillBottom(int r,int c,int m )
{
	for(int i = r; i-- ;)
	{
		for(int j = c ; j--; )
		{
			if(m && o[i][j] == 0)
			{
				o[i][j] = '*';
				--m;
			}
			else
				o[i][j] = '.';
		}
	}
	o[0][0] = 'c';
}

void simpleFillRight(int r,int c,int m)
{	
	for(int j = c ; j--; ) 
	{
		for(int i = r; i--;)
		{
			if(m && o[i][j] == 0)
			{
				o[i][j] = '*';
				--m;
			}
			else
				o[i][j] = '.';
		}
	}
	o[0][0] = 'c';
}

char greedy(int r, int c , int m )
{
	memset(o,0,sizeof(o));
	int total = r*c;

	// must ok
	if( total-1 == m || r == 1 || c == 1 || m == 0 )
	{
		simpleFillBottom(r,c,m);
		o[0][0] = 'c'; 
		return 1;
	}

	
	// c == 2 , fill the bottom
	if( c == 2)
	{
		if( (m&1) || total-2 == m ) //impossible
			return 0;
		
		simpleFillBottom(r,c,m);
		o[0][0] = 'c'; 

		return 1;
	}

	//similarily , r == 2 , fill the right first
	if( r == 2 )
	{
		if( (m&1) || total-2 == m ) //impossible
			return 0;
		simpleFillRight(r,c,m);
		
		o[0][0] = 'c'; 
		return 1;
	}

	//pattern
	if( m == total - 2||
		m == total - 3||
		m == total - 5||
		m == total - 7) return 0;

	for(int a = -1; a<2; ++a) for(int b = -1; b<2; ++b)
		add(a,b,r,c,'.');
	

	if( m%c == 0 && m/c < r-2 )
		simpleFillBottom(r,c,m);
	else if( m%r == 0 && m/r < c-2 )
		simpleFillRight(r,c,m);
	else if(1) 
	{
		int fullR = m/c;
		int remain = m%c;
		
		simpleFillBottom(r,c,m);

		//move left one
		if( c-remain == 1 )
		{
			if( o[r-fullR-1][1]  != '*' ) { cerr << "should be ok"; }
			else
			{
				o[r-fullR-1][1] = '.';
				o[r-fullR-2][c-1] = '*';
			}
		}
		
		//check the top  gap
		for(int j = c; j--; )
		{
			if( o[0][j] == '.' && o[1][j] =='*')
			{
				char ok = 0;
				for(int jj = 0; jj < j; ++jj)
				{
					if( o[1][jj] =='*' )
					{
						o[1][jj] = '.';
						o[0][j] = '*';
						ok=1;
						break;
					}
				}
				if(ok) continue;

				if( o[2][0] =='*' ) //full row, but need to rebuild
				{
					o[0][j] = '*';
					o[2][0] = '.';

					o[1][j-1] = '*';
					o[2][1] = '.';

				}				
				else
				{
					ok = 0;
					for(int jj = 1; jj < j; ++jj)
					{
						if( o[2][jj] =='*' )
						{
							o[2][jj] = '.';
							o[0][j] = '*';
							ok=1;
							break;
						}
					}

					if(!ok)
						{ cerr << "............";  exit(1); }
				}

			}
			
		}



		o[0][0] = 'c'; 
	}


	o[0][0] = 'c';

	if( !isOK(r, c , m ) ) {
		cout << "die"; exit(1);
		return 0;
	}


	return 1;
}


void test()
{
	for(int r = 1; r < 6; ++r)for(int c = 1; c < 6; ++c)
	//int r = 5 , c = 6; 
	for(int m = 1; m<r*c; ++m)
	{
		cout << "testing : " << r << " " << c << " " << m << endl;
		if( greedy(r,c,m) != brute(r,c,m) )
		{
			cout <<"diff: " << r << " " << c << " " << m << endl; exit(1);
		}
	}
	puts("done");
}

int main()
{	
	//test(); return 0;



	//for(int r = 1; r < 51; ++r){for(int c = 1; c < 51; ++c){
	//for(int m = 1 ; m < r*c; ++m)
	//{
	//	if( greedy(r,c,m))
	//	{

	//		if( !isOK(r, c , m ) ) {
	//			cout << "die"; exit(1);
	//			return 0;
	//		}


	//		for(int i = 0 ; i < r; ++i)
	//			puts(o[i]);
	//	}
	//	else
	//	{
	//		puts("Impossible");
	//	}
	//}
	//}
	//}

	scanf("%d" , &cases);	
	while( cases-- )
	{
		int r,c , m;

		cin >>  r >> c >> m;
		printf("Case #%d:\n" , Case++);   

		if( greedy(r,c,m))
		{
			for(int i = 0 ; i < r; ++i)
				puts(o[i]);
		}
		else
		{
			puts("Impossible");
		}

		
	}

	

	return 0;
}

