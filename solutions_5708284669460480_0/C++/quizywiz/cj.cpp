#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;++i)
#define repi(i,a,b) for( int i=a;i<b;++i)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define vi vector<int>
#define sc(a) scanf("%d",&a)
#define pb(a) push_back(a)

int t,k,l,s;
double ans;
double prob[26];
string targ,gen;
set<char> keys;
string temp;
int maxti;
void doit(double pro=1, int i = 0)
{
	if(i>=s)
	{
		int ti = 0;
		auto pos = temp.find(targ);
		while(pos!=string::npos)
		{
		//	cout<<temp<<endl;
			++ti;
			pos = temp.find(targ,pos+1);
		}
		ans += ti*pro;
		maxti = max(maxti,ti);
	}
	else
	{
		for(char c:keys)
		{
			temp.pb(c);
			doit(pro*prob[c-'A'],i+1);
			temp.pop_back();
		}
	}
}
int main() {
	// your code goes here
	
	cin>>t;
	repi(i,1,t+1)
	{
		maxti=0;
		cin>>k>>l>>s;
		cin>>gen>>targ;
		temp.clear();
		keys.clear();
		for(int i = 0;i<26;++i)prob[i]=0;
		for(char c:gen)
		{
			prob[c-'A']++;
			keys.insert(c);
		}
		//cout<<"probs ";for(int i=0;i<26;++i)cout<<prob[i]<<" ";cout<<endl;
		
		for(int i=0;i<26;++i)prob[i]/=k;

		//cout<<"probs ";for(int i=0;i<26;++i)cout<<prob[i]<<" ";cout<<endl;
		ans = 0;
		doit();

		cout<<"Case #"<<i<<": ";
		cout<<setprecision(7)<<maxti-ans;
		cout<<endl;
	}
	return 0;

}