#include <iostream>
#include <string>
#include <iomanip> 
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
		int k,l,s;
		inf>>k>>l>>s;
		char keys[200], target[200];
		for (int i=0; i<k; ++i) inf>>keys[i];
		for (int i=0; i<l; ++i) inf>>target[i];

		//rep:
		int rep=l;
		for (int i=1; i<l; ++i){
			bool bad=false;
			for (int j=0; j<l-i; ++j){
				if (target[j]!=target[j+i]) {
					bad=true;
					break;
				};
			}
			if (!bad) {rep=i; break;};
		}
		bool nok=false;
		//two psbs:
		double psb=1;
		for (int i=0; i<l; ++i){
			int occ=0;
			for (int j=0; j<k; ++j) if (keys[j]==target[i]) occ++;
			psb=double(occ)/double(k)*psb;
			if (occ==0) nok=true;
		}
		double psbacc=1;
		for (int i=0; i<rep; ++i){
			int occ=0;
			for (int j=0; j<k; ++j) if (keys[j]==target[l-i-1]) occ++;
			psbacc=double(occ)/double(k)*psbacc;
		}		

		double exp=0;
		double nexp=(nok?(0):((s-l)/rep+1));
		int len=l;

		/*
		while(abs(exp-nexp)>0.5e-6 && len<=s){
			exp=nexp;
			nexp=exp-psb;
			psb*=psbacc;
			len+=rep;
		}*/

		nexp=nexp-double(s-l+1)*psb;
		of<<"Case #"<<q+1<<": "<<std::setprecision(10)<<nexp<<endl;
	}
}