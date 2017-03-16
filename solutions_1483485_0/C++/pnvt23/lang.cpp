#include<string>
#include<iostream>
#include<fstream>

using namespace std; 

int encode[26];

char decode(char s){
	int temp = s - 97;
	
	return encode[temp]+97;
	
}

void keygen(){
	ifstream f1("inp1.t");
	ifstream f2("int2.t");
	int tag[26];
	int num = 0;
	string temp;
	getline(f2, temp);
	num = 3;
	encode['y'-97] = 0;
	encode['e'-97] = 'o'-97;
	encode['q'-97] = 'z'-97;
	for (int i=0; i<num; i++){
		string code;
		string key;
		getline(f2, code);
		getline(f1, key);
		for (int j=0; j<code.length(); j++)
		if (code[j]!=' ')	
		{
			encode[code[j]-97] = key[j]-97;
			tag[key[j]-97] = 1;
			//cout << encode[code[j]-97] << endl ;
		}
		
	}
	for (int i=0; i<26; i++){
		if (tag[i]==0){
			encode[25] = i;
		}
	}

}
string convert(string st){
	string res = "";
	for (int i=0; i<st.length(); i++){
		if (st[i]!=' ')	res += decode(st[i]);
		else res += ' ';
	}
	return res;
}
int main(){
	int n = 0;
	string st;
	keygen();
	cin >> n;
	getline(cin, st);
	
	for (int i=0; i<n; i++){
		getline(cin, st);
		cout << "Case #" << i+1 << ": " << convert(st) << endl;
	}
}