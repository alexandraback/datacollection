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

int a, b;

int count(int n){
    set<int> se; se.clear();
    
    int ans = 0;
    
    int cnt=0;
    int mu = 1;
    while(mu <=n/10){
             cnt++;
             mu = mu*10;
    }
    
    int next=n;
    for(int i=1; i<=cnt; i++){
            
            next = next/10 + (next%10 * mu);
            
            if(next > n && next <= b && se.find(next) == se.end()){
                    ++ans;
                    se.insert(next);
            }
            
    }

    return ans;
}
int main(){
    //freopen("input.txt", "r", stdin);
    freopen("C-small-attempt0.in", "r", stdin);
    //freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int sotest;           cin>>sotest;
    for(int run=1; run<=sotest; run++){
            cout << "Case #" << run <<": ";
            cin >> a >> b;  
            
            int res = 0;
            for(int i=a; i<b; i++){
                    res += count(i);
            }
             
            cout << res << endl;
    }
    
    return 0;
}
