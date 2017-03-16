#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set> 
#include<cstdlib>
#include<cmath>
#include<string> 
#include<sstream>
#include<queue>
#include<stack>
#include<list>

using namespace std; 

bool check(long long  p){
    while(p%2 == 0)
        p = p/2; 
    if(p == 1)
        return true; 
    else 
        return false;
}

long long gcd(long long a, long long b){
    if(b == 0)
        return a; 
    return gcd(b,a%b);
}

int main(){
    int T; 
    cin >> T; 
    for(int t = 1; t <= T; t++){
        long long  p,q; 
        char c ; 
        cin >> p >> c  >> q;
        int g = 1; 
        cout << "Case #" << t << ": "; 
        long long gab = gcd(p,q); 
        p /= gab; 
        q /= gab; 
        if(check(q) == false){
            cout << "impossible" << endl;
        }else{
        while(true){
            if(2*p >= q){
                break;     
            }
            g++; 
            p *= 2; 
        }
        cout << g << endl;
        }
    }
}
