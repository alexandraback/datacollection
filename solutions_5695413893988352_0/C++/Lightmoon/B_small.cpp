#include <bits/stdc++.h>
using namespace std;

int ntest;
string s,t;
typedef long long LL;

bool correct(int x, string s){
	if(s.length()==1 && x > 9) return false;
	if(s.length()==2 && x>99)  return false;	
	for(int i=s.length()-1; i>-1; i--){
		if(s[i]!='?' && s[i]-'0'!=x%10) return false;
		x/=10;
	}
	return true;
}

void solve(int test) {
   cout << "Case #" << test+1 << ": ";   
   cin>> s>>t;         
   int diff = 1000000;
   int rc =1000;
   int rj = 1000;
   for(int i=0; i<1000; i++){
   		for(int j=0; j<1000; j++){
   			if( correct(i,s) && correct(j,t) ) {
   			//	cout << s << " " << t << endl;
   				int d = abs(i-j);
   				if( d <diff){
   					rc = i;
					rj = j;	
					diff = d;
				}
			}
   		}
   }
   string rs="",rt="";
   for(int i=0;s[i]; i++){
   		rs= char (rc%10 +'0')+rs; rc/=10;
   		rt= char (rj%10 +'0')+ rt; rj/=10;
   }
   cout << rs << " " << rt << endl;
}

int main() {
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("test.out", "w", stdout);
    ios::sync_with_stdio(false);
    int ntest;
    cin >> ntest;
    for(int test=0; test< ntest; test++) {
        solve(test);
    }
    return 0;
}

