#include <bits/stdc++.h>
using namespace std;
vector <string> pos1, pos2;
void generate1(string a, string gen, int pos){
	//~ cout << a << " " << gen << " " << pos << endl;
	if (pos == a.size()){
		pos1.push_back(gen);
		return;
	}
	if (a[pos] != '?'){
		string temp = gen;
		temp.push_back(a[pos]);
		generate1(a, temp, pos + 1);
		return;
	}
	
	for (int i = 0; i <= 9; i++){
		generate1(a, gen + to_string(i), pos + 1);
	}
	return;
}
void generate2(string a, string gen, int pos){
	if (pos == a.size()){
		//~ cout << a << " " << gen << " " << pos << endl;
		pos2.push_back(gen);
		return;
	}
	if (a[pos] != '?'){
		//~ cout << a << pos << endl;
		string temp = gen;
		temp.push_back(a[pos]);
		generate2(a, temp, pos + 1);
		return;
	}
	
	for (int i = 0; i <= 9; i++){
		generate2(a, gen + to_string(i), pos + 1);
	}
	return;
}
int main()
{
	int test; cin >> test;
	for (int t = 1; t <= test; t++){
		string a; string b; cin >> a >> b;
		generate1(a, "", 0);
		generate2(b, "", 0);
		
		int an = 0, bn = 10000000;
		string as, bs;
		for (int i = 0; i < pos1.size(); i++){
			for (int j = 0; j < pos2.size(); j++){
				std::string::size_type sz1, sz2;
				int a1 = stoi(pos1[i]);
				int b1 = stoi(pos2[j]);
				if (abs(a1 - b1) < abs(an - bn)){
					an = a1;
					bn = b1;
					as = pos1[i];
					bs = pos2[j];
				}
			}
		}
		pos1.clear();
		pos2.clear();
		cout << "Case #"<<t<<": "<<as<<" "<<bs<<"\n";
	}
	return 0;
}
