#include <iostream>
#include <string>
#include <fstream>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
	ifstream inf("in.txt");
	ofstream of("out.txt");
	int qN;
	inf>>qN;

	for(int q=0; q<qN; ++q){
		int r,c,w;
		inf>>r>>c>>w;
		int nc=(c/w)*r;
		nc+=(w-1)+(c%w?1:0);

		of<<"Case #"<<q+1<<": "<<nc<<endl;
	}
}