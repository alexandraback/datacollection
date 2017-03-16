#include <bits/stdc++.h>
using namespace std;
typedef long long               ll;
const int mod = 1e9+7;
#ifndef M_PI
#define M_PI acos(-1.0)
#endif

struct vert{
	bool in=false;
	bool out=false;
	bool vis=false;
	vector<vert *> con;
	void reset(){
		in=false;
		out=false;
		vis=false;
		con.clear();
	}
	bool find_path(){
		if(vis){
			return false;
		}
		vis=true;
		if(out){
			out=false;
			return true;
		}
		for(int i=0; i<con.size(); ++i){
			if(con[i]->find_path()){
				con[i]->con.push_back(this);
				con.erase(con.begin()+i);
				return true;
			}
		}
		return false;
	}
};

vert adj_list[2500];


int ford_fulk(int c1, int c2){
	int res=0;
	for(int i=0; i<c1; ++i){
		if(adj_list[i].find_path()){
			++res;
			adj_list[i].in=true;
		}
		for(int j=0; j<2000; ++j){
			adj_list[j].vis=false;
		}
	}
	return res;
}

int main(){
	int t;
	cin>>t;
	for(int ct=0; ct<t; ++ct){
		int c1=0;
		int c2=1000;
		map<string, int> w1, w2;
		int n;
		cin>>n;
		for(int i=0; i<n; ++i){
			string s1, s2;
			cin>>s1>>s2;
			if(!w1.count(s1)){
				w1[s1]=c1;
				++c1;
			}
			if(!w2.count(s2)){
				w2[s2]=c2;
				++c2;
			}
			int v1=w1[s1];
			int v2=w2[s2];
			adj_list[v1].con.push_back(adj_list+v2);
			adj_list[v2].out=true;
		}
		int pairs=ford_fulk(c1, c2);
		printf("Case #%d: ", ct+1);
		cout<<n-c1-(c2-1000)+pairs<<'\n';
		for(int j=0; j<2000; ++j){
			adj_list[j].reset();
		}
	}
	return 0;
}
