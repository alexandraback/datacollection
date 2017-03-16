#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool mmark[256];
string sets[100];

char head(const int& j){return sets[j][0];}
char tail(const int& j){return sets[j][sets[j].length()-1];}
bool single(const int& j){return head(j)==tail(j);}

int adj[256][256];
int nhead[256];
int ntail[256];
int parent[256];
int child[256];

int group[256];
int ngroup[256];

bool back(const int& v, const int& g){
	if(group[v]>=0) return false;
	group[v] = g;
	if(parent[v]>=0)
		return back(parent[v], g);
	return true;
}

bool forward(const int& v, const int& g){
	if(group[v]>=0) return false;
	group[v] = g;
	if(child[v]>=0)
		return forward(child[v],g);
	return true;
}

long long akk(const int& k){
	if(k==0) return 1;
	long long ret = 1;
	for(int i=2; i<=k; ++i){
		ret *= i;
		ret %= 1000000007;
	}
	return ret;
}

bool smark[256];
bool valid(string& s){
	memset(smark, 0, sizeof(smark));
	smark[s[0]]=true;
	for (int i = 1; i < s.length(); ++i){
		if(s[i]!=s[i-1] && smark[s[i]]){
			return false;
		}
		smark[s[i]]=true;
	}
	return true;
}

int main(){
	int t, i, j, k, n;

	long long r;

	cin>>t;
	for (i = 1; i <= t; ++i){
		bool p=true;
		memset(mmark, 0, sizeof(mmark));
		cin>>n;
		for (j=0; j<n; ++j){
			cin>>sets[j];
			if(p){
				if(mmark[head(j)] || mmark[tail(j)] || !valid(sets[j])){
					p = false;
				}
				for (k=1; k<sets[j].length()-1; ++k){
					if(sets[j][k]!=head(j) && sets[j][k]!=tail(j)){
						mmark[sets[j][k]] = true;
					}
				}
			}
		}

		if(p){
			memset(adj, 0, sizeof(adj));
			memset(parent, 0xff, sizeof(parent));
			memset(child, 0xff, sizeof(child));
			for(j=0; j<n; ++j){
				++adj[head(j)][tail(j)];
				if (!single(j)){
					if(parent[tail(j)]<0){
						parent[tail(j)] = head(j);
					} else {
						p = false; break; 
					}
					if(child[head(j)]<0){
						child[head(j)] = tail(j);
					} else {
						p = false; break;
					}
				}
			}

			if(p){
				int ng=0;
				memset(group, 0xff, sizeof(group));
				for (j=0; j<256; ++j){
					if(group[j]<0 &&(adj[j][j]>0 || parent[j]>=0 || child[j]>=0)){
						if(!back(j, ng)){p=false; break;}
						group[j]=-1;
						if(!forward(j, ng)){p=false; break;}
						//cout<< "group" << (char)j <<endl;
						++ng;
					}
				}

				if(p){
					//cout << "ng"<< ng <<endl;
					r = akk(ng);
					for(j=0; j<256; ++j){
						r *= akk(adj[j][j]);
						r %= 1000000007;
					}
				}

			}

		}

		cout<<"Case #"<<i<<": ";
		if(p) cout<<r<<endl;
		else cout<<0<<endl;
	}
	
	return 0;
}