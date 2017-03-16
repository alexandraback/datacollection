#include<iostream>
using namespace std;

int pair_cmp(const void *a, const void *b){
	const pair<int,pair<int,int> > *A = (pair<int,pair<int,int> >*)a;
	const pair<int,pair<int,int> > *B = (pair<int,pair<int,int> >*)b;
	return A->first - B->first;
}

int main(){
	int T,t,N,i,a,b,u1,col,ans;
	pair<int,pair<int,int> > V[3000];
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d",&N);
		for(i=0;i<N;i++){
			scanf("%d",&a);
			scanf("%d",&b);
			V[2*i].first = a;
			V[2*i].second.first = i;
			V[2*i].second.second = 1;
			V[2*i + 1].first = b;
			V[2*i + 1].second.first = i;
			V[2*i + 1].second.second = 2;
		}
		
		qsort(V,2*N,sizeof(pair<int,pair<int,int> >),pair_cmp);
		
		bool lvl_cmpl[N];
		ans = 0;
		u1 = 0;
		col = 0;
		for(i=0;i<2*N;i++){
			if(col >= V[i].first) {
				if(V[i].second.second == 2){
					lvl_cmpl[V[i].second.first] = true;
					col += 2;
					ans++;
				} else
					u1++;
			} else {
				if(u1 >= (V[i].first - col)){
					u1 -= V[i].first - col;
					ans += V[i].first - col;
					col = V[i].first;
					if(V[i].second.second == 2) {
						lvl_cmpl[V[i].second.first] = true;
						col += 2;
						ans++;
					} else
						u1++;
				} else 
					break;
			}
			
			//printf("%d %d %d - %d %d %d\n",V[i].first,V[i].second.first,V[i].second.second,u1,col,ans);
		}
		
		if(i != 2*N){
			printf("Case #%d: Too Bad\n",t);
		} else {
			for(i=0;i<N;i++)
				if(!lvl_cmpl[i])
					break;
			if(i == N)
				printf("Case #%d: %d\n",t,ans);
			else
				printf("Case #%d: Too Bad\n",t);
		}
	}
}