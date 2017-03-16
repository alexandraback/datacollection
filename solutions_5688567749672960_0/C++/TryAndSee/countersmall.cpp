#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

static int forReverse[15];

long long int reverse(long long int value){
	long long int rev=0, val=value;
	for(int i=0; i<15; i++){
		if(val !=0){
			rev=10*rev+(val%10);
			val=val/10;
		}else{
			i=15;
		}
	}
	return rev;
}

int main(){
	cout<<"launching function main"<<endl;
	ifstream file("A-small-attempt0.in");
	ofstream outputfile("myoutput.txt");
	int T, numSteps[1000001];
	bool handled[1000001], goahead;
	long long int N, val, rev;
	vector<int> toHandle;
	file>>T;
	for(int t=0;t<T;t++){
		toHandle.clear();
		//read input
		file>>N;
		//solve
		for(int i=0;i<N;i++)
			numSteps[i]=(N+1);
		numSteps[N]=1;
		toHandle.push_back(N);
		for(int i=0;i<=N;i++){
			handled[i]=false;
		}
		goahead=(N !=1);
		while(goahead){
			if(handled[toHandle[0]]){
				toHandle.erase(toHandle.begin());
			}else{
				val=toHandle[0];
				handled[val]=true;
				goahead=(val !=1);
				rev=val-1;
				toHandle.push_back(rev);
				numSteps[rev]=min(numSteps[rev],numSteps[val]+1);
				if(val%10 !=0){
					rev=reverse(val);
					while(rev<N){
						toHandle.push_back(rev);
						numSteps[rev]=min(numSteps[rev],numSteps[val]+1);
						rev*=10;
					}
				}
			}
		}
		//write output
		outputfile<<"Case #"<<(t+1)<<": "<<numSteps[1]<<endl;
	}
	file.close();
	outputfile.close();
}

