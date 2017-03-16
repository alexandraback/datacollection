#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream fin("A-large (1).in");
	ofstream fout("zz.txt");
	int t;
	fin >> t;
	int mm = 0;
	while (t--){
		mm++;
		int r, c, w;
		fin >> r >> c >> w;
		int num = r*(c / w)+w;
		if(c%w == 0) num--;
		fout << "Case #" << mm << ": " << num << endl;
	}
	system("pause");
}
