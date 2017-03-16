#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <cctype>
#include <cstdio>
#include <memory>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

#define sqr(x) ((x) * (x))
#define minn(x,y) (x=(y)<(x)?(y):(x))
#define maxx(x,y) (x=(y)>(x)?(y):(x))
#define pluss(x,y) (x+=(y),x%=mod)
#define random(x) ((((rand()%32767)*(rand()%32767)*(rand()%32767)%(x))+(x))%(x))

using namespace std;

typedef	long long	int64;


stringstream	Sin;
vector<int64>	a;
int		L, R;


int	isPalindrome(int64 x)
{
	Sin.clear();
	Sin << x;
	string	s;
	Sin >> s;
	int	ok = 1;
	for (int i = 0; i < s.size() / 2; ++ i) ok &= (s[i] == s[s.size() - 1 - i]);
	return ok;
}

int	main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	
	for (int64 x = 1; x <= 10000000; ++ x)
		if (isPalindrome(x) && isPalindrome(x * x))
			a.push_back(x * x);
	
	//for (int i = 0; i < a.size(); ++ i) cout << a[i] << endl;
	
	int	Test;
	scanf("%d", &Test);
	for (int test = 1; test <= Test; ++ test)
	{
		scanf("%d%d", &L, &R);
		printf("Case #%d: %d\n", test, upper_bound(a.begin(), a.end(), R) - upper_bound(a.begin(), a.end(), L - 1));
	}
	
	return 0;
}
