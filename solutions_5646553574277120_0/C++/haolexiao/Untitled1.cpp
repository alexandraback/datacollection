#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream fin("C-small-attempt2.in");
	ofstream fout("zz.txt");
	int kk[7] = {};
	int t;
	fin >> t;
	int mm = 0;
	while (t--){
		int mark[90] = {};
		mark[0] = 1;
		mm++;
		int num = 0;
		int c, d, v;
		fin >> c >> d >> v;
		for (int j = 0; j<d; j++){
			fin >> kk[j];
		}
		int ll = d;
		for (int j = 0; j<d; j++){
			for (int i = v; i >= kk[j]; i--){
				if (mark[i - kk[j]] == 1)
					mark[i] = 1;
			}
		}
		while (1){
			int pp = 0, i;
			for (i = 1; i <= v; i++){
				if (mark[i] != 1){
					pp = i;
					num++;
					break;
				}
			}
			if (pp == 0)
				break;
			for (int i = v; i >= pp; i--){
				if (mark[i - pp] == 1)
					mark[i] = 1;
			}
		}
		fout << "Case #" << mm << ": " << num << endl;
	}
	system("pause");
}
