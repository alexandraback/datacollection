#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	ifstream inf("in.txt");
	ofstream of("out.txt");
	int qN;
	inf>>qN;

	for(int q=0; q<qN; ++q){
		int smax; inf>>smax;
		int s[2000];
		for (int i=0; i<=smax; i++){
			char tmp;
			inf>>tmp;
			s[i]=tmp-'0';
		};

		int vx[2000];
		vx[0]=s[0];
		for (int i=1; i<=smax; ++i){
			vx[i]=vx[i-1]+s[i];
		}
 
		int n=0;
		
		for (int i=1; i<=smax; ++i)
			if (vx[i-1]<i){
				int inc=i-vx[i-1];
				n+=inc;
				for (int j=i; j<=smax; ++j)
					vx[j]+=inc;
			}

		of<<"Case #"<<q+1<<": "<<n<<endl;
	}
}