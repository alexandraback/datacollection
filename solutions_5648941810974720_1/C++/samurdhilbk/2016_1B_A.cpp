#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int tt;
	cin>>tt;
	for(int t=0;t<tt;t++){
		string s;
		cin>>s;
		int len=s.size();
		map<char,int> mp;
		string ans="";
 		for(int i=0;i<len;i++){
 			if(mp.find(s[i])!=mp.end()) mp[s[i]]++;
 			else mp[s[i]]=1;
		}
		if(mp.find('Z')!=mp.end()){
			int num=mp['Z'];
			for(int i=0;i<num;i++) ans+="0";
			mp['E']-=num;
			mp['R']-=num;
			mp['O']-=num;
		}
		if(mp.find('W')!=mp.end()){
			int num=mp['W'];
			for(int i=0;i<num;i++) ans+="2";
			mp['T']-=num;
			mp['O']-=num;
		}
		if(mp.find('U')!=mp.end()){
			int num=mp['U'];
			for(int i=0;i<num;i++) ans+="4";
			mp['F']-=num;
			mp['O']-=num;
			mp['R']-=num;
		}
		if(mp.find('X')!=mp.end()){
			int num=mp['X'];
			for(int i=0;i<num;i++) ans+="6";
			mp['S']-=num;
			mp['I']-=num;
		}
		if(mp.find('G')!=mp.end()){
			int num=mp['G'];
			for(int i=0;i<num;i++) ans+="8";
			mp['E']-=num;
			mp['I']-=num;
			mp['H']-=num;
			mp['T']-=num;
		}
		if(mp.find('T')!=mp.end()){
			int num=mp['T'];
			for(int i=0;i<num;i++) ans+="3";
			mp['H']-=num;
			mp['R']-=num;
			mp['E']-=2*num;
		}
		if(mp.find('F')!=mp.end()){
			int num=mp['F'];
			for(int i=0;i<num;i++) ans+="5";
			mp['I']-=num;
			mp['V']-=num;
			mp['E']-=num;
		}
		if(mp.find('V')!=mp.end()){
			int num=mp['V'];
			for(int i=0;i<num;i++) ans+="7";
			mp['S']-=num;
			mp['E']-=2*num;
			mp['V']-=num;
			mp['N']-=num;
		}
		if(mp.find('I')!=mp.end()){
			int num=mp['I'];
			for(int i=0;i<num;i++) ans+="9";
			mp['E']-=num;
			mp['N']-=2*num;
		}
		if(mp.find('O')!=mp.end()){
			int num=mp['O'];
			for(int i=0;i<num;i++) ans+="1";
			mp['E']-=num;
			mp['N']-=num;
		}
		sort(ans.begin(),ans.end());
		printf("Case #%d: %s\n",t+1,ans.c_str());
	}
}