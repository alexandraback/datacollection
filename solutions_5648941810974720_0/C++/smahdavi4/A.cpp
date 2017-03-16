// IN THE NAME OF ALLAH
#include<bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
#define F(i,a,b) for(ll i=(a) ; i<=(b) ; i++)
#define PI 3.1415926535897932384626433832795
#define eps 0.000001
using namespace std;
typedef long long ll;
typedef float ld;
const ll M=1e5+100;

string s[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"},t,ans;
//               0      0       0       0         0             0       0         00
ll x[400];

void del(ll y,ll d){
	//y--;
	F(i,0,s[y].length()-1){
		x[s[y][i]-'A']-=d;
	}
}


void in(){
	cin>>t;
	F(i,0,t.length()-1) x[t[i]-'A']++;
}

void clr(){
	fill(x,x+400,0);
	ans="";
}

void solve(){
	
	F(i,0,x['Z'-'A']-1) ans+='0';
	del(0,x['Z'-'A']);
	//x['Z'-'A']=0;
	F(i,0,x['X'-'A']-1) ans+='6';
	del(6,x['X'-'A']);
	//x['X'-'A']=0;	
	F(i,0,x['G'-'A']-1) ans+='8';
	del(8,x['G'-'A']);
	//x['G'-'A']=0;	
	F(i,0,x['W'-'A']-1) ans+='2';
    del(2,x['W'-'A']);
	//x['W'-'A']=0;	
	F(i,0,x['U'-'A']-1) ans+='4';
	del(4,x['U'-'A']);
	//x['U'-'A']=0;	
	F(i,0,x['R'-'A']-1) ans+='3';
	del(3,x['R'-'A']);
	//x['R'-'A']=0;	
	F(i,0,x['S'-'A']-1) ans+='7';
	del(7,x['S'-'A']);
	//x['S'-'A']=0;
	F(i,0,x['V'-'A']-1) ans+='5';
	del(5,x['V'-'A']);
	//x['V'-'A']=0;	
	F(i,0,x['I'-'A']-1) ans+='9';
	del(9,x['I'-'A']);	
	//
	F(i,0,x['E'-'A']-1) ans+='1';
	del(1,x['E'-'A']);
	sort(ans.begin(),ans.end() );
	cout<<ans;	
}







int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//cout << setprecision(22) << fixed;
ios::sync_with_stdio(false);


ll tst; cin>>tst;
F(ii,1,tst){
	clr();
	in();
	cout<<"Case #"<<ii<<": ";
	//printf("Case #%lld: ",ii);
	solve();
	cout<<endl;
}





return 0;   
}
