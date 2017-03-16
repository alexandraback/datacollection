#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>

using namespace std;

bool pcake[105];
int num_pcake = 0;

void flip(int n){ //Includes n
	vector<bool> tmp;
	for (int i = n; i >= 0; i--){
		if (pcake[i] == false){
			tmp.push_back(true);
		}
		else{
			tmp.push_back(false);
		}
	}
	for (int i = 0; i <= n; i++){
		pcake[i] = tmp[i];
	}
}

void debug_pcake(){ //For debug use only
	cout << num_pcake << " ";
	for (int i = 0; i < num_pcake; i++){
		cout << pcake[i] << " ";
	}
	cout << endl;
}

bool get_flip(){ //returns false if cannot flip anymore, true if can flip
	//debug_pcake();
	bool first_sign = pcake[0];
	for (int i = 0; i < num_pcake; i++){
		if (pcake[i] != first_sign){
			flip(i-1);
			//cout << "Flip: " << i << endl;
			return true;
		}
	}
	if (first_sign == false){
		flip(num_pcake - 1);
		return true;
	}
	return false;
	//cout << "Done" << endl;
}




int main(){
	ifstream fin("b.txt");
	FILE * fout = fopen("b_out.txt","w");
	int t;
	fin >> t;
	for (int i=0; i<t; i++){
		string s;
		fin >> s;
		for (int j=0; j<s.length(); j++){
			if (s[j] == '-'){
				pcake[j] = false;
			}
			else{
				pcake[j] = true;
			}
		}
		num_pcake = s.length();
		int cnt = 0;
		while (get_flip()){
			cnt += 1;
		}
		fprintf(fout,"Case #%d: %lld\n",i+1,cnt);
	}
	fin.close();
	fclose(fout);
}
