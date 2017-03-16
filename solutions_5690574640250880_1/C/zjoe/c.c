#include <stdio.h>
#include <string.h>

int r, c, rotate;
int a[55][55];
void draw();
int main(){
	int i, j, k, tot, m, rest, width, height, extra;
	
	scanf("%d", &tot);
	for(i = 1; i <= tot; i++){
		scanf("%d%d%d", &r, &c, &m);
		printf("Case #%d:\n", i);

		rotate = 0;
		if(r < c){
			j = r;
			r = c;
			c = j;
			rotate = 1;
		}

		for(j = 1; j <= 50; j++){
			for(k = 1; k <= 50; k++){
				a[j][k] = '*';
			}
		}
		rest = r * c - m;

		if(1 == c){
			for(j = 1; j <= rest; j++){
				a[j][1] = '.';
			}
			a[1][1] = 'c';
			draw();
		}
		else if(2 == c){
			if(1 == rest){
				a[1][1] = 'c';
				draw();
			}
			else if((rest & 1) || rest == 2){
				printf("Impossible\n");
			}
			else{
				for(j = 1; j <= r - m / 2; j++){
					a[j][1] = a[j][2] = '.';
				}
				a[1][1] = 'c';
				draw();
			}
		}
		else{
			if(2 == rest || 3 == rest || 5 == rest || 7 == rest){
				printf("Impossible\n");
			}
			else if(1 == rest){
				a[1][1] = 'c';
				draw();
			}
			else{
				width = c;
				height = rest / c;
				extra = rest % c;
				if(height < 2){
					height = 2;
					width = rest / 2;
					extra = rest % 2;
					
				}
				if(height == 2 && extra == 1){
						height = 3;
						width = rest / 3;
						extra = rest % 3;
				}
				if(extra != 1){
					for(j = 1; j <= height; j++){
						for(k = 1; k <= width; k++){
							a[j][k] = '.';
						}
					}
					for(k = 1; k <= extra; k++){
						a[height + 1][k] = '.';
					}
					a[1][1] = 'c';
				}
				else{
					for(j = 1; j <= height - 1; j++){
						for(k = 1; k <= width; k++){
							a[j][k] = '.';
						}
					}
					for(k = 1; k <= width - 1; k++){
						a[height][k] = '.';
					}
					for(k = 1; k <= extra + 1; k++){
						a[height + 1][k] = '.';
					}
					a[1][1] = 'c';

				}
				draw();
			}
			
		}
	}
	return 0;
}
void draw(){
	int i, j;
	if(!rotate){
		for(i = 1; i <= r; i++){
			for(j = 1; j <= c; j++){
				printf("%c", a[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		for(i = 1; i <= c; i++){
			for(j = 1; j<= r; j++){
				printf("%c", a[j][i]);
			}
			printf("\n");
		}
	}
}
