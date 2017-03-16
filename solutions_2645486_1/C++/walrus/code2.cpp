#include"stdio.h"
#include"cassert"
#include"algorithm"
using namespace std;
long long V[100000];
long long N,E,R;
long long best(int u, int v, int begin_energy, int end_energy) {
	assert(end_energy - begin_energy <= (v-u+1)*R);
	assert((unsigned)end_energy<=E && (unsigned)begin_energy<=E);
	if(v<u)return 0;
	if (u==v) return V[u]*(begin_energy - max(end_energy-R,0LL));
	if(end_energy-begin_energy == (v+1-u) * R)return 0;
	int mx = u;
	for(int l = u+1; l <= v; l++) if(V[mx]<V[l]) mx = l;
	int mid_energy_a = min(begin_energy + (mx - u)*R, E);
	int mid_energy_b = max(0LL, end_energy - (v - mx+1)*R);
	assert(mid_energy_b <= mid_energy_a);
	return (mid_energy_a - mid_energy_b) * V[mx] + best(u, mx-1, begin_energy, mid_energy_a) + best(mx+1, v, min(mid_energy_b+R, E), end_energy);
}
int main(){
	int T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++){
		scanf("%Ld%Ld%Ld",&E,&R,&N);
		for(int i=0;i<N;i++)
			scanf("%Ld", &V[i]);
		printf("Case #%d: %Ld\n", tt, best(0, N-1, E, 0));
	}
}
