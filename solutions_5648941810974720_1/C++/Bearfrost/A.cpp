#include <bits/stdc++.h>
using namespace std;

int al[256];

int main(){
	int t; cin >> t;
	for(int i=1; i<=t; i++){
		string s; cin >> s;
		memset(al, 0, sizeof al);
		for(int j=0; j<s.size(); j++) al[s[j]]++;
		vector<int> v;
		while(al['W']){
			v.push_back(2);
			al['T']--; al['W']--; al['O']--;
		}
		while(al['X']){
			v.push_back(6);
			al['S']--; al['I']--; al['X']--;			
		}
		while(al['G']){
			v.push_back(8);
			al['E']--; al['I']--; al['G']--; al['H']--; al['T']--;
		}
		while(al['S']){
			v.push_back(7);
			al['S']--; al['E']--; al['V']--; al['E']--; al['N']--;			
		}
		while(al['V']){
			v.push_back(5);
			al['F']--; al['I']--; al['V']--; al['E']--;
		}
		while(al['F']){
			v.push_back(4);
			al['F']--; al['O']--; al['U']--; al['R']--;
		}
		while(al['H']){
			v.push_back(3);
			al['T']--; al['H']--; al['R']--; al['E']--; al['E']--;
		}
		while(al['I']){
			v.push_back(9);
			al['N']--; al['I']--; al['N']--; al['E']--;
		}
		while(al['N']){
			v.push_back(1);
			al['O']--; al['N']--; al['E']--;
		}
		while(al['O']){
			v.push_back(0);
			al['Z']--; al['E']--; al['R']--; al['O']--;
		}
		
		sort(v.begin(), v.end());
		cout << "Case #" << i << ": ";
		for(int j=0; j<v.size(); j++) cout << v[j];
		cout << '\n';		
	}
	
	return 0;
}