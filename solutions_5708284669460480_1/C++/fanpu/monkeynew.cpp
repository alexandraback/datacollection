#include<bits/stdc++.h>
using namespace std;

int k,l,s;
vector<char> keys;
vector<char> stringToMatch;
int correctCaseCount;
int numCaseCount;
int maxKeep;
void monkey(int pos, vector<char> vc, int keep){

	if(pos >= (int)stringToMatch.size() - 1){
		bool match = true;
		int count = 0;
		for(int i = pos - (stringToMatch.size() - 1); i <= pos; i++){
			if(stringToMatch[count] != vc[i]) {
				match = false;
				break;
			}
			count++;
		}
		if(match){
			//cout << "matching: ";
			//for(int i = 0; i < vc.size(); i++) cout << vc[i] << " "; cout << endl;
			correctCaseCount += pow(keys.size(),(s - pos - 1));
			keep++;
		}
	}
	//cout << pos << " keep is " << keep << endl;

	if(pos == s - 1){
		//cout << "terminating: ";
		//for(int i = 0; i < vc.size(); i++) cout << vc[i] << " "; cout << endl;

		numCaseCount++;
		maxKeep = max(maxKeep, keep);
		return;
	}
	for(int i = 0; i < (int)keys.size(); i++){
		vc.push_back(keys[i]);
		monkey(pos + 1, vc, keep);
		vc.pop_back();
	}
	return;
}


int main(){
	
	ifstream cin;
	cin.open("blarge.in");
	ofstream cout;
	cout.open("blarge.o");

	cout << setprecision(12);
	int tc; cin >> tc;
	for(int a = 1; a <= tc; a++){
		maxKeep = 0;
		numCaseCount = 0;
		correctCaseCount = 0;
		keys.clear();
		stringToMatch.clear();
		cin >> k >> l >> s;
		char temp;
		for(int i = 0; i < k; i++){
			cin >> temp;
			keys.push_back(temp);
		}
		for(int i = 0; i < l; i++){
			cin >> temp;
			stringToMatch.push_back(temp);
		}
		vector<char> vc;
		for(int i = 0; i < (int)keys.size(); i++){
			vc.push_back(keys[i]);
			int keep = 0;
			/*
			if(stringToMatch.size()==1 && stringToMatch[0] == keys[i]){
				correctCaseCount++;
				keep++;
			}
			*/
			monkey(0, vc, keep);
			vc.pop_back();
		}
		//cout << maxKeep << " " << correctCaseCount << " " << numCaseCount << endl;
		cout << "Case #" << a << ": " << (double)maxKeep - (double)correctCaseCount / ((double)numCaseCount) << "\n";

	}
}
