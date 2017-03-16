#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

const int maxl = 18;
char c[maxl+5];
char j[maxl+5];
char cc[maxl+5];
char jj[maxl+5];
long long diff;
int len;

bool check(long long cnum, long long jnum) {
  //printf("check %lld %lld diff is %lld\n", cnum, jnum, diff);
  long long diffnum = abs(cnum - jnum);
  if(diffnum < diff)
    return true;
  else if(diffnum == diff) {
    long long cold = atoll(cc);
    long long jold = atoll(jj);
    //printf("old: %lld %lld\n", cold, jold);
    if(cnum < cold)
      return true;
    else if(cnum == cold) {
      return jnum < jold;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

void dfs(int idx, int status) {
  //printf("dfs(%d, %d)\n", idx, status);
  if(idx == len) {
    long long cnum = atoll(c);
    long long jnum = atoll(j);
    if(check(cnum, jnum)) {
      // memcpy(cc, c, sizeof c);
      // memcpy(jj, j, sizeof j);
      diff = abs(cnum - jnum);
      //printf("%lld %lld is better\n", cnum, jnum);
      for(int i = len - 1; i >= 0; i--) {
      	if(cnum) {
      	  cc[i] = '0' + (cnum % 10);
      	  cnum /= 10;
      	} else {
      	  cc[i] = '0';
      	}
      }
      cc[len] = '\0';
      for(int i = len - 1; i >= 0; i--) {
      	if(jnum) {
      	  jj[i] = '0' + (jnum % 10);
      	  jnum /= 10;
      	} else {
      	  jj[i] = '0';
      	}
      }
      jj[len] = '\0';
    }
    return;
  }
  if(status == 0) {
    if(c[idx] == '?' && j[idx] == '?') {
      int ctmp = c[idx];
      int jtmp = j[idx];
      c[idx] = '0';
      j[idx] = '1';
      dfs(idx+1, -1);
      c[idx] = '0';
      j[idx] = '0';
      dfs(idx+1, 0);
      c[idx] = '1';
      j[idx] = '0';
      dfs(idx+1, 1);
      c[idx] = ctmp;
      j[idx] = jtmp;
      return;
    } else if(c[idx] == '?') {
      int ctmp = c[idx];
      c[idx] = j[idx];
      dfs(idx+1, 0);
      if(j[idx] < '9') {
	c[idx] = j[idx] + 1;
	dfs(idx+1, 1);
      }
      if(j[idx] > '0') {
	c[idx] = j[idx] - 1;
	dfs(idx+1, -1);
      }
      c[idx] = ctmp;
      return;
    } else if(j[idx] == '?') {
      int jtmp = j[idx];
      j[idx] = c[idx];
      dfs(idx+1, 0);
      if(c[idx] < '9') {
	j[idx] = c[idx] + 1;
	dfs(idx+1, -1);
      }
      if(c[idx] > '0') {
	j[idx] = c[idx] - 1;
	dfs(idx+1, 1);
      }
      j[idx] = jtmp;
      return;
    } else {
      dfs(idx+1, c[idx] - j[idx]);
      return;
    }
  } else if(status > 0) {
    int ctmp = c[idx];
    int jtmp = j[idx];
    if(c[idx] == '?') {
      c[idx] = '0';
    }
    if(j[idx] == '?') {
      j[idx] = '9';
    }
    dfs(idx+1, status);
    c[idx] = ctmp;
    j[idx] = jtmp;
    return;
  } else if(status < 0) {
    int ctmp = c[idx];
    int jtmp = j[idx];
    if(c[idx] == '?') {
      c[idx] = '9';
    }
    if(j[idx] == '?') {
      j[idx] = '0';
    }
    dfs(idx+1, status);
    c[idx] = ctmp;
    j[idx] = jtmp;
    return;
  }
}

bool merge() {
  for(int i = 0; i < len; i++) {
    if(c[i] != '?' && j[i] != '?' && c[i] != j[i]) {
      return false;
    }
  }

  for(int i = 0; i < len; i++) {
    if(c[i] == '?' && j[i] == '?') {
      cc[i] = jj[i] = '0';
    } else if(c[i] == '?') {
      cc[i] = jj[i] = j[i];
    } else if(j[i] == '?') {
      cc[i] = jj[i] = c[i];
    } else {
      cc[i] = jj[i] = c[i];
    }
  }
  cc[len] = '\0';
  jj[len] = '\0';
  return true;
}

int main() {
  int tc;
  scanf("%d\n", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%s %s\n", c, j);
    //printf("c is %s j is %s\n", c, j);
    len = strlen(c);
    if(!merge()) {
      diff = 2e18;
      dfs(0, 0);
    }
    printf("Case #%d: %s %s\n", kase, cc, jj);
  }
  return 0;
}
