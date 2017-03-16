#include <cstdio>

void run(int test){
	int X,R,C;
	scanf("%d %d %d",&X,&R,&C);

	if(X == 1){
		printf("Case #%d: GABRIEL\n",test);
	}else if(X == 2){
		if((R*C)%2 != 0) printf("Case #%d: RICHARD\n",test);
		else printf("Case #%d: GABRIEL\n",test);
	}else if(X == 3){
		if((R*C)%3 != 0) printf("Case #%d: RICHARD\n",test);
		else if(R == 1 || C == 1) printf("Case #%d: RICHARD\n",test);
		else printf("Case #%d: GABRIEL\n",test);
	}else if(X == 4){
		if((R*C)%4 != 0) printf("Case #%d: RICHARD\n",test);
		else if(R <= 4 && C <= 2) printf("Case #%d: RICHARD\n",test);
		else if(R <= 2 && C <= 4) printf("Case #%d: RICHARD\n",test);
		else if(R <= 2 || C <= 2) printf("Case #%d: RICHARD\n",test);
		else printf("Case #%d: GABRIEL\n",test);
	}else if(X == 5){
		if((R*C)%5 != 0) printf("Case #%d: RICHARD\n",test);
		else if(R <= 2 || C <= 2) printf("Case #%d: RICHARD\n",test);
		else if(R <= 3 && C <= 5) printf("Case #%d: RICHARD\n",test);
		else if(R <= 5 || C <= 3) printf("Case #%d: RICHARD\n",test);
		else printf("Case #%d: GABRIEL\n",test);
	}else if(X == 6){
		if((R*C)%6 != 0) printf("Case #%d: RICHARD\n",test);
		else if(R <= 2 || C <= 2) printf("Case #%d: RICHARD\n",test);
		else if(R <= 4 && C <= 6) printf("Case #%d: RICHARD\n",test);
		else if(R <= 6 || C <= 4) printf("Case #%d: RICHARD\n",test);
		else printf("Case #%d: GABRIEL\n",test);
	}else printf("Case #%d: RICHARD\n",test);
}

int main(){
	// freopen("D.txt","r",stdin);
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);

	int T; scanf("%d",&T);
	for(int i=1;i<=T;i++) run(i);
	return 0;
}

/*
 x
xxx
 x

xxxxx

xxxx
x

xxxx
 x


xxx
xx

xxx
x x

xxx
x
x

////////

xxxxxx

xxxxx
x

xxxxx
 x

xxxxx
  x

xxxx
xx

xxxx
x x

xxxx
x  x

xxxx
x
x

xxxx
 x
 x

xxx
xxx

*/