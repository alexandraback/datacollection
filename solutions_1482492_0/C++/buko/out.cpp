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
const int N = 2005;

int q,n,A,i,z;
double d,t[N],x[N],a,g,g2;

int main () {
scanf("%d",&z);
for (q=1;q<=z;q++) {
    printf("Case #%d:\n",q);
    scanf ("%lf %d %d",&d,&n,&A);
    for (i=0;i<n;i++) scanf ("%lf %lf",&t[i],&x[i]);
    if (n==1 || x[0]>d) g=0.0;
    else g = t[1]*(d-x[0])/(x[1]-x[0]);
    //printf(" %.7lf\n",g);
    while (A--) {
          scanf ("%lf",&a);
          g2 = sqrt(2*d/a);
          printf("%.7lf\n",max(g,g2));
    }
}
return 0;
}
