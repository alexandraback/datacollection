using namespace std;
#include <cmath>
#include <cstdio>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
typedef long long ll; 
typedef pair<int,int> pii; 
#define FOR(i,n) for (int i = 0; i < n; i++)
#define SZ(x) ((int)x.size())
#define PB push_back
#define MP make_pair
#define sf(x) scanf("%d",&x)
#define pf(x) printf("%d\n",x)
#define split(str) {vs.clear();istringstream ss(str);while(ss>>(str))vs.push_back(str);}
#define PI 3.141592653589793
int main()
{
  int t;
  sf(t);
  int temp = t;
  while(t--)
  {
    int x,y;
    cin>>x>>y;
    string ans = "";
    if(y>0)
    {
      while(y--)
      {
	ans+="SN";
      }
    }
    else
    {
      while(y<0)
      {
	ans+="NS";
	y++;
      }
    }
    
    if(x>0)
    {
      while(x--)
      {
	ans+="WE";
      }
    }
    else
    {
      while(x<0)
      {
	ans+="EW";
	x++;
      }
    }
    printf("Case #%d: ",temp - t);
    cout<<ans<<endl;
  }
  
}