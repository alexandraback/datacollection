#include <bits/stdc++.h>
#define M 1000

using namespace std;

int nxt[M+1],n,mx,pp;
int ind[M+1],d[M+1];
bool ck[M+1];

queue<int> Q;
void input(void){
	int i;
	scanf("%d",&n);
	mx=0;
	pp=0;
	for(i=1;i<=n;i++) ind[i]=0;
	for(i=1;i<=n;i++) scanf("%d",&nxt[i]), ind[nxt[i]]++;
}

void process(void){
	int i;
	for(i=1;i<=n;i++) if(!ind[i]) Q.push(i);
	for(i=1;i<=n;i++) d[i]=0,ck[i]=false;
	while(!Q.empty()){
		int t=Q.front(); Q.pop();

		d[nxt[t]]=max(d[nxt[t]],d[t]+1);
		if(!(--ind[nxt[t]])) Q.push(nxt[t]);
	}
	for(i=1;i<=n;i++){
		if(!ck[i] && ind[i]){
			int c=1,x=i;
			ck[i]=true;
			while(nxt[x]!=i){
				x=nxt[x];
				ck[x]=true;
				c++;
			}
			if(c==2) pp+=d[x]+d[i]+2;
			else mx=max(mx,c);
		}
	}
}

void output(void){
	printf("%d\n",max(mx,pp));
}

int main(void){
	freopen("input.txt","r",stdin);

	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		input();
		printf("Case #%d: ",i);
		process();
		output();
	}
	return 0;
}
