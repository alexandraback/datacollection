#include<iostream>
#include<sstream>
using namespace std;

long long gcd(long long x, long long y) {
    if (x < y) {
        return gcd(y, x);
    }
    if(x % y != 0) {
        return gcd(y, x%y);
    } else {
        return y;
    }
}

int main(){
    int T;
    cin>>T;
    
    long long maxElves = 1;
    for (int i = 0; i < 40; ++ i) {
        maxElves *= 2;
    }
    
    for (int xx = 1; xx <= T; ++xx) {
        cout<<"Case #"<<xx<<": ";
        
        long long p;
        long long q;
        
        string input;
        cin>>input;
        int pos = input.find('/');
        string pstring(input, 0, pos);
        string qstring(input, pos+1);
        istringstream pstream(pstring);
        istringstream qstream(qstring);
        pstream>>p;
        qstream>>q;        long long agcd = gcd(p,q);
        p = p / agcd;
        q = q / agcd;
        
        long long mgcd = gcd(q, maxElves);
        if (mgcd != q) {
            cout<<"impossible"<<endl;
            continue;
        }
        
        p = p * (maxElves / q);
        long long t = 1, count = 0;
        while (1) {
            t *= 2;
            if (t <= p) {
                ++ count;
            } else {
                break;
            }
        }
        
        cout<<40 - count<<endl;
    }
}