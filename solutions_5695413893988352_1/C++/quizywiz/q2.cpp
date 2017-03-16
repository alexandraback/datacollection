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

bool fits(LL x, string s) {
	//cout<<x<<" "<<s<<endl;
	char s2[10]={0};
	int i =0;
	LL xx = x;
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
LL stoi(string s) {
	LL x = 0;
	for(char y:s) {
		x = x*10 + (y-'0');
	}
	return x;
}
string fill(string s, int a) {
	for(char& x: s) {
		if(x=='?') x = a + '0';
	}
	return s;
}
pair<LL,LL> change(LL& diff, LL a1, LL a2, pair<LL,LL> ans){
	//cout<<a1<<" "<<a2<<" "<<diff<<endl;
	if(diff > abs(a1-a2)) {
		diff = abs(a1-a2);
		return make_pair(a1,a2);
	} else if(diff == abs(a1-a2) && a1<ans.F) {
		diff = abs(a1-a2);
		return make_pair(a1,a2);	
	} else if (diff == abs(a1-a2) && a1==ans.F && a2 < ans.S) {
		return mp(a1,a2);
	}
	return ans;
}
int main() {
	int t;
	cin>>t;
	for(int tt=1;tt<=t;++tt) {
		cout<<"Case #"<<tt<<": ";
		cin>>s1;
		cin>>s2;
		pair<LL,LL> ans;
		LL diff = 1000000000000000000LL;
		bool di = false;
		for(int i=0;i<s1.size();++i) {
			//op1
			if(s1[i]!='?' && s2[i]!='?' && s1[i] != s2[i]) {
				LL a1 = stoi(fill(s1,9));
				LL a2 = stoi(fill(s2,0));
				LL a3 = stoi(fill(s1,0));
				LL a4 = stoi(fill(s2,9));
				ans = change(diff, a1, a2, ans);
				ans = change(diff, a3, a4,ans);
				di = true;
				break;
			} else if(s1[i]!='?' && s2[i]=='?') {
				s2[i] = (s1[i]=='9'?'0':s1[i]+1);
				LL a1 = stoi(fill(s1,9));
				LL a2 = stoi(fill(s2,0));
				LL a3 = stoi(fill(s1,0));
				LL a4 = stoi(fill(s2,9));
				ans = change(diff, a1, a2, ans);
				ans = change(diff, a3, a4,ans);

				s2[i] = (s1[i]=='0'?'9':s1[i]-1);
				 a1 = stoi(fill(s1,9));
				 a2 = stoi(fill(s2,0));
				 a3 = stoi(fill(s1,0));
				 a4 = stoi(fill(s2,9));
				ans = change(diff, a1, a2, ans);
				ans = change(diff, a3, a4,ans);	
				s2[i] = s1[i];
				continue;
			} else if(s2[i]!='?' && s1[i]=='?') {
				s1[i] = (s2[i]=='9'?'0':s2[i]+1);
				LL a1 = stoi(fill(s1,9));
				LL a2 = stoi(fill(s2,0));
				LL a3 = stoi(fill(s1,0));
				LL a4 = stoi(fill(s2,9));
				ans = change(diff, a1, a2, ans);
				ans = change(diff, a3, a4,ans);

				s1[i] = (s2[i]=='0'?'9':s2[i]-1);
				a1 = stoi(fill(s1,9));
				 a2 = stoi(fill(s2,0));
				 a3 = stoi(fill(s1,0));
				 a4 = stoi(fill(s2,9));
				ans = change(diff, a1, a2, ans);
				ans = change(diff, a3, a4,ans);	
				s1[i] = s2[i];
				continue;
			} else if(s1[i]=='?' && s2[i]=='?'){
				s1[i] = '0';
				s2[i] = '1';
				LL a1 = stoi(fill(s1,9));
				LL a2 = stoi(fill(s2,0));
				LL a3 = stoi(fill(s1,0));
				LL a4 = stoi(fill(s2,9));
				ans = change(diff, a1, a2, ans);
				ans = change(diff, a3, a4,ans);

				s1[i]='1';
				s2[i]='0';
				 a1 = stoi(fill(s1,9));
				 a2 = stoi(fill(s2,0));
				 a3 = stoi(fill(s1,0));
				 a4 = stoi(fill(s2,9));
				ans = change(diff, a1, a2, ans);
				ans = change(diff, a3, a4,ans);

				s1[i]='0';
				s2[i]='0';
				continue;
			}
		}
		if(!di)ans = change(diff, stoi(s1), stoi(s2), ans);
		LL x1 = ans.F;
		LL x2 = ans.S;
		int z1=0,z2=0;
		while(x1>0) {
			z1++;
			x1/=10;
		}
		z1 = max(1,z1);
		while(x2>0) {
			z2++;
			x2/=10;
		}
		z2 = max(1,z2);
		repi(i,0,s1.size()-z1) cout<<"0";
		cout<<ans.F<<" ";
		repi(i,0,s1.size()-z2) cout<<"0";
		cout<<ans.S<<endl;

		//cout<<besti<<" "<<bestj<<endl;
	}
	return 0;
}