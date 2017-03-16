#include<iostream>
using namespace std;

int T;
int N,M;
int lawn[100][100];
bool vis[100][100];

bool checkVis(){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if(!vis[i][j]) return true;
	return false;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> T;
	for(int icase = 1; icase <= T; icase++){
		cout<<"Case #"<<icase <<": ";
		cin >> N >> M;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				cin >> lawn[i][j];
		memset(vis,0,sizeof(vis));
		bool ans = true;
		while(checkVis()){
			int minr = 0;
			int minc = 0;
			int minx = 10000;
			for(int i = 0; i < N; i++)
				for(int j = 0; j < M; j++){
					if(!vis[i][j] && lawn[i][j] < minx){
						minx = lawn[i][j];
						minr = i;
						minc = j;
					}
				}
			//row
			bool flagr = true;
			bool flagc = true;
			for(int j = 0; j < M; j++){
				if(!vis[minr][j] && lawn[minr][j] > minx){
					flagr = false;
					break;
				}
			}
			//col
			for(int i = 0; i < N; i++){
				if(!vis[i][minc] && lawn[i][minc] > minx){
					flagc = false;
					break;
				}
			}
			if(flagr == false && flagc == false){
				ans = false;
				break;
			}
			
			if(flagr){
				for(int j = 0; j < M; j++)
					vis[minr][j] = true;
			}
			if(flagc){
				for(int i = 0; i < N; i++)
					vis[i][minc] = true;
			}
		}
		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}