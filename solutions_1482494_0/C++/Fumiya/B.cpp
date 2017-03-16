#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int T; cin >> T;
	int a[2][1000];
	bool clear[2][1000];
	for(int test=1;test<=T;test++){
		int N; cin >> N;
		for(int i=0;i<N;i++) cin >> a[0][i] >> a[1][i];
		int star = 0;
		int cnt = 0;
		int cntB = 0;
		memset(clear, false, sizeof(clear));
		while(cntB < N){
			int idx = -1;
			for(int i=0;i<N;i++){
				if(clear[1][i]) continue;
				if(a[1][i] <= star){
					idx = i;
				}
			}
			if(idx != -1){
				clear[1][idx] = true;
				star += (clear[0][idx] ? 1 : 2);
				cnt++;
				cntB++;
				continue;
			}
			for(int i=0;i<N;i++){
				if(clear[0][i] || clear[1][i]) continue;
				if(a[0][i] <= star){
					if(idx==-1 || clear[1][i]) idx = i;
					else if(idx != -1 && !clear[1][idx] && !clear[1][i] && a[1][idx] < a[1][i]) idx = i;
				}
			}
			if(idx != -1){
				clear[0][idx] = true;
				star++;
				cnt++;
				continue;
			}
			break;
		}
		if(cntB == N)
			printf("Case #%d: %d\n", test, cnt);
		else
			printf("Case #%d: Too Bad\n", test);
	}
}