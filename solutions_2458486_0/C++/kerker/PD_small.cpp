#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

typedef struct A{
	int state,key[20],turn[22],cc;
}AA;
AA now,aft;
int lim[20];
typedef struct B{
	int need;
	vector <int> v;
}BB;
BB b[20];

struct comp{
	bool operator() (const AA& a, const AA& b) const{  //free
		if(a.state!=b.state)	return a.state>b.state ? true : false;
		if(a.cc!=b.cc)	return a.cc>b.cc ? true : false;
		int i;
		//for(i=0;i<a.cc;i++)
			//if(a.turn[i]!=b.turn[i])	return a.turn[i]>b.turn[i] ? true : false;
		for(i=0;i<20;i++)
			if(a.key[i]!=b.key[i])
				return a.key[i]>b.key[i] ? true : false;
		return false;
	}
};
map <AA,int,comp> MAP;
//map <AA,AA,comp> pre;

int main()
{
    freopen("D-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);

    int T,t,K,k,N,n,i,j,M,m;
	scanf(" %d",&T);
	for(t=1;t<=T;t++){
		scanf(" %d %d",&K,&N);
		MAP.clear();
		//pre.clear();
		now.state = 0;
		memset(now.key,0,sizeof(now.key));
		for(k=0;k<K;k++){
			scanf(" %d",&i);
			now.key[i]++;
		}
		memset(lim,0,sizeof(lim));
		for(n=0;n<N;n++){
			scanf(" %d %d",&b[n].need,&M);
			lim[b[n].need]++;
			b[n].v.clear();
			for(m=0;m<M;m++){
				scanf(" %d",&i);
				b[n].v.push_back(i);
			}
		}
		for(n=0;n<N;n++)
			now.key[n] = min(now.key[n],lim[n]);
		memset(now.turn,0,sizeof(now.turn));
		now.cc = 0;
		aft = now;
		aft.state = -1;
		//pre[now] = aft;
		MAP[now] = 1;
		queue <AA> q;
		q.push(now);
		int end = (1<<N)-1,re=0;
		while(!q.empty()){
			now = q.front();	q.pop();
			int sta = now.state;
			if(sta==end){
				re = 1;
				break;
			}
			for(i=0;i<N;i++){
				if(sta & (1<<i))	continue;
				if(now.key[b[i].need]!=0){
					aft = now;
					aft.key[b[i].need]--;
					aft.state |= (1<<i);
					aft.turn[now.cc] = i;
					aft.cc++;
					for(j=0;j<b[i].v.size();j++)
						aft.key[b[i].v[j]]++;
					for(n=0;n<N;n++)
						aft.key[n] = min(aft.key[n],lim[n]);
					if(MAP.find(aft)==MAP.end()){
						MAP[aft] = 1;
						q.push(aft);
						//pre[aft] = now;
					}else{
						/*AA oao = pre[aft];
						int which = -1;
						for(j=0;j<now.cc && which==-1;j++)
							if(oao.turn[j]!=now.turn[j])
								which = oao.turn[j]<now.turn[j] ? 1 : 2;
						if(which==2)
							pre[aft] = now;*/
					}
				}
			}
		}
		if(re==1){
			/*stack <int> sa;
			while(now.state!=0){
				aft = pre[now];
				j = aft.state^now.state;
				for(i=0;i<N;i++)
					if(j & (1<<i))
						break;
				sa.push(i);
				now = aft;
			}*/
			printf("Case #%d:",t);
			/*while(!sa.empty()){
				printf(" %d",sa.top()+1);
				sa.pop();
			}*/
			for(i=0;i<N;i++)
				printf(" %d",now.turn[i]+1);
			printf("\n");
		}else
			printf("Case #%d: IMPOSSIBLE\n",t);
	}

    return 0;
}
