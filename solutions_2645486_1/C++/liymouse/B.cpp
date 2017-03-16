#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

typedef long long i64d;

using namespace std;

int cmp(pair<int , int> &x , pair<int , int> &y)
{
    if (x.first == y.first) return x.second < y.second;
    else return x.first > y.first;
}
int main()
{
	freopen("B-large.in" , "r" , stdin);
	freopen("B-large.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int e , r;
        int n;
        int v[20000];
        scanf("%d %d %d" , &e , &r , &n);
        for (int i = 0; i < n; i ++) scanf("%d" , &v[i]);
        i64d res = 0;
        if (r >= e)
        {
            for (int i = 0; i < n; i ++) res += v[i] * e;
        }
        else
        {
            vector<pair<int , int> > a;
            for (int i = 0; i < n; i ++) a.push_back(make_pair(v[i] , i));
            sort(a.begin() , a.end() , cmp);
            int re = e / r;
            if (e % r != 0) re ++;
            int b[20000] , maxc[20000] , minc[20000] , left[20000];
            for (int i = 0; i < n; i ++) {b[i] = -1; maxc[i] = e; minc[i] = 0; left[i] = e;}
            for (int i = 0; i < n; i ++)
            {
                int have = 0;
                int id = a[i].second;
                b[id] = maxc[id] - minc[id];
                minc[id] = maxc[id];
                left[id] = maxc[id] - b[id];
                for (int j = id-1; j >= max(0 , id-re); j --)
                {
                    minc[j] = max(minc[j] , minc[id]-(id-j)*r);
                }
                for (int j = id+1; j <= min(n-1 , id+re); j ++)
                {
                    maxc[j] = min(maxc[j] , left[id] + (j-id)*r);
                }
            }
            for (int i = 0; i < n; i ++)
                if (b[i] == -1) b[i] = 0;
            for (int i = 0; i < n; i ++) res += (i64d)b[i] * (i64d)v[i];
        }
        printf("%lld\n" , res);
    }
    return 0;
}