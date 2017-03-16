#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long int lint;

lint m, M, curr;
int B, b, casos, idx, resta, ep[64], t[64][64];
vector <int> v;

void crivo(){
	for(int i=2;i<50;i++) ep[i] = 1;

	for(int i=2;i<50;i++){
		if(ep[i] == 1){
			for(int j=2*i;j<50;j+=i) ep[j] = 0;
		}
	}
}

int main(){
	crivo();
	scanf(" %d", &casos);
	for(int inst=1;inst<=casos;inst++){
		scanf(" %d %lld", &b, &m); B = b; M = m;
		
		v.clear();
		for(int i=2;i<B;i++){
			while(ep[i] && m%(lint)i == 0LL){
				v.push_back(i);
				m = m/(lint)i;
			}
		}
		
		//printf("m is %lld\n", m);
		//for(int i=0;i<v.size();i++) printf("%d ", v[i]); printf("\n");
		
		if(m != 1LL){
			printf("Case #%d: IMPOSSIBLE\n", inst);
		}
		else{
			bool pode = true;
			resta = B-1;
			idx = v.size()-1;
			for(int i=0;i<B;i++) for(int j=0;j<B;j++) t[i][j] = 0;
			
			for(int i=0;i<B;i++){
				curr = 1LL;
				for(int k=idx;k>=0;k--){
					idx--;
					curr *= v[k];
					
					if(curr > resta) pode = false;
					else if(k > 0 && curr*v[k-1] > resta) break;
				}
				if(!pode) break;
				for(int j=i+1;j<i+1+curr;j++) t[i][j] = 1;
				
				resta--;
			}
			
			if(!pode) printf("Case #%d: IMPOSSIBLE\n", inst);
			else{
				printf("Case #%d: POSSIBLE\n", inst);
				for(int i=0;i<B;i++){
					for(int j=0;j<B;j++) printf("%d", t[i][j]);
					printf("\n");
				}
			}
		}
	}
	return 0;
}
