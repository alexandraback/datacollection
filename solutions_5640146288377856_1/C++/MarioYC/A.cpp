#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <cassert>

using namespace std;

int R,C,W;

int get_mask(int mask[]){
	int ret = 0;

	for(int i = 0;i < C;++i){
		ret = ret * 3 + mask[i];
	}

	return ret;
}

int memo[59049];
int choose[59049];

int solve(int mask[]){
	int m = get_mask(mask);
	int &ret = memo[m];

	int hits = 0;

	for(int i = 0;i < C;++i){
		if(mask[i] == 1)
			++hits;
	}

	if(hits == W){
		int s,e;

		for(int i = 0;i < C;++i)
			if(mask[i] == 1){
				s = i;
				break;
			}

		for(int i = C - 1;i >= 0;--i)
			if(mask[i] == 1){
				e = i;
				break;
			}

		assert(e - s + 1 == W);

		return 0;
	}

	if(ret == -1){
		ret = C;

		for(int i = 0;i < C;++i){
			if(mask[i] == 0){
				int hit = -1;

				// hit
				mask[i] = 1;

				int pos1,pos2;
				bool ok = true;

				for(int j = 0;j < C;++j){
					if(mask[j] == 1){
						pos1 = j;
						break;
					}
				}

				for(int j = C - 1;j >= 0;--j){
					if(mask[j] == 1){
						pos2 = j;
						break;
					}
				}

				for(int j = pos1;j <= pos2;++j)
					if(mask[j] == 2)
						ok = false;

				int cont = 0;

				for(int j = pos1;j <= pos2;++j)
					if(mask[j] == 1)
						++cont;

				if(ok){
					ok = false;

					for(int j = 0;j + W - 1 < C && !ok;++j){
						ok = true;
						int cont2 = 0;

						for(int k = 0;k < W;++k){
							if(mask[j + k] == 2)
								ok = false;
							if(mask[j + k] == 1)
								++cont2;
						}

						if(cont2 != cont) ok = false;
					}
				}

				if(pos2 - pos1 + 1 <= W && ok){
					hit = solve(mask);
				}

				// miss
				int miss = -1;
				mask[i] = 2;

				ok = true;
				pos1 = -1,pos2 = -1;

				for(int j = 0;j < C;++j){
					if(mask[j] == 1){
						pos1 = j;
						break;
					}
				}

				for(int j = C - 1;j >= 0;--j){
					if(mask[j] == 1){
						pos2 = j;
						break;
					}
				}

				//printf("%d, pos1 = %d,pos2 = %d\n",m,pos1,pos2);

				cont = 0;

				if(pos1 != -1)
					for(int j = pos1;j <= pos2;++j){
						if(mask[j] == 2)
							ok = false;
						if(mask[j] == 1)
							++cont;
					}

				if(ok){
					ok = false;

					for(int j = 0;j + W - 1 < C && !ok;++j){
						ok = true;
						int cont2 = 0;

						for(int k = 0;k < W;++k){
							if(mask[j + k] == 2)
								ok = false;
							if(mask[j + k] == 1)
								++cont2;
						}

						if(cont2 != cont) ok = false;
					}
				}

				if(ok){
					miss = solve(mask);
				}

				if(hit == -1 && miss == -1){
					mask[i] = 0;
					printf("i = %d, W = %d: ",i,W);

					for(int j = 0;j < C;++j){
						printf("%d ",mask[j]);
					}
					printf("\n");
				}

				assert(hit != -1 || miss != -1);

				if(hit == -1){
					ret = min(ret,1 + miss);
					if(ret == 1 + miss){
						choose[m] = 2 * i + 1;
					}
				}else if(miss == -1){
					ret = min(ret,1 + hit);
					if(ret == 1 + hit){
						choose[m] = 2 * i;
					}
				}else{
					ret = min(ret,1 + max(hit,miss));

					if(ret == 1 + max(hit,miss)){
						if(ret == 1 + hit) choose[m] = 2 * i;
						else choose[m] = 2 * i + 1;
					}
				}

				//printf("%d %d : %d %d\n",m,i,hit,miss);

				mask[i] = 0;
			}
		}

		//printf("%d : %d\n",m,ret);
	}

	return ret;
}

int main(){
	ios::sync_with_stdio(0);

	int T;

	scanf("%d",&T);

	for(int tc = 1;tc <= T;++tc){
		scanf("%d %d %d",&R,&C,&W);

		int mask[C];

		for(int i = 0;i < C;++i)
			mask[i] = 0;

		memset(memo,-1,sizeof memo);

		printf("Case #%d: %d\n",tc,solve(mask));
		printf("%d %d\n",choose[0] / 2,choose[0] % 2);
	}

	return 0;
}