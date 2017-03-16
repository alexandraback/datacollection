#include <cstdio>
#include <vector>

using namespace std;

// h i j k
// l m n o
char next(char a,char b) {
  switch(a) {
  case 'h': return b; // "hijklmno"
  case 'i': return "ilknmhoj"[b-'h'];
  case 'j': return "jolinkhm"[b-'h'];
  case 'k': return "kjmlonih"[b-'h'];
  case 'l': return "lmnohijk"[b-'h'];	   
  case 'm': return "mhojilkn"[b-'h'];
  case 'n': return "nkhmjoli"[b-'h'];
  case 'o': return "onihkjml"[b-'h'];
  }
}

int main() {
  int T;
  scanf("%d",&T);
  for (int n=1;n<=T;++n) {
    printf("Case #%d: ",n);
    int L,X;
    scanf("%d%d",&L,&X);
    char c;
    do { scanf("%c",&c); } while (c<'i' || c>'k');
    vector<char> s;
    s.push_back(c);
    for (int i=1;i<L;++i) {
      scanf("%c",&c);
      s.push_back(c);
    }
    c=s[0];
    char needle='i';
    for (int p=1;p<X*s.size();++p) {
      if (needle=='i' && c=='i') {
	needle='j';
	c=s[p%s.size()];
      } else if (needle=='j' && c=='j') {
	needle='k';
	c=s[p%s.size()];
      }
      else c=next(c,s[p%s.size()]);
    }
    if (needle=='k' && c=='k') printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
