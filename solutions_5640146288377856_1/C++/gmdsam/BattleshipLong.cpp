#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ofstream output;
	output.open("out.txt");
	ifstream input;
	input.open("A-large.in");
	int t, j=1;
	input>>t;
	while(j<=t){
		int r, c, w;
		input>>r>>c>>w;
		if(w==1){
			output<<"Case #"<<j<<": "<<r*c<<endl;
		}else if(w==c){
			output<<"Case #"<<j<<": "<<r+w-1<<endl;
		}else{
			if(c%w == 0){
				output<<"Case #"<<j<<": "<<((c/w)*r)+w-1<<endl;
			}else{
				output<<"Case #"<<j<<": "<<((c/w)*r)+w<<endl;
			}
		}
		j++;
	}
	return 0;
}
