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

#define INP_FILE "C-small-attempt0.in"
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

bool s[2100000];
int p[2100000];
bool xfind(vector<int>&x,int t)
{
  for(int i=0;i<x.size();++i)
    if(x[i]==t)
      return true;
  return false;
}
int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

	for(int tst=1;tst<=tstCnt;tst++)
	{
    int n; cin>>n;
    int a[21];
    
    for(int i=0;i<n;++i) cin>>a[i];
    C(s);
    C(p);
    s[0]=true;
    int sum;
    bool win=false;
    int jj=0;
    int ii=0;
    for(int i=0;i<n;++i) {
      for(int j=2000010;j>=0;--j) {
        if(s[j]) {
          sum=j+a[i];
          if (s[sum]) {
            win=true;
            jj=j;
            ii=i;
            break;
          }else{
            s[sum]=true;
            p[sum]=j;
          }
        }
      }
      if(win) break;
    }
    if(win) {
      printf("Case #%d:\n",tst);
      int cur;
      vector<int> x;
      vector<int> y;
      cur=sum;
      while(cur>0){
        x.push_back(cur-p[cur]);
        cur=p[cur];
      }
      y.push_back(a[ii]);
      cur=jj;
      while(cur>0){
        y.push_back(cur-p[cur]);
        cur=p[cur];
      }
      for(int i=0;i<x.size();++i)
        if(!xfind(y,x[i]))
          printf(" %d",x[i]);
      printf("\n");
      for(int i=0;i<y.size();++i)
        if(!xfind(x,y[i]))
          printf(" %d",y[i]);
      printf("\n");

    }else{
      printf("Case #%d: Impossible\n",tst);
    }
    
		//printf("Case #%d: ",tst);
	}
	
	return 0;
}