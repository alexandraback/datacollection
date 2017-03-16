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
    freopen("/Users/shalini/Downloads/B.txt","r",stdin);
    freopen("/Users/shalini/Downloads/B1.txt","w",stdout);
    int t,a,b,k;
    int x = 0;
    cin>>t;
    while(t--) {
        ++x;
        cin>>a>>b>>k;
        int cnt = 0;
        for(int i = 0;i < a;++i) {
            for(int j = 0;j < b;++j) {
                int c = i&j;
                if(c<k) {
                    ++cnt;
                }
            }
        }
        cout<<"Case #"<<x<<": "<<cnt<<"\n";
    }
    return 0;
}