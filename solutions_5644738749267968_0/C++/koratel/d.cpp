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

bool all_for_naomi(set<double>& naomi, set<double>& ken)
{
    auto n=naomi.begin(), k=ken.begin();
    while(n!=naomi.end())
    {
        if(*n<*k) return false;
        n++;
        k++;
    }
    return true;
}

void solve(int num)
{
    int n;
    cin>>n;
    set<double> naomi, ken, naomi2, ken2;
    for(int i=0; i<n; i++)
    {
        double w;
        cin>>w;
        naomi.insert(w);
    }
    for(int i=0; i<n; i++)
    {
        double w;
        cin>>w;
        ken.insert(w);
    }
    naomi2=naomi;
    ken2=ken;
    cout<<"Case #"<<num<<": ";
    while(!all_for_naomi(naomi, ken))
    {
        naomi.erase(naomi.begin());
        ken.erase(*ken.rbegin());
    }
    cout<<naomi.size()<<" ";
    while(naomi2.size() && ken2.upper_bound(*naomi2.begin())!=ken2.end())
    {
        ken2.erase(ken2.upper_bound(*naomi2.begin()));
        naomi2.erase(naomi2.begin());
    }
    cout<<naomi2.size()<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
}
