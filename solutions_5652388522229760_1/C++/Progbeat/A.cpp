#include <algorithm>
#include <iostream>
#include <assert.h>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)      (a).begin(),(a).end()
#define sz(a)       int((a).size())
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define REP(i,n)    FOR(i,0,n)
#define UN(v)       sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)     memset(a,b,sizeof a)
#define pb          push_back
#define X           first
#define Y           second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> point;

void run() {
	ll n;
    cin >> n;
    if (n == 0) {
        cout << "INSOMNIA" << endl;
        return;
    }
    ll x = 0, mask = 0;
    do {
        ll y = ++x * n;
        do mask |= 1 << (y % 10);
        while (y /= 10);
    } while (mask < 1023);
    cout << x * n << endl;
}

int main(){
	cout.precision(12);
	cout.setf(ios::fixed);
	int a = 0, b = 0;
	for(cin >> b; a++ < b ; run()) 
		printf("Case #%d: ", a);
	return 0;
}
