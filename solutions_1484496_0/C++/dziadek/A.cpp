#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#define MAX 25
using namespace std;

int tab[MAX],t,n,i,j;
vector< pair<long long, int> > Q;

int main(){
    scanf("%d",&t);
    for(i=0; i<t; ++i){
	scanf("%d",&n);
	printf("Case #%d:\n",i+1);
	for(j=0; j<n; ++j) scanf("%d",&tab[j]);
	int k;
	Q.clear();
	
	for(j=1; j<(1<<20); ++j){
	    long long sum=0;
	    for(k=0; k<20; ++k)
		if((1<<k)&j) sum+=tab[k];
		Q.push_back(make_pair(sum,j));
	}
	
	sort(Q.begin(),Q.end());
	pair<long long, int> last = Q[0];
	bool ok=false;
	
	for(j=1; j<Q.size(); ++j)
	    if(Q[j].first==last.first){
		int mask1=~Q[j].second;
		int mask2=~last.second;
		for(k=0; k<n; ++k)
		    if((1<<k) & (mask1 & last.second)) printf("%d ",tab[k]);
		printf("\n");
		for(k=0; k<n; ++k)
		    if((1<<k) & (mask2 & Q[j].second)) printf("%d ",tab[k]);
		ok=true;
		break;
	    }
	    else last=Q[j];
	    
	if(!ok) printf("impossible");
	printf("\n");
    }
    return 0;
}