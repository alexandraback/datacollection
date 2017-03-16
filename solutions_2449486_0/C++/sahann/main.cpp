//#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;
ifstream cin ("B-small-attempt0.in");
ofstream cout("B-small0.out");

int main(){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		int N,M;
		cin >> N >> M;
		vector <vector <int> > vvi;
		int z;
		for(int n=0;n<N;n++){
			vector <int> vi;
			for(int m=0;m<M;m++){
				cin >> z;
				vi.push_back(z);
			}
			vvi.push_back(vi);
		}
		vector <int> vrmax;
		vector <int> vcmax;
		for(int n=0;n<N;n++){
			int mx = -1000;
			for(int m=0;m<M;m++){
				mx = max(mx,vvi[n][m]);
			}
			vrmax.push_back(mx);
		}
		for(int m=0;m<M;m++){
			int mx = -1000;
			for(int n=0;n<N;n++){
				mx = max(mx,vvi[n][m]);
			}
			vcmax.push_back(mx);
		}
		vector <vector<int> > vvi2;
		vvi2 = vvi;
		for(int n=0;n<N;n++) for(int m=0;m<M;m++) vvi2[n][m] = 100;
		for(int n=0;n<N;n++){			
			for(int m=0;m<M;m++){
				vvi2[n][m] = min(vrmax[n],vcmax[m]);
			}			
		}
		if(vvi == vvi2) cout <<"Case #" <<t+1 << ": YES"<<endl;
		else cout <<"Case #" <<t+1 << ": NO"<<endl;
		

	}
	return 0;
}

