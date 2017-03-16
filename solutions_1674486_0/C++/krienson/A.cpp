 /*
*  Javier Segovia
*  0.016
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int N;
vector<int> A[1005];
bool seen[1005];

bool dfs(int a){
	bool ok=false;
	for (int i=0; i<int(A[a].SL) && !ok; i++) {
		if(seen[A[a][i]]){ ok=true;break;}
		seen[A[a][i]] = true;
		ok|=dfs(A[a][i]);
	}
	return ok;
}

int main(){
	int T;
	cin>>T;
	for(int kases = 1;kases<= T;kases++){ //cout<<kases<<endl;
		cin>>N;
		int cant,ac;
		for (int i=1; i<=N ; i++) {
			A[i].clear();
			cin>>cant;
			for (int j=0; j<cant; j++) {
				cin>>ac;
				A[i].PB(ac);
			}
		}
		bool ok=false;
		for (int i=1; i<=N ; i++) {
			for(int j=0;j<=N;j++) seen[j] = false;
			seen[i] = true;
			if(dfs(i)){ ok=true; break;}
		}
		cout<<"Case #"<<kases<<": "<<(ok?"Yes":"No")<<endl;
		
	}
}