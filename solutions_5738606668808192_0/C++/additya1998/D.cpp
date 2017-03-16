#include<bits/stdc++.h>
#define int unsigned long long int
using namespace std;
vector<string> v, vv;
vector<int> pr;
int a[1100000];
const int M = 1e6 + 1;
bool composite(int val){
	for(int i=2; i<=10000; ++i){
		if(i == val) continue;
		if(val%i == 0) return 1;
	}
	return 0;
}
void generate(string s, int pos){
	if(pos == 1){
		v.push_back(s+"1");
	}
	else{
		generate(s+"1",pos-1);
		generate(s+"0",pos-1);
	}
}
int get(int base, string s){
	reverse(s.begin(), s.end());
	int val = 0, pw = 1;
	for(int i=0; i<s.size(); ++i){
		val = val + ( s[i] - '0' ) * pw;
		pw = pw * base; 
	}
	return val;
}
int factor(int val){
	for(int i=2; i<=10000; ++i){
		if(i == val) continue;
		if(val%i == 0) return i;
	}
}
signed main(){
	freopen("Csmall.out","w",stdout);
//	for(int i=0; i<20; ++i) cout << pr[i] << endl;
	string s;
	s="1";
	generate(s,15);
	for(auto it : v){
		int f = 1;
		for(int base=2; base<=10; ++base){
			int num = get(base,it);
			if(!composite(num)){
				f=0;
			} 
		}
		if(f) vv.push_back(it);
	}
//	cout << vv.size() << endl;
	cout << "Case #1:\n" ;
	for(int i=0; i<50; ++i){
		cout << vv[i] << ' ' ;
		for(int base=2; base<=10; ++base){
			int num = get(base,vv[i]);
//			cout << num << ' ';
			cout << factor(num) << ' ';
		}
		cout << endl;
	}
}
