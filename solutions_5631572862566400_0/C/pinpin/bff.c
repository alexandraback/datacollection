#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv)
{
  int T, N, M;
  int i, j, k, x, y;
  int bff[2000];
  int len[20][20];
  int ml;
  int flg;

  scanf("%d", &T);
  for(i=1;i<=T;i++) {
    scanf("%d", &N);
    flg = 0;
    for(j=0;j<N;j++) {
      scanf("%d", &bff[j]);
      bff[j]--;
      flg |= (1 << bff[j]);
    }
    ml = 0;
    for(j=0;j<N;j++) {
      //      if (!(flg & (1 << j))) {
      //	continue;
      //      }
      x = bff[j];
      for(k=1;k<=11;k++) {
	if (x == j) {
	  break;
	}
	x = bff[x];
      }
      if ((k <= 10) && (ml < k)) {
	ml = k;
      }
    }
    
    for(j=0;j<20;j++) {
      for(k=0;k<20;k++) {
	len[j][k] = 100000;
      }
    }
    for(j=0;j<N;j++) {
      if (bff[bff[j]] != j) {
	len[j][bff[j]] = 1;
      }
    }

    for(y=0;y<N;y++) {
    for(j=0;j<N;j++) {
      for(k=0;k<N;k++) {
        for(x=0;x<N;x++) {
          if ((len[k][j]+len[j][x]) < len[k][x]) {
            len[k][x] = len[k][j]+len[j][x];
          }
        }
      }
    }
    }

    /*
    for(j=0;j<N;j++) {
      for(k=0;k<N;k++) {
	printf("%d ", len[j][k]);
      }
      printf("\n");
    }
    */

    for(j=0;j<N;j++) {
      if (bff[bff[j]] == j) {
	/*printf("j=%d\n", j);*/
	for(k=0;k<N;k++) {
	  if (len[k][j] > N)
	    continue;
	  if (ml < (len[k][j]+2)) {
	    ml = len[k][j]+2;
	  }
	  for(x=0;x<N;x++) {
	    if (x == k)
	      continue;
	    if (len[x][bff[j]] > N)
	      continue;
	    if (ml < (len[k][j]+len[x][bff[j]]+2)) {
	      ml = len[k][j]+len[x][bff[j]]+2;
	      /*printf("%d %d\n", k, x);*/
	    }
	  }
	}
      }
    }
    for(j=0;j<N;j++) {
      for(k=j+1;k<N;k++) {
	if (bff[bff[j]] == j && bff[bff[k]] == k && j != k && j != bff[k]) {
	  if (ml < 4) {
	    ml = 4;
	  }
	}
      }
    }

    printf("Case #%d: %d\n", i, ml);
  }
  return 0;
}

