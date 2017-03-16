#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
#include<functional>
#include<vector>
#include<cstdlib>
#include<cstring>
using namespace std;
char buf[128];
int a[1024],b[1024],l[1024],n;
class cmpa{
public:
	cmpa(){}
	bool operator()(int l,int r)const {return a[l]>a[r];}
};
class cmpb{
public:
	cmpb(){}
	bool operator()(int l,int r)const {return b[l]>b[r];}
};
string solve(){
	priority_queue<int,vector<int>,cmpa	>	x;
	priority_queue<int,vector<int>,cmpb	>	y;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d%d",a+i,b+i);
		l[i]=0;
		x.push(i);
		y.push(i);
	}
	int ans = 0, ss=0;
	for(;y.size();++ans){
		if(b[y.top()]<=ss){
			++ss;
			if(!l[y.top()])++ss;
			l[y.top()]=2;
			y.pop();
		}else{
			for(;x.size()&&	l[x.top()]>1;)x.pop();
			if(!x.size()||a[x.top()]>ss)return "Too Bad";
			l[x.top()]=1;x.pop();++ss;
		}
	}
	sprintf(buf,"%d",ans);
	return buf;
}
int main(){
	int Tc,ti;
	for(scanf("%d",&Tc),ti=1;ti<=Tc;++ti)
		printf("Case #%d: %s\n",ti,solve().c_str());
	return 0;
}
