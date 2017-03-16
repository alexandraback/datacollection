#include <iostream>  
#include <cstdio>  
#include <fstream> 
#include <map> 
using namespace std;  

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
map<long long, int> mp;
const long long MAX_N = 1000000000000LL;

void init() {
    int num = 1;
    for (long long i = 2; i <= MAX_N; i *= 2) {
        mp[i] = num++;
    }
}

int main()  
{  
    //ifstream cin("D:\\A-large.in");  
    //freopen("D:\\A-large","w",stdout); 
    init(); 
    int k;  
    cin >> k;   
    for(int times = 1; times <= k; times++)  
    {  
        printf("Case #%d: ", times);
        long long P, Q;
        char ch;
        cin >> P >> ch >> Q;
        long long temp = gcd(P, Q);
        P /= temp;
        Q /= temp;
        if (mp.find(Q) == mp.end()) {
            cout << "impossible" << endl;
            continue;
        }
        int ans = 0;
        while(P < Q) {
            Q /= 2;
            ans++;
        }
        cout << ans << endl;
    }  
}  
