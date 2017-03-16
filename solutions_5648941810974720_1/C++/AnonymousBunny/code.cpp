#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int uu;

void print(int res){
	cout<<"Case #"<<uu<<": "<<res<<endl;
}

void solve(){

}

map <char, int> M;
int cnt[10];
void res(){
	string s;
	cin>>s;
	for (int i=0; i<s.size(); i++) M[s[i]]++;
	while (M['Z']){
		cnt[0]++;
		M['Z']--;
		M['E']--;
		M['R']--;
		M['O']--;
	}
	cnt[4]= M['U'];
	cnt[5]= M['F']-cnt[4];
	cnt[7]= M['V']-cnt[5];
	cnt[2]= M['W'];
	cnt[8]= M['G'];
	cnt[3]= M['H']-cnt[8];
	cnt[6]= M['X'];
	cnt[9]= M['I']-cnt[5]-cnt[6]-cnt[8];
	cnt[1]= M['O']-cnt[2]-cnt[4];
	vector <int> v;
	for (int i=0; i<10; i++){
		for (int j=0; j<cnt[i]; j++) v.push_back(i);
	}
	cout<<"Case #"<<uu<<": ";
	for (int i=0; i<v.size(); i++) cout<<v[i];
	cout<<endl;
}

void reset(){
	M.clear();
	for (int i=0; i<10; i++) cnt[i]= 0;

}

int main() {
	// your code goes here
	int t;
	cin>>t;
	for (uu=1; uu<=t; uu++){
		reset();
		res();
	}
	return 0;
}
