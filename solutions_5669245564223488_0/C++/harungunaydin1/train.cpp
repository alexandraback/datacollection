#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MOD 1000000007
#define MAXN 105
using namespace std;
string str[MAXN];
int K,N,res;
int H[300] , H2[300];
bool used[MAXN];
void rec(int x,char pre)
{
	if(x == N + 1)
	{
		res++;
		return;
	}
	int i,j,s;
	FOR(i,1,N)
		if( !used[i] )
		{
			s = 0;
			for(j = 0; j < str[i].size(); j++)
			{
				if( j && str[i][j] != str[i][j-1] ) s = 1;
				if( !H[ str[i][j] ] || ( H[ str[i][j] ] && str[i][j] == pre && !s ) ) continue;
				break;
			}
			if(j == str[i].size())
			{
				used[i] = true;
				for(j = 0; j < str[i].size(); j++)
					H[ str[i][j] ]++;

				rec(x+1,str[i][ str[i].size() - 1 ]);

				for(j = 0; j < str[i].size(); j++)
					H[ str[i][j] ]--;
				used[i] = false;
			}
		}
}
void solve()
{
	memset( H , 0 , sizeof H );
	memset( H2 , 0 , sizeof H2 );
	int h(0),i,j,k;
	scanf("%d" , &N );
	FOR(i,1,N)
	{
		cin >> str[i];
		h++;
		for(j = 0; j < str[i].size(); j++)
		{
			k = j;
			while( j < str[i].size() && str[i][j] == str[i][k] ) j++;
			j--;
			if( H2[ str[i][j] ] == h ) { printf("0\n"); return; }
			H2[ str[i][j] ] = h;
		}
	}

	rec(1,0);

	printf("%d\n" , res );

	res = 0;
}
int main()
{
	int T,i;
	scanf("%d" , &T );
	FOR(i,1,T)
	{
		printf("Case #%d: " , i );
		solve();
	}
	return 0;
}
