#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int max;
	char *str;
	int *b;

}Complete;
void input(Complete *c){
	int i;
	scanf("%d", &(c->max));
	c->str = malloc((c->max + 1));
	scanf("%s", c->str);
	c->b = malloc(sizeof(int)*(c->max + 1));
	for (i = 0; i < (c->max)+1; i++){
		*(c->b + i) = *(c->str + i)-'0';

	}

}
int process(Complete *c){
	int i,count,required=0;
	count = *(c->b);
	for (i = 1; i <= c->max; i++){
		if (*(c->b + i) != 0){
			if (i > count){
				if (required < (i - count))
					required = i - count;
			}
			count = count + *(c->b + i);
			
		}
		
	}
	return required;
}
void main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int t,i,j,count=0,*out;
	scanf("%d", &t);
	out = malloc(sizeof(int)*t);
	Complete *c;
	c=malloc(sizeof(Complete)*t);
	
	for (i = 0; i < t; i++){
		input(c + i);
	}
	for (j = 0; j < t; j++){
		printf("Case #%d: %d \n", j+1, process(c + j));
	}

}