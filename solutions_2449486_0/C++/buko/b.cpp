#include<cstdio>
#include<iostream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<iomanip>
#include<fstream>
#include<ctime>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;
const int N = 105;

int n,m,maxRow[N],maxCol[N],tab[N][N],i,j,ok,z,q;

int main() {
scanf("%d",&z);
for (q=1;q<=z;q++) {
    scanf("%d %d",&n,&m);
    for (i=0;i<n;i++) maxRow[i]=0;
    for (i=0;i<m;i++) maxCol[i]=0;
    for (i=0;i<n;i++) for (j=0;j<m;j++) {
        scanf("%d",&tab[i][j]);
        maxRow[i]=max(maxRow[i],tab[i][j]);
        maxCol[j]=max(maxCol[j],tab[i][j]);
    }
    ok = 1;
    for (i=0;i<n;i++) for (j=0;j<m;j++) if (tab[i][j] < maxRow[i] && tab[i][j] < maxCol[j]) ok = 0;
    if (ok) printf("Case #%d: YES\n",q); else printf("Case #%d: NO\n",q);
}
return 0;
}
