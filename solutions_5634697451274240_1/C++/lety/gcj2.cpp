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

char buf[102];
string s;

// ; 빼먹지 않았는지 확인 ;;;;;;;;;;;;;;;;;
// -------------------------- declare function

void work(string s)
{
	int ret = 0;
	vector<char> arr(s.size());
	int n = s.size();
	for(int i = 0 ; i<  n; i++)
	{
		arr[i] = s[i];
	}
	
	auto last = unique(arr.begin(), arr.end());
	
	//for(char &c : arr)
		//printf("%c ",c);
	//printf("\n");
	
	n = last - arr.begin();
	
	if(n % 2 == 0) // 짝수
	{
		if(arr[0] == '+')
		{
			ret = n;
		}
		else
		{
			ret = n-1;
		}
	}
	else
	{
		if(arr[0] == '+')
		{
			ret = n-1;
		}
		else
		{
			ret = n;
		}
	}
	
	printf(" %d\n", ret);
}

// -------------------------- main

int main(int argc, char **argv)
{
	int t;
	scanf("%d",&t);
	for(int i = 1 ; i <= t; i++)
	{
		scanf("%s",buf);
		s = buf;
		printf("Case #%d:",i);
		work(s);
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

