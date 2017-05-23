#include <iostream>
#include <fstream>
using namespace std;
int main(){ 
    ofstream fout("A.out"); 
	int n;
	cin >> n;
	string input;
	for ( int i = 0 ; i < n ; i ++ ){
		cin >> input;
		int len = input.length();
		string ret = "";
		for ( int j = 0 ; j < len ; j ++){
			char temp = input[0];
			input = input.substr(1);
			if ( ret == "" ){
				ret.push_back(temp);
			}
			else {
				char first = ret[0];
				if (first > temp){
					ret.push_back(temp);
				}
				else
				{
					string retT = "";
					retT.push_back(temp);
					retT.append(ret);
					ret = retT;
				}
			}
				
		}
		fout << "Case #" << i + 1 <<": " << ret << endl;
	

	}
	
	return 0;
}
