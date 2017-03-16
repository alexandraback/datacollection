#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <map>
#include <functional>
#include <cassert>
#include <ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;

int main()
{
#ifdef MICRO_LOCAL
	//freopen("in.put", "r", stdin);
	clock_t timer_start = clock();
#endif
/*------------------------------------------------------------------------------------*/
    int T;
    scanf("%d",&T);
    for (int tc=1; tc<=T; tc++) {
        int n;
        scanf("%d", &n);
        set<pair<string, string> > sps;
        char s[16][22],t[16][22];
        for (int i=0; i<n; i++) {
            scanf("%s %s",s[i],t[i]);
            sps.insert(pair<string,string>(s[i],t[i]));
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (strcmp(s[i],t[j]))
                    sps.insert(pair<string,string>(s[i],t[j]));
            }
        }
        printf("Case #%d: %d\n", tc, (int)sps.size() - n);
    }
/*------------------------------------------------------------------------------------*/
#ifdef MICRO_LOCAL
	printf("\nElapsed time : %.2lfms\n", ((double)clock() - (double)timer_start)/1000.0);
#endif
	return 0;
}
