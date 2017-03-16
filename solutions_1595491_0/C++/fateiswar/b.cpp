#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int a[200];
int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T;
	cin>>T;
	for(int cas=1; cas<=T; cas++){
		int N, S, p;cin>>N>>S>>p;
		int ret=0;
		for(int i=1; i<=N; i++){ 
			int n; cin>>n;
			int score;
			if(n%3==0) score=n/3;
			else score=n/3+1;
			if(score>=p) ret++;
			else if(S>0 && n%3!=1 && score+1>=p && n!=0){
				S--; ret++;
			}
		}
		printf("Case #%d: %d\n", cas, ret);
	}
	return 0;
}