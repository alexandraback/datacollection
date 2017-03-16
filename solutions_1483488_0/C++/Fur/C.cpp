#include<cstdio>
#include<algorithm>

using namespace std;

#define range(i, a, b) for(int i(a); i < (b); i++)
#define rep(i, n) range(i, 0, n)

const int MAX_N = 10;

int a, b;
char sa[MAX_N];
char sb[MAX_N];
char sx[MAX_N];
int na, nb, nx;

inline int cmp(char s1[], int x, int n1, char s2[], int y, int n2){
  if(n1 != n2){
    return n1 - n2;
  }
  rep(i, n1){
    if(s1[x] == s2[y]){
      x = (x + 1) % n1;
      y = (y + 1) % n2;
    }
    else{
      return s1[x] - s2[y];
    }
  }
  return 0;
}

inline int atos(int x, char s[]){
  int n = 0;
  while(x > 0){
    s[n++] = x % 10 + '0';
    x /= 10;
  }
  reverse(s, s + n);
  return n;
}

int main(){
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int T;
  scanf("%d", &T);
  range(cs, 1, T + 1){
    int cnt = 0;
    scanf("%d %d", &a, &b);
    na = atos(a, sa);
    nb = atos(b, sb);
    range(x, a, b){
      nx = atos(x, sx);
      range(i, 1, nx){
	if(cmp(sx, 0, nx, sx, i, nx) < 0 and cmp(sx, i, nx, sb, 0, nb) <= 0){
	  bool seen = false;
	  range(j, 1, i){
	    if(cmp(sx, j, nx, sx, i, nx) == 0){
	      seen = true;
	      break;
	    }
	  }
	  if(not seen){
	    cnt++;
	  }
	}
      }
    }
    printf("Case #%d: %d\n", cs, cnt);
  }
}
