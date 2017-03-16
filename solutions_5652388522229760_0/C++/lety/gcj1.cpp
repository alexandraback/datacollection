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

string s;
vector<int> checked(10);

// ; 빼먹지 않았는지 확인 ;;;;;;;;;;;;;;;;;
// -------------------------- declare function

void work(int n)
{
	checked = vector<int>(10,0);
	int temp;
	int cnt = 0;
	int num = 0;
	while(checked != vector<int>(10,1))
	{
		cnt++;
		temp = num;
		num += n;
		if(cnt == 1000 || temp == num)
		{
			printf("INSOMNIA\n");
			return;
		}
		s = to_string(num);
		int ssizz = s.size();
		for(int i = 0 ; i < ssizz; i++)
		{
			checked[s[i]- '0'] = 1;
		}
	}
	printf("%d\n",num);
}

// -------------------------- main

int main(int argc, char **argv)
{
	int t;
	scanf("%d",&t);
	for(int i = 1;i<=t;i++)
	{
		int n;
		scanf("%d",&n);
		printf("Case #%d: ",i);
		work(n);
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
