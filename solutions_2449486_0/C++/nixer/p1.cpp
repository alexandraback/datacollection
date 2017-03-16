#include <iostream>
using namespace std;

int main(){

	int t;
	cin>>t;
	int arr[100][100];
	bool done[100][100];
	for(int l=1; l<=t; l++){
		int m,n;
		cin>>m>>n;	

		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++){
				cin>>arr[i][j];
			}
		}
			
		bool done = false;

		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(arr[i][j] == 1) {

					bool x1 = true;
					for(int k=0; k<m; k++) {
						if(arr[k][j] == 2){ x1 = false; break; }
					}
					if(x1) continue;
					x1 = true;
					for(int k=0; k<n; k++) {
						if(arr[i][k] == 2){ x1 = false; break; }
					}
					if(x1) continue;

					cout<<"Case #"<<l<<": NO"<<endl;
					done = true; break;
				}
			}
			if(done) break;
		}
		if(done) continue;

		cout<<"Case #"<<l<<": YES"<<endl;
	}
	return 0;
}