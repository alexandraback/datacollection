// Example program
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

int parseString(string str);

int main()
{
	ifstream myfile("B-large.in");
	ofstream file("out.txt");
	int n;
	myfile >> n;
	myfile.ignore(1000,'\n');
	for (int i = 0; i < n; i++){
		string str;
		getline(myfile, str);
		file << "Case #" << i+1 << ": " << parseString(str) << endl;
	}
}

int parseString(string str){
	int ans = 0;
	bool happy = true;
	for (int i = str.size() - 1; i >= 0; i--){
		if (happy && str[i] != '+'){
			ans++;
			happy = false;
		}
		else if (!happy && str[i] != '-'){
			ans++;
			happy = true;
		}
	}
	return ans;
}