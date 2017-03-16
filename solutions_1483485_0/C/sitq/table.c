#include <stdio.h>

char table_1[26];
char table_2[26];

    const char googlese[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi"
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
"de kr kd eoya kw aej tysr re ujdr lkgc jv";

    const char english[] = "our language is impossible to understand"
"there are twenty six factorial possibilities"
"so it is okay if you want to just give up";


char g_to_e[26]= { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q' };

void prepare_table ( void )
{
    int rec;

    for ( rec = 0; rec<26; rec++ ) table_1 [rec] = table_2[rec] = 0;
    int pos = 0;
    const char* g_ptr = googlese;
    const char* e_ptr = english;

    table_1['y'-'a'] = 'a';
    table_2['a'-'a'] = 'y';
    table_1['e'-'a'] = 'o';
    table_2['o'-'a'] = 'e';
    table_1['q'-'a'] = 'z';
    table_2['z'-'a'] = 'q';

    while ( *e_ptr ) 
    {
	char g_c = (*g_ptr) - 'a';
        char e_c = (*e_ptr) - 'a';

	if ( *g_ptr != ' ' )
	{

	if ( table_1[g_c] != 0 && table_1[g_c] != *e_ptr || g_c < 0 || g_c > 25 ) 
	{
		printf ("WHOPS 1 at %d\n",pos); exit ( -1 );
	}
        if ( table_2[e_c] != 0 && table_2[e_c] != *g_ptr || e_c < 0 || e_c > 25 )
        {
                printf ("WHOPS 2 at %d\n",pos); exit ( -1 );
        }
        table_1[g_c] = *e_ptr;
        table_2[e_c] = *g_ptr;
	}
        e_ptr++; g_ptr++;
	pos++;
    }

    for ( rec = 0; rec<26; rec++ )
    {
      printf ("%c, - %c\n", rec+'a', table_2[rec] );
    }

	printf ("-------------------------\n");
     for ( rec = 0; rec<26; rec++ )
    {
      printf ("'%c', ", table_1[rec] );
    }


}


int main ( void )
{
	int cases,cas;
	char line[256];
	scanf("%d\n", &cases );		
        for ( cas = 0; cas < cases; cas++ )
	{
		char *l_ptr = line;
		gets ( line );
		
		printf ("Case #%d: ", cas+1 );
                while ( *l_ptr ) 
			{ 
				if ( *l_ptr == ' ' ) printf (" ");
				else printf ("%c", g_to_e[(*l_ptr)-'a'] ); l_ptr++; 
			}
		printf ("\n");
	}
}        
 
