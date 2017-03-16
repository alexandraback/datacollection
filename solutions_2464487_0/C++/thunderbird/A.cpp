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
typedef long long ll;

ll r,t;
 int main()
{
	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
	//freopen("A.in","r",stdin);freopen("A.out","w",stdout);
	//freopen("A-large-attemp.in","r",stdin);freopen("A-large-attemp.out","w",stdout);
	int testcase;
	ll ans=0;
	
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		scanf("%I64d%I64d", &r,&t);
		printf("Case #%d: ",case_id);
		ll ring=1;
		
		ans=0;
		while(t>0)
		{
			ll tn=4*ring+2*r-3;;
			ring++;
			if(tn<=t) ans++;
			t-=tn;

		}
		printf("%I64d",ans);
		printf("\n");
	}
	return 0;
}

