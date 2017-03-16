#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)

//#define maxn 510
//#define maxm 1010
//#define maxnumber 500000

typedef long long LL;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	int T;
	scanf("%d",&T);
	for(int tcase=1;tcase<=T;tcase++)
	{
		printf("Case #%d: ",tcase);
		
		int n,m,w;
		scanf("%d%d%d",&n,&m,&w);
		
		int ans=0;
		if (m%w==0)
			ans=(m/w)*n+(w-1);
		else
			ans=(m/w)*n+w;
		
		printf("%d\n",ans);
	}
	
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
