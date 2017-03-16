
#include <iostream>
using namespace std;
void solve(int icase){
    int n;
    string str;
    cin >> n >> str;
    int cur = 0;
    int ans = 0;
    for(int i=0; i<=n; i++){
        if( i > cur){
            ans += i - cur;
            cur = i;
        }
        cur += str[i] - '0';
    }
    printf("Case #%d: %d\n", icase, ans);
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        solve(i+1);

    }

}
