#include <cstdio>
#include <cstring>

const int max_word = 521196;
const int max_slen = 10000;
const int index_diff = 5;
const int infinity = 1000000000;

char words[max_word][20];
int len[max_word];

int a[max_slen][10];
char s[max_slen];

void read_words()
{
  FILE* fp = fopen("garbled_email_dictionary.txt","r");
  for(int i=0; i<max_word; i++) {
    fscanf(fp,"%s",words[i]);
    len[i] = strlen(words[i]);
  }
}

void checkword(int i, int w, bool& match, 
               int& cdiff,
               int& firstdiff, 
               int& lastdiff)
{
  if(len[w] > i+1) {
    match = false;
    return;
  }

  lastdiff = 0;
  firstdiff = 0;
  cdiff = 0;
  for(int j=0; j<len[w]; j++)
    if(words[w][len[w]-j-1]!=s[i-j]) {
      cdiff++;
      if(cdiff==1) {
        firstdiff = j;
        lastdiff = j;
      } else if(j - lastdiff < 5) {
        match = false;
        return;
      } else
        lastdiff = j;
    }
  match = true;
  //printf("%s %d %d %d %d\n",words[w],i,cdiff,firstdiff,lastdiff);
}

void work(int tt)
{
  scanf("%s",s);
  int slen = strlen(s);

  for(int i=0; i<slen; i++)
    for(int j=0; j<10; j++)
      a[i][j] = infinity;

  for(int i=0; i<slen; i++) {
    for(int j=0; j<max_word; j++) {
      bool match;
      int cdiff, firstdiff, lastdiff;
      checkword(i,j,match,cdiff,firstdiff,lastdiff);
      if(match) {
        int slack;
        if(cdiff==0) {
          for(int k=0; k<=4; k++) {
            int kk = k+len[j];
            if(kk > 4)
              kk = 4;
            if(i == len[j]-1)
              a[i][kk] = 0;
            else {
              if(a[i][kk] > a[i-len[j]][k])
                a[i][kk] = a[i-len[j]][k];
            }
          }
        } else {
          slack = 4 - (len[j] - lastdiff - 1);
          if(slack < 0)
            slack = 0;

          int oldbest = infinity;
          if(i == len[j]-1)
            oldbest = 0;
          else {
            for(int k=slack; k<=4; k++)
              if(oldbest > a[i-len[j]][k])
                oldbest = a[i-len[j]][k];
          }

          if(firstdiff >4)
            firstdiff = 4;
          if(oldbest + cdiff < a[i][firstdiff])
            a[i][firstdiff] = oldbest + cdiff;
        }
      }
    }

    /*printf("%c [",s[i]);
    for(int k=0; k<=4; k++)
      printf("%d,",a[i][k]);
      printf("]\n");*/
  }
  int sol = infinity;
  for(int k=0; k<=4; k++)
    if(sol > a[slen-1][k])
      sol = a[slen-1][k];
  printf("Case #%d: %d\n",tt,sol);
}

main()
{
  read_words();
  int t;
  scanf("%d",&t);
  for(int tt=0; tt<t; tt++)
    work(tt+1);
}
