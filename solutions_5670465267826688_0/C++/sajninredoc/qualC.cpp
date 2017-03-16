#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;


int mult(int a, int b){
    if(a>=4) return mult(a-4, (b+4)%8);
    if(b>=4) return (4+mult(a, b-4))%8;
    if(a==0) return b;
    if(b==0) return a;
    if(a==b) return 4;
    if(a==1){
        if(b==2) return 3;
        if(b==3) return 6;
    }
    if(a==2){
        if(b==1) return 7;
        if(b==3) return 1;
    }
    if(a==3){
        if(b==1) return 2;
        if(b==2) return 5;
    }
    return -1;
}

int fpow(int a, ll e){
    if(e==0) return 0;
    int halfpow = fpow(a, e/2);
    int ans = mult(halfpow, halfpow);
    if(e%2==0) return ans;
    else return mult(ans, a);
}

int main(){
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int L;
        ll X;
        cin >> L >> X;
        
        string S;
        cin >> S;
        
        
        string ans;
        
        int val = 0;
        for(int i=0;i<L;i++) val = mult(val, S[i]-'h');
        val = fpow(val, X);
        
        
        
        if(val!=4){
            ans = "NO";
        }else{
            int firstI = 0;
            int cur = 0;
            while(cur!=1 && firstI <5*L){
                cur = mult(cur, S[firstI%L]-'h');
                firstI++;
            }
            
            int firstK = 0;
            cur = 0;
            while(cur!=3 && firstK < 5*L){
                cur = mult(S[(6*L-1-firstK)%L], cur);
                firstK++;
            }
            
            if(firstI + firstK >= X*L || firstI == 5*L || firstK == 5*L){
                ans = "NO";
            }else{
                ans = "YES";
            }
        }

        
        cout << "Case #" << t << ": " << ans << endl;    
    }

    return 0;
}