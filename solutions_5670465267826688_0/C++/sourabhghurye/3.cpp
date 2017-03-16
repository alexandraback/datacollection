#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

char mult(char c1,char c2,bool &b){
	if(c1=='1' && c2=='1'){ return '1';}
	if(c1=='1' && c2=='i'){ return 'i';}
	if(c1=='1' && c2=='j'){ return 'j';}
	if(c1=='1' && c2=='k'){ return 'k';}
	
	if(c1=='i' && c2=='1'){ return 'i';}
	if(c1=='i' && c2=='i'){ b=!b; return '1';}
	if(c1=='i' && c2=='j'){ return 'k';}
	if(c1=='i' && c2=='k'){ b=!b; return 'j';}
	
	if(c1=='j' && c2=='1'){ return 'j';}
	if(c1=='j' && c2=='i'){ b=!b; return 'k';}
	if(c1=='j' && c2=='j'){ b=!b; return '1';}
	if(c1=='j' && c2=='k'){ return 'i';}
	
	if(c1=='k' && c2=='1'){ return 'k';}
	if(c1=='k' && c2=='i'){ return 'j';}
	if(c1=='k' && c2=='j'){ b=!b; return 'i';}
	if(c1=='k' && c2=='k'){ b=!b; return '1';}
}
	
	
	
int main(){
	int t;cin>>t;
	for(int qq=1;qq<=t;qq++){
		int l,x;  cin>>l>>x;
		string s; cin>>s;
		
		char c='1';bool b=1; int i=0;
		bool end=0,ans=0;
		
		string cp=s;
		for(int i=0;i<x-1;i++) s+=cp;
		
		//cout<<s<<endl;
		while(c!='i'){
			if(i==s.size()) {end=1;break;}
			c=mult(c,s[i],b);
			i++;
		}
		//cout<<i<<endl;
		if(!end){
			c='1';
			while(c!='j'){
				if(i==s.size()) {end=1;break;}
				c=mult(c,s[i],b);
				i++;
			}
			//cout<<i<<endl;
			if(!end){
				c='1';
				while(i!=s.size()){
					c=mult(c,s[i],b);
					i++;
				}
				//cout<<c<<" "<<b<<" "<<x<<endl;
				if(c=='k' && b) ans=1;
			}
		}
		
		if(ans) cout<<"Case #"<<qq<<": YES"<<endl;
		else cout<<"Case #"<<qq<<": NO"<<endl;
	}
}
