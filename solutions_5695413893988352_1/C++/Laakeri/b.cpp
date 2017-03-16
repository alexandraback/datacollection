#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, pair<ll, ll> > asd;

ll low(string s){
	ll k=1;
	ll r=0;
	for (int i=(int)s.size()-1;i>=0;i--){
		ll t=0;
		if (s[i]!='?'){
			t=(ll)(s[i]-'0');
		}
		r+=k*t;
		k*=10ll;
	}
	return r;
}

ll high(string s){
	ll k=1;
	ll r=0;
	for (int i=(int)s.size()-1;i>=0;i--){
		ll t=9;
		if (s[i]!='?'){
			t=(ll)(s[i]-'0');
		}
		r+=k*t;
		k*=10ll;
	}
	return r;
}

void get(vector<asd>&v, string s1, string s2){
	ll v1h=high(s1);
	ll v1l=low(s1);
	ll v2h=high(s2);
	ll v2l=low(s2);
	v.push_back({llabs(v1h-v2h), {v1h, v2h}});
	v.push_back({llabs(v1h-v2l), {v1h, v2l}});
	v.push_back({llabs(v1l-v2h), {v1l, v2h}});
	v.push_back({llabs(v1l-v2l), {v1l, v2l}});
}

void solve(){
	string s1,s2;
	cin>>s1>>s2;
	vector<asd> v;
	get(v, s1, s2);
	int n=s1.size();
	for (int i=0;i<n;i++){
		if (s1[i]=='?'&&s2[i]=='?'){
			for (s1[i]='0';s1[i]<='9';s1[i]++){
				for (s2[i]='0';s2[i]<='9';s2[i]++){
					get(v, s1, s2);
				}
			}
			s1[i]='0';
			s2[i]='0';
		}
		else if(s1[i]=='?'){
			for (s1[i]='0';s1[i]<='9';s1[i]++){
				get(v, s1, s2);
			}
			s1[i]=s2[i];
		}
		else if(s2[i]=='?'){
			for (s2[i]='0';s2[i]<='9';s2[i]++){
				get(v, s1, s2);
			}
			s2[i]=s1[i];
		}
	}
	sort(v.begin(), v.end());
	ll v1=v[0].S.F;
	ll v2=v[0].S.S;
	string vv1,vv2;
	for (int i=0;i<n;i++){
		vv1+=(char)(v1%10ll+'0');
		vv2+=(char)(v2%10ll+'0');
		v1/=10ll;
		v2/=10ll;
	}
	reverse(vv1.begin(), vv1.end());
	reverse(vv2.begin(), vv2.end());
	cout<<vv1<<" "<<vv2<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tcs;
	cin>>tcs;
	for (int tc=1;tc<=tcs;tc++){
		cout<<"Case #"<<tc<<": ";
		solve();
	}
}