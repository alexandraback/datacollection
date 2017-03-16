/* Author: hypothesist */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <ctime>

using namespace std;

#define all(c) (c).begin(), (c).end()

template <typename T> class __cl
{
	public:
		std::vector<T> values;
		void operator()(const T& value)
		{
			if (std::find(all(values), value) == values.end())
				values.push_back(value);
		}
};

typedef istringstream is;
typedef ostringstream os;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define eps 1e-8
#define inf 1e8

#define tr(container, it) for(typeof((container).begin()) it = (container).begin(); it != (container).end(); it++)

#define ex_set(container, element) ((container).find((element)) != (container).end())
#define ex_vec(container, element) (find(all(container), (element)) != (container).end())

#define rm_dupl_s(container) set<typeof(*((container).begin()))> __s(all(container)); (container) = vector<typeof(*((container).begin()))>(all(__s))
#define rm_dupl_us(container) (container) = for_each(all(container), __cl<int>()).values

int d[1009];
int csol[1009], psol[1009];
int endpsol[1009];
int visited[1009][1009];
int cur;
int n;

void dfs(int v, int l) {//printf("%d, ", v);
    //printf("cur = %d, v = %d, l = %d\n", cur, v, l);
    visited[cur][v] = 1;
    int gn = d[v];
    if(d[gn] == v) {
        psol[cur] = l;
        endpsol[cur] = gn;
    }
    else if(gn == cur)
        csol[cur] = l;
    else if(!visited[cur][gn])
        dfs(gn, l + 1);
    else
       psol[cur] = csol[cur] = 0;
}

int val(int gn) {
    int sol[1009];
    for(int i = 0; i < n; i++)
        sol[i] = 0;
    for(int i = 0; i < n; i++) {
        if(gn & (1 << i)) {
            if(!psol[i])
                return -1;
            for(int j = 0; j < n; j++) {
                if(sol[j] == 1 && visited[i][j] == 1)
                    return -1;
                else if(visited[i][j] == 1)
                    sol[j] = 1;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += sol[i];
    //printf("%d, %d\n", gn, ans);
    return ans;
}

int main() {
    int test;
    scanf("%d", &test);
    for(int t = 1; t <= test; t++) {
        memset(visited, 0, sizeof(visited));
        memset(endpsol, 0, sizeof(endpsol));
        memset(csol, 0, sizeof(csol));
        memset(psol, 0, sizeof(psol));
        memset(d, 0, sizeof(d));
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &d[i]);
            d[i]--;
        }
        for(int i = 0; i < n; i++) {
            cur = i;
            dfs(i, 1);
            //printf("\n");
        }
        printf("Case #%d: ", t);
        int ans = -1;/*
        for(int i = 0; i < n; i++)
            printf("%d: (%d, %d)\n", i, csol[i], psol[i]);
        printf("\n");
        for(int i = 0; i < n; i++) {
            if(!csol[i])
                continue;
            for(int j = 0; j < n; j++)
                printf("%d", visited[i][j]);
            printf(": %d, %d\n", i, csol[i]);
        }
        printf("\n");
        for(int i = 0; i < n; i++) {
            if(!psol[i])
                continue;
            for(int j = 0; j < n; j++)
                printf("%d", visited[i][j]);
            printf(": %d, %d\n", i, psol[i]);
        }
        printf("\n");*/
        for(int i = 0; i< n; i++)
            ans = max(ans, csol[i]);
        for(int i = 0; i < (1 << (n % 8)); i++)
            ans = max(ans, val(i));
        printf("%d\n", ans);
    }
}
