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

#define INP_FILE "A-large.in"
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
    int n; cin>>n;
    double sum=0;
    double a[300];
    double b[300];
    for(int i=0;i<n;++i) {cin>>a[i];b[i]=a[i];sum+=a[i];}
    double tot=sum;
    sort(b,b+n);
    double border=0;
    for(int i=0;i<n;++i) {
      sum+=b[i];
      if(sum>b[i]*(i+1))
        border=sum/(tot*(i+1));
    }
    printf("Case #%d:",tst);
    for(int i=0;i<n;++i) { 
      double s=100*(border-a[i]/tot);
      if (s<0) s=0;
      printf(" %lf",s ); }
    printf("\n");

		//printf("Case #%d: ",tst);
	}
	
	return 0;
}