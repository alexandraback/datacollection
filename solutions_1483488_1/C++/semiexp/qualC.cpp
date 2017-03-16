#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int T, A, B;
int pows[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

int main()
{
	scanf("%d", &T);
	for(int i=0;i<T;i++){
		scanf("%d%d", &A, &B);
		int ln = 0;
		for(int j=0;j<8;j++) if(B <= pows[j]){
			ln = j; break;
		}
		int ret = 0;
		for(int j=A;j<B;j++){
			vector<int> sol;
			for(int k=1;k<ln;k++){
				int nw = (j%pows[k])*pows[ln-k] + (j/pows[k]);
				if(j < nw && nw <= B){
					sol.push_back(nw);
					//printf("%d %d\n", j, nw);
					//ret++;
				}
			}
			sort(sol.begin(), sol.end());
			sol.erase(unique(sol.begin(), sol.end()), sol.end());
			ret += sol.size();
		}
		printf("Case #%d: %d\n", i+1, ret);
	}
}
