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
double pi = 3.14159265;
    
double calc(double a)
{
       return (2*a+1);
}
int main()
{
    ofstream cout ("abig.out");
   ifstream cin ("asmall.in");
    int test,cas;
    cin>>test;
    cas = 0;
    while(test-- && ++cas)
    {
     double r,t;
     cin>>r>>t;
     LL ret =0;
     t-=calc(r);
     if(t>=0.00)
      ret++;
     for(long long int i=2;t>=0;i+=2)
     {
        
              t-=calc(r+i);
             if(t>=0.00)
               ret++;
     }
     
    cout<<"Case #"<<cas<<": "<<ret<<"\n";
    
    }
    return 0;
}
