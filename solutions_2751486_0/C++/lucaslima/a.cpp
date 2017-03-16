#include <bits/stdc++.h>
#define fr(i,a,b) for(int i = (a); i < (b); ++i)
#define pb push_back

using namespace std;

string vowels = "aeiou";

bool f(char c) {
	fr(i,0,5) if(vowels[i]==c) {return 0;}
	return 1;
}

int main() {
	int t; cin>>t;++t;
	fr(_,1,t) {
		string s;
		int n;
		cin>>s>>n;
		int ans=0;
		fr(i,0,s.size()) fr(j,i,s.size()) {
			int cons=0;
			int maxx=0;
			fr(k,i,j+1) {
				if(f(s[k]))++cons;
				else maxx=max(maxx,cons),cons=0;
			}
			maxx=max(maxx,cons);
			if(maxx>=n)++ans; 
		}
		printf("Case #%d: %d\n",_,ans);
	}
	return 0;
}
