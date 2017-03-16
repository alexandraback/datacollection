#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

long long power_m(long long a){
	long long s=1;
	for(long long i=2;i<=a;i++){
		s*=i;
		s %= 1000000007;
	}
	return s;
}

int main(){
	int time;
	cin>>time;
	for(int tt=1;tt<=time;tt++){
		bool flag = true;
		int N; cin>>N;
		bool char_c[26];
		for(int i=0;i<26;i++){
			char_c[i]=false;
		}
		vector<string> all;
		vector<string> head[26],tail[26],hetail[26];
		for(int n=0;n<N;n++){
			string s;
			cin>>s;
			bool flag_ht = false;
			if(s[0]==s[s.size()])flag_ht = true;
			vector<char> cs;
			bool char_cc[26];
			for(int i=0;i<26;i++)char_cc[i]=false;
			for(int i=0;i<s.size();i++){
				if(char_c[s[i]-97]==false){
					char_c[s[i]-97]=true;
				}else{
					if(i!=0&&i!=s.size()-1)
						if(s[i-1]!=s[i]&&s[i+1]!=s[i])
							flag = false;
				}
				if(char_cc[s[i]-97]==false){
					char_cc[s[i]-97]=true;
					cs.push_back(s[i]);
				}
			}
			if(cs.size()>2&&flag_ht)flag = false;
			if(!flag)break;
			all.push_back(s);
			if(flag_ht)hetail[s[0]-97].push_back(s);
			else{
				head[s[0]-97].push_back(s);
				tail[s[s.size()]-97].push_back(s);
			}
		}
		cout<<"Case #"<<tt<<": ";
		if(!flag){
			cout<<"0\n"; continue;
		}
		for(int i=0;i<26;i++){
			if(head[i].size()>1){
				flag = false;
				break;
			}
			if(tail[i].size()>1){
				flag = false;
				break;
			}
		}
		if(!flag){
			cout<<"0\n"; continue;
		}
		long long ans = 1,block = 1;
		for(int i=0;i<26;i++){
			if(head[i].size()==0&&hetail[i].size()!=0)block++;
			if(tail[i].size()==0&&hetail[i].size()!=0)block++;
			ans *= power_m(hetail[i].size());
			ans%=1000000007;
		}
		ans*=power_m(block);
		ans%=1000000007;
		cout<<ans<<endl;		
	}
}
