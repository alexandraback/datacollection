#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <iostream>
#include <map>
using namespace std;


int path[1111][1111];
int appears[2][1111];
map <string,int> slist1,slist2;
int N,M;
char s1[22][22],s2[22][22];

int main(){

	int T = 0;
	int tt = 1;
	scanf("%d",&T);
	while (T--){
		memset(path,0,sizeof path);
		M = 0;
		N = 0;
		slist1.clear();
		slist2.clear();
		memset(appears,0,sizeof appears);

		printf("Case #%d: ",tt++);
		int N;
		scanf("%d",&N);
		for (int i=0;i<N;i++){
			scanf("%s %s",s1[i],s2[i]);
		}

		int res = 0;
		for (int i=0;i<(1<<N);i++) {
			//cout<<"AA "<<i<<endl;
			slist1.clear();
			slist2.clear();
			bool gagal = 0;
			int bz = 0;
			for (int j=0;j<N;j++){
				if (i & (1<<j)) {
					slist1[s1[j]] = 1;
					slist2[s2[j]] = 1;
				}
			}

			for (int j=0;j<N;j++){
				if ((i & (1<<j)) == 0) {
					bz++;
					if (slist1[s1[j]] == 0 || slist2[s2[j]] == 0)
						gagal = 1;
				}
			}

			if (!gagal)
				res = max(res, bz);
		}
		printf("%d\n",res);
	}
}