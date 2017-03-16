#include <bits/stdc++.h>
using namespace std;

vector<int> r[3],t[3];
vector<string> go,jam;
int n,m;
void make(int x,string s){
	if(x==n){
		go.push_back(s);
		return;
	}
	int i;
	for(i=0;i<r[x].size();++i)
		make(x+1,s+char('0'+r[x][i]));
}
void m2(int x,string s){
	if(x==m){
		jam.push_back(s);
		return;
	}
	int i;
	for(i=0;i<t[x].size();++i){
		m2(x+1,s+char('0'+t[x][i]));
	}
}
int num(string s){
	int i,ret=0;
	for(i=0;i<s.size();++i){
		ret*=10;ret+=s[i]-'0';
	}
	return ret;
}
int main(){
	int T,i,j,k;
	string a,b;
	cin>>T;
	for(int test=1;test<=T;++test){
		cin>>a>>b;
		n= a.size(),m= b.size();
		go.clear();jam.clear();
		for(i=0;i<3;++i)
			r[i].clear(),t[i].clear();
		
		for(i=0;i<a.size();++i){
			if(a[i]=='?'){
				for(j=0;j<10;++j)
					r[i].push_back(j);
			}
			else
				r[i].push_back(a[i]-'0');
		}
		for(i=0;i<b.size();++i){
			if(b[i]=='?'){
				for(j=0;j<10;++j)
					t[i].push_back(j);
			}
			else
				t[i].push_back(b[i]-'0');
		}
		make(0,"");
		m2(0,"");
		//cout<<jam.size()<<endl;
		vector<pair<string,string> > T;int diff = 1e9,temp;	
		for(i=0;i<go.size();++i)
			for(j=0;j<jam.size();++j){
				temp = abs(num(go[i])-num(jam[j]));
				if(temp<=diff){
					if(temp!=diff)T.clear();
					T.push_back(make_pair(go[i],jam[j]));
					diff= temp;
				}
			}
		sort(T.begin(),T.end());
		cout<<"Case #"<<test<<": "<<T[0].first<<" "<<T[0].second<<endl;
	}
}
