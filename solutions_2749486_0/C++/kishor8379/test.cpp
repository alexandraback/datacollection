#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

FILE * fin = fopen("f:/cj/a.in","r");
FILE * fout = fopen("f:/cj/a.out","w");

bool checkn(char *s,int n,int a,int b,int &pos){
	int cn = 0;
	char c;
	for( int i = a; i <= b ; i++ ) {
		c = s[i];
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ) 
		{
			cn=0;
			continue;
		}
		cn++;
		if( cn == n ) {
			pos = i - n + 1 ;
			return true;
		}
	}
	return false;
}
int main () {

			
	int tc ;
	fscanf(fin,"%d",&tc);
	int t = 0 ;
	int pos =0;
	char str[1000000];
	while( t < tc ) {
		t++ ;
		int x,y;
		int x1 = 0,y1 =0;
		int s = 1;
		int i = 0;
		fscanf(fin,"%d %d",&x,&y);
		
		int flip = 0;

		if( x > 0 ) {
			while ( x1 != x ) { 
				if( x1 + s <= x ) {
					x1+=s;
					str[i++] = 'E' ;
					s++;
				} else {
					str[i++] = 'W' ;
					str[i++] = 'E' ;
					x1+=1;
					s+=2;
				}
			}
		} else {
			while ( x1 != x ) { 
				if( x1 - s >= x ) {
					x1-=s;
					str[i++] = 'W' ;
					s++;
				} else {
					str[i++] = 'E' ;
					str[i++] = 'W' ;
					x1-=1;
					s+=2;
				}
			}
		}
	
		if( y > 0 ) {
			while ( y1 != y ) { 
				if( y1 + s <= y ) {
					y1+=s;
					str[i++] = 'N' ;
					s++;
				} else {
					str[i++] = 'S' ;
					str[i++] = 'N' ;
					y1+=1;
					s+=2;
				}
			}
		} else {
			while ( y1 != y ) { 
				if( y1 - s >= y ) {
					y1-=s;
					str[i++] = 'S' ;
					s++;
				} else {
					str[i++] = 'N' ;
					str[i++] = 'S' ;
					y1-=1;
					s+=2;
				}
			}
		}
		str[i]=0;
		fprintf(fout,"Case #%d: %s\n",t,str);
		
		
				
	}

	
	fflush(fout);
	fclose(fout) ;
	fclose(fin);

	return 0 ;

}
