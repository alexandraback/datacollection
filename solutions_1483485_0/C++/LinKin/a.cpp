#include<stdio.h>
#include<string.h>

char Map[777];
char Str[777];
char Used[777];

int main( void )
{
	long i,Icase,k = 0;
	char Str1[] = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
	char Str2[] = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
	
	Map[' '] = ' ';
	Map['z'] = 'q';
	Map['q'] = 'z';
	for( i=0;Str1[i];i++ ){
		if( Map[Str1[i]] ) continue;
		else Map[Str1[i]] = Str2[i];
	}
	
	
	freopen("Ain.txt","r",stdin );
	freopen("Aout.txt","w",stdout );
	
	/*for( i='a';i<='z';i++ ){
		if( Map[i] ) Used[Map[i]] = true;
	}
	for( i='a';i<='z';i++ ){
		if( !Used[i] ) printf("%c\n",i );
	}*/
	
	scanf("%ld%*c",&Icase );
	while( Icase-- ){
		gets( Str );
		for( i=0;Str[i];i++ ){
			Str[i] = Map[Str[i]];
		}
		printf("Case #%ld: %s\n",++k,Str );
	}
		
	
	//scanf("%*ld");
	
	return 0;
}
