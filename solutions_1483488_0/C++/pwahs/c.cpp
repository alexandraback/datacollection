#include<iostream>

using namespace std;

int solve(){
    int a,b;
    cin >> a >> b;
    int count=0;
    int d=1,n,m;
    while (10*d<=a) d*=10;
    for(n=a;n<b;n++){
        m=(n%d)*10+n/d;
        while (m!=n){
            if (m>n && m<=b) count++;
            m=(m%d)*10+m/d;
        }
    }
    return count;
}

int main(){
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        cout << "Case #" << i << ": " << solve() << "\n";
    }
    return 0;
}
