#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<string.h>
#include<vector>
using namespace std;
const int maxd = 7;
const int maxt = 10;
int pnum[maxd];
int mtime[maxt];
int t, d;
int main(){
	scanf("%d",&t);
	int ks = 1;
	while(t > 0){
		t--;
		scanf("%d", &d);
		for(int i = 1; i <= d; ++i){
			scanf("%d", pnum + i);
		}
		memset(mtime, 0, sizeof(mtime));
		for(int tmpt = 1; tmpt < maxt; ++tmpt){
			for(int i = 1; i <= d; ++i){
				mtime[tmpt] += (pnum[i] - 1) / tmpt;
			}
			mtime[tmpt] += tmpt;
		}
		int mmax = 0x7fffffff;
		int recid = -1;
		for(int tmpt = 1; tmpt < maxt; ++tmpt){
			if(mmax > mtime[tmpt]){
				recid = tmpt;
				mmax = mtime[tmpt];
			}
		}
		printf("Case #%d: %d\n",ks++, mmax);
	}
	return 0;
}

