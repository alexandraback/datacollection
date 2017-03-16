#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void recSort(vector<int> & toSort, int a, int b){
	if(b<a+2)
		return;
	int middle=(a+b)/2;
	recSort(toSort, a, middle);
	recSort(toSort, middle, b);
	//merge
	vector<int> merged;
	int pos1=a, pos2=middle;
	for(int i=a; i<b; i++){
		if(pos1==middle){
			merged.push_back(toSort[pos2]);
			pos2++;
		}else{
			if(pos2==b){
				merged.push_back(toSort[pos1]);
				pos1++;
			}else{
				if(toSort[pos1]<toSort[pos2]){
					merged.push_back(toSort[pos1]);
					pos1++;
				}else{
					merged.push_back(toSort[pos2]);
					pos2++;
				}
			}
		}
	}
	for(int i=a; i<b; i++){
		toSort[i]=merged[i-a];
	}
}

void sort(vector<int> & toSort){
	recSort(toSort, 0, toSort.size());
}



int time(int D, vector<int> & P, int size){
	int steps=0, realsize=0, localsize, cut;
	for(int i=0;i<D;i++){
		cut=((P[i]+size-1)/size);
		localsize=((P[i]+cut-1)/cut);
		realsize=max(realsize,localsize);
		steps+=(cut-1);
	}
	return (steps+realsize);
}

int main(){
	cout<<"launching function main"<<endl;
	ifstream file("B-large.in");
	ofstream outputfile("myoutput.txt");
	int T, D, p, best;
	vector<int> P;
	file>>T;
	for(int t=0;t<T;t++){
		//read input
		P.clear();
		file>>D;
		for(int i=0;i<D;i++){
			file>>p;
			P.push_back(p);
		}
		//solve
		sort(P);
		best=P[D-1];
		for(int i=2;i<P[D-1];i++){
			best=min(best,time(D,P,i));
		}
		//write output
		outputfile<<"Case #"<<(t+1)<<": "<<best<<endl;
	}
	file.close();
	outputfile.close();
}

