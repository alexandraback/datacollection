#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int shift = 500,U=20;
char r[20][shift<<1|1][shift<<1|1];
bool ok(int n,int a,int b){
	if(r[n][a][b])return r[n][a][b]&1;
	if(n==0)return (r[n][a][b]=2-(a==shift&&b==shift))&1;
	return	 (r[n][a][b]=2-(ok(n-1,a-n,b)||ok(n-1,a,b-n)||
				ok(n-1,a+n,b)||ok(n-1,a,b+n)))&1;
}
int x,y;
bool ok(int n){
	if(n*(n+1)>>1<abs(x)+abs(y))return false;
	if((abs(x+y)&1)^(n*(n+1)>>1&1))return false;
	int a=x,b=y,t;
	for(t=n;t>=U;--t){
		if(abs(a)>=abs(b)){
			if(a>0)a-=t;
			else a+=t;
		}else{
			if(b>0)b-=t;
			else b+=t;
		}
	}
	if(n*(n+1)>>1<abs(a)+abs(b))return false;
	return ok(t,a+shift,b+shift);
}
string gen(int n){
	int a=x,b=y,t;
	string ans;
	for(t=n;t>=U;--t){
		if(abs(a)>=abs(b)){
			if(a>0){a-=t;ans+='E';}
			else{a+=t;ans+='W';}
		}else{
			if(b>0){b-=t;ans+='N';}
			else{b+=t;ans+='S';}
		}
	}
	for(a+=shift,b+=shift;t;--t){
		if(ok(t-1,a-t,b)){
			a-=t;ans+='E';continue;
		}
		if(ok(t-1,a+t,b)){
			a+=t;ans+='W';continue;
		}
		if(ok(t-1,a,b-t)){
			b-=t;ans+='N';continue;
		}
		if(ok(t-1,a,b+t)){
			b+=t;ans+='S';continue;
		}
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int main(){
	int T,ts=1,n;
	for(cin>>T;ts<=T;++ts){
		cin >> x >> y;
		for(n = 1;!ok(n);++n);
		cout << "Case #"<<ts<<": "<<gen(n)<< endl;
		//cout <<"Case #" <<ts<<": "<< n << endl;
	}
}
