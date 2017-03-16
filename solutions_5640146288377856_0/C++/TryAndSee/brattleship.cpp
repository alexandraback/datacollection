#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int brattle(int r, int c, int w){
	if(w==1)
		return (r*c);
	int tofind=(c/w);
	bool multiple=(w*tofind == c);
	if(multiple)
		return (r*tofind+(w-1));
	else
		return (r*tofind+w);
}

int main(){
	cout<<"launching function main"<<endl;
	ifstream file("A-small-attempt0.in");
	ofstream outputfile("myoutput.txt");
	int T, R, C, W;
	file>>T;
	for(int t=0;t<T;t++){
		//read input
		file>>R>>C>>W;
		//solve & write
		outputfile<<"Case #"<<(t+1)<<": "<<brattle(R,C,W)<<endl;
	}
	file.close();
	outputfile.close();
}

