#include <bits/stdc++.h>
using namespace std;

int ntest;
string s;
int vt[30];
string digit[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

bool canGo(int cnt[30],int x){
	string dg = digit[x];
	int ct[30]; memset(ct,0,sizeof ct);
	for(int i=0;dg[i]; i++) ct[dg[i]-'A'] ++;
	for(int i=0; i<30; i++) if(cnt[i] < ct[i] ) return false;
	return true;	
}

string f(int cnt[30], int start,string curr){
	bool flag= true;
	for(int i=0; i<30; i++) {
		if( cnt[i] != 0){
			flag=false;
		}
	}
	if(flag){		
		return curr;
	}	
	for(int i=start; i<10; i++){
		if(canGo(cnt,i)){
			flag=false;
			string dg = digit[i];
			for(int j=0;dg[j]; j++) cnt[dg[j]-'A'] --;
			string temp = f( cnt,i, curr + (char) (i+'0') );
			for(int j=0;dg[j]; j++) cnt[dg[j]-'A'] ++;
			if(temp!="-1") return temp;
		}
	}
	if(!flag) return "-1";
}

void solve(int test) {
   cout << "Case #" << test+1 << ": ";   
   cin>>s;
   memset(vt,0,sizeof vt);
   for(int i=0; s[i]; i++){
	 vt[s[i]-'A']++;
   }
   string temp;
   string res = f(vt,0,temp);
   cout << res;
   cout << endl;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("test.out", "w", stdout);
    ios::sync_with_stdio(false);
    int ntest;
    cin >> ntest;
    for(int test=0; test< ntest; test++) {
        solve(test);
    }
    return 0;
}

