#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<ctype.h>
#include<vector>
#include<set>
#include<algorithm>
#include<map>

int TC, TC_n;

#define N_ 20
int N;
int D[N_+1];
using namespace std;
vector<int> T[2000001];
int res, res1, res2;

int main(){
	freopen("INPUT.TXT","r",stdin);
	freopen("OUTPUT.TXT","w",stdout);

	int i, j;
	T[0].push_back(0);
	vector<int>::iterator it, it2;
	for( scanf("%d",&TC); TC --;){
		scanf("%d",&N);
		for(i=1; i<=N; i++) scanf("%d",&D[i]);
		std::sort(D+1,D+N+1);
		
		for(j=1; j<=2000000; j++) T[j].clear();
		
		res = res1 = res2 = 2147483647;
		int sm = 0;
		for(i=1; i<=N; i++){
			sm += D[i];
			if(sm > 2000000) break;
			for(j=sm; j>=D[i]; j--){
				if(j > 2000000) continue;
				for(it = T[j-D[i]].begin(); it!=T[j-D[i]].end(); it++){
					T[j].push_back(*it | (1<<i));
					bool tmp = false;
					for( it2 = T[j].begin(); it2!=T[j].end(); it2++)
						if(((*it | (1<<i)) & *it2) == 0) { tmp = true; break; }
					if(tmp){
						int a = *it | (1<<i), b = *it2;
						res = j; res1 = a; res2 = b; 
						goto print;
						break;
					}
				}
			}
		}

		if(res == 2147483647) printf("Case #%d:\nImpossible\n",++TC_n);
		else{
			print:
			printf("Case #%d:\n",++TC_n);
			for(i=1; i<=N; i++){ if(res1 & (1<<i)) printf("%d ",D[i]); } puts("");
			for(i=1; i<=N; i++){ if(res2 & (1<<i)) printf("%d ",D[i]); } puts("");
		}
	}
	return 0;
}