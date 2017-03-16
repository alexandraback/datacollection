#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <iostream>
#include <map>
using namespace std;

pair <int,int> isi[1111];
vector <pair<pair<int,int>,int> > sol;
int jeans_shirt[20][20];
int jean_pants[20][20];
int pants_shirt[20][20];
int main() {

	int T = 0;
	int tt = 1;
	scanf("%d",&T);
	while (T--){
		int J,P,S,K;
		printf("Case #%d: ",tt++);
		scanf("%d%d%d%d",&J,&P,&S,&K);

		sol.clear();
		memset(jean_pants,0,sizeof jean_pants);
		memset(jeans_shirt,0,sizeof jeans_shirt);
		memset(pants_shirt,0,sizeof pants_shirt);

		if (S < K)
			K = S;
		int ct=0;

		printf("%d\n",J*P*K);
		for (int j=0;j<P;j++){
			ct =j*K;
			for (int i=0;i<J;i++){
				for (int k=0;k<K;k++){
					printf("%d %d %d\n",i+1,j+1,ct % S + 1);
					ct++;
				}
			}
		}
		
	}
}