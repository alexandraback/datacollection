#include <bits/stdc++.h>
using namespace std;
typedef long long               ll;
const int mod = 1e9+7;
#ifndef M_PI
#define M_PI acos(-1.0)
#endif

typedef tuple<ll, ll, ll, string, string> score;
vector<score> pos;

void dfs(string coders, string jammers, int loc, int dir){
	if(loc==coders.size()){
		pos.emplace_back(abs(stoll(coders)-stoll(jammers)), stoll(coders), stoll(jammers), coders, jammers);
	}
	else if(dir==-1){
		if(coders[loc]=='?'){
			coders[loc]='9';
		}
		if(jammers[loc]=='?'){
			jammers[loc]='0';
		}
		dfs(coders, jammers, loc+1, dir);
	}
	else if(dir==1){
		if(coders[loc]=='?'){
			coders[loc]='0';
		}
		if(jammers[loc]=='?'){
			jammers[loc]='9';
		}
		dfs(coders, jammers, loc+1, dir);
	}
	else{
		if(coders[loc]=='?'){
			if(jammers[loc]=='?'){
				string c_c=coders, c_j=jammers;
				c_c[loc]='0';
				c_j[loc]='0';
				dfs(c_c, c_j, loc+1, 0);
				c_c[loc]='1';
				c_j[loc]='0';
				dfs(c_c, c_j, loc+1, 1);
				c_c[loc]='0';
				c_j[loc]='1';
				dfs(c_c, c_j, loc+1, -1);
			}
			else{
				string c_c=coders, c_j=jammers;
				c_c[loc]=c_j[loc];
				dfs(c_c, c_j, loc+1, 0);
				if(c_j[loc]!='9'){
					c_c[loc]=c_j[loc]+1;
					dfs(c_c, c_j, loc+1, 1);
				}
				if(c_j[loc]!='0'){
					c_c[loc]=c_j[loc]-1;
					dfs(c_c, c_j, loc+1, -1);
				}
			}
		}
		else{
			if(jammers[loc]=='?'){
				string c_c=coders, c_j=jammers;
				c_j[loc]=c_c[loc];
				dfs(c_c, c_j, loc+1, 0);
				if(c_c[loc]!='9'){
					c_j[loc]=c_c[loc]+1;
					dfs(c_c, c_j, loc+1, -1);
				}
				if(c_c[loc]!='0'){
					c_j[loc]=c_c[loc]-1;
					dfs(c_c, c_j, loc+1, 1);
				}
			}
			else{
				string c_c=coders, c_j=jammers;
				if(c_c[loc]>c_j[loc]){
					dfs(coders, jammers, loc+1, 1);
				}
				else if(c_c[loc]<c_j[loc]){
					dfs(coders, jammers, loc+1, -1);
				}
				else{
					dfs(coders, jammers, loc+1, 0);
				}
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	for(int ct=0; ct<t; ++ct){
		string coders, jammers;
		cin>>coders>>jammers;
		dfs(coders, jammers, 0, 0);
		sort(pos.begin(), pos.end());
		tie(ignore, ignore, ignore, coders, jammers)=pos.front();
		printf("Case #%d: ", ct+1);
		cout<<coders<<' '<<jammers<<'\n';
		pos.clear();
	}
	return 0;
}
