#include <iostream>
#include <string>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;
double cha[26];
double ans;
int times=0;
int maxi;
string target;
double cau(string t){
	int copies=0;
	for(int i=0;i<t.size();i++){
		bool tof=true;
		for(int j=0;j<target.size();j++){
			if(i+j>=t.size())tof=false;
			if(i+j<t.size()&&target[j]!=t[i+j])tof=false;
		}
		if(tof)copies++;
	}
	maxi=max(maxi,copies);
	double tchance=1;
	for(int i=0;i<t.size();i++){
		tchance*=cha[t[i]-'A'];
	}
	return tchance*copies;
}
void dfs(int len,string now){
//	cout<<len<<' '<<now.size()<<endl;
	if(now.size()==len){
		ans+=cau(now);
		times++;
	}else{
		for(int i=0;i<26;i++){
			if(cha[i]>0){
				dfs(len,now+(char)('A'+i));
			}
		}
	}
}
int main(){
	int tc;cin>>tc;
	int i=0;
	while(tc-->0){
		i++;
		int k,l,s;
		cin>>k>>l>>s;
		memset(cha,0,sizeof(cha));
		ans=maxi=0;
		string kb;cin>>kb;
		cin>>target;
		for(int i=0;i<k;i++){
			cha[kb[i]-'A']++;
		}
		for(int i=0;i<26;i++){
			cha[i]/=k;
		}
		dfs(s,"");
		cout<<"Case #"<<i<<": ";
		cout<<fixed<<setprecision(10)<<(1.*maxi)-ans<<endl;
	}
	return 0;
}
