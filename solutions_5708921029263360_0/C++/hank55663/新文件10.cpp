#include<bits/stdc++.h>
#define N 3005
using namespace std;
struct clothes{
	int x,y,z;
	clothes(int _x,int _y,int _z):x(_x),y(_y),z(_z){
		
	} 
};
int j,p,s,k;
vector<clothes> can;
stack<clothes> ans;
int Max;
stack<clothes> maxans;
int jp[10][10],ps[10][10],js[10][10];
void dfs(vector<clothes>::iterator it,int a){
	if(it==can.end())
	{
		if(a>Max){
			Max=a;
			maxans=ans;
		}
		return;
	}
	dfs(it+1,a);
	if(jp[it->x][it->y]<k&&ps[it->y][it->z]<k&&js[it->x][it->z]<k){
	ans.push(*it);
	jp[it->x][it->y]++;
	ps[it->y][it->z]++;
	js[it->x][it->z]++;
	dfs(it+1,a+1);
	ans.pop();
	jp[it->x][it->y]--;
	ps[it->y][it->z]--;
	js[it->x][it->z]--;
	} 
}
int main(){
	int t;
	scanf("%d",&t);
	for(int T=1;T<=t;T++){
		scanf("%d %d %d %d",&j,&p,&s,&k);
		can.clear();
		while(!ans.empty())
		ans.pop();
		Max=0;
		memset(jp,0,sizeof(jp));
		memset(js,0,sizeof(js));
		memset(ps,0,sizeof(ps));
		for(int x=0;x<j;x++)
		for(int y=0;y<p;y++)
		for(int z=0;z<s;z++){
			can.push_back(clothes(x,y,z));
		}
		dfs(can.begin(),0);
		printf("Case #%d: %d\n",T,Max);
		while(!maxans.empty()){
			printf("%d %d %d\n",maxans.top().x+1,maxans.top().y+1,maxans.top().z+1);
			maxans.pop();
		}
	}
	return 0;
}
