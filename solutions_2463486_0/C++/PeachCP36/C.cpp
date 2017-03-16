#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

using namespace std;

#define FOR(i,s,e) for(int i=(s); i<(e); ++(i))
#define FORE(i,s,e) for(int i=(s); i<=(e); ++(i))
#define fs first
#define se second
#define pb push_back

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
int gcd(int a,int b){if(b==0)return a; if(b>a) return gcd(b,a); return gcd(b,a%b);}
vector<ll> palindrome;
vector<ll> fairSquare;
bool isPalindrome(ll num)
{
    stringstream ss;
    ss << num;
    string s = ss.str();
    string s2 = string(s.rbegin(),s.rend());
    return s.compare(s2)==0;
}

void generator(){
    for(ll i = 1; i <= 1000; ++i){
        if(isPalindrome(i))
            palindrome.pb(i);
    }
    ll sqrt1000 = static_cast<ll>(sqrt(1000)+1);
    int pSize = static_cast<int>(palindrome.size());
    FOR(i,0,pSize){
        ll num = palindrome[i];
        ll num2 = num*num;
        if(binary_search(palindrome.begin(),palindrome.end(),num2)){
            fairSquare.pb(num2);
            cout << num2 << " ";
        }
        if(num2 > 1000) break;
    }
}

int solve()
{
    ll A, B;
    cin >> A >> B;
    vector<ll>::iterator lower, upper;
    lower = lower_bound(fairSquare.begin(),fairSquare.end(),A);
    upper = upper_bound(fairSquare.begin(),fairSquare.end(),B);
    cout << (upper - lower) << endl;
	return 0;
}

int main()
{
	//freopen("C.in","r",stdin);
	//freopen("C.out","w",stdout);
    generator();
	int test;
	scanf("%d",&test);
	for(int i = 0; i < test; ++i)
	{
	    printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
