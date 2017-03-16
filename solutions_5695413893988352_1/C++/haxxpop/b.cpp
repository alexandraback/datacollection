#include <stdio.h>
#include <string.h>
typedef long long ll;

char a[1000],b[1000];
char ta[1000],tb[1000];
char aa[1000],ab[1000];
ll av;
int n;
int update(char *ta, char *tb){
  ll va = 0, vb = 0;
  for(int i = 0; i < n ; i++ ){
    va *= 10;
    va += ta[i]-'0';

    vb *= 10;
    vb += tb[i]-'0';
  }
  ll d = va-vb;
  if( d < 0 ) d = -d;
  if( d < av ){
    av = d;
    strcpy(aa,ta);
    strcpy(ab,tb);
  }else if( d == av ){
    if( strcmp( ta, aa ) < 0 ){
      av = d;
      strcpy(aa,ta);
      strcpy(ab,tb);
    }else if( strcmp( ta, aa ) == 0 && strcmp( tb, ab ) < 0 ){
      av = d;
      strcpy(aa,ta);
      strcpy(ab,tb);
    }
  }
}
int swap(char *ta,char *tb){
  for(int i = 0 ; i < n ; i++ ){
    char k = ta[i];
    ta[i] = tb[i];
    tb[i] = k;
  }
}
int main(){
  int t;
  scanf("%d",&t);
  for(int e = 0 ; e < t ; e++ ){
    scanf("%s %s",a,b);
    n = strlen(a);
    av = (1LL<<62);
    // TODO: check equal

    strcpy(ta,a);
    strcpy(tb,b);
    for(int gg = 0 ; gg < 2 ; gg++ ){
      for(int k = 0 ; k < n ; k++ ){
        for(int x = 0 ; x < 10 ; x++ ){
          for(int y = x ; y < 10 ; y ++ ){
            int chk = 1;
            for(int i = 0 ; i < k ; i++ ){
              if( a[i] == '?' && b[i] == '?'){ ta[i] = '0'; tb[i] = '0'; }
              else if( a[i] == '?' && b[i] != '?'){ ta[i] = b[i]; tb[i] = b[i]; }
              else if( a[i] != '?' && b[i] == '?'){ ta[i] = a[i]; tb[i] = a[i]; }
              else if( a[i] != b[i] ){
                chk = 0;
                break;
              }
            }
            if( a[k] != '?' && a[k] != x+'0' ){ chk = 0; continue; }
            if( b[k] != '?' && b[k] != y+'0' ){ chk = 0; continue; }
            if( chk == 0 ) continue;
            ta[k] = x+'0';
            tb[k] = y+'0';

            for(int i = k+1; i < n ; i++ ){
              if( a[i] != '?' ) ta[i] = a[i];
              else ta[i] = '9';

              if( b[i] != '?' ) tb[i] = b[i];
              else tb[i] = '0';
            }
            if( gg == 0 ) update(ta,tb);
            else update(tb,ta);
          }
        }
      }

      swap(a,b);
      strcpy(ta,a);
      strcpy(tb,b);
    }
    printf("Case #%d: %s %s\n",e+1,aa,ab);
  }
}


