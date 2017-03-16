#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<set>
#include<cmath>
#include<stdio.h>
#include<utility>
#include<queue>
#include<stack>
#include<deque>
#include<string.h>
using namespace std;

int main()
{
	string r;
	int t;
	cin >> t;
	int freq[256];
	for(int z = 1; z <= t; ++ z){
		cin >> r;
		vector<int> ret;
		memset(freq, 0, sizeof freq);
		for(int i = 0; i < r.size(); ++ i){
			if(r[i] == 'Z'){
				ret.push_back(0);
				freq['E'] --;
				freq['R'] --;
				freq['O'] --;
			}
			else if(r[i] == 'U'){
				ret.push_back(4);
				freq['F']--;
				freq['O']--;
				freq['R']--;
			}
			else if(r[i] == 'X'){
				ret.push_back(6);
				freq['S']--;
				freq['I']--;
			}
			else if(r[i] == 'W'){
				ret.push_back(2);
				freq['T']--;
				freq['O']--;
			}
			else if(r[i] == 'G'){
				ret.push_back(8);
				freq['E']--;
				freq['I']--;
				freq['H']--;
				freq['T']--;
			}
			else {
				freq[r[i]]++;
			}
		}
		r = "";
		for(int i = 'A'; i <= 'Z'; ++ i){
			for(int j = 0; j < freq[i]; ++ j)
				r += (char)i;
			freq[i] = 0;
		}
		for(int i = 0; i < r.size(); ++ i){
			if(r[i] == 'O'){
				freq['N']--;
				freq['E']--;
				ret.push_back(1);
			}
			else if(r[i] == 'R'){
				freq['T'] --;
				freq['H'] --;
				freq['E']--;
				freq['E']--;
				ret.push_back(3);
			}
			else if(r[i] == 'F'){
				freq['I']--;
				freq['V']--;
				freq['E']--;
				ret.push_back(5);
			}
			else {
				freq[r[i]]++;
			}
		}
		r = "";
		for(int i = 'A'; i <= 'Z'; ++ i){
			for(int j = 0; j < freq[i]; ++ j)
				r += (char)i;
			freq[i] = 0;
		}
		for(int i = 0; i < r.size(); ++ i){
			if(r[i] == 'V'){
				ret.push_back(7);
			}
			else if(r[i] == 'I'){
				ret.push_back(9);
			}
		}
		sort(ret.begin(), ret.end());
		cout << "Case #" << z << ": ";
		for(int i = 0; i < ret.size(); ++ i)
			cout << ret[i];
		cout << endl;
	}
	return 0;
}