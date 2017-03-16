#include <bits/stdc++.h>
#define fr(i,a,b) for(int i = (a); i < (b); ++i)
#define pb push_back
#define eps 1e-7
#define inf 0x3f3f3f3f
#define mod 1000000007

using namespace std;


int main(){
	int t, caso = 1, a, b, k;
	
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &a, &b, &k);
		int cont = 0;
		fr(i, 0, a){
			fr(j, 0, b){
				if((i&j) < k) cont++;
			}
		}
		
		printf("Case #%d: %d\n", caso++, cont);
	}
	
	return 0;
}

