#include<stdio.h>

FILE*f=fopen("b.in","r");
FILE*g=fopen("b.out","w");

int x,y;

inline void solve ( int x , char minus , char plus ) {

	if ( x < 0 ){
		x = -x;
		for ( int i = 1 ; i <= x ; ++i ){
			fprintf(g,"%c%c",plus,minus);
		}
	}
	else{
		for ( int i = 1 ; i <= x ; ++i ){
			fprintf(g,"%c%c",minus,plus);
		}
	}
}

int main () {

    int t;
    fscanf(f,"%d",&t);
    
    for ( int ii = 1 ; ii <= t ; ++ii ){
		
		fprintf(g,"Case #%d: ",ii);
		fscanf(f,"%d %d",&x,&y);
		solve(x,'W','E');
		solve(y,'S','N');
		fprintf(g,"\n");
    }

    return 0;
}
