#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <sstream>
#include <map>
#include <queue>
#include <stack>

using namespace std;

set<int> num1,num2;

void dfs1(string s,int pos){
	if(pos==s.size()){
		num1.insert(atoi(s.c_str()));
		//cout<<s<<" "<<atoi(s.c_str())<<endl;
	}else if(s[pos]!='?'){
		dfs1(s,pos+1);
	}else{
		for(char c='0';c<='9';c++){
			string ns=s;
			ns[pos]=c;
			dfs1(ns,pos+1);
		}
	}
}

void dfs2(string s,int pos){
	if(pos==s.size()){
		num2.insert(atoi(s.c_str()));
		//cout<<s<<" "<<atoi(s.c_str())<<endl;
	}else if(s[pos]!='?'){
		dfs2(s,pos+1);
	}else{
		for(char c='0';c<='9';c++){
			string ns=s;
			ns[pos]=c;
			dfs2(ns,pos+1);
		}
	}
}

int main()
{
		
    int T;
    cin>>T;
	
    for(int t=1;t<=T;t++){
		
		num1.clear();
		num2.clear();

		string s1,s2;
		cin>>s1>>s2;

		dfs1(s1,0);
		dfs2(s2,0);
		int res1,res2;
		int d=10000000;
		for(auto it=num1.begin();it!=num1.end();it++){
			for(auto it2=num2.begin();it2!=num2.end();it2++){
				if(d>abs(*it-*it2)){
					res1=*it; res2=*it2;
					d=abs(res1-res2);
				}
			}
		}
		if(s1.size()==1) printf("Case #%d: %d %d\n",t,res1,res2);
		if(s1.size()==2) printf("Case #%d: %02d %02d\n",t,res1,res2);
		if(s1.size()==3) printf("Case #%d: %03d %03d\n",t,res1,res2);
    }
    
    return 0;
}