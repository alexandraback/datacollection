//compiled in vc
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
// C++
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>
using namespace std;

#define IN_THE_SET(_set,_val) (_set.find(_val) != _set.end())

int cases , Case = 1;
////////////

struct Item
{
	long long val;
	int idx;
}item[2][128];

int n , m;
long long ans;
long long mem[128][128][2][2];

long long dfs(int curA, long long A, int curB , long long B ,
	         char usedA , char usedB , 
	          long long done)
{
	if( mem[curA][curB][usedA][usedB] != -1 )
	{
	//	if( done < mem[curA][curB][usedA][usedB] ) 
			return mem[curA][curB][usedA][usedB] ;
	}

	if( curA == n || curB == m)
	{
		ans = max(done, ans);
		return mem[curA][curB][usedA][usedB] = done;
	}

	char aa = usedA , bb = usedB;
	if( item[0][curA].idx == item[1][curB].idx )
	{
		long long good = min( A , B);
		done += good;
		A-=good;
		B-=good;
		usedB = usedA = 1;
	}

	long long anss = 0 , t;
	if( B)
	{
		t = dfs( curA+1 , item[0][curA+1].val , curB , B , 0 ,  usedB,  done);
		anss = max(t,ans);
	}

	if(A)
	{
		t = dfs( curA , A , curB+1 , item[1][curB+1].val , usedA , 0 , done);
		anss = max(t,ans);
	}

	t = dfs( curA+1 , item[0][curA+1].val , curB+1, item[1][curB+1].val ,0,0 , done);
	anss = max(t,ans);

	return mem[curA][curB][aa][bb] = anss;
}


void aaa()
{
	int t = 10;

	printf("%d\n" , t);
	while(t--)
	{
		int n = 100 , m = 100;
		printf("%d %d\n" , n , m);

		for(int i = 0 ; i < n; ++i)
			printf("%d %d " , rand() , rand()%n +1);
		puts("");
		for(int i = 0 ; i < m; ++i)
			printf("%d %d " , rand() , rand()%m +1);
		puts("");
	}

}


int main()
{	
	//aaa(); return 0;
	scanf("%d" , &cases);

	
	while( cases-- )
	{
		printf("Case #%d: " , Case++);   

		cin >> n >> m;

		for(int i = 0 ; i < n; ++i)
		{
			cin >> item[0][i].val;
			cin >> item[0][i].idx;
		}

		for(int i = 0 ; i < m; ++i)
		{
			cin >> item[1][i].val;
			cin >> item[1][i].idx;
		}
		

		ans = 0;
		memset( mem , -1 , sizeof(mem));
		dfs( 0 , item[0][0].val , 0 , item[1][0].val ,0,0 ,0);

		cout << ans << endl;
	}


	return 0;
}
