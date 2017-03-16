#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

int f[26];

void init() {
	for(int i=0;i<26;i++)	f[i] = 0;
}

int main() {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	long long T,N,n,t,c;
	cin >>T;
	string s = "";
	for(int i=0;i<T;i++) {
		vector<int> v;
		cin>>s;
		init();
		for(int j=0;j<s.length();j++) {
			f[s[j]-'A']++;
		}
		int c = s.length();
		string res = "";
		while(c>0) {
			if(f['Z'-'A'] > 0 
				&& f['E'-'A'] > 0  
				&& f['R'-'A'] > 0  
				&& f['O'-'A'] > 0  ) {
				res += "0";
				f['Z'-'A']--;
				f['E'-'A']--;
				f['R'-'A']--;
				f['O'-'A']--;
				c-=4;
				v.push_back(0);
			}
			
			else if(f['T'-'A'] > 0 
				&& f['W'-'A'] > 0  
				&& f['O'-'A'] > 0  ) {
				res += "2";
				f['T'-'A']--;
				f['W'-'A']--;
				f['O'-'A']--;
				c-=3;
				v.push_back(2);
			}
			else if(f['F'-'A'] > 0 
				&& f['O'-'A'] > 0  
				&& f['U'-'A'] > 0  
				&& f['R'-'A'] > 0  ) {
				res += "4";
				f['F'-'A']--;
				f['O'-'A']--;
				f['U'-'A']--;
				f['R'-'A']--;
				c-=4;
				v.push_back(4);

			}
			else if(f['S'-'A'] > 0 
				&& f['I'-'A'] > 0  
				&& f['X'-'A'] > 0 ) {
				res += "6";
				f['S'-'A']--;
				f['I'-'A']--;
				f['X'-'A']--;
				c-=3;
				v.push_back(6);
			}
			else if(f['E'-'A'] > 0 
				&& f['I'-'A'] > 0  
				&& f['G'-'A'] > 0  
				&& f['H'-'A'] > 0 
				&& f['T'-'A'] > 0 ) {
				res += "8";
				f['E'-'A']--;
				f['I'-'A']--;
				f['G'-'A']--;
				f['H'-'A']--;
				f['T'-'A']--;
				c-=5;
				v.push_back(8);
			}
			else if(f['F'-'A'] > 0 
				&& f['I'-'A'] > 0  
				&& f['V'-'A'] > 0  
				&& f['E'-'A'] > 0  ) {
				res += "5";
				f['F'-'A']--;
				f['I'-'A']--;
				f['V'-'A']--;
				f['E'-'A']--;
				c-=4;
				v.push_back(5);
			}
			else if(f['T'-'A'] > 0 
				&& f['H'-'A'] > 0  
				&& f['R'-'A'] > 0  
				&& f['E'-'A'] > 1  ) {
				res += "3";
				f['T'-'A']--;
				f['H'-'A']--;
				f['R'-'A']--;
				f['E'-'A']-=2;
				c-=5;
				v.push_back(3);
			}
			else if(f['O'-'A'] > 0 
				&& f['N'-'A'] > 0  
				&& f['E'-'A'] > 0    ) {
				res += "1";
				f['O'-'A']--;
				f['N'-'A']--;
				f['E'-'A']--;
				c-=3;
				v.push_back(1);
			}
			
			
			
			else if(f['S'-'A'] > 0 
				&& f['E'-'A'] > 1  
				&& f['V'-'A'] > 0  
				&& f['N'-'A'] > 0  ) {
				res += "7";
				f['S'-'A']--;
				f['E'-'A']-=2;
				f['V'-'A']--;
				f['N'-'A']--;
				c-=5;
				v.push_back(7);
			}
			
			else if(f['N'-'A'] > 1 
				&& f['I'-'A'] > 0  
				&& f['E'-'A'] > 0  ) {
				res += "0";
				f['N'-'A']-=2;
				f['I'-'A']--;
				f['E'-'A']--;
				c-=4;
				v.push_back(9);
			}

		}
		sort(v.begin(),v.end());
		cout<<"Case #"<<(i+1)<<": ";
		for(int i=0;i<v.size();i++)	cout<<v[i];
			cout<<endl;
	}
	return 0;
}