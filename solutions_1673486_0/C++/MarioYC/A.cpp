#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    int TC;
    
    cin >> TC;
    
    int A,B;
    double p[100000],prod[100001];
    
    for(int tc = 1;tc <= TC;++tc){
        cin >> A >> B;
        
        prod[0] = 1;
        
        for(int i = 0;i < A;++i){
            cin >> p[i];
            prod[i + 1] = prod[i] * p[i];
        }
        
        double ans = 2 + B;
        
        for(int i = 0;i <= A;++i)
            ans = min(ans,prod[A - i] * (B - A + 2 * i + 1) + (1 - prod[A - i]) * (2*B - A + 2*i + 2));
        
        cout << "Case #" << tc << ": " << fixed << setprecision(6) << ans << '\n';
    }
    
    return 0;
}
