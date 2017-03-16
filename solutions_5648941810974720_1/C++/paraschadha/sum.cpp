#include <bits/stdc++.h>
using namespace std;

void remove(long long *arr, string s){
	long long i;
	for(i=0;i<s.size();i++) arr[s[i]-'A']--;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	long long T, cas, arr[26]={0}, ans[10]={0}, i;
	cin >> T;
	for(cas=1;cas<=T;cas++){
		for(i=0;i<26;i++){
			arr[i] = 0;
			if(i<10) ans[i] = 0;
		}
		cin >> s;
		for(i=0;i<s.size();i++) arr[s[i]-'A']++;
		while(arr['Z'-'A']){
			ans[0]++;
			remove(arr, "ZERO");
		}
		while(arr['W'-'A']){
			ans[2]++;
			remove(arr, "TWO");
		}
		while(arr['U'-'A']){
			ans[4]++;
			remove(arr, "FOUR");
		}
		while(arr['X'-'A']){
			ans[6]++;
			remove(arr, "SIX");
		}
		while(arr['G'-'A']){
			ans[8]++;
			remove(arr, "EIGHT");
		}
		while(arr['O'-'A'] and !arr['Z'-'A'] and !arr['W'-'A'] and !arr['U'-'A']){
			ans[1]++;
			remove(arr, "ONE");
		}
		while(arr['H'-'A'] and !arr['G'-'A']){
			ans[3]++;
			remove(arr, "THREE");
		}
		while(arr['S'-'A'] and !arr['X'-'A']){
			ans[7]++;
			remove(arr, "SEVEN");
		}
		while(arr['V'-'A']){
			ans[5]++;
			remove(arr, "FIVE");
		}
		while(arr['N'-'A']){
			ans[9]++;
			remove(arr, "NINE");
		}
		cout << "Case #" << cas << ": ";
		for(i=0;i<10;i++){
			while(ans[i]){
				cout << i;
				ans[i]--;
			}
		}
		cout << '\n';
	}
	return 0;
}
