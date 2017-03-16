#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void stringToArray(int *data, const std::string &tline, int maxLength){
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
		data[i] = std::atoi(tline.substr(seperatorLocation[i]+1, seperatorLocation[i+1] - seperatorLocation[i] - 1).c_str());
	}
}

int GetInt(ifstream &fid, string &str) {
	getline(fid, str);
	return atoi(str.c_str());
}



void GetResult3(vector<string> &out, int C, int num) {
	if(num == 2 || num == 3 || num == 5 || num == 7)out.clear();
	else
	{	
		int n = num / 3, n0, n2;
		if(num % 3 == 0) {
			n0 = n; n2 = n;
		}else if(num % 3 == 1) {
			n0 = n + 1; n2 = n - 1;
		}else{
			n0 = n + 1;
			n2 = n;
		}
		for(int i = 0; i < n0; i ++) {
			out[0][i] = '.';
			out[1][i] = '.';
		}
		for(int i = 0; i < n2; i ++) {
			out[1][i] = '.';
		}
		out[0][0] = 'c';
	}
}


void GetResult4(vector<string> &out, int C, int num) {
	int r = num / C, a = num % C;
	for(int i = 0; i < r; i ++) {
		out[i] = string(C, '.');
	}
	for(int i = 0; i < a; i ++) {
		out[r][i] = '.';
	}
	if(a == 1) {
		out[r-1][C-1] = '*';
		out[r][1] = '.';
	}
	out[0][0] = 'c';
}

void GetResult(vector<string> &out, int R, int C, int M) {
	out = vector<string>(R,string(C,'*'));
	out[0][0] = 'c';
	int num = C * R - M;
	if(num == 1) return;
	if(R == 1) {
		for(int j = 1; j < num; j++) {
			out[0][j] = '.';
		}
	}else if(R == 2) {
		if(num % 2 == 1 || num == 2)out.clear();
		else{
			for(int j = 0; j < num/2; j ++) {
				out[0][j] = '.';
				out[1][j] = '.';
			}
			out[0][0] = 'c';
		}
	}else if(R == 3 || num <= C * 3) {
		GetResult3(out, C, num);
	}else {
		GetResult4(out, C, num);
	}

}


int main(int , char* []){
	ifstream fid("F:\\Projects_Cpp\\Tutorial\\C-large.in");
	ofstream fido("f:\\Projects_Cpp\\tutorial\\out.txt");
	string str;
	int count = GetInt(fid, str);
	int A[4];
	for(int k = 1; k <= count; k ++) {
		getline(fid, str);
		stringToArray(A, str, 4);
		fido<<"Case #"<<k<<": "<<endl;
	//	cout<<A[0]<<", "<<A[1]<<", "<<A[2]<<endl;
		vector<string> out;
		if(A[0] <= A[1]){
			GetResult(out, A[0], A[1], A[2]);
			if(out.empty()) {
				fido<<"Impossible"<<endl;
			}else
				for(int i = 0; i < A[0]; i ++) {
					fido<<out[i]<<endl;
				}
		}
		else {
			GetResult(out, A[1], A[0], A[2]);
			if(out.empty()){
				fido<<"Impossible"<<endl;
			}else{
				for(int i = 0; i < A[0]; i ++) {
					for(int j = 0; j < A[1]; j ++) {
						fido<<out[j][i];
					}
					fido<<endl;
				}
			}
		}
	}
	fid.close();
	fido.close();
	system("pause");
}