#include <cstring>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
bool map[1000][1000];
bool wf(int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				if(!(i == j && j == k)){
					if(map[j][k]&&map[j][i]&&map[i][k]) return 1;
					else if(map[j][i] && map[i][k]) map[j][k] = true;
				}
			}
		}
	}
	return 0;
}


int main(){
	int T;
	cin >> T;
	int t = 0;
	while(t++ < T){
		memset(map,0,sizeof map);
		int n;
		cin >> n;
		for(int i = 0; i < n;i++){
			int mi;
			cin >> mi;
			for(int j = 0; j < mi;j++){
				int m;
				cin >> m;
				map[i][m-1] = 1;
			}
		}
		cout << "Case #" << t << ":";
		cout << (wf(n)?" Yes":" No");
		cout << endl;
	}
}
