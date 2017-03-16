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
bool notvo ( char a)
{
  //cout<<a<<endl;
  if(a == 'a' || a== 'i' || a=='e' || a=='o' || a=='u')
    return false;
  return true;
}
int main()
{
  int t;
  sf(t);
  int temp = t;
  while(t--)
  {
    string s;
    cin>>s;
    int n;
    cin>>n;
    ll ans = 0;
    int beg = 0;
    int end = -1;
    int cons = 0;
    while(beg < s.size())
    {
      while(cons < n && end+1 != s.size())
      {	
	if(notvo(s[end+1]))
	{
	  cons++;
	  end++;
	}
	else
	{
	  cons = 0;
	  end++;
	}
      }
      if(cons == n)
      {
	//cout<<"beg"<<endl;
	ans += s.size()-end;
	if(notvo(s[beg]) && end-beg + 1 == n)
	{
	  beg++;
	  cons--;
	}
	else
	{
	  beg++;
	}
      }
      else
	break;
      
    }
    printf("Case #%d: %lld\n",temp - t, ans);
  }
}