#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int T; cin >> T;
	int N, M;
	int a[100][100], b[100][100];
	for(int test=1;test<=T;test++){
		cin >> N >> M;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				cin >> a[i][j];
				b[i][j] = 100;
			}
		}
		for(int i=0;i<N;i++){
			int mh = 0;
			for(int j=0;j<M;j++) mh = max(mh, a[i][j]);
			for(int j=0;j<M;j++) b[i][j] = min(b[i][j], mh);
		}
		for(int i=0;i<M;i++){
			int mh = 0;
			for(int j=0;j<N;j++) mh = max(mh, a[j][i]);
			for(int j=0;j<N;j++) b[j][i] = min(b[j][i], mh);
		}
		bool ok = true;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if(a[i][j]!=b[i][j]) ok = false;
		printf("Case #%d: %s\n", test, ok ? "YES" : "NO");
	}
}