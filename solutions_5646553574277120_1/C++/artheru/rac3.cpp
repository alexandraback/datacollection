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
		int c,d,v;
		inf>>c>>d>>v;
		int ds[200];
		for (int i=0; i<d; ++i) inf>>ds[i];

		int nowmax=0;
		int nowcur=0;
		int nc=0;
		int ptr=0;
		while(nowmax<v){
			if (nowmax>=ds[ptr]-1 && ptr<d){//continuous
				nowcur=ds[ptr];
				ptr++;
			}else{ //incontinous
				nowcur=nowmax+1;
				nc++;
			}
			nowmax=nowcur*c+nowmax;
		}

		of<<"Case #"<<q+1<<": "<<nc<<endl;
	}
}