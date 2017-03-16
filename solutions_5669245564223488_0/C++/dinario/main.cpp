#pragma comment(linker, "/STACK:64000000")
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
#define forn(i,n) for (int i=0;i<n;i++)
#define rforn(i,n) for (int i=n-1;i>=0;i--)
#define mp make_pair
#define __int64 long long
#define LL unsigned long long
#define re return
#define N 550000
#define double long double

#define mod 1000000007

vector < vector<int> > g;
vector<char> cl;
vector<int> p;
int cycle_st, cycle_end;

bool dfs (int v) {
	cl[v] = 1;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (cl[to] == 0) {
			p[to] = v;
			if (dfs (to))  return true;
		}
		else if (cl[to] == 1) {
			cycle_end = v;
			cycle_st = to;
			return true;
		}
	}
	cl[v] = 2;
	return false;
}

typedef struct{char s[200];}tp;
tp all[200];
LL fr[200];int rv;
void solve(){
	LL i,j,n,k;
	cin>>n;
	int cnt[50];memset(&cnt,0,sizeof(int)*50);

	int con=0,len=0;

	for(i=0;i<n;++i){
		cin>>all[i].s;
		int slen=strlen(all[i].s);
		int cnt2[50];memset(&cnt2,0,sizeof(int)*50);
		for(j=0;j<slen;++j)cnt2[all[i].s[j]-'a']=1;
		for(j=0;j<50;++j)cnt[j]+=cnt2[j];

		memset(&cnt2,0,sizeof(int)*50);
		for(j=0;j<slen;++j){
			if(j>0&&all[i].s[j-1]!=all[i].s[j]){
				con+=1;
				if(cnt2[all[i].s[j]-'a']>0)
				{
					cout<<0;re;
				}
			}
			cnt2[all[i].s[j]-'a']+=1;
		}
	}
	for(i=0;i<n;++i){
		int slen=strlen(all[i].s);
		for(j=0;j<slen;++j){
			if(all[i].s[j]!=all[i].s[0]&&all[i].s[j]!=all[i].s[slen-1]){
				if(all[i].s[0]==all[i].s[slen-1]){cout<<0;re;}
				if(cnt[all[i].s[j]-'a']>1){
					cout<<0;re;
				}
			}
		}
	}
	int cL[50],cR[50],cAll[50];
	memset(&cL,0,sizeof(int)*50);
	memset(&cR,0,sizeof(int)*50);
	memset(&cAll,0,sizeof(int)*50);
	

	for(j=0;j<50;++j){
		g[j].clear();
		if(cnt[j]>0)len+=1;
	}
	
	for(i=0;i<n;++i){
		int slen=strlen(all[i].s);
		if(all[i].s[0]==all[i].s[slen-1])cAll[all[i].s[0]-'a']+=1;
		else {
			cL[all[i].s[0]-'a']+=1;
			cR[all[i].s[slen-1]-'a']+=1;


			g[all[i].s[0]-'a'].push_back(all[i].s[slen-1]-'a');
			//con+=1;
		}
	}

	for(j=0;j<50;++j)if(cL[j]>1||cR[j]>1){
		cout<<0;
		re;
	}

	int na=50;
	p.assign (na, -1);
	cl.assign (na, 0);
	cycle_st = -1;
	for (int i=0; i<na; ++i)
		if (dfs (i))
			break;

	if (cycle_st != -1){
		cout<<0;
		re;
	}

	LL res=1;
	if(len>con)res=(res*fr[len-con])%mod;
	for(j=0;j<50;++j)if(cAll[j]>1){
		res=(res*fr[cAll[j]])%mod;
	}
	cout<<res;
}

int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("B.out","w",stdout);

	LL T,t,i,j,k;

	fr[1]=1;
	for(i=2;i<200;++i)
		fr[i]=(fr[i-1]*i)%mod;

	for(i=0;i<50;++i){
		vector<int>newV;
		g.push_back(newV);
	}

	cin>>T;
	for(t=0;t<T;++t){
		cout<<"Case #"<<t+1<<": ";
		solve();
		cout<<endl;
	}
	return 0;
}