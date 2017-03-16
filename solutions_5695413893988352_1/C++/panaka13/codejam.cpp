#include <bits/stdc++.h>
using namespace std;

string s,t;
struct res_ {
	string s,t;
	long long res;
} res,ans;

res_ xuly(string s,string t) {
	bool ok=false;
	res_ res;
	res.s=s;
	res.t=t;
	res.res=0;
	for(int i=0;i<s.length();i++) 
		if (ok) {
			if (s[i]=='?') res.s[i]='9';
			if (t[i]=='?') res.t[i]='0';
		} else {
			if (t[i]=='?' && s[i]=='?') res.s[i]=res.t[i]='5'; else 
			if (t[i]=='?') res.t[i]=res.s[i]; else 
			if (s[i]=='?') res.s[i]=res.t[i]; else 
				if (s[i]<t[i]) ok=true; else
				if (s[i]>t[i]) {
					if (i==0) {
						res.res=1e19;
						return res;
					}
					
					bool tok=false;
					string tam=res.s;
					--res.s[i-1];
					for(int j=i-1;j>=0 && (!tok);j--) 
						if (s[j]!='?') break; else 
						if (res.s[j]>='0') tok=true; else {
							res.s[j]='9';
							res.s[j-1]--;
							if (j==0) break;
						}
					if (tok) {
						ok=true;
						continue;
					}
					res.s=tam;
					
					++res.t[i-1];
					for(int j=i-1;j>=0 && (!tok);j--) 
						if (s[j]!='?') break; else 
						if (res.s[j]<='9') tok=true; else {
							res.s[j]='0';
							res.s[j-1]++;
							if (j==0) break;
						}
					if (!tok) {
						res.res=1e19;
						return res;
					} else ok=true;
				}
		}
	for(int i=0;i<s.length();i++) 
		if (s[i]==t[i] && s[i]=='?') {
			int d=min(res.s[i],res.t[i])-'0';
			res.s[i]-=d;
			res.t[i]-=d;
		}
	res.res=0;
	for(int i=0;i<s.length();i++) 
		res.res=(res.res*10+res.t[i]-res.s[i]);
	return res;
}

bool sosanh(res_ x,res_ y) {
	if (x.res!=y.res) return x.res<y.res;
	if (x.s!=y.s) return x.s<y.s;
	return x.t<y.t;
}

void dq2(int k) {
	if (k==s.length()) {
		res.res=0;
		for(int i=0;i<s.length();i++) 
			res.res=(res.res*10+res.t[i]-res.s[i]);
		if (res.res<0) res.res=-res.res;
		if (sosanh(res,ans)) ans=res;
		return;
	}
	if (t[k]!='?') {
		dq2(k+1);
		return;
	}
	for(char ch='0';ch<='9';ch++) {
		res.t[k]=ch;
		dq2(k+1);		
	}
}

void dq1(int k) {
	if (k==s.length()) {
		dq2(0);		
		return;
	}
	if (s[k]!='?') {
		dq1(k+1);
		return;
	}
	for(char ch='0';ch<='9';ch++) {
		res.s[k]=ch;
		dq1(k+1);		
	}
}

int main() {
	freopen("input.inp","r",stdin);
	freopen("output.out","w",stdout);
	int test;
	scanf("%i\n",&test);
	for(int dem=1;dem<=test;dem++) {
		printf("Case #%i: ",dem);
		getline(cin,s,' ');
		getline(cin,t);
		res.s=s;
		res.t=t;
		ans.res=1e19;
		//dq1(0);
		if (sosanh(xuly(s,t),xuly(t,s))) {
			res=xuly(s,t);
			cout<<res.s<<" "<<res.t;
		} else {
			res=xuly(t,s);
			cout<<res.t<<" "<<res.s;
		}
		//cout<<ans.s<<" "<<ans.t;
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}