#include <bits/stdc++.h>
using namespace std;

long long arr[100][100];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long T, cas, B, M, t, i, j, x, y;
	cin >> T;
	for(cas=1;cas<=T;cas++){
		cout << "Case #" << cas << ": ";
		cin >> B >> M;
		t = 1<<(B-2);
		if(M>t) cout << "IMPOSSIBLE\n";
		else{
			cout << "POSSIBLE\n";
			for(i=1;i<=B;i++){
				for(j=1;j<=B;j++){
					arr[i][j] = 0;
				}
			}
			t = M;
			x=0;
			i=0;
			while(t){
				if(t%2) x=i;
				t /= 2;
				i++;
			}
			y = 1<<x;
			x += 2;
			for(x=B-(x-1);x<B;x++){
				for(i=x+1;i<=B;i++){
					arr[x][i] = 1;
				}
			}
			for(i=1;i<x;i++){
				arr[i][i+1] = 1;
			}
			M -= y;
			i = B-1;
			while(M){
				if(M%2){
					arr[1][i] = 1;
				}
				i--;
				M /= 2;
			}
			if(M) arr[1][B] = 1;
			for(i=1;i<=B;i++){
				for(j=1;j<=B;j++) cout << arr[i][j];
				cout << '\n';
			}
		}
	}
	return 0;
}
