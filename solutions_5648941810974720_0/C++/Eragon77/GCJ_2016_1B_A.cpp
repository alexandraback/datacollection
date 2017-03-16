#include <bits/stdc++.h>
using namespace std;
typedef long long               ll;
const int mod = 1e9+7;
#ifndef M_PI
#define M_PI acos(-1.0)
#endif

int cnt_n_l[10][30];

string s_n[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int ord[]={6, 0, 2, 8, 4, 5, 1, 3, 7, 9};
char ide[]={'X', 'Z', 'W', 'G', 'U', 'F', 'O', 'T', 'V', 'I'};

int main(){
	for(int i=0; i<10; ++i){
		for(char c : s_n[i]){
			++cnt_n_l[i][c-'A'];
		}
	}
	int t;
	cin>>t;
	for(int ct=0; ct<t; ++ct){
		string s;
		cin>>s;
		int cnt_l[30] {};
		int cnt_n[10] {};
		for(char c:s){
			++cnt_l[c-'A'];
		}
		for(int i=0; i<10; ++i){
			cnt_n[ord[i]]+=cnt_l[ide[i]-'A'];
			for(int j=0; j<30; ++j){
				cnt_l[j]-=cnt_n[ord[i]]*cnt_n_l[ord[i]][j];
			}
		}
		printf("Case #%d: ", ct+1);
		for(int i=0; i<10; ++i){
			for(int j=0; j<cnt_n[i]; ++j){
				cout<<i;
			}
		}
		cout<<'\n';
	}
	return 0;
}
