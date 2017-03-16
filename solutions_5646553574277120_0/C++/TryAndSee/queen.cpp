#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

static vector<int> val;

int toadd(int c, int d, int v){
	int range=0, res=0, pos=0;
	while(range<v){
		if(pos<d && val[pos]<=(range+1)){
			range=range+c*val[pos];
			pos++;
		}else{
			res++;
			range=range+c*(range+1);
		}
	}
	return res;
}

int main(){
	cout<<"launching function main"<<endl;
	ifstream file("C-small-attempt0-1.in");
//	ifstream file("C-large.in");
	ofstream outputfile("myoutput.txt");
	int T, C, D, V, p;
	file>>T;
	for(int t=0;t<T;t++){
		//read input
		val.clear();
		file>>C>>D>>V;
		for(int i=0;i<D;i++){
			file>>p;
			val.push_back(p);
		}
		//solve & write output
		outputfile<<"Case #"<<(t+1)<<": "<<toadd(C,D,V)<<endl;
	}
	file.close();
	outputfile.close();
}

