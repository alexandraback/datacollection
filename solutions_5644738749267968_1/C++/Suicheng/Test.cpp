#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

void stringToArray(double *data, const std::string &tline, int maxLength){
	int seperatorCount = 0;//count
	size_t seperatorLocation[1002];
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

int GetResult(vector<double> &A, vector<double> &B, int num) {
	int count = 0, ind = 0;
	while(ind < num && count < num) {
		if(A[ind] > B[count]) {
			count ++;
			ind ++;
		}else ind++;
	}
	return count;
}


int main(int , char* []){
	ifstream fid("F:\\Projects_Cpp\\Tutorial\\D-large.in");
	ofstream fido("f:\\Projects_Cpp\\tutorial\\out.txt");
	string str;
	int count = GetInt(fid, str);
	double A[1001], B[1001];
	vector<double> VA, VB;
	for(int k = 1; k <= count; k ++) {
		int num = GetInt(fid, str);
		getline(fid, str);
		stringToArray(A, str, 1000);
		getline(fid, str);
		stringToArray(B, str, 1000);
		VA.resize(num);
		VB.resize(num);
		for(int i = 0; i < num ; i++) {
			VA[i] = A[i];
			VB[i] = B[i];
		}
		std::sort(VA.begin(), VA.end());
		std::sort(VB.begin(), VB.end());
		fido<<"Case #"<<k<<": "<<GetResult(VA, VB, num)<<" "<<num - GetResult(VB, VA, num)<<endl;
	}
	fid.close();
	fido.close();
	system("pause");
}