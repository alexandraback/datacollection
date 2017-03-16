#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;

string tostr(int n)
{
	char buf[10];
	sprintf(buf,"%d",n);
	return buf;
}
int toint(const string& s)
{
	int res=0;
	for(int i=0;i<s.size();i++)
		res=res*10+s[i]-'0';
	return res;
}

void solve(){
	int a,b; cin>>a>>b;
	int res=0;
	for(int x=a;x<=b;x++){
		string s=tostr(x);
		unordered_set<int> ys;
		for(int i=0;i<s.size();i++){
			rotate(s.begin(),s.begin()+1,s.end());
			int y=toint(s);
			if(x<y && a<=y && y<=b)
				ys.insert(y);
		}
		res+=ys.size();
	}
	cout<<res<<endl;
}

int main()
{
	int tc; cin>>tc;
	for(int i=1;i<=tc;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
