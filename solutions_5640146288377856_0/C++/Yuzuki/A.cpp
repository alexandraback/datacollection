#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
#define LL long long
#define Maxn 10050
int main(){
	int cases;
	int r,c,w;
	scanf("%d",&cases);
	for (int cas=1;cas<=cases;cas++){
		scanf("%d%d%d",&r,&c,&w);
		int ans=(c+w-1)/w *r+w-1;
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}