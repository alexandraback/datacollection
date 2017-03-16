#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <string>
#include <set>
#include <bitset>

using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int,int> pi;
#define MOD 1000000007
#define MAX 1000000000
#define For(i,n) for(int i=0;i<n;i++) 

int d1,d2;
int s1,s2;
int main()
{
int _t;
cin>>_t;
for(int _i=1;_i<=_t;_i++)
{
 int n;
 cin>>n;
 for(int i=0;i<n;i++)
 {
  int deg,a,b;
  cin>>deg>>a>>b;
  if(i==0&&a==1)
  {
   d1=deg;
   s1=b;
  }
  else if(a==1)
  {
   d2=deg;
   s2=b;
  }
  else
  {
   d1=d2=deg;
   s1=b;
   s2=b+1;
  } 
 }
int ans=0;
if(s2==0) {ans=0;}
else 
{
 if(s1==s2){ans=0;}
 else if(s1>s2)
 {
 long long int x=720-d1;
  long long int y=360-d2;
  float tx=x/s1;
  float ty=y/s2;
  if(x*s2<=y*s1){ans=1;}
 }
 else
 {
 long long int x=720-d2;
 long long int y=360-d1;
  float tx=(float)x/s2;
  float ty=y/s1;
  if(x*s1<=y*s2){ans=1;}
 }     
}
cout<<"Case #"<<_i<<": "<<ans<<endl;
}


}    


