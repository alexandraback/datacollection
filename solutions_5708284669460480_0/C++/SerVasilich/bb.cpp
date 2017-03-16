#include <bits\stdc++.h>

using namespace std;
#define ll long long

int T;

void test(int nom)
{     ll k,l,s,su=0,t,ma=0,ki=0; int cur=0,f=1; string ms,ss; set <char> m;
      map<string,ll> mp[2]; map<string,ll> ::iterator it;
      cin>>k>>l>>s>>ms>>ss; 
	  for(int i=0;i<ms.size();i++) m.insert(ms[i]);
	  for(int i=0;i<ss.size();i++) if (m.find(ss[i])==m.end()) {f=0; break;}; 
	  if (!f) {cout<<"Case #"<<nom<<": 0.0\n"; return;} 
	  mp[0][""]=1;
	  for(int i=0;i<s;i++) {mp[1-cur].clear(); 
		for(it=mp[cur].begin();it!=mp[cur].end();it++)
			for(int j=0;j<ms.size();j++) mp[1-cur][it->first+ms[j]]+=it->second;
		cur=1-cur;}
	  for(it=mp[cur].begin();it!=mp[cur].end();it++){t=0; su+=it->second;
	    //cout<<it->first<<' '<<it->second<<'*'<<'\n';
		for(int j=0;j<=s-l;j++) if ((it->first).substr(j,l)==ss) t++;
	    ma=max(ma,t); ki+=t*it->second; }
	  //cout<<"Case #"<<nom<<": "<<ma<<' '<<ki<<' '<<su<<'\n';
	  cout<<"Case #"<<nom<<": "<<double(ma)-(double)ki/su<<'\n';
}

int main ( )
{
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
 
 cin>>T; cout.precision(7); cout<<fixed;
 for(int i=1;i<=T;++i) test(i);
}
