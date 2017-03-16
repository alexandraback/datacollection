
#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
int solve2(int maxn){
    int ans = 0;
    for(int i=0 ;i<(int)a.size(); i++){
        ans += (a[i]-1) / maxn;
    }
    return ans + maxn;
}
void solve(int icase){
    int n;
    cin >>n;
    a.clear();
    for(int i=0; i<n; i++){
        int q;
        cin >> q;
        a.push_back(q);
    }
    int ans = 10000;
    for(int i=1; i<=1000; i++){
        ans = min(ans, solve2(i));
    }
    printf("Case #%d: %d\n", icase,  ans);

}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        solve(i+1);

    }

}
