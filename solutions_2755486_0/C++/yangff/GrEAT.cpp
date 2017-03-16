#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;
struct event{
	int l,r,s;
	event(int l,int r,int s):l(l),r(r),s(s){};
};
vector<event> evs[676060+1];
int height[676060+1];
int minl,maxr,n;
void work(){
	scanf("%d",&n);
	maxr = 0;
	minl = 0x3fffffff;
	memset(height,0,sizeof(height));
	for (int i = 0; i <= 676060;i++){
		evs[i].clear();
	}
	for (int i = 1; i<= n; i++){
		int d,t,w,e,s,dd,dp,ds;
		scanf("%d%d%d%d%d%d%d%d",&d,&t,&w,&e,&s,&dd,&dp,&ds);
		for (int x = 0; x< t; x++){
			event ev(w,e,s);
			evs[d].push_back(ev);
			if (w<minl) minl=w;
			if (e>maxr) maxr=e;
			d+=dd;w+=dp;e+=dp;s+=ds;
		}
	}
	for (int i = 0; i <= 676060;i++){
		for (vector<event>::iterator it = evs[i].begin();it!=evs[i].end();it++){
			it->l-=minl;
			it->r-=minl;
		}
	}

	int count = 0;
	for (int i = 0; i <= 676060;i++){
		for (vector<event>::iterator it = evs[i].begin();it!=evs[i].end();it++){
			bool succ = false;
			//printf("[%d %d) %d",it->l,it->r,it->s);
			for (int p = it->l;p<=it->r-1;p++){
				//printf("%d ",height[p]);
				if (height[p]<it->s){
					//printf("SUCC");
					succ = true;break;
				}
			}//printf("\n");
			count += succ;
		}
		for (vector<event>::iterator it = evs[i].begin();it!=evs[i].end();it++){
			//printf("[%d %d] -> %d\n",it->l,it->r,it->s);
			for (int p = it->l;p<=it->r-1;p++)
				if (height[p]<it->s) height[p]=it->s;
		}
	}
	printf("%d",count);
};
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);

	int T;scanf("%d",&T);
	for (int i = 1; i<= T; i++)
	{
		printf("Case #%d: ",i);
		work();
		printf("\n");
	}//system("pause");
}