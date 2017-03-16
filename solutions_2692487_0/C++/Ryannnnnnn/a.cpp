#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int A,N,B[111];
int solve(){
	cin>>A>>N;
	rep(i,N) cin>>B[i];
	sort(B,B+N);
	int res=1000000000;
	for (int i=0;i<=N;i++){
		int t=A,r=0;
		for (int j=0;j<i;j++){
			if (t<=1){r=1000000000;break;}
			while (t<=B[j]){
				t+=t-1;
				r++;
			}
			t+=B[j];
		}
		r+=(N-i);
		if (r<res) res=r;
	}
	return res;
}
int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt","w", stdout);
	int T;
	cin >> T;
	for (int i=1;i<=T;i++) printf("Case #%d: %d\n",i,solve());
	return 0;
}
