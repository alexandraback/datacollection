// #includes {{{
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cmath>
using namespace std;
// }}}
// pre-written code {{{
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define RREP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define LET(x,a) __typeof(a) x(a)
//#define IFOR(i,it,c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();++it,++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair

#define EXIST(e,s) ((s).find(e)!=(s).end())

#define RESET(a) memset((a),0,sizeof(a))
#define SET(a) memset((a),-1,sizeof(a))
#define PB push_back
#define DEC(it,command) __typeof(command) it=command

const int INF=0x3f3f3f3f;

typedef long long Int;
typedef unsigned long long uInt;
#ifdef __MINGW32__
typedef double rn;
#else
typedef long double rn;
#endif

typedef pair<int,int> pii;

/*
#ifdef MYDEBUG
#include"debug.h"
#include"print.h"
#endif
*/
// }}}

vector<string> transpose(const vector<string> &s){
	vector<string> v(s[0].size());
	REP(i,s[0].size())v[i].assign(s.size(),'?');
	REP(i,s.size())REP(j,s[0].size())v[j][i]=s[i][j];
	return v;
}

vector<int> result[55][55][3000];

int nbr[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,-1},{1,1},{-1,-1},{-1,1}};

int R,C,M;

bool inner(int x, int y){
	return 0<=x and x<R and 0<=y and y<C;
}

void dfs(int x,int y,const vector<string> &ans, vector<vector<bool> > &vis){
	if(vis[x][y])return;
	if(ans[x][y]=='*')return;
	vis[x][y]=true;
	bool bomb = false;
	REP(d,8){
		int x2=x+nbr[d][0], y2=y+nbr[d][1];
		if(!inner(x2,y2))continue;
		if(ans[x2][y2]=='*')bomb=true;
	}
	if(bomb)return;
	REP(d,8){
		int x2=x+nbr[d][0], y2=y+nbr[d][1];
		if(!inner(x2,y2))continue;
		dfs(x2,y2,ans,vis);
	}
}

bool test(const vector<string> &ans){
	int ct=0, x=-1, y=-1;
	REP(i,R)REP(j,C){
		if(ans[i][j]=='*')ct++;
	}
	assert(ct==M);
	ct=0;
	REP(i,R)REP(j,C){
		if(ans[i][j]=='c')x=i,y=j,ct++;
	}
	assert(ct==1);
	vector<vector<bool> > vis(R,vector<bool>(C,false));
	dfs(x,y,ans,vis);
	ct=0;
	REP(i,ans.size())REP(j,ans[0].size())ct+=vis[i][j];
	assert(ct==R*C-M);
}

void init(){
	for(int R=3;R<=50;R++){
		for(int C=3;C<=50;C++){
			for(int a=2;a<=C;a++){
				for(int b=a;b<=C;b++){
					for(int k=2;k<=R-1;k++){
						int D = a+b*k;
						vector<int> v;
						v.push_back(0);
						v.push_back(a);
						v.push_back(b);
						v.push_back(k);
						result[R][C][D]=v;
					}
				}
			}
			for(int a=2;a<=R;a++){
				for(int b=a;b<=R;b++){
					for(int k=2;k<=C-1;k++){
						int D = a+b*k;
						vector<int> v;
						v.push_back(1);
						v.push_back(a);
						v.push_back(b);
						v.push_back(k);
						result[R][C][D]=v;
					}
				}
			}
		}
	}
}


void main2(){
	cin>>R>>C>>M;
	bool tp = false;
	if(R>C)tp=true, swap(R,C);
	int D = R*C-M;
	vector<string> ans(R,string(C,'*'));
	if(R==1){
		REP(i,D)ans[0][i]='.';
	}else if(R==2){
		if(D==1){
			ans[0][0]='.';
		}else if(D==2 or D%2!=0){
			cout<<"Impossible"<<endl;
			return;
		}else{
			REP(i,D/2)ans[0][i]=ans[1][i]='.';
		}
	}else{
		if(D<=7){
			if(D==1){
				ans[0][0]='.';
			}else if(D==4){
				REP(i,2)REP(j,2)ans[i][j]='.';
			}else if(D==6){
				REP(i,2)REP(j,3)ans[i][j]='.';
			}else{
				cout<<"Impossible"<<endl;
				return;
			}
		}else{
			if(R==C and M==C-1){
				REP(i,R)REP(j,C)ans[i][j]='.';
				REP(i,M-1)ans[R-1][i]='*';
				ans[R-2][0]='*';
			}else{
				vector<int> v = result[R][C][D];
				assert(v.size()>0);
				int a = v[1], b = v[2], k = v[3];
				if(v[0]==0){
					REP(i,k)REP(j,b)ans[i][j]='.';
					REP(j,a)ans[k][j]='.';
				}else{
					REP(i,k)REP(j,b)ans[j][i]='.';
					REP(j,a)ans[j][k]='.';
				}
			}
		}
	}
	ans[0][0]='c';
	if(tp)swap(C,R),ans=transpose(ans);
	test(ans);
	REP(i,R)cout<<ans[i]<<endl;
}

// main function {{{
int main() {
	init();
	/*
	for(int R=3;R<=50;R++){
		for(int C=3;C<=50;C++){
			for(int D=8;D<=R*C;D++){
				if(result[R][C][D].size()==0){
					cout<<R<<" "<<C<<" "<<D<<endl;
				}
			}
		}
	}
	return 0;
	*/



	int T;cin>>T;
	REP(ct, T){
		cout<<"Case #"<<ct+1<<": "<<endl;
		main2();
	}
	return 0;
}
//}}}
