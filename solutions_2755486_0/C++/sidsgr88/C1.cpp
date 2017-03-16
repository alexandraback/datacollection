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
typedef struct node
{
int di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
} node;
int main()
{
  int t;
  sf(t);
  int temp = t;
  while(t--)
  {
    vector<int> h(2000,0);
    vector<int> h1(2000,0);
    ll ans = 0;
    int n;
    cin>>n;
    node v[n];
    FOR(i,n)
    {
      cin>>v[i].di>>v[i].ni>>v[i].wi>>v[i].ei>>v[i].si>>v[i].delta_di>>v[i].delta_pi>>v[i].delta_si;
    }
    priority_queue<pair<int,pair<int,pair<int,int> > > > q; //day,strength,west east
    FOR(i,n)
    {
      FOR(j,v[i].ni)
      {
	q.push(MP(-(v[i].di+j*v[i].delta_di),MP(v[i].si+j*v[i].delta_si,MP(v[i].wi+j*v[i].delta_pi,v[i].ei+j*v[i].delta_pi))));
      }
    }
    while(!q.empty())
    {
      vector<pair<int,pair<int,pair<int,int> > > > day;
      int per = q.top().first;
      
      while(!q.empty() && q.top().first == per)
      {
	pair<int,pair<int,int> > p = q.top().second;
	day.PB(q.top());
	q.pop();
	for(int i = p.second.first + 1000; i <= p.second.second + 1000; i++)
	{
	  if(h[i]<p.first)
	  {
	    //cout<<p.first<<" "<<i<<endl;
	    ans++;
	    break;
	  }
	  else if(i != p.second.second + 1000 && h1[i]<p.first)
	  {
	    ans++;
	    break;
	  }
	}
      }
      
      FOR(i,day.size())
      {
	pair<int,pair<int,int> > p = day[i].second;
	for(int i = p.second.first + 1000; i <= p.second.second + 1000; i++)
	{
	  h[i] = max(h[i],p.first);
	  if(i != p.second.second + 1000)
	    h1[i] = max(h1[i],p.first);
	}
      }
    }
    printf("Case #%d: %lld\n",temp - t, ans);
  }
}