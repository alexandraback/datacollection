#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

string digs[] = {"EIGHT", "SIX", "TWO", "ZERO", "SEVEN", "THREE", "FIVE", "FOUR", "ONE", "NINE", };
int digVals[] = {8, 6, 2, 0, 7, 3, 5, 4, 1, 9};

int main(){
	int T; cin >> T;
	for(int t=1;t<=T;t++){
		string s; cin >> s;
		vi alpha(26, 0);
		int n = s.length();
		for(int i=0;i<n;i++){
			alpha[s[i]-'A']++;
		}
		//for(int i=0;i<26;i++) cout << alpha[i] <<" "; cout << endl;
		string ans = "";
		for(int k=0;k<10;k++){
			// dig
			vi a2(26, 0);
			int mul = 1<<30;
			for(int i=0;i<digs[k].size();i++){
				a2[digs[k][i]-'A']++;
			}

			for(int i=0;i<26;i++){
				if(a2[i] > 0) mul = min(mul, alpha[i]/a2[i]);
			}
			for(int i=0;i<26;i++){
				alpha[i] -= a2[i]*mul;
			}
			//for(int i=0;i<26;i++) cout << a2[i] <<" "; cout << endl;
			//for(int i=0;i<26;i++) cout << alpha[i] <<" "; cout <<"--- "; cout << endl; 
			string z(mul, char(digVals[k]+'0'));
			ans += z;
		}
		sort(ans.begin(), ans.end());
		cout << "Case #"<<t<<": "<< ans << endl;

	}


}
