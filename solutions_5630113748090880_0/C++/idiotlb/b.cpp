#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e3+10;
int T, n;
int a[N];

void Work(){
	scanf("%d", &n);
	for(int i = 1; i <= 2*n - 1; i ++)
		for(int j = 1; j <= n; j ++) scanf("%d", &a[(i - 1)*n + j]);
	sort(a + 1, a + 1 + 2*n*n - n);
	int acc = 1;
	for(int i = 2; i <= 2*n*n - n; i ++){
		if(a[i] != a[i - 1]){
			if(acc % 2) printf(" %d", a[i - 1]);
			acc = 1;
		} else acc ++;
	}
	if(acc % 2) printf(" %d", a[2*n*n - n]);
	printf("\n");
}

int main(){
	//freopen("b.in", "r", stdin), freopen("b.out", "w", stdout);
	
	scanf("%d", &T); int t = 0;
	while(T --){
		t ++;
		printf("Case #%d:", t);
		Work();
	}
	
	return 0;
}