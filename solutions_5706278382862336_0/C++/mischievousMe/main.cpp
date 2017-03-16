#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <valarray>
#include <algorithm>
#include <queue>
#include <cstdio>
#include<stack>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include<climits>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define pi 2.0*acos(0.0)


int main() {
    freopen("/Users/shalini/Downloads/A.txt","r",stdin);
    freopen("/Users/shalini/Downloads/A1.txt","w",stdout);
    int t,x=0;
    cin>>t;
    ll p,q;
    char c;
    while(t--) {
        ++x;
        string s;
        cin>>s;
        stringstream ss;
        ss<<s;
        ss>>p;
        ss>>c;
        ss>>q;
        double ratio = (double)p/q;
        int cnt = 0;
        while(q%2 == 0) {
            q /= 2;
            cnt++;
        }
        cnt = 0;
        while(ratio < 1) {
            ratio *= 2;
            ++cnt;
        }
        if(q == 1) {
            cout<<"Case #"<<x<<": "<<cnt<<"\n";
        }
        else if(q == p) {
            cout<<"Case #"<<x<<": "<<cnt<<"\n";
        }
        else {
            cout<<"Case #"<<x<<": impossible\n";
        }
    }
    return 0;
}