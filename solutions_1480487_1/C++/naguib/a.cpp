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
int cases,g;
int n;
int judges[300];
int tot =0;
bool check(dl m,int x) {
  dl points = tot*(1-m);
  dl tar = judges[x] + (tot - points);
  for(int i=0;i<n;i++) {
    if(i==x)continue;
    dl req = max(0.0,tar - judges[i]);
    points -= req;
  }
  return points < 0;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
////////////////////////////////////////////
	int i,j,k;
	scanf("%d",&cases);
	for(g=0;g<cases;g++)
	{
		printf("Case #%d: ",g+1);
    scanf("%d",&n);
    tot=0;
    for(i=0;i<n;i++) {
      scanf("%d",&judges[i]);
      tot+=judges[i];
    }
    for(i=0;i<n;i++) {
      dl s=0,m,e=1;
      for(k=0;k<100;k++) {
        m=(s+e)/2;
        if(check(m,i)) {
          e=m;
        } else {
          s=m;
        }
      }
      printf("%lf ",m*100);
    }
    printf("\n");
	}

	return 0;
}