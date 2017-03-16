#define _CRT_SECURE_NO_WARNINGS

#include <iostream> // standard input & output cout cin
#include <cstdio> // scanf printf
#include <vector> // std~::vector
#include <algorithm>
#include <string> // std::string
#include <queue> // std::queue
#include <cstring> // memset
#include <set> // std::set
#include <utility> // std::pair, std::make_pair

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)


// -------------------------- global variable



// ; 빼먹지 않았는지 확인 ;;;;;;;;;;;;;;;;;
// -------------------------- declare function


// -------------------------- main

int main(int argc, char **argv)
{
	int t;
	int k,c,s;
	scanf("%d",&t);
	for(int i = 1; i <= t;i++)
	{
		scanf("%d%d%d",&k,&c,&s);
		printf("case #%d: ",i);
		for(int j = 1; j<=k;j++)
		{
			printf("%d ",j);
		}
		printf("\n");
	}
	return 0;
}

/* memo
*
*
*
*
*
*/

