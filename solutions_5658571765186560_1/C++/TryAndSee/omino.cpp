//I apologize if this does not work, I just try an idea

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool gabriel(int x, int r, int c){
	if((r==0) || (c==0))
		return true;
	switch(x){
		case 0:
			return false;
		case 1:
			return true;
		case 2:
			return ((r%2 ==0)||(c%2 ==0));
		case 3:
			return (((r%3 ==0)||(c%3 ==0)) && (r != 1) && (c !=1));
		case 4:
			return (((r*c)%4 ==0) && ((r>3) || (c>3)) && (r>2) && (c>2));
		case 5:
			return ((r%5 ==0) || (c%5 ==0)) && (r>3) && (c>3);
		case 6:
			return ((r*c) % 6 ==0) && (r>3 && c>3);
		default:
			return false;
	}
}

int main(){
	cout<<"launching function main"<<endl;
	ifstream file("D-large.in");
	ofstream outputfile("myoutput.txt");
	int T, X, R, C;
	file>>T;
	for(int t=0;t<T;t++){
		//read input
		file>>X>>R>>C;
		//solve & write
		outputfile<<"Case #"<<(t+1)<<": "<<(gabriel(X,R,C)?"GABRIEL":"RICHARD")<<endl;
	}
	file.close();
	outputfile.close();
}

