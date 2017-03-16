#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

set <pair <int,int> > arb;
int T,A,B,ret;

inline void get_ok_cif (int val,int &ok,int &cif) {

 int last,cur;

 ok=0; cif=0;
 for (last=0; val; val/=10) {

  cur=val%10; ++cif;
  if (cur<last)
    ok=1;
  last=cur;
 }
}

inline int putere (int put) {
  int ret,i;

  ret=1;
  for (i=1; i<=put; ++i)
    ret=ret*10;

  return ret;
}

inline int transforma (int val,int put) {

  int cif;

  cif=val%10; val/=10;
  return putere (put)*cif+val;
}

int main () {

  freopen ("C.in","r",stdin);
  freopen ("C.out","w",stdout);

  int i,j,ok,cif,val,newval;

  scanf ("%d",&T);
  for (i=1; i<=T; ++i) {

    ret=0; arb.clear ();
    scanf ("%d%d",&A,&B);
    for (val=A; val<=B; ++val) {

      newval=val;
      get_ok_cif (newval,ok,cif);

      if (ok)
        for (j=1; j<cif; ++j) {

          newval=transforma (newval,cif-1);
          if (val<newval && newval>=A && newval<=B)
            if (arb.find (make_pair (val,newval))==arb.end ()) {

              ++ret;
              arb.insert (make_pair (val,newval));
        }
      }
    }
    printf ("Case #%d: %d\n",i,ret);
  }

  return 0;
}
