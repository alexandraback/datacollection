#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <sstream>
#include <Windows.h>
#include <iomanip>
#include <list>

using namespace std;

#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long

bool fcmp(int a, int b) {
  return a < b;
}

void doit()
 {
  int x, y;
  cin>>x>>y;
  int i=1;
  while(x!=0 || y!=0) {
     if(x!=0 && abs(abs(x)-i)<abs(abs(y)-i)) {
                  if((x<0 && abs(x)>=i) || (x>0 && abs(x)<i)) { cout<<"W";
                            x+=i; }
                  else { cout<<"E";
                            x-=i; }
                 }
     else {
                  if((y<0 && abs(y)>=i) || (y>0 && abs(y)<i)) { cout<<"S";
                            y+=i; }
                  else { cout<<"N";
                            y-=i; }
                 }
     
            
     i++;     
  } 
 
}


int main()
{  
   freopen("B-small-attempt0.in", "r", stdin);  
   //freopen("practice.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
    
   int T;
   cin>>T;
   
   for ( int i = 0; i < T; i++ )
   {
     cout<<"Case #"<<i+1<<": ";
     doit();
     cout<<endl;
   }

   return 0;
}
