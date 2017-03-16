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

char buf[128];

int inToInt()
{
	cin >> buf;
	if( buf[0] == '1' ) return 100000;
	if( buf[0] != '0' || buf[1] != '.' ) cerr << "....?" << buf;
	{
		for(int i = strlen(buf); i < 7; ++i)		
			buf[i] = 48;
		buf[7] = 0;
		return atoi( buf+2);
	}
}


int in[2][1024];

int temp[2][1024];


int playwar(int n)
{
		for(int j = 0 ; j < 2; ++j)
		{
		for(int i = 0 ; i < n; ++i)
		{
			in[j][i] = temp[j][i];
		//	cout <<  in[j][i] << " ";
		}
		//puts("");
		}

	sort( in[0] , in[0] + n);
	sort( in[1] , in[1] + n);
	int ans = 0;

	for(int i = n; i--;)
	{
		int kChoose = -1;
		for(int j = 0 ; j < n; ++j)
		{
			if( in[1][j] >= 0 )
			{
				if( in[1][j] > in[0][i] ) // k just win
				{
					kChoose = j;
					in[1][j] = -1;
					break;
				}
			}
		}
		if(kChoose>=0) continue;

		for(int j = 0 ; j < n; ++j)
		{
			if( in[1][j] >= 0 && in[1][j] == in[0][i] ) // draw
			{
				kChoose = j;
				in[1][j] = -1; break;
			}				
		}
		if(kChoose>=0) continue;

		++ans; // n win
		for(int j = 0 ; j < n; ++j)
		{
			if( in[1][j] >= 0 ) // choose the worst block to burn
			{							
				in[1][j] = -1; break;
			}				
		}
	}
	return ans;
}

int playCheat(int n)
{
	for(int j = 0 ; j < 2; ++j)
		for(int i = 0 ; i < n; ++i)
			in[j][i] = temp[j][i];

	sort( in[0] , in[0] + n);
	sort( in[1] , in[1] + n);
	int ans = 0;

	int kS = 0, kE = n-1;
	for(int i = 0; i < n; ++i)
	{
		if( in[0][i] > in[1][kS] )
		{
			++ans;
			++kS;
		}
		else
		{
			kE--;
		}

	}

	return ans;
}

int main()
{	
	scanf("%d" , &cases);	
	while( cases-- )
	{
		printf("Case #%d:" , Case++);   
		int n;
		cin >> n;
		
		for(int j = 0 ; j < 2; ++j)
		for(int i = 0 ; i < n; ++i)
			temp[j][i] = in[j][i] =  inToInt();

		
		printf(" %d %d\n" , playCheat(n) , playwar(n) );
	}

	

	return 0;
}

