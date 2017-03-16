#include<cstdio>
#include<vector>
#define PB push_back
using namespace std;
int t,test,c,d,v,r;
int tab[110];
int pt[30];
int ile[1000000];
bool dt[300];
bool zaj[300];
vector<int> now;
vector<int> tyle[100];
bool all(){
    dt[0] = true;
    for(int i=0;i<now.size();++i)
		for(int j=v;j>=0;--j){
			if(now[i]+j<200 && dt[j]){
				dt[now[i]+j] = true;
				}
			}
	for(int i=0;i<=v;++i)
		if(!dt[i])
			return false;
	return true;
	}
bool check(int x){
	int a;
    for(int q=0;q<tyle[x].size();++q){
		a = tyle[x][q];
		now.clear();
		for(int j=0;j<=v;++j)
			dt[j] = false;
		int w = a,which = 1;
		while(w){
			if(w&1){
				if(zaj[which])
					break;
				now.PB(which);
				}
			w>>= 1;
			++which;
			}
		for(int i=0;i<d;++i)
			now.PB(tab[i]);
		if(all())
			return true;
		}
	return false;
	}
int main(){
	pt[0] = 1;
	for(int i=1;i<25;++i)pt[i] = pt[i-1]*2;
	for(int i=0;i<pt[16];++i){
        r = i;
        while(r){
            if(r&1)
				++ile[i];
			r>>= 1;
			}
		}
	for(int i=0;i<pt[16];++i)
		tyle[ile[i]].PB(i);
	freopen("t.in","r",stdin);
	freopen("t.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		++test;
		scanf("%d%d%d",&c,&d,&v);
		for(int i=0;i<d;++i){
			scanf("%d",&tab[i]);
			zaj[tab[i]] = true;
			}
		for(r=0;;++r){
            if(check(r))
				break;
			}
		printf("Case #%d: %d\n",test,r);
		for(int i=0;i<d;++i)
			zaj[tab[i]] = false;
		}
	}
