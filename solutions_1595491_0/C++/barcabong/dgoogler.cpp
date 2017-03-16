#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>
#include <fstream>


using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                        
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }


int main(int argc, char *argv[]){
int t,d,x=1,a[105],n,s,p,p1;
int count=0;
int maybe;
string g="";
ifstream in(argv[1],ios::in);
ofstream op("output.txt",ios::out);
in>>t;
while(t>0){
  getline(in,g);
  in>>n;
  in>>s;
  in>>p;
  count=0;maybe=0;
  p1=3*p;
  for(int i=0;i<n;i++)
     in>>a[i];
  
  for(int i=0;i<n;i++)
  {
    if(p==0){
     count++;
     continue;
    }
    else if(a[i]>=p1)
    {
      count++;
      continue;
    }
    else if(a[i]<p)
    {
      continue;
    }
    else
    {
      d=p1-a[i];
      if(d==1||d==2)
	count++;
      else if(d==3||d==4)
      	maybe++;
    }
  }
  if(maybe<=s)
    count+=maybe;
  else
    count+=s;
  op<<"Case #"<<x<<": "<<count<<endl;
  x++;t--;
}
in.close();
op.close();
return 0;
}