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
		j < 0 || j >= c || v[i][j]) return 0;
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
	
	do
	{
		for(int i = 0 ; i < total; ++i)
		{
			//cout << (int)allchoice[i] << " ";
			o[i/c][i%c] = allchoice[i]?'*':'.';
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
			for(int i = 0 ; i < r; ++i)
				puts(o[i]);
		  /* for(int i = 0 ; i < r; ++i)
			{			
				for(int j = 0 ; j < c; ++j)
				{
					if( o[i][j] == '.' ) cout << cnt[i][j];
					else cout << o[i][j];
				}
				puts("");
			}*/
			return 1;
		}

		trynext:;
	}while( next_permutation( allchoice.begin(), allchoice.end() ) );


	return 0;
}

int main()
{	
	scanf("%d" , &cases);	
	while( cases-- )
	{
		int r,c , m;
		cin >>  r >> c >> m;
		printf("Case #%d:\n" , Case++);   
		//only know how to brute
		if(brute(r,c,m))
		{

		}
		else
		{
			puts("Impossible");
		}
		
		


		
	}

	

	return 0;
}

