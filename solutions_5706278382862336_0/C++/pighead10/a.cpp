#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(){
	using namespace std;
	ofstream ofile;
	ifstream ifile;

	ifile.open("A-small-attempt1.in");
	ofile.open("output.txt");

	if (ifile.is_open()){
		string line;
		getline(ifile, line);
		int casen = stoi(line);

		for (int CASE = 0; CASE < casen; CASE++){
			getline(ifile, line);
			stringstream ss(line);
			string current = "";
			int p;
			int q;
			for (auto& it : line){
				if (it != '/'){
					current += it;
				}
				else{
					p = stoi(current);
					current = "";
				}
			}
			q = stoi(current);
			if ((q & (q-1)) != 0){
				ofile << "Case #" << to_string(CASE + 1) << ": " << "impossible" << endl;
			}
			else{
				int counter = 0;
				while (p < q){
					p *= 2;
					counter++;
				}
				ofile << "Case #" << to_string(CASE + 1) << ": " << counter << endl;
			}
		}
	}

	ofile.close();
}