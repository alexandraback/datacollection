#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<utility>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<map>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

#define openfile {freopen("test.txt","r",stdin);}
#define closefile {freopen("res.txt","w",stdout);}

using namespace std;

typedef long long ll;
typedef pair<int,int> pint;

template <class T> inline T abs(T x) { if (x < 0) return -x; return x; }

const int maxn = 100 + 10;

int nTest,n,m;
string res;
int a[maxn][maxn];
bool b[maxn][maxn];

int main() {

    openfile
    closefile

    scanf("%d",&nTest);
    for(int test=0; test<nTest; test++) {
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
           for(int j=0; j<m; j++) {
                scanf("%d",&a[i][j]);
                b[i][j] = true;
           }

        int w,h;
        for(int i=0; i<n; i++)
          for(int j=0; j<m; j++) {

            w = a[i][j];
            h = a[i][j];

            for(int k=0; k<n; k++) if (a[k][j] > h) h = a[k][j];
            for(int k=0; k<m; k++) if (a[i][k] > w) w = a[i][k];

            if (w > a[i][j] && h > a[i][j]) {
                b[i][j] = false;
            }
          }

        res = "YES";
        for(int i=0; i<n; i++)
          for(int j=0; j<m; j++) if (b[i][j] == false) {
                res = "NO";
          }

        cout <<"Case #" << test+1 << ": " << res << endl;
    }

	return 0;
}
