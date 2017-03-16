#include <cstdio>
int tc, tcn, x, r, c;

void solve(){
	scanf("%d", &tc);
	while (tc--){
		scanf("%d %d %d", &x, &r, &c);
		printf("Case #%d: ", ++tcn);
		if (x >= 7){
			puts("RICHARD");
			continue;
		}
		if (x == 1)
			puts("GABRIEL");
		else if (x == 2){
			if( r%2 && c%2 )
				puts("RICHARD");
			else
				puts("GABRIEL");
		}
		else if (x == 3){
			if ((r*c) % 3)
				puts("RICHARD");
			else if (r == 1 || c == 1)
				puts("RICHARD");
			else
				puts("GABRIEL");
		}
		else if (x == 4){
			if ((r*c) % 4)
				puts("RICHARD");
			else if (r <= 2 || c <= 2)
				puts("RICHARD");
			else
				puts("GABRIEL");
		}
		else if (x == 5){
			if ((r*c) % 5)
				puts("RICHARD");
			else if (r <= 3 || c <= 3)
				puts("RICHARD");
			else
				puts("GABRIEL");
		}
		else if (x == 6){
			if ((r*c) % 6)
				puts("RICHARD");
			else if (r <= 3 || c <= 3)
				puts("RICHARD");
			else
				puts("GABRIEL");
		}
	}
}

int main(void){
	//freopen("D-small-attempt0.in", "r", stdin);
	//freopen("output.txt","w",stdout);
	solve();
	return 0;
}