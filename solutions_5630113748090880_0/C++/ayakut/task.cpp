#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define MAXN 102000
#define pb push_back

using namespace std;
int n;
int ar[MAXN];
int main(){
	int Test,tt;
	scanf(" %d",&Test);
	for(tt=1;tt<=Test;tt++){
		printf("Case #%d: ",tt);
		for(int i = 0 ; i < MAXN ; i++) ar[i] = 0;
		scanf(" %d",&n);
		for(int i = 0 ; i < n*(2*n-1) ; i++){
			int x;
			scanf(" %d",&x);
			ar[x]++;
		}
		for(int i = 0 ; i < MAXN ; i++){
			if(ar[i] & 1) printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}