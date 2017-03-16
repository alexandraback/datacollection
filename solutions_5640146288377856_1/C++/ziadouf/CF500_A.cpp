#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <string.h>
#include <numeric>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long ll;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define INF 1000000000000000LL
#define EPS 1e-5

int solve (int col , int C , int W)
{
	if (col == 0) return W;
	if (col == C-1) return W;
	return W+1;
}

int main() {
    freopen ("txt.in","r",stdin);
    freopen ("txt.out","w",stdout);

    int TC;
    cin >> TC;
    int CC = 1;
    while (TC--)
    {

    	int R,C,W;
    	cin >> R >> C >> W;
    	printf("Case #%d: ",CC++);

    	int ret = 0;
    	int cnt = -1;
    	for (int i=W-1 ; i<C ; i+=W)
    	{
    		cnt ++;
    		ret = max(ret, cnt + solve(i,C,W));
//    		cout << cnt << " " << solve(i,C,W) << endl;
    	}
//    	cout << ret << endl;

    	cout << (R-1)*C + ret << endl;
    }
}
