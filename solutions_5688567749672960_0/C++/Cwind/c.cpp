#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
#include<cstring>
#include<cmath>
#define INF 0x3fffffff
#define pb push_back
#define pn(x) cerr<<x<<endl

using namespace std;
typedef long long ll;
const int maxv=1e6+20;
typedef pair<int,int> P;///num,pos

int tab[maxv];
bool mark[maxv];
int rev(int a){
	int b[10];
	int h=0;
	while(a>0){
		b[h++]=a%10;
		a/=10;
	}
	int ans=0;
	int xx=1;
	for(int i=h-1;i>=0;i--){
		ans+=b[i]*xx;
		xx*=10;
	}
	return ans;
}
void get_tab(){
	memset(tab,0x3f,sizeof tab);
	tab[1]=1;
	queue<int> Q;
	Q.push(1);
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		int v=u+1;
		if(v<maxv&&tab[u]+1<tab[v]){
			Q.push(v);
			tab[v]=tab[u]+1;
		}
		v=rev(u);
		if(v<maxv&&v>0&&tab[u]+1<tab[v]){
			Q.push(v);
			tab[v]=tab[u]+1;
		}
		v=rev(v);
		if(v<maxv&&v>0&&tab[u]+1<tab[v]){
			Q.push(v);
			tab[v]=tab[u]+1;
		}
	}
}
int N;
int t=0;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	get_tab();
	cin>>N;
	int q;
	while(N--){
		t++;
		cin>>q;
		printf("Case #%d: %d\n",t,tab[q]);
	}
	//for(int i=1;i<=50;i++)
	//	cout<<i<<" "<<tab[i]<<endl;
	//cout<<rev(2300)<<endl;
    return 0;
}