#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

#define SIGMA 30
#define MAX 105

char trans[SIGMA];

string aux1="ejp mysljylc kd kxveddknmc re jsicpdrysi";
string aux2="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
string aux3="de kr kd eoya kw aej tysr re ujdr lkgc jvqey";

string rez1="our language is impossible to understand";
string rez2="there are twenty six factorial possibilities";
string rez3="so it is okay if you want to just give upzoa";

char sir[MAX];
int f[SIGMA];
int T,N;

int main () {
  freopen ("A.in","r",stdin);
  freopen ("A.out","w",stdout);

  int i,j;

  for (i=0; i<(int)aux1.size (); ++i)
    if (aux1[i]>='a' && aux1[i]<='z')
      trans[aux1[i]-'a']=rez1[i];
  for (i=0; i<(int)aux2.size (); ++i)
    if (aux2[i]>='a' && aux2[i]<='z')
      trans[aux2[i]-'a']=rez2[i];
  for (i=0; i<(int)aux3.size (); ++i)
    if (aux3[i]>='a' && aux3[i]<='z')
      trans[aux3[i]-'a']=rez3[i];

  for (i=0; i<26; ++i)
    if (trans[i]>='a' && trans[i]<='z')
      ++f[trans[i]-'a'];
  for (i=0; i<26; ++i)
    if (!f[i])
      trans['z'-'a']=i+'a';

  scanf ("%d\n",&T);

  for (i=1; i<=T; ++i) {

  memset (sir,'\0',sizeof (sir));
  fgets (sir,MAX,stdin);
  N=strlen (sir);

  printf ("Case #%d: ",i);
  for (j=0; j<N; ++j)
    if (sir[j]>='a' && sir[j]<='z')
      printf ("%c",trans[sir[j]-'a']);
    else
      printf ("%c",sir[j]);
  }

  return 0;
}
