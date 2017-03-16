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

string s1,s2;

bool fits(int x, string s) {
	//cout<<x<<" "<<s<<endl;
	char s2[10]={0};
	int i =0;
	int xx = x;
	while(x>0) {
		s2[i++]=(x%10);
		x/=10;
	}
	reverse(s.begin(),s.end());

	bool ret = true;
	i = 0;
	for(char y : s) {
		
		if(y!='?' && y-'0'!= s2[i]) ret = false;
		++i;
	}
//	if(ret) cout<<xx<<" "<<s<<" "<<s2<<endl;
	return ret;
}
int main() {
	int t;
	cin>>t;
	for(int tt=1;tt<=t;++tt) {
		cout<<"Case #"<<tt<<": ";
		cin>>s1;
		cin>>s2;
	//	cout<<s1.size()<<" "<<s2.size()<<endl;
		int besti,bestj;
		int diff = 1000000;
		string x;
		int high = 999;
		if(s1.size()==1)high=9;
		else if(s1.size()==2) high = 99;
		else if(s1.size()==3)high = 999;
		repi(i,0,high+1) repi(j,0,high + 1) {
			if(fits(i,s1) && fits(j,s2)) {
			//	cout<<i <<" "<<j<<endl;
				if(abs(j-i) < diff) {
					besti = i;
					bestj = j;
					diff = abs(j-i);
			//		cout<<diff<<" "<<i<<" "<<j<<endl;
				}
			}
		}
	//	for(int i=0;i<15;++i) cout<<i<<" "<<fits(i,s1)<<endl;
		int k1 = s1.size() - (besti>99) - (besti>9) - 1;
		int k2 = s1.size() - (bestj>99) - (bestj>9) - 1;
		repi(i,0,k1) cout<<"0";
		cout<<besti<<" ";
		repi(i,0,k2) cout<<"0";
		cout<<bestj<<endl;

		//cout<<besti<<" "<<bestj<<endl;
	}
	return 0;
}