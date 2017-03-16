#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
int main(){
	ifstream inf("in.txt");
	ofstream of("out.txt");
	int qN;
	inf>>qN;

	const string y="YES";
	const string n="NO";
	for(int q=0; q<qN; ++q){
		int D;
		inf>>D;
		
		int P[1000];
		int m=0;
		for (int i=0; i<D; ++i){
			inf>>P[i];
			if (m<P[i]) m=P[i];
		}

		for (int i=m; i>0; --i){
			int time=i;
			for (int j=0; j<D; ++j){
				int extra=P[j]-i;
				if (extra>0)
					time+=extra/i+(extra%i>0?1:0);
			}
			if (time<m) m=time;
		}
		of<<"Case #"<<q+1<<": "<<m<<endl;
	}
}