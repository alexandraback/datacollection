#include <cstdio>
#define f(a, b, c) for(int a = (b); a < (c); a++)

int n, t, x, y;
char c[109][109];

int main(){
	freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    f(z, 0, t){
		printf("Case #%d:\n", z + 1);
		scanf("%d %d %d", &x, &y, &n);
		n = x * y - n;
		int b = 0, k;
		if(x == 1){
			f(i, 0, y) printf("%c", i < n ? (i ? '.' : 'c') : '*');
			printf("\n");
		}else if(y == 1)
			f(i, 0, x) printf("%c\n", i < n ? (i ? '.' : 'c') : '*');
		else if((x == 2 || y == 2) && ((n % 2 && n > 1) || n == 2))
			printf("Impossible\n");
		else if(x == 2){
			printf("%c", n ? 'c' : '*');
			f(i, 1, y) printf("%c", i < n / 2 ? '.' : '*'); printf("\n");
			f(i, 0, y) printf("%c", i < n / 2 ? '.' : '*'); printf("\n");
		}else if(y == 2){
			printf("%c%c\n", n ? 'c' : '*', n >= 2 ? '.' : '*');
			f(i, 1, x) printf("%c%c\n", i < n / 2 ? '.' : '*', i < n / 2 ? '.' : '*');
		}else if(n == 2 || n == 3 || n == 5 || n == 7){
			printf("Impossible\n");
		}else if(n == 1 || n == 4){
			f(i, 0, x) f(j, 0, y) c[i][j] = '*';
			c[0][0] = 'c';
			if(n >= 3){
				c[0][1] = '.';
				c[1][0] = '.';
				c[1][1] = '.';
			}
			f(i, 0, x){
				f(j, 0, y) printf("%c", c[i][j]);
				printf("\n");
			}
		}else{
			if(y > x){
				b = 1;
				x ^= y ^= x ^= y;
			}
			if(y < (n - 1) / 3 + 1) k = y;
			else k = (n - 1) / 3 + 1;
			f(i, 0, x) f(j, 0, y) c[i][j] = '*';
			f(i, 0, n / k) f(j, 0, k) c[i][j] = '.';
			if(n - (n / k) * k == 1){
				c[n / k][0] = c[n / k][1] = '.';
				c[n / k - 1][k - 1] = '*';
			}else{
				f(i, 0, n - (n / k) * k) c[n / k][i] = '.';
			}
			c[0][0] = 'c';
			if(!b) f(i, 0, x){
				f(j, 0, y) printf("%c", c[i][j]);
				printf("\n");
			}else f(j, 0, y){
				f(i, 0, x) printf("%c", c[i][j]);
				printf("\n");
			}
			
		}
	}
    
    scanf("\n");
}
