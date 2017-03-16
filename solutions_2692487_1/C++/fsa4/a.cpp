#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>

#define eps 1e-8

using namespace std;

typedef long long ll;

ll a, mote[200];

ll qtd(int n){
	ll atual = a, ret = 0;

	for(int i = 0; i < n; i++){
		if(atual > mote[i]){
			atual += mote[i];
		}else{
		    if(atual == 1){
		        ll inf = 1;
		        inf = (inf << 50);
                return inf;
		    }

			while(atual <= mote[i]){
				ret++;
				atual += atual-1;
			}
			i--;
		}
	}

	return ret;
}

int main (){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

	ll resp = 1, temp;
	resp = (resp << 50);
	int t, N;
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		printf("Case #%d: ", caso);
		scanf("%lld %d", &a, &N);
		for(int i = 0; i < N; i++){
			scanf("%lld", &mote[i]);
		}

		resp = 1;
		resp = (resp << 50);

		sort(mote, mote+N);

		for(int i = 0; i <= N; i++){
			temp = qtd(N-i)+i;
			if(resp > temp){
				resp = temp;
			}
		}

		printf("%lld\n", resp);
	}

	return 0;
}
