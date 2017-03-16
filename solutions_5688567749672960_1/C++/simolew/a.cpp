#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cstring>
#include<cstdint>
#include<cstdlib>
#include<sstream>
using namespace std;
const int64_t MX = 1LL<<62;
int64_t reverse(int64_t num) {
    int64_t ans=0;
    while(num > 0) {
        ans = ans * 10;
        ans += num % 10;
        num /= 10;
    }
    return ans;
}

int64_t pw(int64_t a, int64_t b) {
    int64_t l=1;
    for(int64_t i=0;i<b;i++) l*=a;
    return l;
}


int64_t toll(string s) {
    stringstream ss(s);
    int64_t num;
    ss>>num;
    return num;
}

int64_t tr(int64_t num, int64_t base, int64_t count, int64_t diff) {
    string s = to_string(num);
    int64_t x = 0;
    for(int64_t i=0;i<count;i++) {
        x*=10;
        x+=s[i]-'0';
    }
    x += diff;


    int64_t step = reverse(x);
    int64_t a = base + reverse(x);
    a = reverse(a);
    if(a > num) return MX;
    
    return num - a + step + 1;

//    return num - reverse((base + reverse(x))) + step+1;

}


int64_t g(int64_t num) {
    if(num == 1) return 10;
    
    string s = to_string(num);
    int64_t digits = s.length();
    int64_t half = pow(10,digits/2)-1;
    int64_t b = reverse(num+half);
    half += num*10 - b;
    return half + 1 + g(num/10);

}


int64_t f() {
    string ns;
    cin>>ns;
    int64_t n = toll(ns);

    if( n <= 10) return n;



    int64_t digits = ns.length();


    int64_t base = pw(10,digits-2);
    
    int64_t step = g(base);
    
    
    
    int64_t ans = n - base*10;

    if(ns[digits-1]=='0') {
        int64_t best = ans;
        for(int64_t i=1;i<digits;i++) {
            best = min(best, tr(n,base*10,i,0));
            best = min(best, tr(n,base*10,i,-1));
        }
        return best + step;
    }

    int64_t split = digits/2;
    

    int64_t number1=0;
    int64_t number2=0;
    for(int64_t i=split-1;i>=0;i--) {
        number1*=10;
        number1+=ns[i]-'0';
    }

    for(int64_t i=split;i<digits;i++) {
        number2*=10;
        number2+=ns[i]-'0';
    }
    
    ans = min(ans, number1+number2);
    return step+ans;


}

int main() {
    int64_t T;

 //   for(int64_t i=1;i<10;i++) {
 //       cout<<pw(10,i)<<": "<<g(pw(10,i))<<endl;
 //   }

    cin>>T;
    for(int64_t i=1;i<=T;i++) {
        cout<<"Case #"<<i<<": ";
        cout<<f();
        cout<<endl;
    }
}
