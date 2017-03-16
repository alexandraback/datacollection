#include<bits/stdc++.h>
using namespace std;
const int H = 2510;
int cnt[H];
int main(){
	freopen("B-large.in","r",stdin);
	freopen("output_B_large.out","w",stdout);
	int t, N;
	cin >> t;
	int c = 0;
	while(t--){
		memset(cnt, 0 , sizeof cnt);
		cin >> N;
		for(int i=1; i<=2*N - 1; ++i){
			for(int j=1; j<=N; ++j){
				int x;
				cin >> x;
				++cnt[x];	
			}
		}
		cout << "Case #" << ++c <<": ";
		for(int i=1; i<=2500; ++i){
			if(cnt[i]%2){
				cout << i << ' ';
			}
		}
		cout << endl;
	}
}
