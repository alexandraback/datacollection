#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int get(int &A,int X) {
	int ans(0);
	while(A<=X) A+=(A-1), ++ans;
	A+=X;
	return ans;
}
int main() {
	int _,A,N,X[110],ca(0); cin>>_;
	while(_--) {
		cin>>A>>N;
		int ans(1e8),cur(0);
		for(int i(0);i!=N;++i)
			cin>>X[i];
		sort(X,X+N);
		if(A!=1) for(int i(0);i!=N;++i) {
			ans = min(ans,cur+N-i);
			cur+=get(A,X[i]);
		}
		ans = min(cur,ans);
		printf("Case #%d: %d\n",++ca,A==1?N:ans);
	}
	return 0;
}
