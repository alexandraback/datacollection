#include<fstream>
#include<iostream>
#include<string>

using namespace std;
int num = 0;
char mapping[] = {'y','h','e','s','o','c','v',
	              'x','d','u','i','g','l','b',
				  'k','r','z','t','n','w','j',
				  'p','f','m','a','q'};

int main() {
	ifstream input ("in.txt");
	ofstream output ("out.txt");
	input >> num;
	string line;
	getline(input,line);
	
	for (int i = 0; i < num; ++i) {		
		getline(input,line);
		output<< "Case #" <<i+1<<": ";		
		for (int j = 0; j < line.size(); ++j) {
			if (line[j] == ' ')
				output << ' ';
			else 
				output << mapping[line[j]-97];			
		}
		output<<endl;
	}
}