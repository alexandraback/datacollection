#include <iostream>

using namespace std;

int main(){

	int ncases;
	cin >> ncases;
	for (int caseno = 0; caseno < ncases; caseno++){
		int N;
		cin >> N;
		int parent[N][N];
		int numparent[N];
		int des[N][N];
		int nchild[N];
		for (int i = 0; i < N; i++){
			nchild[i] = 0;
			for (int j = 0; j < N; j++){
				parent[i][j] = 0;
				des[i][j] = 0;
			}
		}
		for (int i = 0; i < N; i++){
			
			cin >> numparent[i];
			for (int j = 0; j < numparent[i]; j++){
				int newparent;
				cin >> newparent;
				parent[i][newparent-1] = 1;
				des[newparent-1][i] = 1;
				nchild[newparent-1]++;
			}
		}
		int diamond = 0;
		for(int cc= 0; cc < N; cc++){
//			cout <<"---\n";
//			for(int i = 0; i < N; i++){
//				cout << numparent[i];
//				for(int j = 0; j < N; j++){
//					cout << parent[i][j];
//				}
//				cout<<endl;
//			}
		
		
			int leaf = 0;
			for(leaf = 0; leaf < N; leaf++){
				if (nchild[leaf] == 0)
					break;
			}
			if(nchild[leaf]!= 0) break;
			
			for (int par = 0; par < N; par++){
				if(parent[leaf][par] == 1){
					for(int dd = 0; dd < N; dd++){
						if(des[leaf][dd] == 1){
							if (des[par][dd] == 1){
								diamond = 1;
								break;
							}
							des[par][dd] = 1;
						}
					}
					nchild[par]--;
				}
			}
			nchild[leaf] = -1;
			if(diamond == 1) break;
			
		}
		
		if (diamond == 1)
			cout << "Case #" << caseno + 1 <<": Yes" << endl;
		else
			cout << "Case #" << caseno + 1 <<": No" << endl;
	}

	return 0;

}
