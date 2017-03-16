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
#define ord(c) (c-'A')
#define MAX 2010
using namespace std;
char x[MAX]; int c[26],d[10];
char y[][10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int exists(int i)
{
  int n=(int)strlen(y[i]);
  int f=1;
  REP(j,0,n) f&=(c[ord(y[i][j])]>0);
  if(f)
  {
    REP(j,0,n) c[ord(y[i][j])]--;
    return 1;
  }
  return 0;
}
int main()
{
  int tc; cin>>tc;
  REP(t,0,tc)
  {
    cin>>x;
    int n=(int)strlen(x);
    REP(i,0,n) c[ord(x[i])]++;
    while(exists(0)) d[0]++;
    while(exists(6)) d[6]++;
    while(exists(2)) d[2]++;
    while(exists(4)) d[4]++;
    while(exists(3)) d[3]++;
    while(exists(8)) d[8]++;
    while(exists(7)) d[7]++;
    while(exists(5)) d[5]++;
    while(exists(1)) d[1]++;
    while(exists(9)) d[9]++;
    cout<<"Case #"<<t+1<<": ";
    REP(i,0,10) while(d[i]--) cout<<i;
    cout<<"\n";
    //clean-up
    mems(c); mems(d);
  }
  return 0;
}
