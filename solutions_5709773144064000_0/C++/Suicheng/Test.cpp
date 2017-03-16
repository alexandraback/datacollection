#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void stringToArray(double *data, const std::string &tline, int maxLength){
	int seperatorCount = 0;//count
	size_t seperatorLocation[100];
	seperatorLocation[0] = -1; //seperator location
	const char *lineData = tline.c_str();

	for(int i = 0; i < tline.length(); i ++){
		if(lineData[i] == ' '){
			seperatorCount ++;
			seperatorLocation[seperatorCount] = i;
		}
	}
	seperatorLocation[++seperatorCount] = tline.length();
	if(seperatorCount > maxLength ){
		seperatorCount = maxLength;
	}

	for(int i = 0; i < seperatorCount; i ++){
		data[i] = std::atof(tline.substr(seperatorLocation[i]+1, seperatorLocation[i+1] - seperatorLocation[i] - 1).c_str());
	}
}

int GetInt(ifstream &fid, string &str) {
	getline(fid, str);
	return atoi(str.c_str());
}


double GetResult(double v0, double price, double dv, double amount) {
	double t0 = amount / v0;
	double t1 = price / v0 + amount / (v0 + dv);
	if(t0 < t1) return t0;
	else return GetResult(v0+dv, price, dv, amount) + price/v0;
}


int main(int , char* []){
	ifstream fid("F:\\Projects_Cpp\\Tutorial\\B-small-attempt0.in");
	string str;
	int count = GetInt(fid, str);
	vector<double> output(count);
	double A[4];
	for(int k = 0; k < count; k ++) {
		getline(fid, str);
		stringToArray(A, str, 4);
		cout<<A[0]<<", "<<A[1]<<", "<<A[2]<<endl;
		output[k] = GetResult(2.0, A[0], A[1], A[2]);
	}
	fid.close();

	ofstream fido("f:\\Projects_Cpp\\tutorial\\out.txt");
	fido.precision(11);
	for(int i = 0; i < count; i ++) {
		fido<<"Case #"<<i+1<<": "<<output[i]<<endl; 
	}
	fido.close();
	system("pause");
}