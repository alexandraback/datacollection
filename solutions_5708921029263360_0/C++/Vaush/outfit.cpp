#include <iostream>
#include <limits>
#include <cstdio>
#include <vector>
#include <cassert>
using namespace std;
int coppie[11][11][11];
int main(int argc, char **argv)
{
	freopen("input", "r", stdin);
    freopen("output", "w", stdout);
	
	int times;
	cin >> times;
	for(int t = 1; t <= times; t++){
		for(int i = 0; i < 11; i++){
			for(int j = 0; j < 11; j++){
				for(int k = 0; k < 11; k++){
					coppie[i][j][k] = 0;
				}
			}
		}
		int jacks,pants,shirts,maxk;
		cin >> jacks >> pants >> shirts >> maxk;
		int i,j,k;
		i = j = k = 1;
	//	cout << jacks << " " << pants<< " " << shirts<< " " << maxk << endl;
		vector<int> lista;
		while(i <= jacks){
			j = 1;
			while(j <= pants){
				if(coppie[i][j][0] >= maxk){
					j++;
					continue;
				}
				k = 1;
				while(k <= shirts){
				//	cout << "----" << coppie[i][j][0] << endl;
					assert(coppie[i][j][0] <= maxk && coppie[i][0][k] <= maxk && coppie[0][j][k] <= maxk);
					if(coppie[i][j][0] >= maxk){
						break;
					}
					if(coppie[i][0][k] >= maxk){
						k++;
						continue;
					}
					if(coppie[0][j][k] >= maxk){
						k++;
						continue;
					}
					lista.push_back(i);
					lista.push_back(j);
					lista.push_back(k);
					coppie[i][j][0]++;
					coppie[i][0][k]++;
					coppie[0][j][k]++;
					k++;
				}
				j++;
			}
			i++;
		}
		cout << "Case #" << t << ": " << lista.size()/3 << endl;
		for(int i = 0; i < ((int)lista.size())/3; i++){
			cout << lista[i*3] << " " << lista[i*3+1] << " " << lista[i*3+2] << endl;
		}
	}
	return 0;
}

