#include <iostream>
using namespace std;

void solve()
{
    int n,m,k;
    cin >> n>> m >> k;
    int ans = (n-1) *m / k;
    if (m % k == 0){
        ans = ans + m / k + k - 1;
    }else
    {
        ans = ans + m / k +  k;
    } 
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #"<<i<<": ";
        solve();
    } 
    return 0;
}
