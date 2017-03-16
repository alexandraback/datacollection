#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

#define mp make_pair
#define nd second
#define st first
#define pb push_back

using namespace std;

typedef long long int LL;

int main(){
	int q;
	scanf("%d", &q);
	for(int kozdreczka=1;kozdreczka<=q;++kozdreczka){
		int a, b, c, res;
		scanf("%d %d %d", &a, &b, &c);
		res=a*((b-1)/c+c);
		printf("Case #%d: %d\n", kozdreczka, res);
	}
	return 0;
}
