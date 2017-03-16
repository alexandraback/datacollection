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

double d; int n;int m;
double xx[3000],t[3000];

double solve(double a) {
  if(n==1 || xx[0]>=d )
    return sqrt(2*d/a);
  double xcur=0;
  double vcur=0;
  double tcur=0;
  double time,vmax,xnew;
  rp(i,n-1) {
    time =t[i+1]-t[i];
    vmax=(xx[i+1]-xx[i])/time;
    xnew = xcur + vcur*(t[i+1]-tcur) + a*(t[i+1]-tcur)*(t[i+1]-tcur)/2;
    if (xnew>xx[i+1]) {
      xcur=xx[i+1];
      vcur=vmax;
      tcur=t[i+1];
    }
  }
  return tcur+
    (-vcur+sqrt(vcur*vcur+2*a*(d-xcur))) / a;
}

int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

	for(int tst=1;tst<=tstCnt;tst++)
	{
    
    cin>>d>>n>>m;
    rp(i,n) {
      cin>>t[i]>>xx[i];
    }
    printf("Case #%d:\n",tst);
    if(n==1 || xx[0]>=d )
        rp(i,m) {
          double a;
          cin>>a;
          printf("%lf\n",solve(a));
        }
    else {
        while(xx[n-2]>=d)
            --n;
        t[n-1] = t[n-2]+(t[n-1]-t[n-2])*(d-xx[n-2])/(xx[n-1]-xx[n-2]);
        xx[n-1] = d;
        rp(i,m) {
          double a;
          cin>>a;
          printf("%lf\n",solve(a));
        }
    }

		//printf("Case #%d: ",tst);
	}
	
	return 0;
}