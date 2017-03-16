#include "math.h"
#include "iostream"
#include "fstream"
#include "vector"
#include "string"
#include "set"
#include "unordered_set"
using namespace std;


int main(){
	int T;
	ifstream in("inputs.txt");
	ofstream out("outputs.txt");
	in>>T;
	for(int i=0;i<T;i++){
		out<<"Case #"<<i+1<<": ";
		string S;
		string lw;
		in>>S;
		for(int k=0;k<S.size();k++){
			if(k==0){
				lw=lw+S[k];
			}
			else{
				if(S[k]>=lw[0]){
					lw=S[k]+lw;
				}
				else{
					lw=lw+S[k];
				}
			}
		}
		out<<lw<<endl;	
	}
}
