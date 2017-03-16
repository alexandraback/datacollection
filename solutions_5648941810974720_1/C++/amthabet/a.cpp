#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<iterator>
#include<numeric>
using namespace std;

//#define SMALL 1
#define LARGE 1

string a[] = {"ZERO", "TWO", "FOUR", "SIX", "SEVEN", "FIVE", "EIGHT", "THREE", "ONE", "NINE"};
char b[] = {'0', '2', '4', '6', '7', '5', '8', '3', '1', '9'};

int main() {
#ifdef LARGE
	freopen("a_large.i", "rt", stdin);
	freopen("a_large.o", "wt", stdout);
#elif SMALL
	freopen("a_small.i", "rt", stdin);
	freopen("a_small.o", "wt", stdout);
#else
	freopen("a_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		string s;
		cin>>s;
		vector<int> v(256, 0);
		for(auto c:s) {
			v[c]++;
		}
		string ans = "";
		for(int i=0;i<10;i++) {
			while(1) {
				vector<int> vv = v;
				bool skip = 0;
				for(auto c:a[i]) {
					if(vv[c] == 0) {
						skip = 1;
						break;
					}
					vv[c]--;
				}
				if(skip) {
					break;
				}
				ans.push_back(b[i]);
				v = vv;
			}
		}
		sort(ans.begin(), ans.end());
		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}

	return 0;
}
