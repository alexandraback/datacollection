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
#include<ctime>
#include<iomanip>
#include<fstream>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair <int,int> ii;
typedef long long LL;
#define sz(a) int((a).size())
#define pb push_back
const int INF = 2147483647;
const double PI = 3.141592653589793;
const int N = 105;

int z,n,m,i,j,A[N],B[N],w1,w2,q;
LL a[N],b[N],res[N][N],r,maxx,g,d,s;

int main () {
scanf("%d",&z);
for (q=1;q<=z;q++) {
    scanf ("%d %d",&n,&m);
    for (i=0;i<n;i++) cin >> a[i] >> A[i];
    for (i=0;i<m;i++) cin >> b[i] >> B[i];
    for (i=0;i<=max(n,m);i++) res[i][m]=res[n][i]=0;
    for (i=n-1;i>=0;i--) for (j=m-1;j>=0;j--) {
        if (A[i]!=B[j]) res[i][j]=max(res[i+1][j],res[i][j+1]);
        else {
             w1=i; w2=j; r=0; maxx=0; g=a[w1]; d=b[w2];
             while (w1<n && w2<m && g!=d) {
                   s=min(g,d); r+=s; g-=s; d-=s;
                   maxx=max(maxx,r+res[w1+1][w2+1]);
                   if (g==0) {
                      w1++;
                      while(w1<n && A[w1]!=A[i]) w1++;
                      if (w1<n) g=a[w1];
                   }
                   else {
                      w2++;
                      while(w2<m && B[w2]!=B[j]) w2++;
                      if (w2<m) d=b[w2];
                   }
             }
             if (w1<n && w2<m) {
                r+=g;
                maxx=max(maxx,r+res[w1+1][w2+1]);
             }
             res[i][j]=maxx; 
        }
    }
    cout << "Case #" << q << ": " << res[0][0] << endl;
}
return 0;
}
