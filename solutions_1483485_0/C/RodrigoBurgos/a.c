# include <stdio.h>
# include <string.h>

char first[1000] ="ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
char second[1000]="our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
int hash[1000];
char line[1000];

main(){
  int x, ncases, cases;
  for( x = 0; x < 1000; x++) hash[x] = x;
  hash['q'] = 'z';
  hash['z'] = 'q';
  hash['q'] = 'z';
  hash['z'] = 'q';
  for(x  = 0; x < strlen( first ) ; x++){
     hash[ first[ x ]] = second[ x ];	
  }
  for( gets( line ), sscanf(line, "%d", &ncases) , cases = 1; cases <= ncases ; cases++ ){
  	printf("Case #%d: ", cases );
  	gets( line );
  	for( x = 0; x < strlen( line ); x++){
  	  printf("%c", hash[ line[ x ] ]);	
  	}
  	printf("\n");
  }
  return 0;	
}