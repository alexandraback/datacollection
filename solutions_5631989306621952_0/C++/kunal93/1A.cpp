#include<bits/stdc++.h>
using namespace std;
void eval(){
	string s;
	cin>>s;
	string r;
	r+=s[0];
	int l = s.size();
	for(int i=1;i<l;i++)
	{
		if(s[i]>=r[0])
			r=s[i]+r;
		else
			r=r+s[i];
	}
	cout<<r<<endl;
}

int main(){
	int t;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	cin>>t;
	for(int te=1;te<=t;te++){
		cout<<"Case #"<<te<<": ";
		eval();
	}
}
