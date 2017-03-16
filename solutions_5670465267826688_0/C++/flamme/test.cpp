#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
using namespace std;

string muiltResult[][5] = {
	{"1", "i", "j", "k"},
	{"i", "-1", "k", "-j"},
	{"j", "-k", "-1", "i"},
	{"k", "j", "-i", "-1"}};

int getPixelNum(string s){
	char number = s[0];
	if (number == '-'){
		number = s[1];
	}
	if(number == '1')
		return 0;
	else{
		return number - 'i' + 1;	
	}
}

string getMutilResult(string s1, string s2){
	int isNagtive = 0;
	if ((s1[0] == '-' && s2[0] != '-') || (s1[0] != '-' && s2[0] == '-')){
		isNagtive = 1;
	}
	int row = getPixelNum(s1);
	int col = getPixelNum(s2);
	string mr = muiltResult[row][col];
	if (isNagtive){
		if(mr[0] == '-')
			mr = mr.substr(1,2);
		else
			mr = "-" + mr;
	}
	return mr;
}


int main()
{
	string letters;
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		int result = 0;
		long long l,x;
		cin >> l >> x;
		cin >> letters;
		string letterMul = "1";
		for(int i = 0; i < l; i++){
			letterMul = getMutilResult(letterMul, letters.substr(i, i+1));
		}
		if ((letterMul == "1") || (letterMul == "-1" && x % 2 != 1) ||
			(letterMul != "-1" && x == 1)||(letterMul != "-1" && (x - 2) % 4 != 0)){
			cout << "Case #" << tt << ": " << "NO" << endl;
			continue;
		}

		long long iIndex = 0;
		long long kIndex = 0;
		string temp = "1";
		bool findI = false, findK = false;
		for(; iIndex < l * 4;iIndex++){
			temp = getMutilResult(temp, letters.substr(iIndex % l, iIndex % l + 1 ));
			if (temp == "i"){
				findI = true;
				break;
			}
		}
		temp = "1";
		for(;kIndex < l * 4; kIndex++){
			temp = getMutilResult(letters.substr(l - (kIndex % l) - 1, l - (kIndex % l)), temp);
			if (temp == "k"){
				findK = true;
				break;
			}
		}
		if ((iIndex + kIndex + 2 < l * x) && findI && findK)
			result = 1;
		cout << "Case #" << tt << ": ";
		if (result)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	//system("pause");
	return 0;
}