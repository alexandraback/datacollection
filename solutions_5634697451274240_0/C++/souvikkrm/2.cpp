#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>

#define LL long long
#define vi vector<int>
#define pb push_back
#define sz size
#define all(x) (x).begin(),(x).end()
#define it iterator
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define REPX(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define DEP(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define REX(i,x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end();i++)
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define st string
#define ffo find_first_of
#define su substr
#define vs vector<st>
#define vpii vector<pii >
#define ub upper_bound
#define lb lower_bound
#define mems(x) memset(x,0,sizeof(x))
#define memc(x,y) memcpy(x,y,sizeof(y))
#define cl clear
#define fr front
#define em empty
#define ord(c) (c=='-' ? 0 : 1)
#define MAX 110
using namespace std;
int x[MAX][2]; char s[MAX];
int main()
{
  //pre-compute
  x[1][0]=1; x[1][1]=0;
  REP(i,2,MAX)
  {
    x[i][0]=x[i-1][1]+2;
    x[i][1]=x[i-1][0];
  }
  int tc; cin>>tc;
  REP(t,0,tc)
  {
    cin>>s;
    int n=(int)strlen(s);
    //filter out the extra + & -
    int l=0; char p=s[0];
    REP(i,1,n)
    {
      if(s[i]!=p) { l++; p=s[i]; }
    }
    l++;
    cout<<"Case #"<<t+1<<": "<<x[l][ord(s[n-1])]<<"\n";
  }
  return 0;
}
