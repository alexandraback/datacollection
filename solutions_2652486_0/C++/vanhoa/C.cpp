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

bool findIt(int ri, const set<long long>& s_){
	bool done = true;
	for(int i=0;i<K;i++){
		if(s_.find(prod[i])==s_.end()){
			done=false;
			break;
		}
	}
	if(done) return true;
	if(ri==N){return false;}
	for(int i=2;i<=M;i++){
		set<long long> s(s_);
		for(set<long long>::iterator it = s_.begin();it!=s_.end();it++){
			s.insert((*it)*i);
		}
		r[ri]=i;
		if(findIt(ri+1,s)) return true;
	}
	return false;
}

int main(int argc, char *argv[]) {
	freopen("C-small-1-attempt0.in","r",stdin);
	freopen("C-small-1-attempt0.out","w",stdout);
	printf("Case #1:\n");
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d%d%d%d",&R,&N,&M,&K);
		int KK=K;
		for(int rr=0;rr<R;rr++){
			K=KK;
			for(int k=0;k<K;k++){
				scanf("%lld",&prod[k]);
			}
			sort(prod,prod+K);
			K=unique(prod,prod+K)-prod;
			//(2->M)^N
			set<long long> s;
			s.insert(1);
			for(int i=0;i<N;i++) r[i]=2;
			findIt(0,s);
			for(int i=0;i<N;i++) printf("%d",r[i]);
			printf("\n");
		}
	}
}