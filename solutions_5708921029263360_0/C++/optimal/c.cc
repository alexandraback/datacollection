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
#include <tuple>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;

int main()
{
#ifdef MICRO_LOCAL
	freopen("in.put", "r", stdin);
	clock_t timer_start = clock();
#endif
/*------------------------------------------------------------------------------------*/
    int T;
    scanf("%d",&T);
    for (int tc=1; tc<=T; tc++) {
        int jackets,pants,shirts,K,cnt=0;
        map<tuple<int,int>, int> jp,js,ps;
        tuple<int,int> t1,t2,t3;
        vector<tuple<int,int,int>> ans;
        scanf("%d%d%d%d", &jackets, &pants, &shirts, &K);
        for (int i=0; i<jackets; i++) {
            for (int j=0; j<pants; j++) {
                for (int k=0; k<shirts; k++) {
                    //printf("i,j,k: %d %d %d\n", i, j, k);
                    t1 = make_tuple(i,j);
                    if (jp[t1] >= K) {/*puts("jp");*/continue;}

                    t2 = make_tuple(i,k);
                    if (js[t2] >= K) {/*puts("js");*/continue;}

                    t3 = make_tuple(j,k);
                    if (ps[t3] >= K) {/*puts("ps");*/continue;}

                    cnt++;
                    jp[t1]++;
                    js[t2]++;
                    ps[t3]++;
                    ans.push_back(make_tuple(i,j,k));
                }
            }
        }
        printf("Case #%d: %d\n", tc, cnt);
        for (int i=0; i<ans.size(); i++) {
            printf("%d %d %d\n", get<0>(ans[i])+1, get<1>(ans[i])+1, get<2>(ans[i])+1);
        }
        //puts("---------");
    }
/*------------------------------------------------------------------------------------*/
#ifdef MICRO_LOCAL
	printf("\nElapsed time : %.2lfms\n", ((double)clock() - (double)timer_start)/1000.0);
#endif
	return 0;
}
