#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

vector<string> numbers = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
string S;
int cnt[500], ans[20];

inline void sub(int c,int q){
	for(unsigned i=0;i<numbers[c].size();i++)
		cnt[numbers[c][i]]-=q;
}

int main(){
	int T, tt;
	cin >> T;
	for( tt = 1; tt <= T; tt++ ){
		printf( "Case #%d: ", tt );
		cin >> S;
		fill(cnt,cnt+500,0);
		fill(ans,ans+20,0);
		for(unsigned i=0;i<S.size();i++)cnt[S[i]]++;
		ans[0]=cnt['Z']; sub(0,cnt['Z']);
		ans[6]=cnt['X']; sub(6,cnt['X']);
		ans[2]=cnt['W']; sub(2,cnt['W']);
		ans[7]=cnt['S']; sub(7,cnt['S']);
		ans[8]=cnt['G']; sub(8,cnt['G']);
		ans[5]=cnt['V']; sub(5,cnt['V']);
		ans[4]=cnt['F']; sub(4,cnt['F']);
		ans[1]=cnt['O']; sub(1,cnt['O']);
		ans[9]=cnt['N']/2; sub(9,cnt['N']/2);
		ans[3]=cnt['T'];
		for(int i=0;i<10;i++)
			while(ans[i]>0){
				cout << (char)('0'+i);
				ans[i]--;
			}
		cout << endl;
	}
	return 0;
}
