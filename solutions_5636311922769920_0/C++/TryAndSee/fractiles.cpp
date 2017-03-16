#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main(){
	cout<<"launching function main"<<endl;
	ifstream file("D-small-attempt0.in");
//	ifstream file("D-large.in");
	ofstream outputfile("myoutput.txt");
	int T, K, C, S, N;
	long long int pow;
	vector<long long int> toUncover;
	file>>T;
	for(int t=0;t<T;t++){
		//read input
		file>>K>>C>>S;
		outputfile<<"Case #"<<(t+1)<<":";
		//case IMPOSSIBLE
		if(S*C<K)
			outputfile<<" IMPOSSIBLE";
		//other cases
		else{
			//solve
			N=(K+C-1)/C;//N<=S
			toUncover.clear();
			toUncover.resize(N);
			for(int j=0; j<N; j++)
				toUncover[j]=1;
			pow=1;
			for(int i=0; i<C; i++){
				for(int j=0; j<N; j++){
					if(C*j+i<K){
						toUncover[j]=toUncover[j]+pow*(C*j+i);
					}
				}
				pow*=K;
			}
			//write output
			for(int j=0; j<N; j++)
				outputfile<<" "<<toUncover[j];
		}
		outputfile<<endl;
	}
	file.close();
	outputfile.close();
}

