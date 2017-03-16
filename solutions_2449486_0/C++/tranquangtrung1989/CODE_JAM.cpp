#include <iostream>
#include<fstream>
#include<vector>
#include<map>
using namespace std;
#define cin fin
#define cout fout
ifstream fin("in.txt");
ofstream fout("out.txt");
using namespace std;

int main() {

	int T, M, N;
	cin >> T;
	for(int t=1;t<=T;t++){
		cin >> N >>M;
		vector<vector<int > > v(N, vector<int>(M));
		vector<vector<int > > V(N, vector<int>(M));
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++){
				cin >> v[i][j];
				V[i][j]=100;
			}
	    for(int i=0;i<N;i++){
	    	int max=-1;
	    	for(int j=0;j<M;j++)
	    		if(max<v[i][j]) max=v[i][j];
	    	for(int j=0;j<M;j++) if(V[i][j]>max) V[i][j]=max;
	    }

	    for(int j=0;j<M;j++){
	    	int max=-1;
	    	for(int i=0;i<N;i++)
	    		if(max<v[i][j]) max=v[i][j];
	    	for(int i=0;i<N;i++) if(V[i][j]>max) V[i][j]=max;
	    }
	    cout<<"Case #"<<t<<": ";
	    if(v==V) cout<<"YES";
	    else cout<<"NO";
	    cout<<endl;
	}
	return 0;
}
