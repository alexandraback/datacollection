#include <vector> 
#include <string> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <stack> 
#include <queue> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
#include <cctype> 
#include <cassert> 
#include <memory.h> 
using namespace std;
long long bn[110];
long long obn[110];
long long bt[110];
long long otn[110];
long long tn[110];
long long tt[110];
using namespace std;
int N, M;
int main() {
	int T;
	scanf("%d", &T);
	for(int q=1;q<=T;q++) {
		memset(bn, 0, sizeof(bn));
		memset(bt, 0, sizeof(bt));
		memset(tn, 0, sizeof(tn));
		memset(tt, 0, sizeof(tt));
		scanf("%d %d", &N, &M);
		for(int i=0;i<N;i++) {
			scanf("%lld %lld", &bn[i], &bt[i]);	
			obn[i] = bn[i];
		}
		for(int i=0;i<M;i++) {
			scanf("%lld %lld", &tn[i], &tt[i]);	
			otn[i] = tn[i];
		}
		if(N == 1) {
			long long nn = bn[0];
			for(int i=0;i<M;i++) {
				if(tt[i] == bt[0]) 
					nn -= tn[i];
			}
			if(nn < 0) nn = 0;
			printf("Case #%d: %lld\n", q, bn[0] - nn);
			continue;
		} else if(N == 2) {
			long long mm = 0;
			for(int i=0;i<M;i++) {
				for(int l=0;l<N;l++)
					bn[l] = obn[l];
				for(int l=0;l<M;l++)
					tn[l] = otn[l];

				long long mk = 0;	
				long long sum = 0;
				for(int k=0;k<=i;k++) {
					if(bt[0] == tt[k]) {
						if(bn[0] <= tn[k])  {
							mk = bn[0];
							bn[0] -= mk;
							tn[k] -= mk;
						} else {
							mk = tn[k];
							bn[0] -= mk;
							tn[k] -= mk;
						}
						sum += mk;
					}
				}
				for(int k=i;k<M;k++) {
					if(bt[1] == tt[k]) {
						if(bn[1] <= tn[k])  {
							mk = bn[1];
							bn[1] -= mk;
							tn[k] -= mk;
						} else {
							mk = tn[k];
							bn[1] -= mk;
							tn[k] -= mk;
						}
						sum += mk;
					}
				}
				if(sum > mm) mm = sum;

			}
			printf("Case #%d: %lld\n", q, mm);
			continue;
		} else {
			long long mm = 0;
			for(int i=0;i<M;i++) {
				for(int j=i;j<M;j++) {

					for(int l=0;l<N;l++)
						bn[l] = obn[l];
					for(int l=0;l<M;l++)
						tn[l] = otn[l];

					long long mk = 0;	
					long long sum = 0;
					for(int k=0;k<=i;k++) {
						if(bt[0] == tt[k]) {
							if(bn[0] <= tn[k])  {
								mk = bn[0];
								bn[0] -= mk;
								tn[k] -= mk;
							} else {
								mk = tn[k];
								bn[0] -= mk;
								tn[k] -= mk;
							}
							sum += mk;
						}
					}
					for(int k=i;k<=j;k++) {
						if(bt[1] == tt[k]) {
							if(bn[1] <= tn[k])  {
								mk = bn[1];
								bn[1] -= mk;
								tn[k] -= mk;
							} else {
								mk = tn[k];
								bn[1] -= mk;
								tn[k] -= mk;
							}
							sum += mk;
						}
					}
					for(int k=j;k<M;k++) {
						if(bt[2] == tt[k]) {
							if(bn[2] <= tn[k])  {
								mk = bn[2];
								bn[2] -= mk;
								tn[k] -= mk;
							} else {
								mk = tn[k];
								bn[2] -= mk;
								tn[k] -= mk;
							}
							sum += mk;
						}
					}
					if(sum > mm) mm = sum;

				}
			}
			printf("Case #%d: %lld\n", q, mm);
			continue;
		}
	}
	return 0;
}
