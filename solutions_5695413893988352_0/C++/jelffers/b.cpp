#include<bits/stdc++.h>
using namespace std;
string subst(string s,char what){for(char&c:s)if(c=='?')c=what;return s;}
long long toint(string s){long long re=0;for(char c:s)re*=10,re+=c-'0';return re;}
pair<long long,pair<string,string>> key(string a,string b){return make_pair(abs(toint(a)-toint(b)),make_pair(a,b));}
vector<string>poss(string s){
	vector<string>re(1,s);
	while(count(re[0].begin(),re[0].end(),'?')){
		vector<string>re2;
		for(string s:re){
			for(int i=0;;i++)if(s[i]=='?'){for(int v=0;v<10;v++){string t=s;t[i]='0'+v;re2.push_back(t);}break;}
		}
		re=re2;
	}
	return re;
}
string reA,reB;
// A <= B
void dfs1(string A,string B,int i){
	if (i==(int)A.size()) {
		if (reA.empty() || key(A,B)<key(reA,reB))reA=A,reB=B;
		return;
	}
	int la=(A[i]=='?')?0:(A[i]-'0'),ua=(A[i]=='?')?9:(A[i]-'0');
	int lb=(B[i]=='?')?0:(B[i]-'0'),ub=(B[i]=='?')?9:(B[i]-'0');
	for(int ca=la;ca<=ua;ca++)for(int cb=lb;cb<=ub;cb++) {
		string A2=A,B2=B;
		A2[i]='0'+ca,B2[i]='0'+cb;
		if(subst(A2,'0')<=subst(B2,'9')){
			bool qmark=A[i]=='?';
			if(!qmark){A=A2;B=B2;dfs1(A,B,i+1);}else {
				while(1){
					A=A2,B=B2;
					ca++;
					A2[i]='0'+ca;
					if(ca==10 || subst(A2,'0')>subst(B2,'9'))break;
				}
				dfs1(A,B,i+1);
				if(A[i]>'0') { A[i]--;dfs1(A,B,i+1); }
			}
		}
	}
}
void dfs2(string A,string B,int i){
	if (i==(int)A.size()) {
		if (reA.empty() || key(A,B)<key(reA,reB))reA=A,reB=B;
		return;
	}
	int la=(A[i]=='?')?0:(A[i]-'0'),ua=(A[i]=='?')?9:(A[i]-'0');
	int lb=(B[i]=='?')?0:(B[i]-'0'),ub=(B[i]=='?')?9:(B[i]-'0');
	for(int ca=la;ca<=ua;ca++)for(int cb=lb;cb<=ub;cb++) {
		string A2=A,B2=B;
		A2[i]='0'+ca,B2[i]='0'+cb;
		if(subst(A2,'9')>=subst(B2,'0')){
			bool qmark=B[i]=='?';
			if(!qmark){A=A2,B=B2;dfs2(A,B,i+1);}else {
				while(1){
					A=A2,B=B2;
					cb++;
					B2[i]='0'+cb;
					if(cb==10 || subst(A2,'9')<subst(B2,'0'))break;
				}
				dfs2(A,B,i+1);
				if(B[i]>'0') { B[i]--;dfs2(A,B,i+1); }
			}
		}
	}
}
int main(){
	int T; cin >> T;
	for (int tc=1;tc<=T;tc++){
		string _A,_B; cin >> _A >> _B;
		//cout << "Input: " << _A << " " << _B << endl;
		reA="",reB="";
		// 1. A <= B.
		if(subst(_A,'0')<=subst(_B,'9'))dfs1(_A,_B,0);
		if(subst(_A,'9')>=subst(_B,'0'))dfs2(_A,_B,0);
		//cout<<"ans: "<<reA<<" "<<reB<<endl;
		/*for(string sa:poss(_A))for(string sb:poss(_B)){
			if (key(sa,sb) < key(reA,reB)) {
				cout << sa << " " << sb << endl;
				assert(false);
			}
		}*/
		printf("Case #%d: %s %s\n",tc,reA.c_str(),reB.c_str());
	}
}
