#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <iomanip> 
#include <vector>
#include <list>
#include <utility> 
#include <iterator> 
#include <math.h> 
#include <algorithm> 
#include <stdio.h> 
using namespace std;


#define REP(i,T) for(int i=0;i<T;++i)
#define MP make_pair
#define PII pair<int,int>
#define BG begin
#define ND end
#define VI vector<int>
#define VB vector<bool>
#define ALL(i) i.BG(),i.ND()
#define FORI(i,a,b) for(int i=a;i<b;++i)
#define OUT(i) while(!i.empty())
#define GP(a,b) a[b.first][b.second]
#define EX(a,b) (a.find(b)!=a.end())


bool dfs(int st,vector<int > &gra,vector<int> &ex){
	int t=st;
	if(ex[t]!=-1)return true;
	if(gra[t]!=-1)ex[t]=st;
	while(gra[t]!=-1){		
		ex[t]=st;
		t=gra[t];
		if(ex[t]==st)return false;
	}
	return true;
}
bool inval(string x,vector<int> &ch,vector<int> &ct,vector<int> &cb,vector<int> &cw,vector<int> &gra){
	vector<int> c(26,0);
	int n=x.size();
	char las=x[0];
	c[las-'a']=1;
	for(int i=1;i<n;++i){
		if(x[i]!=las){
			las=x[i];
			if(c[las-'a']!=0)return false;
			c[las-'a']=1;
		}
	}
	if(n==1||las==x[0]){
		cw[las-'a']++;
	}
	else {
		ch[x[0]-'a']++;
		ct[las-'a']++;
		gra[x[0]-'a']=las-'a';
		REP(i,26){
			if(c[i]==1&&i!=(x[0]-'a')&&i!=(las-'a')){
				cb[i]++;
			}
		}
	}
	return true;
}
void judge(){
	int n;
	cin>>n;
	long long ans=1;
	vector<int> ch(26,0),ct(26,0),cb(26,0),cw(26,0);
	vector<int > gra(26,-1),ex(26,-1),exd(26,0);

	vector<string> da(n);
	REP(i,n){
		cin>>da[i];
	}
	
	REP(i,n){
		if(!inval(da[i],ch,ct,cb,cw,gra)){
			cout<<0;
			return;
		}
	}
	REP(i,26){
		if(ct[i]>1||ch[i]>1||cb[i]>1||(cb[i]==1&&ct[i]+ch[i]+cw[i]!=0)||!dfs(i,gra,ex)){
			cout<<0;
			return;
		}
	}
	int count=1,exc=0;
	REP(i,26){
		if(ch[i]+ct[i]==0&&cw[i]!=0)count++;
		REP(j,cw[i]){
			ans=(ans*(j+1))%1000000007;
		}
		if(ex[i]!=-1)exd[ex[i]]=1;
	}
	
	REP(i,26)exc+=exd[i];
	count+=exc-1;
	REP(j,count){
		ans=(ans*(j+1))%1000000007;
	}
	cout<<ans;
	return;


}
int main(){
	int t;
	scanf("%d",&t);
	REP(tt,t){
		cerr<<tt<<endl;
		printf("Case #%d: ",tt+1);
		judge();
		
		printf("\n");
	}




	return 1;



}