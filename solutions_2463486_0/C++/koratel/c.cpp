#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define x first
#define y second

const int INF = 1 << 30;
const double EPS = 1e-13;

const int MAXN=10000000;
int p[MAXN+42];
ll h[39]={1LL, 4LL, 9LL, 121LL, 484LL, 10201LL, 12321LL, 14641LL, 40804LL, 44944LL, 1002001LL, 1234321LL,
4008004LL, 100020001LL, 102030201LL, 104060401LL, 121242121LL, 123454321LL, 125686521LL,
400080004LL, 404090404LL, 10000200001LL, 10221412201LL, 12102420121LL, 12345654321LL,
40000800004LL, 1000002000001LL, 1002003002001LL, 1004006004001LL, 1020304030201LL,
1022325232201LL, 1024348434201LL, 1210024200121LL, 1212225222121LL, 1214428244121LL,
1232346432321LL, 1234567654321LL, 4000008000004LL, 4004009004004LL};

string lltoa(ll x)
{
    string s(1, '0'+x%10);
    if(!(x/10)) return s;
    return lltoa(x/10)+s;
}

bool isPal(ll x)
{
    string s=lltoa(x), s2=s;
    reverse(s2.begin(), s2.end());
    if(s==s2) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int preprocessing=0;
    vector<ll> ziomki;
    if(preprocessing)
    {
        ofstream myfile;
        myfile.open ("c.txt");
        for(ll i=1; i<=MAXN; i++)
        {
            p[i]=p[i-1];
            if(isPal(i) && isPal(i*i)) myfile<<i*i<<", ";
        }
        myfile.close();
        return 0;
    }
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        ll A, B, ans=0;
        cin>>A>>B;
        for(int i=0; i<39; i++) if(A<=h[i] && h[i]<=B) ans++;
        cout<<"Case #"<<t<<": "<<ans<<"\n";
    }
}
