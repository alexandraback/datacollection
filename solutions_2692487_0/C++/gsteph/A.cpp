#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int T,A,N,m[100];

int recurse(int a, int i){
	
	if (i==N) return 0;
	if (a<=m[i]){
		int m1=0,tmp=a;
		while(tmp<=m[i]){
			tmp+=(tmp-1);
			m1++;
		}
		return min(m1+recurse(tmp+m[i],i+1), 1+recurse(a,i+1));
	}else return recurse(a+m[i],i+1);
}

int main(){
	freopen("A-small.in","r",stdin);
	freopen("A-small.out","w",stdout);
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> A >> N;
		for (int i = 0; i < N; i++) cin >> m[i];
		if (A==1) {
			cout << "Case #" << t+1 << ": " << N << endl;
			continue;
		}
		sort(m,m+N);
		cout << "Case #" << t+1 << ": " << recurse(A,0) << endl;
	}
	return 0;
}
