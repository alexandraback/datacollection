#include <iostream>
#include <vector>
#include <stdio.h>
#include <stack>
#include <queue>
#include <string>
using namespace std;

long long s1,s2;
bool hs_sol;
int T;
string in1,in2;
int n;

long long fabs(long long h){
	if(h<0)return -h;
	return h;
}
void add_sol(long long t1,long long t2){
	if(!hs_sol){
		hs_sol=true;
		s1=t1;
		s2=t2;
		return;
	}
	if(fabs(t1-t2) < fabs(s1-s2)){
		s1=t1;
		s2=t2;
		return;
	} else if (fabs(t1-t2) == fabs(s1-s2)){
		if(t1<s1){
			s1=t1;
			s2=t2;
			return;
		} else if(t1==s1){
			if(t2<s2){
				s1=t1;
				s2=t2;
				return;
			}
		}
	}
}

long long get_min(long long init,string s){
	int m=s.length();
	for(int i=0;i<m;i++){
		init*=10;
		if(s[i]=='?'){
			continue;
		} else {
			init+=s[i]-'0';
		}
	}
	return init;
}
long long get_max(long long init,string s){
	int m=s.length();
	for(int i=0;i<m;i++){
		init*=10;
		if(s[i]=='?'){
			init+=9;
		} else {
			init+=s[i]-'0';
		}
	}
	return init;
}
char get_val(char a,char b){
	if(a=='?' && b=='?'){
		return '0';
	} else if(a=='?'){
		return b;
	} else {
		return a;
	}
}
string get_next_sol(string pattern,string solution){
	int m=pattern.length();
	bool hand=true;
	for(int i=m-1;i>=0;i--){
		if(!hand)break;
		if(pattern[i]=='?'){
			hand=false;
			if(solution[i]=='9'){
				hand=true;
				solution[i]='0';
			} else {
				solution[i]++;
			}
		}
	}
	return solution;
}
long long to_num(string h){
	int m=h.length();
	long long ret=0;
	for(int i=0;i<m;i++){
		ret*=10;
		ret+=h[i]-'0';
	}
	return ret;
}
string get_prev_sol(string pattern,string solution){
	int m=pattern.length();
	bool hand=true;
	for(int i=m-1;i>=0;i--){
		if(!hand)break;
		if(pattern[i]=='?'){
			hand=false;
			if(solution[i]=='0'){
				hand=true;
				solution[i]='9';
			} else {
				solution[i]--;
			}
		}
	}
	return solution;
}
int main(){
	freopen("inn.in","r",stdin);
	freopen("111.txt","w",stdout);
	cin>>T;
	for(int jj=1;jj<=T;jj++){
		cin>>in1>>in2;
		cout<<"Case #"<<jj<<": ";
		int n=in1.length();
		hs_sol=false;
		int ind_st=-1;
		for(int i=0;i<n;i++){
			if(in1[i]!='?' && in2[i]!='?' && in1[i]!=in2[i]){
				ind_st=i;
				break;
			}
		}
		if(ind_st==-1){
			string ans="";
			for(int i=0;i<n;i++){
				ans+=get_val(in1[i],in2[i]);
			}
			cout.width(0);
			cout<<ans<<" "<<ans<<endl;
			continue;
		}
		string sol="";
		for(int i=0;i<ind_st;i++){
			sol+=get_val(in1[i],in2[i]);
		}
		add_sol(get_max(to_num(sol),in1.substr(ind_st,n-ind_st)), get_min(to_num(sol),in2.substr(ind_st,n-ind_st)));
		add_sol(get_min(to_num(sol),in1.substr(ind_st,n-ind_st)), get_max(to_num(sol),in2.substr(ind_st,n-ind_st)));
		add_sol(get_min(to_num(sol),in1.substr(ind_st,n-ind_st)), get_min(to_num(sol),in2.substr(ind_st,n-ind_st)));
		add_sol(get_max(to_num(sol),in1.substr(ind_st,n-ind_st)), get_max(to_num(sol),in2.substr(ind_st,n-ind_st)));

		add_sol(get_max(to_num(get_prev_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_min(to_num(sol),in2.substr(ind_st,n-ind_st)));
		add_sol(get_min(to_num(get_prev_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_max(to_num(sol),in2.substr(ind_st,n-ind_st)));
		add_sol(get_min(to_num(get_prev_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_min(to_num(sol),in2.substr(ind_st,n-ind_st)));
		add_sol(get_max(to_num(get_prev_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_max(to_num(sol),in2.substr(ind_st,n-ind_st)));
	
		add_sol(get_max(to_num(get_next_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_min(to_num(sol),in2.substr(ind_st,n-ind_st)));
		add_sol(get_min(to_num(get_next_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_max(to_num(sol),in2.substr(ind_st,n-ind_st)));
		add_sol(get_min(to_num(get_next_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_min(to_num(sol),in2.substr(ind_st,n-ind_st)));
		add_sol(get_max(to_num(get_next_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_max(to_num(sol),in2.substr(ind_st,n-ind_st)));
	
		/////////
		add_sol(get_max(to_num(sol),in1.substr(ind_st,n-ind_st)), get_min(to_num(get_prev_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
		add_sol(get_min(to_num(sol),in1.substr(ind_st,n-ind_st)), get_max(to_num(get_prev_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
		add_sol(get_min(to_num(sol),in1.substr(ind_st,n-ind_st)), get_min(to_num(get_prev_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
		add_sol(get_max(to_num(sol),in1.substr(ind_st,n-ind_st)), get_max(to_num(get_prev_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));

		add_sol(get_max(to_num(get_prev_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_min(to_num(get_prev_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
		add_sol(get_min(to_num(get_prev_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_max(to_num(get_prev_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
		add_sol(get_min(to_num(get_prev_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_min(to_num(get_prev_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
		add_sol(get_max(to_num(get_prev_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_max(to_num(get_prev_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
	
		add_sol(get_max(to_num(get_next_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_min(to_num(get_prev_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
		add_sol(get_min(to_num(get_next_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_max(to_num(get_prev_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
		add_sol(get_min(to_num(get_next_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_min(to_num(get_prev_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
		add_sol(get_max(to_num(get_next_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_max(to_num(get_prev_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
	


		add_sol(get_max(to_num(sol),in1.substr(ind_st,n-ind_st)), get_min(to_num(get_next_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
		add_sol(get_min(to_num(sol),in1.substr(ind_st,n-ind_st)), get_max(to_num(get_next_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
		add_sol(get_min(to_num(sol),in1.substr(ind_st,n-ind_st)), get_min(to_num(get_next_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
		add_sol(get_max(to_num(sol),in1.substr(ind_st,n-ind_st)), get_max(to_num(get_next_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));

		add_sol(get_max(to_num(get_prev_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_min(to_num(get_next_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
		add_sol(get_min(to_num(get_prev_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_max(to_num(get_next_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
		add_sol(get_min(to_num(get_prev_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_min(to_num(get_next_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
		add_sol(get_max(to_num(get_prev_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_max(to_num(get_next_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
	
		add_sol(get_max(to_num(get_next_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_min(to_num(get_next_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
		add_sol(get_min(to_num(get_next_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_max(to_num(get_next_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
		add_sol(get_min(to_num(get_next_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_min(to_num(get_next_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
		add_sol(get_max(to_num(get_next_sol(in1.substr(0,ind_st+1),sol)),in1.substr(ind_st,n-ind_st)), get_max(to_num(get_next_sol(in2.substr(0,ind_st+1),sol)),in2.substr(ind_st,n-ind_st)));
		
		cout.width(n);
		cout.fill('0');
		cout<<s1<<" ";

		cout.width(n);
		cout.fill('0');
		cout<<s2<<endl;

	}
}