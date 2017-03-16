#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;++i)
#define repi(i,a,b) for(int i=a;i<b;++i)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define vi vector<int>
#define sc(a) scanf("%d",&a)
#define pb(a) push_back(a)
#define pr(a) printf("%d",a)
#define prn(a) printf("%d\n",a)
#define scll(a) scanf("%lld",&a)
#define prll(a) printf("%lld",a)
#define prlln(a) printf("%lld\n",a)
typedef long long LL;

string s;
int a[10];
int al[26];
string nums[] = {"ZERO","TWO","EIGHT","THREE","SIX","FOUR","FIVE","SEVEN","NINE","ONE"};
int numint[] = {0,2,8,3,6,4,5,7,9,1};
string spec = "ZWGHXUFVIO";
void remo(string s, int m) {
	for(char x : s) {
		al[x-'A'] -= m;
	}
}
int main() {

	int t;
	cin>>t;
	repi(tt,1,t+1) {
		cin>>s;
		cout<<"Case #"<<tt<<": ";
		repi(i,0,10) a[i] = 0;
		repi(i,0,26) al[i] = 0;
		for(char x : s) {
			al[x-'A']++;
		}

		for(int i=0; i<10;++i) {
			char x = spec[i];
			string num = nums[i];
			if(al[x-'A'] > 0) {
				int m = al[x-'A'];
			//	cout<<x<<" "<<m<<endl;
				remo(num, m);
				a[numint[i]]+=m;
			}
		}
		repi(i,0,10) repi(j,0,a[i]) cout<<i;
		cout<<endl;
	}
	return 0;
}