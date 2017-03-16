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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


// data define

const int maxn=1000+5;

int n;
int a[maxn],b[maxn],c[maxn];

int solve()
{
    int res=0;
    
    
    return res;
}
int main()
{
//	freopen("a.in","r",stdin);
//	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
//	freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d%d",&a[i],&b[i]);
		int ret=solve();
		printf("Case #%d: ",case_id);
		if (ret<0)
			printf("Too Bad\n");
		else
			printf("%d\n",ret);
	}
	return 0;
}
