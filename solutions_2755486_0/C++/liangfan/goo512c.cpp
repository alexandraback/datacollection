#include <iostream>
#include <queue>
#include <string>
#include <iomanip> 
#include <vector>
#include <list>
#include <utility> 
#include <iterator> 
#include <algorithm> 
#include <map>
#include <time.h>
#include <set> 
using namespace std;
#define REP(i,T) for(int i=0;i<T;++i)
#define MP make_pair
#define PII pair<int,int>
#define BG begin
#define ND end
#define VI vector<__int64>
#define VB vector<bool>
#define ALL(i) i.BG(),i.ND()
#define FORI(i,a,b) for(int i=a;i<b;++i)
#define OUT(i) while(!i.empty())
#define GP(a,b) a[b.first][b.second]
#define EX(a,b) (a.find(b)!=a.end())

int intree[8000000];
int mark[8000000];



void change(int *a,int d){
	*a=d;
}

int merge(int a,int b){
	return a<b?a:b;
}
bool match(int a,int b){
	return a>=b;
}
int get_inter(int* data,int lt,int rt,int p,int st,int ed){
	int ans;
	
	int stack[33];
	int sp=0;
	while(lt<st||rt>ed+1){
		stack[sp++]=p;
		
		int m=(rt+lt)/2;
		if(mark[p]!=0&&(mark[p<<1]!=mark[p]||mark[p<<1|1]!=mark[p])){
			
			mark[p<<1]=mark[p<<1]>mark[p]?mark[p<<1]:mark[p];
			data[p<<1]=data[p<<1]>mark[p<<1]?data[p<<1]:mark[p<<1];
			mark[p<<1|1]=mark[p<<1|1]>mark[p]?mark[p<<1|1]:mark[p];
			data[p<<1|1]=data[p<<1|1]>mark[p<<1|1]?data[p<<1|1]:mark[p<<1|1];
			mark[p]=0;
		}
		if(ed<m){
			
			rt=m;
			p=p<<1;
		}
		else if(st>=m){
			lt=m;
			p=(p<<1)+1;
		}
		else{
			ans=merge(get_inter(data,lt,m,p<<1,st,m-1),get_inter(data,m,rt,(p<<1)+1,m,ed));
			return ans;
		}
	}
	
	REP(i,sp){
		int ps=stack[sp-i-1];
		int x=merge(data[ps<<1],data[ps<<1|1]);
		if(data[ps]==x)break;
		data[ps]=x;
	}
	return data[p];

}

void build(int* data,int lt,int rt,int p,int d){
	data[p]=d;
	if(rt-lt==1)return;
	int x=(lt+rt)/2;
	build(data,lt,x,p<<1,d);
	build(data,x,rt,p<<1|1,d);
	//data[p]=merge(data[p<<1],data[p<<1|1]);
	return ;

}



int push_down(int *data,int* mark,int lt, int rt,int p,int st,int ed,int d){
	int ans;
	
	int stack[33];
	int sp=0;
	while(lt<st||rt>ed+1){
		stack[sp++]=p;
		int m=(rt+lt)/2;
		if(mark[p]!=0&&(mark[p<<1]!=mark[p]||mark[p<<1|1]!=mark[p])){
			
			mark[p<<1]=mark[p<<1]>mark[p]?mark[p<<1]:mark[p];
			data[p<<1]=data[p<<1]>mark[p<<1]?data[p<<1]:mark[p<<1];
			mark[p<<1|1]=mark[p<<1|1]>mark[p]?mark[p<<1|1]:mark[p];
			data[p<<1|1]=data[p<<1|1]>mark[p<<1|1]?data[p<<1|1]:mark[p<<1|1];
			mark[p]=0;
		}
		if(ed<m){
			
			rt=m;
			p=p<<1;
		}
		else if(st>=m){
			lt=m;
			p=(p<<1)+1;
		}
		else{
			merge(push_down(data,mark,lt,m,p<<1,st,(rt+lt)/2-1,d),push_down(data,mark,m,rt,(p<<1)+1,(rt+lt)/2,ed,d));
			break;
		}
	}
	
	if(lt==st&&rt==ed+1){
		data[p]=data[p]>d?data[p]:d;
		mark[p]=d;
	}
	REP(i,sp){
		int ps=stack[sp-i-1];
		int x=merge(data[ps<<1],data[ps<<1|1]);
		if(data[ps]==x)break;
		data[ps]=x;
	}
	return data[p];
}

struct node{
	int st;
	int ed;
	int s;
	node(int a,int b,int c){st=a;ed=b;s=c;}
	node(const node &a){st=a.st;ed=a.ed;s=a.s;}
	
};
int main(){
	int t;
	scanf("%d",&t);
	REP(tt,t){
		int n;
		scanf("%d",&n);
		vector<int> di(n),ni(n),wi(n),ei(n),si(n),dd(n),dp(n),ds(n);
		map<int,int> timer;
		vector< vector<node>  > list;

		vector<int > poss;
		REP(i,n){
			scanf("%d%d%d%d%d%d%d%d",&di[i],&ni[i],&wi[i],&ei[i],&si[i],&dd[i],&dp[i],&ds[i]);
			
			REP(j,ni[i]){
				int dat=di[i]+j*dd[i];
				if(EX(timer,dat)){
					int ind=timer[dat];
					list[ind].push_back(node(wi[i]+dp[i]*j,ei[i]+dp[i]*j,si[i]+ds[i]*j));
				}
				else{
					timer.insert(MP(dat,list.size()));
					list.push_back(vector<node>(1,node(wi[i]+dp[i]*j,ei[i]+dp[i]*j,si[i]+ds[i]*j)));

				}

				
				poss.push_back(2*(wi[i]+dp[i]*j)-1);
				poss.push_back(2*(wi[i]+dp[i]*j));
				poss.push_back(2*(ei[i]+dp[i]*j));
				
				poss.push_back(2*(ei[i]+dp[i]*j)+1);

			}
		}
		sort(ALL(poss));

		vector<int >::iterator it = unique (ALL(poss)); 
		poss.resize(it-poss.begin());
		map<int,int > where;
		int m=poss.size();
		REP(i,m){
			where[poss[i]]=i;
		}
		int ans=0;
		
		build(intree,0,m,1,0);
		build(mark,0,m,1,0);
		for(map<int,int> ::iterator it=timer.begin();it!=timer.end();++it){
			int i=it->second;
			vector<node> works;
			REP(j,list[i].size()){
				node att=list[i][j];
				att.st=where[att.st*2];
				att.ed=where[att.ed*2];

				int min=get_inter(intree,0,m,1,att.st,att.ed);
				if(min<att.s){
					works.push_back(att);
					ans++;
				}
			}

			REP(j,works.size()){
				push_down(intree,mark,0,m,1,works[j].st,works[j].ed,works[j].s);
			}
		}


	
		
		printf("Case #%d: %d\n",tt+1,ans);

	}

	return 1;
	

	
}