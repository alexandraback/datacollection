#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long i64;
#define fu(i,m,n) for(int i=m; i<n; i++)
#define fr(i,m,n) for(typeof(m) i=m; i!=n; i++)
#define fa(i,c) fr(i,(c).begin(),(c).end())

bool iscons(char c) {
	return !(c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int main(void) {
	int T;
	cin >> T;
	for(int ts=1; ts<=T; ts++) {
		cout << "Case #" << ts << ": ";
		string s;
		cin >> s;
		int L=s.size();
		int n;
		cin >> n;
		int cnt=0;
		vector<int> spots;
		for(int i=0; i<s.size(); i++) {
			if(iscons(s[i])) cnt++;
			else cnt=0;
			if(cnt>=n) spots.push_back(i-n+1);
		}
		i64 ret=0;
		int cur=0;
		for(int i=0; i<L; i++) {
			while(cur<spots.size() && i>spots[cur]) cur++;
			if(cur==spots.size()) break;
			ret += L-(spots[cur]+n)+1;
		}
		cout << ret << endl;
        }
}
