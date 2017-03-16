#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
#include <functional>
using namespace std;

#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define ll long long
#define ld long double
#define mod 1000000007
#define inf 1061109567LL
#define pii pair< int, int >
#define pll pair< ll, ll >
#define psi pair< string, int >
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int T = 1;
	while(t--){
		string s;
		cin>>s;
		int cnt[26];
		for(int i=0;i<26;i++)
			cnt[i]=0;
		for(int i=0;i<s.size();i++){
			cnt[s[i]-'A']++;
		}
		int ans[10];
		CLR(ans);
		cout<<"Case #"<<T<<": ";
		T++;
		for(int i=0;i<cnt['Z'-'A'];i++){
			ans[0]++;
		}
		cnt['E'-'A']-=cnt['Z'-'A'];
		cnt['R'-'A']-=cnt['Z'-'A'];
		cnt['O'-'A']-=cnt['Z'-'A'];
		for(int i=0;i<cnt['W'-'A'];i++){
			ans[2]++;
		}
		cnt['T'-'A']-=cnt['W'-'A'];
		cnt['O'-'A']-=cnt['W'-'A'];
		for(int i=0;i<cnt['X'-'A'];i++){
			ans[6]++;
		}
		cnt['S'-'A']-=cnt['X'-'A'];
		cnt['I'-'A']-=cnt['X'-'A'];
		for(int i=0;i<cnt['G'-'A'];i++){
			ans[8]++;
		}
		cnt['E'-'A']-=cnt['G'-'A'];
		cnt['I'-'A']-=cnt['G'-'A'];
		cnt['H'-'A']-=cnt['G'-'A'];
		cnt['T'-'A']-=cnt['G'-'A'];
		for(int i=0;i<cnt['S'-'A'];i++){
			ans[7]++;
		}
		cnt['E'-'A']-=2*cnt['S'-'A'];
		cnt['V'-'A']-=cnt['S'-'A'];
		cnt['N'-'A']-=cnt['S'-'A'];
		for(int i=0;i<cnt['V'-'A'];i++){
			ans[5]++;
		}
		cnt['F'-'A']-=cnt['V'-'A'];
		cnt['I'-'A']-=cnt['V'-'A'];
		cnt['E'-'A']-=cnt['V'-'A'];
		for(int i=0;i<cnt['T'-'A'];i++){
			ans[3]++;
		}
		cnt['E'-'A']-=2*cnt['T'-'A'];
		cnt['H'-'A']-=cnt['T'-'A'];
		cnt['R'-'A']-=cnt['T'-'A'];
		for(int i=0;i<cnt['F'-'A'];i++){
			ans[4]++;
		}
		cnt['O'-'A']-=cnt['F'-'A'];
		cnt['U'-'A']-=cnt['F'-'A'];
		cnt['R'-'A']-=cnt['F'-'A'];
		for(int i=0;i<cnt['O'-'A'];i++){
			ans[1]++;
		}
		for(int i=0;i<cnt['I'-'A'];i++){
			ans[9]++;
		}
		for(int i=0;i<10;i++){
			for(int j=0;j<ans[i];j++){
				cout<<i;
			}
		}
		cout<<endl;
	}
	return 0;
}