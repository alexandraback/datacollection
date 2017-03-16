#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <map>
#include <iostream>
#include <string>

using namespace std;

char buffer[2048];

#define FILE_NAME "A-large"
#define ULL unsigned long long
#define CASET int _t=0, case_num;cin>>case_num;while(++_t<=case_num)

typedef vector<int> VI;
typedef vector<VI> VVI;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char dir[4] = {'E', 'S', 'W', 'N'};

ULL num1, num2;

ULL gcd ( ULL a, ULL b )
{
  ULL c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int solve()
{
	ULL gNum = gcd(num1, num2);
	ULL n1 = num1/gNum;
	ULL n2 = num2/gNum;

	ULL base = 1;
	while(1)
	{
		base*=2;
		if(base==n2)
			break;
		if(base>n2)
			return -1;
	}

	int gen = 0;
	while(1)
	{
		n1*=2;
		gen++;
		if(n1>=n2)
			return gen;
	}
	return -1;
}	

int main()
{
	sprintf(buffer, "%s.in", FILE_NAME);
	freopen(buffer, "r", stdin);
	sprintf(buffer, "%s.out", FILE_NAME);
	freopen(buffer, "w", stdout);

	CASET
	{
		printf("Case #%d: ", _t);
	
		char ch;
		cin>>num1>>ch>>num2;

		int ans = solve();
		if(ans==-1)
			printf("impossible");
		else
			printf("%d", ans);

		printf("\n");
	}
		
	return 0;
}