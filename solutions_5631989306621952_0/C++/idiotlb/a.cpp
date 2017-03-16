#include <cstdio>
#include <cstring>

const int N = 1e4+10, LEN = 1e4;
int T;
int a[N][2];
char st[LEN];

void Work(){
	memset(a, 0, sizeof(a));
	scanf("%s", st);
	int head = 1, last = 1;
	a[head][0] = 0;
	int len = strlen(st);
	int tot = 1;
	for(int i = 1; i < len; i ++){
		a[++ tot][0] = i;
		if(st[a[head][0]] <= st[i])
			{a[tot][1] = head; head = tot;}
		else 
			{a[last][1] = tot; last = tot;}
	}
	
	for(int p = head; p; p = a[p][1])
		printf("%c", st[a[p][0]]);
	printf("\n");
}

int main(){
	//freopen("a.in", "r", stdin), freopen("a.out", "w", stdout);
	
	scanf("%d", &T); int t = 0;
	while(T --){
		t++;
		printf("Case #%d: ", t);
		Work();
	}
	
	return 0;
}