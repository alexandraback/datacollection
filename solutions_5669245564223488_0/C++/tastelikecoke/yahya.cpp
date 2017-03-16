#include <iostream>
#include <vector>
using namespace std;
bool conti(string & s){
	bool mem[255] = {};
	int pos = 0;
	while(pos != s.size()){
		char c = s[pos];
		if(mem[c]){
			return false;
		}
		while(s[pos] == c){
			pos++;
		}
		mem[c] = true;
	}
	return true;
}
int traverse(vector<string> ss, string all){
	int poss = 0;
	for(int i=0;i<ss.size();i++){
		string n = all + ss[i];
		if(!conti(n)) continue;
		vector<string> sscopy = ss;
		sscopy.erase(sscopy.begin()+i);
		poss += traverse(sscopy,n);
	}
	if(ss.size() == 0) return 1;
	return poss;
}
int main() {
	int cases = 0;
	cin >> cases;
	for(int c=0;c<cases;c++){
		int strings;
		cin >> strings;
		vector<string> ss;
		for(int i=0;i<strings;i++){
			string temp;
			cin >> temp;
			ss.push_back(temp);
		}
		string start ="";
		cout << "Case #"<<c+1<<": "<<traverse(ss,start) << endl;
		
	}
	return 0;
}