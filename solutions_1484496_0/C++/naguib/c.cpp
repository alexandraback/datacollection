#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cctype>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <iostream>
#include <stack>
#include <sstream>
using namespace std; 
#define PB push_back
#define MP make_pair
#define F first
#define S second 
#define BE(a) a.begin(),a.end() 
#define CLS(a,b) memset(a,b,sizeof(a))
#define SZ(a) ((int)a.size())
const long double pi=acos(-1.0);
#define torad(a) ((a)*pi/180.0)
typedef vector<int> vi ; 
typedef vector<string> vs ; 
typedef vector<double> vd ; 
typedef pair<int,int> pii ; 
typedef long long ll ; 
typedef long double ld ; 
typedef double dl ; 
class node {public:
};
typedef vector<node> vn ; 
int cases,g,n;
char best[21][4000009][2];
int vals[21];
char solve(int p,int d,bool f) {
  if(p==n) {
    if(d==0 && f)return 3;
    return 0;
  }
   char & ret= best[p][d+2000000][f];
   if(ret!=-1)return ret;
   ret=0;
   //don't take
   if(solve(p+1,d,f))return ret=3;
   if(solve(p+1,d+vals[p],1))return ret=1;
   if(solve(p+1,d-vals[p],1))return ret=2;
   return ret=0;
}
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
////////////////////////////////////////////
	int i,j,k;
	scanf("%d",&cases);
	for(g=0;g<cases;g++)
	{
    CLS(best,-1);
		printf("Case #%d:\n",g+1);
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&vals[i]);
    int p=0,d=0;
    bool f=0;
    vi a;
    vi b;
    while(p<n) {
      k=solve(p,d,f);
      if(k==3){
        p++;
        continue;
      }
      if(k==1) {
        f=1;
        d+=vals[p];
        a.push_back(vals[p]);
        p++;
        continue;
      }
       if(k==2) {
        f=1;
        d-=vals[p];
        b.push_back(vals[p]);
        p++;
        continue;
      }
       if(k==0) {
         break;
       }
    }
    if(a.size()) {
      for(i=0;i<a.size();i++)
        printf("%d ",a[i]);
      printf("\n");
      for(i=0;i<b.size();i++)
        printf("%d ",b[i]);
      printf("\n");
    } else {
      printf("Impossible\n");
    }
	}

	return 0;
}