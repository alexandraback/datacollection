#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
	cout<<"launching function main"<<endl;
	ifstream file("C-small-attempt0.in");
//	ifstream file("C-large.in");
	ofstream outputfile("myoutput.txt");
	int T, J, P, S, K, vals;
	file>>T;
	for(int t=0;t<T;t++){
		//read input
		file>>J>>P>>S>>K;
		K=min(K,S);
		//solve & write
		outputfile<<"Case #"<<(t+1)<<": "<<(J*P*K)<<endl;
		for(int j=0; j<J; j++){
			for(int p=0; p<P; p++){
				for(int k=0; k<K; k++){
					vals=(j+p+k)%S;
					outputfile<<(j+1)<<" "<<(p+1)<<" "<<(vals+1)<<endl;
				}
			}
		}
	}
	file.close();
	outputfile.close();
}

