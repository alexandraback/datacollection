//         /\_/\
//   _____/ o o \
//  /~____  =ø= /
// (______)__m_m)

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <sstream>
#include <stack>
#include <queue>
#include <climits>
#include <limits>
#include <cstring>

#define pb push_back
#define pf push_front
#define all(c) c.begin(), c.end()
#define tr(c, it) \
for(typeof(c.begin()) it = c.begin(); it!=c.end(); ++it)
#define present(container, element) (find(all(container),element) != container.end())
#define present2(c,x) ((c).find(x) != (c).end()) // For maps and set

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const long double PI = 3.141592653589793238462643383;
const ll MOD = 1000000007;
const double EPS = 1e-9; // a==b is abs(a-b)<EPS, a>=b is a>b-EPS, a>b is a>=b+EPS
const int MAX_INT = 2147483647;

using namespace std;

long long gcd(long long a, long long b)
{
    if(a==0) return b;
    return gcd(b%a,a);
}

bool isPowerOfTwo(long long n)
{
	return (n&(n-1))==0;
}

long long stringToInt(string s)
{
    long long ans = 0;
    int n = s.size();
    for(int i=0; i<n; ++i){
        ans = 10*ans + int(s[i]-48);
    }
    return ans;
}

int main()
{
    int T; cin>>T;
    for(int t=1; t<=T; ++t){
        string s; cin>>s;
        string P="", Q="";
        int n = s.size();
        bool haha = true;
        for(int i=0; i<n; ++i){
            if(haha){
                if(s[i]=='/'){
                    haha = false;
                    continue;
                }
                else{
                    P += s[i];
                }
            }
            else{
                Q += s[i];
            }
        }
        long long p = stringToInt(P);
        long long q = stringToInt(Q);
        long long g = gcd(p,q);
        if(!isPowerOfTwo(q/g)){
            cout<<"Case #"<<t<<": impossible"<<endl;
            continue;
        }
        p = p/g;
        q = q/g;
        long long a = 2;
        int ans = 1;
        while(q > p*a){
            a = a<<1;
            ans += 1;
        }
        if(ans<=40){
            cout<<"Case #"<<t<<": "<<ans<<endl;
        }
        else{
            cout<<"Case #"<<t<<": impossible"<<endl;
        }
    }
}