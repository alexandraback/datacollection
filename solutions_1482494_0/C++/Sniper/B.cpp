#include <deque>
#include <set>
#include <queue>
#include <cstdio>
using namespace std;

int A[1004],B[1004];

int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t){
		int n;
		scanf("%d",&n);
		set<pair<int,int> > lo,hi;
		set<int> solvedlo;
		for(int i=0;i<n;++i){
			scanf("%d%d",&A[i],&B[i]);
			pair<int,int> p;
			p.second = i;

			p.first = A[i];
			lo.insert(p);
			
			p.first = B[i];
			hi.insert(p);
		}
		int score = 0;
		int cost = 0;
		bool good = true;
		while(!hi.empty()){
			pair<int,int> b = *hi.begin();
			while(score < b.first && !lo.empty() && score >= lo.begin()->first){
				pair<int,int> target(score,-1);
				set<pair<int,int> >::iterator it = lo.upper_bound(target);
				if(it==lo.end() || it->first > score){
					-- it;
				}
				target = *it;
				lo.erase(it);
				++ score;
				solvedlo.insert(target.second);
				++ cost;
				//printf("level1 : %d, cost : %d, score : %d\n",target.second,cost,score);
			}
			if(score >= b.first){
				if(solvedlo.find(b.second) != solvedlo.end()){
					++ score;
				}
				else{
					score += 2;
				}
				hi.erase(hi.begin());
				pair<int,int> target(A[b.second],b.second);
				set<pair<int,int> >::iterator it = lo.find(target);
				if(it != lo.end())	lo.erase(it);
				++ cost;
				//printf("level2 : %d, cost : %d, score : %d\n",b.second,cost,score);
			} else {
				good = false;
				break;
			}
		}
		if(good)	printf("Case #%d: %d\n",t,cost);
		else	printf("Case #%d: Too Bad\n",t);
	}
}
