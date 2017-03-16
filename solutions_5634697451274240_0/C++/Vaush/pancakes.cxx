#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

int main(int argc, char **argv)
{
	ifstream in("input");
	ofstream out("output");
	int times;
	in >> times;
	for(int t = 1; t <= times; t++){
		string linea;
		in >> linea;
		in.ignore(numeric_limits<streamsize>::max(), '\n');
		int cnt = 0;
		for(unsigned int i = 0; i < linea.size() -1; i++){
			if(linea[i] != linea[i+1]) cnt++;
		}
		if(linea[linea.size()-1] == '-') cnt++;
		out << "Case #" << t << ": " << cnt << endl;
	}
	return 0;
}

