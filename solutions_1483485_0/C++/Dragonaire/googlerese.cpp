#include <iostream>
#include <fstream>

using namespace std;

ifstream reader("in");
ofstream writer("out");

//                       abcdefghijklmnopqrstuvwxyz
string decoder_string = "yhesocvxduiglbkrztnwjpfmaq";

string input = "";

int main(){
	
	int casen = 0;

	getline(reader, input);

	while(getline(reader, input)){
		++casen;
		for(int a = 0; a < input.length(); ++a){
			if(input[a] >= 'a' && input[a] <= 'z')
				input[a] = decoder_string[input[a] - 'a'];
		}
		writer << "Case #" << casen << ": " << input << endl;
	}
	
	return 0;

}
