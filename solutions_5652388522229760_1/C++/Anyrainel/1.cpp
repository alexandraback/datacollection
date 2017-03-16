#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int used[10];
bool check()
{
	for(int i = 0;i < 10; i++)
		if(!used[i])
			return false;
	return true;
}
void count(int x)
{
	while(x) {
		used[x%10]=1;
		x/=10;
	}
	return;
}
int main()
{
	int n, T, cur, maxc = 0, cnt;
	bool found;
	cnt = scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		cnt = scanf("%d", &n);
		printf("Case #%d: ", kase);
		if(!n) {
			printf("INSOMNIA\n");
			continue;
		}
		memset(used, 0, sizeof(used));
		cur = 0;
		found = false;
		for(int i = 1; i <= 100; i++) {
			cur += n;
			count(cur);
			if(check()) {
				found = true;
				break;
			} 
		}
		if(found)
			printf("%d\n", cur);
		else 
			printf("INSOMNIA\n");
	}
	return 0;
}