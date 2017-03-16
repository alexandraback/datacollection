#include <stdio.h>
#include <string.h>

char g2nmapping[26] = {'y','h','e','s','o','c','v',
                       'x','d','u','i','g','l','b',
                       'k','r','z','t','n','w',
                       'j','p','f','m','a','q'};

int main(int argc, char *argv[])
{
  int casecount,c;
  scanf("%d%c",&casecount,&c);
  char line[202];
  int i;
  for (i = 0; i < casecount; ++i){
    fgets(line,202,stdin);
    int index;
    for(index = 0 ; index < strlen(line); index++){
      if (line[index] == ' ')
        continue;
      if (line[index] == '\n'){
        line[index] = '\0';
        break;
      }
      line[index] = g2nmapping[line[index]- 'a'];
    }
    printf("Case #%d: %s\n",i+1,line);
  }
  return 0;
}


