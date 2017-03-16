#include<iostream>
#include<fstream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;
#ifdef Nameless
#define FILES freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#else
#define FILES //freopen("input.txt","r",stdin); freopen("output.txt","r",stdin);
#endif

typedef long long Long;
typedef long double Double;

int n;
string s1[1111],s2[1111];
map<string, int> mp1, mp2;
vector<int> classeq1[1111];
vector<int> classeq2[1111];

string S1[1111], S2[1111];


void solve(int test = 0)
{
	cout << "Case #" << test+1  << ": ";


	cin >> n;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		cin >> s1[i] >> s2[i];
	}

	int maxmask = (1<<n);
	for (int mask = 0; mask < maxmask; ++mask) {


		int sz = 0;
		mp1.clear();
			mp2.clear();
		for (int j = 0;j < n; ++j) {
			if (((1<<j) & mask) == 0) {
				S1[sz] = s1[j];
				S2[sz] = s2[j];
				sz++;
			}
		}
		int good = sz;
		for (int j = 0;j < n; ++j) {
			if (((1<<j) & mask) > 0) {
				S1[sz] = s1[j];
				S2[sz] = s2[j];
				sz++;
			}
		}

		int curr = 0;
		for (int i = 0;i < n; ++i) {
			if (i>=good && mp1.count(S1[i]) > 0 && mp2.count(S2[i]) > 0) {
				curr++;
			}
			mp1[S1[i]] = 1;
			mp2[S2[i]] = 1;
		}
		if (curr>res)
			res = curr;
	}


	cout << res << endl;
}

int main(){
    FILES;
    cin.tie(0);
    ios_base::sync_with_stdio(0);
//    solve();
    int test;
    cin >> test;
    for (int i = 0; i < test; ++i) {
        solve(i);
    }
    return 0;
}
