#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>

using namespace std;

int main() {
	int T;scanf("%d",&T);
	for(int t=1;t<=T;++t){
		map<int,int> cnt;
		int n;scanf("%d",&n);

		for(int i=0;i<2*n-1;++i){
			for(int j=0;j<n;++j){
				int x;scanf("%d",&x);
				cnt[x]++;
			}
		}


		printf("Case #%d:", t);

		for(map<int,int>::iterator it = cnt.begin(); it!=cnt.end();++it){
			if (it->second % 2 == 1){
				printf(" %d", it->first);
			}
		}
		puts("");
	}	
	return 0;
}
