/*******************
    D Rupinder
***********************/


#include<bits/stdc++.h>

#define lld long long int
#define FOR(i,a,b) for(i= a ; i < b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define all(x) x.begin(),x.end()
#define LET(x,a) __typeof(a) x(a)
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define pb push_back
#define sz size()
#define pii pair<int, int>
#define pll pair <lld ,lld>
#define mp make_pair
#define fill(x,v) memset(x,v,sizeof(x))
#define scan(v,n) vector<int> v(n);rep(i,n)cin>>v[i];
#define vi vector<int>
#define MOD 1e9 + 7

using namespace std;
lld modpow(lld a,lld n,lld temp){lld res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 
string te;
double num,den,max1;
void go (int s, string &key, string &tar, int cur, string &temp) {
	if (cur == s) {
		den++;
		double cnt = 0;
		for (int i = 0; i < temp.size(); i++)
			if (temp.substr(i, tar.size()) == tar) {
				cnt++;
				num++;
			}
		max1 = max(cnt, max1);
	} else {
		for (int i =0; i < key.size(); i++) {
			string te2=temp+key[i];
			go(s,key,tar,cur+1,te2);
		}
	}
	return;
}
int main()
{
	int t;
	cin>>t;
	int T=t;
	while (t--) {
		num=den=0;max1=-1;
		int k,l,s;
		cin>>k>>l>>s;
		string key, tar;
		cin>>key>>tar;
		te="";
		go(s,key,tar,0,te);
		printf("Case #%d: %.7lf\n", T-t, max1 - num/den);
	}
	return 0;
}
