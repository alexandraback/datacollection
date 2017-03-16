#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	int nb_testcases;
	cin >> nb_testcases;
	for(int current_case = 1; current_case <= nb_testcases; ++current_case){
		int Smax;
		cin >> Smax;
		string s;
		cin >> s;
		int standing = 0;
		int extra_needed = 0;
		for(int i = 0; i <= Smax; ++i){
			int x = s[i]-'0';
			extra_needed = max(extra_needed, i-standing);
			standing += x;
		}
		cout << "Case #" << current_case << ": " << extra_needed << endl;
	}
    return 0;
}
