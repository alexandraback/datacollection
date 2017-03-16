#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long LL;
typedef pair<pair<int,int>,pair<LL,LL> > state;
map<state,LL> m;
#define make_state(i,j,x,y) make_pair(make_pair(i,j),make_pair(x,y))

int nn,mm;
LL an[110],bn[110];
int at[110],bt[110];

LL solve(int i, int j, LL x, LL y){
	LL v;
	state s=make_state(i,j,x,y);
	if (m.find(s)!=m.end()) return m[s];
	if (x==0 && i==nn) v=0;
	else if (y==0 && j==mm) v=0;
	else if (x==0) v=solve(i+1,j,an[i],y);
	else if (y==0) v=solve(i,j+1,x,bn[j]);
	else if (at[i-1]==bt[j-1]) v=min(x,y)+solve(i,j,x-min(x,y),y-min(x,y));
	else v=max(solve(i,j,0,y),solve(i,j,x,0));
	m[s]=v;
	return v;
}

int main(){
	int t,u,i,j,k,a,b;
	cin>>t;
	for (u=0; u<t; u++){
		cin>>nn>>mm;
		for (i=0; i<nn; i++) cin>>an[i]>>at[i];
		for (i=0; i<mm; i++) cin>>bn[i]>>bt[i];
		m.clear();
		cout<<"Case #"<<(u+1)<<": "<<solve(0,0,0,0)<<endl;
	}
	return 0;
}
