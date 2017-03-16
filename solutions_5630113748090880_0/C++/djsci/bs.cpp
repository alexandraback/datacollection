#include "math.h"
#include "iostream"
#include "fstream"
#include "vector"
#include "string"
#include "set"
#include "unordered_set"
#include "algorithm"
#include "map"
#include "sstream"
using namespace std;


int main(){
	int T;
	ifstream in("inputs.txt");
	ofstream out("outputs.txt");
	in>>T;
	for(int i=0;i<T;i++){
		out<<"Case #"<<i+1<<": ";
		int N;
		in>>N;
		map < int, int> numct;
		for(int j=0;j<2*N-1;j++){
			for(int k=0;k<N;k++){
				int tmp;
				in>>tmp;
				if(numct.find(tmp)==numct.end()){
					numct[tmp]=1;
				}
				else numct[tmp]++;
			}
		}	
		vector <int> op;
		for(auto iter=numct.begin();iter!=numct.end();iter++){
			if(iter->second%2!=0){
				op.push_back(iter->first);
			}
		}
		sort(op.begin(),op.end());
		for(int j=0;j<N;j++){
			out<<op[j]<<" ";
		}
		out<<endl;
			
	}
}
