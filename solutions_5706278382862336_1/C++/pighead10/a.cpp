#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

long long int euclidgcd(long long int a, long long int b){
	long long int temp;
	while (b != 0){
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main(){
	using namespace std;
	ofstream ofile;
	ifstream ifile;

	ifile.open("A-large.in");
	ofile.open("output.txt");

	if (ifile.is_open()){
		string line;
		getline(ifile, line);
		int casen = stoi(line);

		for (int CASE = 0; CASE < casen; CASE++){
			getline(ifile, line);
			stringstream ss(line);
			string current = "";
			long long int p;
			long long int q;
			for (auto& it : line){
				if (it != '/'){
					current += it;
				}
				else{
					p = stoll(current);
					current = "";
				}
			}
			q = stoll(current);
			long long int minq = q/euclidgcd(p, q);
			if ((minq & (minq-1)) != 0){ //power of 2
				ofile << "Case #" << to_string(CASE + 1) << ": " << "impossible" << endl;
			}
			else{
				long long int counter = 0;
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