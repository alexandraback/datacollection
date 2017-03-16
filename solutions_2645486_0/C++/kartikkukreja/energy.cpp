#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <bitset>
#include <climits>
#include <stack>
#include <cctype>
#include <sstream>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int E, N, v[15], rem[15], R;

int utility(int p)  {
    int mx = -1, tmp;
    if(p == N-1) return rem[p]*v[p];
    if(p >= N) return 0;
    for(int i=0; i<=rem[p]; i++)    {
        rem[p+1] = min(rem[p] - i + R, E);
        tmp = i*v[p] + utility(p+1);
        if(tmp > mx) mx = tmp;
    }
    return mx;
}

int main()	{
    int T, i, j;

	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small.txt", "w", stdout);

	scanf("%d", &T);
	for(i=1; i<=T; i++) {
        scanf("%d %d %d", &E, &R, &N);
        for(j=0; j<N; j++)
            scanf("%d", &v[j]);
        rem[0] = E;
        printf("Case #%d: %d\n", i, utility(0));
	}

	return 0;
}
