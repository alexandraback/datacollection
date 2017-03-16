
/***
	AUTHOR :
	Harshil Shah
	IIT INDORE
***/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
int main(){
	map<pair<string,string>,string>m;
	string a,b,c;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cin>>a>>b>>c;
			m[make_pair(a,b)]=c;
		}
	}
	freopen("C-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	ll t,l,x;
	cin>>t;
	string s,y;
	ll cnt=0;
	string suff[200001];
	while(t--){
		cnt++;
		cin>>l>>x>>s;

		if(x>8){
			x=x%4+8;
		}

		y=s;
		for(int i=1;i<x;i++) s+=y;
		suff[s.length()-1]=s[s.length()-1];
		for(int i=s.length()-2;i>=0;i--){
			y=s[i];
			suff[i]=m[make_pair(y,suff[i+1])];
		}
		string cur;
		bool b=0;
		if(s[0]=='i')
			cur="i";//=s[0];
		else if(s[0]=='j')
			cur="j";
		else
			cur="k";
		if(cur=="i") b=1;
		bool found=0;
		for(int i=1;i<s.length()-1 and !found;i++){
			y=s[i];
			cur=m[make_pair(cur,y)];
			if(b==1 and cur=="k" and suff[i+1]=="k"){
				found=1;
				break;
			}
			if(cur=="i") b=1;
		}
		if(found==1){
			cout<<"Case #"<<cnt<<": "<<"YES\n";
		}
		else{
			cout<<"Case #"<<cnt<<": "<<"NO\n";
		}
	}
}
