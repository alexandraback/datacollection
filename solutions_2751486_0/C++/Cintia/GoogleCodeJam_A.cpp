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

bool isVowel(char vc){
     if(vc=='a') return true; 
    if(vc=='e') return true;
    if(vc=='i') return true;
    if(vc=='o') return true;
    if(vc=='u') return true;
    return false;
     }

void doit()
 {
  string strL;
  cin>>strL;
  
  int n, nn=0, L=strL.length(), ulti=0;
  cin>>n;
  int resp=0;
  FOR(i, 0, L-1) {         
         if(isVowel(strL[i])) {
                              nn=0;
                              continue;
                              }
         if(nn<n) nn++;
         if(nn==n) {
              resp+=(i+2-ulti-n)*(L-i);
              ulti=i-n+2;
              }    
                  
  }
  cout<<max(resp, 0);
}


int main()
{  
   freopen("A-small-attempt0.in", "r", stdin);  
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
