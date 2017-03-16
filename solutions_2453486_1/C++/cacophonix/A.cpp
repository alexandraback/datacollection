#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cctype>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <complex>
#include <numeric>
#include <valarray>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

#define inf 1061109567
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define mem(x,a) memset(x,a,sizeof(x))
#define rep(i,n) for(int i(0),_n(n);i<_n;++i)
#define repi(i,a,b) for(int i(a),_b(b);i<_b;++i)
#define repe(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define len(x) ((int)(x.size()))





string s[4];
string tm;
int f;


int fun(string s,char c){
	
	int ret=0;
	rep(i,len(s))ret+=(s[i]==c||s[i]=='T');
	return ret==4;
}


int main(){
	ios_base::sync_with_stdio(0);
	
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	
	int tests;
	cin>>tests;
	for(int t=1;t<=tests;t++){
		cout<<"Case #"<<t<<": ";
		
		rep(i,4){
			cin>>s[i];
		}
		rep(i,4){
			if(fun(s[i],'X')){
				cout<<"X won"<<endl;
				goto jmp;
			}
				
			if(fun(s[i],'O')){
				cout<<"O won"<<endl;
				goto jmp;
			}
		}
		tm="";
		rep(i,4)tm+=s[i][i];
		if(fun(tm,'X')){
			cout<<"X won"<<endl;
			goto jmp;
		}
			
		if(fun(tm,'O')){
			cout<<"O won"<<endl;
			goto jmp;
		}
		
		tm="";
		rep(i,4)tm+=s[i][3-i];
		if(fun(tm,'X')){
			cout<<"X won"<<endl;
			goto jmp;
		}
			
		if(fun(tm,'O')){
			cout<<"O won"<<endl;
			goto jmp;
		}
		
		tm="";
		rep(i,4)tm+=s[i][0];
		if(fun(tm,'X')){
			cout<<"X won"<<endl;
			goto jmp;
		}
			
		if(fun(tm,'O')){
			cout<<"O won"<<endl;
			goto jmp;
		}
		tm="";
		rep(i,4)tm+=s[i][1];
		if(fun(tm,'X')){
			cout<<"X won"<<endl;
			goto jmp;
		}
			
		if(fun(tm,'O')){
			cout<<"O won"<<endl;
			goto jmp;
		}
		tm="";
		rep(i,4)tm+=s[i][2];
		if(fun(tm,'X')){
			cout<<"X won"<<endl;
			goto jmp;
		}
			
		if(fun(tm,'O')){
			cout<<"O won"<<endl;
			goto jmp;
		}
		tm="";
		rep(i,4)tm+=s[i][3];
		if(fun(tm,'X')){
			cout<<"X won"<<endl;
			goto jmp;
		}
			
		if(fun(tm,'O')){
			cout<<"O won"<<endl;
			goto jmp;
		}
		
		f=0;
		
		rep(i,4)rep(j,4)f+=s[i][j]=='.';
		
		if(f){
			cout<<"Game has not completed"<<endl;
			goto jmp;
		}
		
		cout<<"Draw"<<endl;
		
		
		jmp:;
	}
	
	
}









