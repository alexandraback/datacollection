#include <bits/stdc++.h>
#define fr(i,a,b) for(int i = (a); i < (b); ++i)
#define pb push_back

using namespace std;

bool arr[1100];

bool is(int n) {
	ostringstream os;
	os<<n;
	string s = os.str();
	string s2 = s;
	reverse(s2.begin(),s2.end());
	bool isPal = s2==s;
	int x = sqrt(n);
	bool isSqr = (x*x)==n;
	ostringstream os2;
	n=x;
	os2<<n;
	s = os2.str();
	s2 = s;
	reverse(s2.begin(),s2.end());
	bool isPal2 = s2==s;
	return isPal&isSqr&isPal2;
}

void precalc() {
	fr(i,1,1010) arr[i]=is(i);
}

int main() {
	int tc; cin>>tc; ++tc;
	precalc();
	fr(_,1,tc) {
		printf("Case #%d: ",_);
		int a,b;
		cin>>a>>b;
		int ans = 0;
		fr(i,a,b+1) {
			if(arr[i])++ans;
		}
		cout<<ans<<endl;
	}
	return 0;	
}
