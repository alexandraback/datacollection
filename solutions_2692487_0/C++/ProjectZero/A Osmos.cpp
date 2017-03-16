#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 105;
const int MAXSIZE = 1e6+100;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int T,A,N,mote[MAXN];
int ans;

map < iii, int > M;

int rec(int ind,int now,int last){
	if(ind > last) return 0;
	
	//printf("rec (%d,%d,%d)\n",ind,now,last);
	if(M.count(iii(ind,ii(now,last)))) return M[iii(ind,ii(now,last))];
	
	if(now > mote[ind]){
		return M[iii(ind,ii(now,last))] = rec(ind+1,now+mote[ind],last);
	}
	else{
		if(now + now -1 == now) return M[iii(ind,ii(now,last))] = rec(ind,now,last-1)+1;
		else return M[iii(ind,ii(now,last))] = min( rec(ind,now+now-1,last)+1 ,rec(ind,now,last-1)+1 );
	}
}

int main(){
	freopen("A-small-attempt3.in","r",stdin);
	freopen("A-small-output3.out","w",stdout);
	
	scanf("%d",&T);
	for(int _i=1;_i<=T;_i++){
		printf("Case #%d: ",_i);
		
		scanf("%d %d",&A,&N);
		for(int i=1;i<=N;i++) scanf("%d",&mote[i]);
		sort(&mote[1],&mote[N+1]);
		
		M.clear();
		int ans = rec(1,A,N);
		printf("%d\n",ans);
	}
	return 0;
}