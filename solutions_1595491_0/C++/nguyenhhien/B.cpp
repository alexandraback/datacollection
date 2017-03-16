#include <iostream>
#include <sstream> 
#include <cstdio>
#include <istream>
#include <string>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <cmath>
 
using namespace std;

int n, s, p;
int cnt1; //both;
int cnt2; //suprising only;

int type(int x){
    if(x%3==0){
               if(x/3>=p)  return 1;
               else if(x/3>0 && x/3+1>=p) return 2;
    }
    else if(x%3==1){
         if(x/3+1>=p)        return 1;          
    }
    else{
         if(x/3+1 >=p)       return 1;
         else if(x/3+2>=p)   return 2;
    }
    
    return 0;
}
int main(){
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int sotest;           cin>>sotest;
    for(int run=1; run<=sotest; run++){
            cout << "Case #" << run <<": ";
            
            cin >> n >> s >> p;
            cnt1=0, cnt2=0;
            for(int i=0; i<n; i++){
                    int tmp;  cin>>tmp;
                    if(type(tmp)==1)   ++cnt1;
                    else if(type(tmp)==2)     ++cnt2;
            }
            
            int res = cnt1 + min(cnt2, s);
            cout << res << endl;
    }
    
    return 0;
}
