#include<bits/stdc++.h>
using namespace std;

int k,l,s;
vector<char> keys;
vector<char> targetString;
int otherCaseCount;
int correctCaseCount;
int maxKeep = 0;
void monkey(int pos, vector<char> vc, int keep){
	for(int i = 0; i < vc.size(); i++){
			cout << vc[i] << " ";
		} cout << endl;
	cout << "pos is " << pos << " " << endl;
	if(pos >= s) {
		cout << "EXITING AT POS " << pos << endl;
		maxKeep = max(maxKeep, keep);
		otherCaseCount++;
		return;
	}
	if(pos >= (int)targetString.size() - 1){
		bool match = true;
		int count = 0;
		for(int i = pos - targetString.size(); i < pos; i++){
			cout << "i is " << i << endl;
			cout << "vc[i] is " << vc[i] << " and targetstring is " << targetString[count] << endl;
			if(vc[i] != targetString[count]){
				cout << "OI\n";
				match = false;
				break;
			}
			count++;
		}
		if(match){ 
			correctCaseCount++;
			cout << "MATCH!\n";
			keep++;
		}
	}
	for(int i = 0; i < (int)keys.size(); i++){
		vc.push_back(keys[i]);
		monkey(pos + 1, vc, keep);
		vc.pop_back();
	}
}


int main(){
	/*
	ifstream cin;
	cin.open("alarge.in");
	ofstream cout;
	cout.open("alarge.o");
	*/
	
	int tc; cin >> tc;
	for(int a = 1; a <= tc; a++){
		maxKeep = 0;
		otherCaseCount=0;
		correctCaseCount=0;
		cin >> k >> l >> s;
		char temp;
		for(int i = 0; i < k; i++){
			cin >> temp;
			keys.push_back(temp);
		}
		for(int i = 0; i < l; i++){
			cin >> temp;
			targetString.push_back(temp);
		}
		for(int i = 0; i < k; i++){
			vector<char> vc;
			vc.push_back(keys[i]);
			int keep = 0;
			if(targetString.size()==1 && targetString[0] == keys[i]){
				keep = 1;
				correctCaseCount++;
			}
			monkey(1, vc, keep);
		}
		cout << otherCaseCount << " " << correctCaseCount << endl;
		cout << "Case #" << a << ": " << (double)maxKeep - (double)correctCaseCount / ((double)otherCaseCount) << "\n"; 
	}
}
