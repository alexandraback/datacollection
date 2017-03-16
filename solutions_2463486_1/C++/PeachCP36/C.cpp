#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
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
const string fsfile = "FairSquare.out";
vector<ll> fairSquare;
const ll RANGE = 100000000000000LL;
const int NDIGIT = 14;

void loadFairSquare(){
    ifstream fin(fsfile.c_str());
    while(fin.good()){
        ll in;
        fin >> in;
        fairSquare.pb(in);
    }
}

bool isPalindrome(ll num)
{
    stringstream ss;
    ss << num;
    string s = ss.str();
    string s2 = string(s.rbegin(),s.rend());
    return s.compare(s2)==0;
}

void generator(){
    ofstream fout(fsfile.c_str());
    for(ll i = 1; i < RANGE; ++i){
        if(!isPalindrome(i))continue;
        ll num = i;
        ll num2 = num*num;
        if(isPalindrome(num2)){
            fout << num2 << endl;
        }
        if(num2 > RANGE) break;
    }
    fout.close();
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
	freopen("CL.in","r",stdin);
	freopen("CL.out","w",stdout);

    //generator();
    loadFairSquare();

	int test;
	scanf("%d",&test);
	for(int i = 0; i < test; ++i)
	{
	    printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
