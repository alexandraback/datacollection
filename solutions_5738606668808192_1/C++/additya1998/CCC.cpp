#include<bits/stdc++.h>	
#define int unsigned long long int
using namespace std;
vector<string> v;
vector<int> pr;
int get(int base, string s){
	for(auto j : pr){
	int cur = 0, mult =  1;
		for(int k=0; k<s.size(); ++k){
			cur = cur + mult*(s[k] - '0');
			cur = cur % j;
			mult = mult * base;
		}
		if(!cur) return j;
	}
}
signed main(){
	freopen("C_large.out","w",stdout);
	pr.push_back(2);
	pr.push_back(3);
	pr.push_back(5);
	pr.push_back(7);
	pr.push_back(11);
	pr.push_back(13);
	int x = 1ll;
	x = x<<31;
	//cout << x;
	++x;
	for(int i=x; v.size()<500; i=i+2){
		string s = "";
		int cur = i;
		while(cur){
			char y = '0' + cur%2;
			s = s + y;
			cur/=2;
		}
		reverse(s.begin(),s.end());
//		cout << s << endl;
		int k = 1;
		for(int base=2; base<=10; ++base){
			int f = 0;
			for(auto j : pr){
				int cur = 0, mult =  1;
				for(int k=0; k<s.size(); ++k){
					cur = cur + mult*(s[k] - '0');
					cur = cur % j;
					mult = mult * base;
				}
				if(!cur) f=1;
				if(f) break;
			}
			if(!f){
				k = 0;
				break;
			}
		}
		if(k){
			v.push_back(s);
			//cout << v.size() << endl;	
		} 
	}
	cout << "Case #1:\n";
	for(int i=0; i<v.size(); ++i){
		cout << v[i] << ' ';
		for(int base=2; base<=10; ++base){
			cout << get(base,v[i]) << ' ';
		}
		cout << endl;
	}	
}
