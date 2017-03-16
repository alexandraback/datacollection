#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

char res[] = {0,1,2,3,1,4,3,6,2,7,4,1,3,2,5,4};
char mult(char a, char b) {
  a-='h';
  b-='h';
  char n = (a^b)&4;
  a&=~4;
  b&=~4;
  return 'h'+res[a*4+b]^n;
}
/*
h  i  j  k  l  m  n  o
1  i  j  k -1 -i -j -k
*/

int main() {
  int T;

  cin >> T;

  vector<int> p(1000);
  for (int t=1;t<=T;t++) {
    int L, X;
    cin >> L >> X;

    string str;
    cin >> str;

    char total = 'h';
    for (int i=0;i<L;i++) {
      total = mult(total,str[i]);
    }

    int earliesti = -1; //find earliest i possible
    char current = 'h';
    for (int i=0;i<L;i++) {
      current = mult(current,str[i]);

      char jumped = current;
      for (int j=0;j<4;j++) {
        if (jumped == 'i' && (earliesti==-1 || earliesti>i+1+L*j)) {
          earliesti = i+1+L*j;
        }
        jumped = mult(total,jumped);
      }
    }

    int latestk = -1; //find earliest i possible
    current = 'h';
    for (int i=L-1;i>=0;i--) {
      current = mult(str[i],current);

      char jumped = current;
      for (int j=0;j<4;j++) {
        if (jumped == 'k' && (latestk==-1 || latestk>(L-i)+L*j)) {
          latestk = (L-i)+L*j;
        }
        jumped = mult(jumped,total);
      }
    }

    if (earliesti != -1 && latestk != -1 && earliesti+latestk < L*X) {
      // check if middle portion is a j!
      //printf("Case #%d: i=[0,%d), j=?, k=[L*X-%d,L*X)\n",t,earliesti,latestk);
      //printf("Case #%d: YES (maybe)\n",t);

      int kstart = (L*X-latestk);
      int current = 'h';
      if (earliesti/L == kstart/L) {
        for (int i=earliesti%L;i<kstart%L;i++) current = mult(current,str[i]);
      }
      else {
        for (int i=earliesti%L;i<L;i++) current = mult(current,str[i]);
        int totals = (kstart/L - earliesti/L-1)%4;
        for (int i=0;i<totals;i++) current = mult(current,total);
        for (int i=0;i<kstart%L;i++) current = mult(current,str[i]);
      }
      //printf("Case #%d: mid=%c\n",t,current);
      printf("Case #%d: %s\n",t,current=='j'?"YES":"NO");
    }
    else printf("Case #%d: NO\n",t);
    //printf("Case #%d: %c\n",t,total);
  }

}


