#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int N, J, T;
    cin >> T >> N >> J;
    cout << "Case #1:\n";
    for(unsigned int i=1;J>0;i+=2,--J){
        for(int j=0;j<N/2;++j)cout << ((i&(1<<j))>>j);
        for(int j=N/2-1;j>=0;--j)cout << ((i&(1<<j))>>j);
        for(int i=2;i<=10;++i) cout << " " << i+1;
        cout << "\n";
    }
    return 0;
}
