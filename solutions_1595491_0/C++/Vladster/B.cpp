#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define INP_FILE "B-small-attempt0.in"
#define OUT_FILE "output.txt"

#define rp(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define L(s) (int)s.size()
#define mp make_pair
#define pii pair<int,int>
#define x first 
#define y second
#define inf 1000000000
#define VI vector<int>
#define ll long long
#define all(s) (s).begin(),(s).end()
#define C(u) memset((u),0,sizeof((u)))
#define ull unsigned ll
#define uint unsigned int


int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

	for(int tst=1;tst<=tstCnt;tst++)
	{
    int n, s, p;
    int t;
    bool pos[200][200]; C(pos); pos[0][0] = true;
    int ans[200][200]; C(ans);
    cin >> n >> s >> p;
    for(int i = 1; i <= n; ++i) {
      cin >> t;
      int b1 = ((t + 2) / 3) >= p;
      int b2 = ((t + 4) / 3) >= p;
      pos[i][0]=true;
      ans[i][0]=ans[i-1][0]+b1;
      for(int j=1;j<=s;++j) {
        pos[i][j] = pos[i-1][j] || (pos[i-1][j-1] && abs(t-15)<14);
        if (abs(t-15)<14) {
          if (pos[i-1][j] && pos[i-1][j-1])
            ans[i][j] = max(ans[i-1][j]+b1,ans[i-1][j-1]+b2);
          else 
            ans[i][j] = ans[i-1][j-1]+b2;
        } else {
          ans[i][j] = ans[i-1][j]+b1;
        }
      }
    }
		printf("Case #%d: %d\n",tst,ans[n][s]);
	}
	
	return 0;
}