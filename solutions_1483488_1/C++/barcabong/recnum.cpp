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

inline int num_digits(int i){
  
    if(1<=i && i<=9)
      return 1;
    if(10<=i && i<=99)
      return 2;
    if(100<=i && i<=999)
      return 3;
    if(1000<=i && i<=9999)
      return 4;
    if(10000<=i && i<=99999)
      return 5;
    if(100000<=i && i<=999999)
      return 6;
    if(1000000<=i && i<=9999999)
      return 7;
}

inline int rotate(int i,int j){
  int m=1,a,b;
  for(int k=1;k<=j;k++)
      m=m*10;
  a=i/m;
  b=i%m;
  m=1;
  for(int k=1;k<=num_digits(a);k++)
      m=m*10;
   return (b*m+a);
}

int main(int argc, char *argv[]){
int t,x=1,a,b,n,l;
ll count=0;
int check[2000001];
ifstream in(argv[1],ios::in);
ofstream op("output.txt",ios::out);
in>>t;
while(t>0){
  in>>a;
  in>>b;
  count=0;
  for(int i=a;i<=b;i++)
     check[i]=1;
  for(int i=a;i<=b;i++)
  {
    if(num_digits(i)==1)
	continue;
    if(check[i]==0)
	continue;
    check[i]=0;  n=1;
    for(int j=1;j<=num_digits(i);j++)
    {
      l=rotate(i,j);
      if(l<a||l>b)
	continue;
      if(check[l]==0)
	continue;
      if(num_digits(i)==num_digits(l))
      {
	check[l]=0;
	n++;
      }
     }
     if(n>1)
       count+=n*(n-1)/2;
  }
  op<<"Case #"<<x<<": "<<count<<endl;
  x++;t--;
}
in.close();
op.close();
return 0;
}