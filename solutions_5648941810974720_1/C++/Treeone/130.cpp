#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
//#define int long long
#define fi first
#define se second
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

signed main(){
	int test_case;
	cin>>test_case;
	string str[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	rep(x,0,test_case){
		string s,ans="";
		cin>>s;
		int l=s.size();
		int d[26]={};
		rep(i,0,s.size()){
			d[(int)(s[i]-'A')]++;
		}
		int tmp;
		if(d[25]){
			tmp=d[25];
			rep(i,0,tmp) ans+='0';
			rep(i,0,4) d[(int)(str[0][i]-'A')]-=tmp;
		}
		if(d[22]){
			tmp=d[22];
			rep(i,0,tmp) ans+='2';
			rep(i,0,3) d[(int)(str[2][i]-'A')]-=tmp;
		}
		if(d[23]){
			tmp=d[23];
			rep(i,0,tmp) ans+='6';
			rep(i,0,3) d[(int)(str[6][i]-'A')]-=tmp;
		}
		if(d[6]){
			tmp=d[6];
			rep(i,0,tmp) ans+='8';
			rep(i,0,5) d[(int)(str[8][i]-'A')]-=tmp;
		}
		if(d[18]){
			tmp=d[18];
			rep(i,0,tmp) ans+='7';
			rep(i,0,5) d[(int)(str[7][i]-'A')]-=tmp;
		}
		if(d[21]){
			tmp=d[21];
			rep(i,0,tmp) ans+='5';
			rep(i,0,4) d[(int)(str[5][i]-'A')]-=tmp;
		}
		if(d[5]){
			tmp=d[5];
			rep(i,0,tmp) ans+='4';
			rep(i,0,4) d[(int)(str[4][i]-'A')]-=tmp;
		}
		if(d[19]){
			tmp=d[19];
			rep(i,0,tmp) ans+='3';
			rep(i,0,5) d[(int)(str[3][i]-'A')]-=tmp;
		}
		if(d[14]){
			tmp=d[14];
			rep(i,0,tmp) ans+='1';
			rep(i,0,3) d[(int)(str[1][i]-'A')]-=tmp;
		}
		if(d[4]){
			tmp=d[4];
			rep(i,0,tmp) ans+='9';
			rep(i,0,4) d[(int)(str[9][i]-'A')]-=tmp;
		}
		sort(all(ans));
		cout<<"Case #"<<x+1<<": "<<ans<<endl;
	}
}
