#include <cstdio>
#include <cstring>
using namespace std;

const int N = 11;
int T, n;
bool b[N];

void Work(){
	memset(b, 0, sizeof(b));
	scanf("%d", &n);
	if(n == 0){printf("INSOMNIA\n"); return;}
	int now = n;
	int num = 10;
	while(1){
		int t = now;
		while(t){
			if(!b[t % 10]) num --;
			b[t % 10] = 1;
			t = t/10;
		}
		if(!num){
			printf("%d\n", now);
			return;
		}
		now += n;
	}
}

int main(){
	freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	
	scanf("%d", &T); int t = 0;
	while(T --){
		t ++;
		printf("Case #%d: ", t);
		Work();
	}
	
	return 0;
}