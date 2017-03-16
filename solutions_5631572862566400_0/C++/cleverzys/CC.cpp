#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>
#include <iomanip> 
#include <sstream>

using namespace std;

#define TRY
#define SMALL
//#define LARGE
int link(int or1, int or2);
void Solve();
vector<int> t[1002];
bool b[1002]={false};
int maxnum[1002]={0};
int index[1002];
void main() 
{
#ifdef TRY
	freopen("1.txt", "rt", stdin);
	//freopen("C-large.txt","wt",stdout);
	//freopen("2.out","wt",stdout);
#endif
#ifdef SMALL
	freopen("C-small-attempt0.in","rt",stdin);
	freopen("C-small.txt","wt",stdout);
#endif
#ifdef LARGE
	freopen("C-large.in","rt",stdin);
	freopen("C-large.txt","wt",stdout);
#endif
	int Numcase;
	cin>>Numcase;

	for(int test=1;test<=Numcase;test++)
	{
		cout<<"Case #"<<test<<": ";
		Solve();
	}
}

void Solve(){
	int a,N;
	cin>>N;
	for(int i=0;i<1002;i++) {t[i].clear(); b[i]=false;maxnum[i]=0;index[i]=-1;}
	vector<pair<int,int>> pa;
	for(int i=1;i<=N;i++){
		cin>>a;
		t[a].push_back(i);
		index[i]=a;
	}
		
	for(int i=1;i<=N;i++){
		if(b[i]) continue;
		int len=t[i].size();
		if(len==0) b[i]=false;
		for(int j=0;j<t[i].size();j++){
			int like=t[i][j];
			for(int k=0;k<t[like].size();k++){
				if(t[like][k]==i) {
					pa.push_back(make_pair(i,like));
					b[i]=true;b[like]=true;
				}
			}
		}
	}
	int ma=0,tmp=0;
	//cout<<link(10,3);
	if(pa.size()!=0){
		for(int i=0;i<pa.size();i++){
			tmp=2;
			int f = pa[i].first;
			int s = pa[i].second;
			tmp=link(f,s)+link(s,f);
			ma=max(ma,tmp);
		}	
	}
	for(int i=1;i<=N;i++){
		if(maxnum[i]==0){
			maxnum[i]=1;int level =1;
			int next=index[i];
			while(maxnum[next]==0){
				level++;

				maxnum[next]=level;
				next=index[next];
			}
			tmp = level-maxnum[next]+1;
			
			ma=max(ma,tmp);
		}
	}
	cout<<ma<<endl;
}

int link(int or1, int or2){
	int level = 2;
	
	maxnum[or1]=1;
	vector<int> tmplike,tmplike2;
	int tmplike_len=t[or1].size();
	for(int i=0;i<t[or1].size();i++){
		int like=t[or1][i];
		if(like==or2) continue;
		tmplike.push_back(like);
		maxnum[like]=level;			
	}
	
	tmplike_len = tmplike.size();
	while(tmplike_len!=0){
		level++;
		tmplike2=tmplike;
		tmplike.clear();
		for(int k=0;k<tmplike_len;k++){
			or1 = tmplike2[k];
			for(int i=0;i<t[or1].size();i++){
				int like=t[or1][i];
				if(like==or2) continue;
				tmplike.push_back(like);
				maxnum[like]=level;			
			}		
		}
		tmplike_len = tmplike.size();
		
	}
	return level-1;
}
