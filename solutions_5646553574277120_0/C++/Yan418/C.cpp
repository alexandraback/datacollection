#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int main(){
	int T,C,D,V;
	ifstream inf("C-small-attempt0.in");
	ofstream outf("C-small-attempt0.out");
	inf >> T;
	for (int i = 1; i <= T; i++){
		inf >> C >> D >> V;
		vector<int> coin;
		for (int j = 0; j < D; j++){
			int x;
			inf >> x;
			coin.push_back(x);
		}
		int f[10000] = { 0 };
		f[0] = 1;
		int tot = 0;
		for (int j = 0; j < coin.size(); j++){
			for (int k = V; k >= 0; k--){
				if (f[k] == 1)
					f[k + coin[j]] = 1;
			}
			if (j == coin.size() - 1){
				for (int k = 0; k <= V; k++){
					if (f[k] == 0){
						coin.push_back(k);
						tot++;
						break;
					}
				}
			}
		}
		outf << "Case #" << i << ": " << tot << "\n";
		
	}
	return 0;
}