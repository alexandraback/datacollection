#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int requ[1005][2];
struct Unit{
	int id,val,typ;
	bool friend operator<(Unit a,Unit b){
		return requ[a.id][1]<requ[b.id][1];
	}
};
bool cmp(Unit a,Unit b){
	return a.val<b.val;
}
Unit ut[2005];
priority_queue<Unit>s1,s2;
int N,lvl[1005],N2;
void ini(){
	memset(lvl,0,sizeof(lvl));
	while(s1.size())s1.pop();
	while(s2.size())s2.pop();

}

void get_data(){
	ini();
	scanf("%d",&N);
	int i,a,b;
	N2=0;
	for(i=0;i<N;i++){
		scanf("%d%d",&a,&b);
		requ[i][0]=a;requ[i][1]=b;
		ut[N2].id=i;ut[N2].val=a;ut[N2++].typ=1;
		ut[N2].id=i;ut[N2].val=b;ut[N2++].typ=2;
	}
	sort(ut,ut+N2,cmp);
}
int run(){
	int now=0,cnt=0,i=0;
	Unit t;
	while(true){
		for(;i<N2;i++){
			if(ut[i].val<=now){
				if(ut[i].typ==1)s1.push(ut[i]);
				else s2.push(ut[i]);
			}else break;
		}
	//	printf("i=%d %d %d\n",i,ut[i].val,now);
		if(s2.size()){
			t=s2.top();
		//	printf("%d %d*\n",t.id,t.typ);
			cnt++;
			now+=2-lvl[t.id];
			lvl[t.id]=2;
			s2.pop();
		}else if(s1.size()){
			t=s1.top();s1.pop();
			if(lvl[t.id]==0){
			//	printf("%d %d*\n",t.id,t.typ);
				cnt++;
				now++;
				lvl[t.id]=1;
			}
		}else break;
	}
	if(now==N2)return cnt;
	else return -1;
}
int main(){
//	freopen("B-large.in","r",stdin);
//	freopen("B-large.out","w",stdout);
	int t,i=0;
	scanf("%d",&t);
	while(t--){
		get_data();
		printf("Case #%d: ",++i);
		int a=run();
		if(a==-1)printf("Too Bad\n");
		else printf("%d\n",a);
	}
	return 0;
}
