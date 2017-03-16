#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int T,R,N,M,K;
long long prod[20];
int r[20];
bool poss[10];

bool findIt(int ri, const set<long long>& s_, int mm){
	
	if(s_.size()==0) return true;
	if(ri==N){
		return false;
	}
	for(int i=2;i<=mm;i++){
		if(!poss[i]) continue;
		//if(ri< && i!=M) continue;
		set<long long> s(s_);
		bool changed = false;
		for(set<long long>::iterator it = s_.begin();it!=s_.end();it++){
			long long x=*it;
			if(x%i==0){
				changed= true;
				s.erase(x);
				if(x!=i) s.insert(x/i);
			}
		}
		if(changed){
			r[ri]=i;
			if(findIt(ri+1,s,i)) return true;
			r[ri]=2;
		}
	}
	return false;
}

int main(int argc, char *argv[]) {
	freopen("C-small-2-attempt6.in","r",stdin);
	freopen("C-small-2-attempt6.out","w",stdout);
	printf("Case #1:\n");
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d%d%d%d",&R,&N,&M,&K);
		int KK=K;
		for(int rr=0;rr<R;rr++){
			if(rr%50==0){
				FILE* h=fopen("C-status.txt","w");
				fprintf(h,"%d/%d\n",rr+1,R);
				fclose(h);
			}
			K=KK;
			memset(poss,0,sizeof(poss));
			prod[0]=1;
			set<long long> s;
			for(int k=1;k<=K;k++){
				scanf("%lld",&prod[k]);
				s.insert(prod[k]);
				for(int i=2;i<10;i++){
					if(prod[k]%i==0) poss[i]=true;
				}
			}
			sort(prod,prod+K+1);
			K=unique(prod,prod+K+1)-prod;
			//(2->M)^N
			s.erase(1);
			for(int i=0;i<N;i++) r[i]=2;
			FILE* toStop = fopen("stop.txt","r");
			if(!toStop) findIt(0,s,M);
			else fclose(toStop);
			for(int i=0;i<N;i++) printf("%d",r[i]);
			printf("\n");
		}
	}
}