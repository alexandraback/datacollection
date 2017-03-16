#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int INF = 1 << 30;
const double EPS = 1e-8;

void solve(int num)
{
    double c, f, x;
    cin>>c>>f>>x;
    double fac_ret=c/f;
    double t=0.0, prod=2.0;
    while(c/prod+fac_ret<x/prod)
    {
        t+=c/prod;
        prod+=f;
    }
    t+=x/prod;
    cout<<"Case #"<<num<<": "<<t<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    cout<<setprecision(7)<<fixed;
    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
}
