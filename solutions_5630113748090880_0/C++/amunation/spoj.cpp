#include<bits/stdc++.h>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb push_back
using namespace std;
vector < int > sd;
int solve()
{
    int n;int a[2505]={0};
    cin >> n;
    int i,j;int tmp;
    int l=(2*n)-1;
    rep(i,0,l)
    {
        rep(j,0,n)
        {
        cin >> tmp;
        a[tmp]++;
        }
    }
    rep(i,0,2505)
    {
        if(a[i]%2==1)
            sd.pb(i);
    }
    return 0;
}
int main()  
{
    int t;
    cin >> t;
    int j;
    for(j=0;j<t;j++)
    {
         sd.clear();
         solve();
         cout << "Case #" << j+1 << ": ";
         int i;
         rep(i,0,sd.size())
            cout << sd[i] << " ";
        cout << "\n";
    }
    return 0;
    
}