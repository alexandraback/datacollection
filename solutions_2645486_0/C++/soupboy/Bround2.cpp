#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <string.h>
 
#define repx(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repx(i,0,n)
#define pb push_back
#define full(v)  v.begin(),v.end()
#define np next_permutation
#define VI vector<int>
#define VS vector<string>
#define VC vector<char>
#define VD vector<double>
#define VF vector<float>
#define SI set<int>
#define SC set<char>
#define SS set<string>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MIC map<int,char>
#define MCI map<char,int>
#define LL long long
using namespace std;
int e,r,n;
VI v;

int calc(int pos ,int having)
{
 
 int ret = -1;
 if(pos == n)
  return 0;
 rep(i,having+1)
 {
   ret = max(ret , calc(pos+1,min((having-i+r) , e))+(i*v[pos]));
 }
 return ret;
}

int main()
{
    ofstream cout ("bbig.out");
    ifstream cin ("bsmall.in");
    int test,cas;
    cin>>test;
    cas = 0;
    while(test-- && ++cas)
    {
     v.clear();
     cin>>e>>r>>n;
     rep(i,n)
     {
     int temp;
     cin>>temp;
     v.pb(temp);
     }
     cout<<"Case #"<<cas<<": "<<calc(0,e)<<"\n";
    }
return 0;
}
