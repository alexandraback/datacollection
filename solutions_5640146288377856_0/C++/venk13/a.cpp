#include <vector>
#include <map>
//#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#define sz(a) (int)(a.size())
#define len(a) (int)(a.length())
#define pb push_back
#define mp make_pair
#define fi first
#define se second

int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("o.txt","w",stdout);
	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d: ",cas++);
		int r,c,w;
		scanf("%d%d%d",&r,&c,&w);
		printf("%d\n",c/w*r+w-1+(c%w?1:0));
	}
	return 0;
}