#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
using namespace std;
string _main()
{
    string str, ret = "";
    cin >> str;
    ret += str[0];
    for(int i = 1; i < str.size(); i++)
    {
        if(str[i] >= ret[0])ret = str[i] + ret;
        else ret += str[i];
    }
    return ret;
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    for(int i = 1; i <= tt; i++)
    {
        cout << "Case #" << i << ": " << _main() << "\n";
    }
    return 0;
}
