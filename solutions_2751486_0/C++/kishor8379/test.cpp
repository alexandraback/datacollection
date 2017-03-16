#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

FILE * fin = fopen("f:/cj/a.in","r");
FILE * fout = fopen("f:/cj/a.out","w");

bool checkn(char *s,int n,int a,int b){
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
			return true;
		}
	}
	return false;
}
int main () {

			
	int tc ;
	fscanf(fin,"%d",&tc);
	int t = 0 ;
	
	char str[1024];
	while( t < tc ) {
		t++ ;
		int L = 0;
		int n = 0 ;
		int ans =0;
		fscanf(fin,"%s %d",str,&n);
		L = strlen(str);

		for( int i = 0 ; i < L ; i ++ ) {
			for ( int j = L-1 ; j >= i ; --j ) {
				if( checkn(str,n,i,j)){
					ans++;
				}
			}
		}
		fprintf(fout,"Case #%d: %d\n",t,ans);
		
		
				
	}

	
	fflush(fout);
	fclose(fout) ;
	fclose(fin);

	return 0 ;

}
