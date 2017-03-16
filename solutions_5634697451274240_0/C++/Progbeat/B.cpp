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
	string s;
    cin >> s;
    s += '+';
    int res = 0;
    FOR (i, 1, sz(s))
        res += s[i - 1] != s[i];
    cout << res << endl;
}

int main(){
	cout.precision(12);
	cout.setf(ios::fixed);
	int a = 0, b = 0;
	for(cin >> b; a++ < b ; run()) 
		printf("Case #%d: ", a);
	return 0;
}
