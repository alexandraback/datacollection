#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

long long r, t;

bool test(long long k){
    double result = (double)k*(2*(double)r+2*(double)k-1);
    if(result > pow(2.0, 63)-1) return false;
    long long rr = k*(2*r+2*k-1);
    if(rr > t) return false;
    return true;
}

int main(){
    int T;
    int cnt = 0;
    scanf("%d", &T);
    while(T--){
        cin >> r >> t;
        long long up, low, mid;
        up = t;
        low = 0;
        while(up > low+1){
            mid = (up+low)/2;
            if(test(mid)) low = mid;
            else up = mid;
        }
        printf("Case #%d: ", ++cnt);
        cout << low << endl;
    }
    return 0;
}
