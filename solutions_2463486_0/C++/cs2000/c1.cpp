#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
using namespace std;  
struct swing{
	long long p,l;
    bool operator<(const swing ext) const{
    return (p<ext.p);
    }
};
bool check(long long x){
     string s="";
     long long y=x;
     while (y>0){
        s=char(y % 10 + 48) + s;
        y=y/10;   
     }
     for (int j=0; j<s.length(); ++j){
         if (s[j]!=s[s.length()-1-j])
            return false;
     }
     return true;
}
long long num[1000];
long n;
int main(){
    long long k,i;
    n=0;
    for (i=1; i<=2001002; ++i){
        if (i % 10 ==1 || i % 10 ==2 || i==3){
        if (check(i)){
           k=i*i;
           if (check(k)){
              num[n]=k;
              n++;
              //cout<<i<<" "<<k<<endl;
           }
        }
        }
    }
    int z,t,x,y;
    cin>>t;
    long long a,b;
    for (z=1; z<=t; ++z){
        cin>>a>>b;
        x=n;
        y=n-1;
        for (long j=0; j<n; ++j){
            if (num[j]>=a){
               x=j;
               break;
            }
        }
        for (long j=0; j<n; ++j){
            if (num[j]>b){
               y=j-1;
               break;
            }
        }
        cout<<"Case #"<<z<<": "<<y-x+1<<endl;
    }
    return 0;
}
