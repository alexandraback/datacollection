#include<iostream>
#include<cstdio>
using namespace std;

int a[10001],sm,tot=0,t;

void solve(){
	int i, j, s = 0;
	for(i = 0; i <= sm; i++){
		s = a[0] + i;
		for(j = 1; j <= sm; j++){
			if(j <= s){
				s+=a[j];
			}
			else break;
		}
		if(s-i==tot){
			printf("%d\n", i);
			return;
		}
	}
}

int main(){
	freopen("t1.in","r",stdin);
	freopen("t1.out","w",stdout);
	char ch;
	scanf("%d\n", &t);
	for(int i = 1; i <= t; i++){
		printf("Case #%d: ", i);
		scanf("%d ", &sm);
		tot=0;
		for(int j = 0; j <= sm; j++){
			scanf("%c", &ch);
			a[j] = ch-'0';
			tot+=a[j];
		}
		scanf("\n");
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
