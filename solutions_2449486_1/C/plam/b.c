#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXROW (100)
#define MAXCOL (100)
typedef struct board_s {
  int b[MAXROW][MAXCOL];
} board_t;

int ROWVALIDL[MAXROW];
int COLVALIDL[MAXCOL];
int ROWVALIDR[MAXROW];
int COLVALIDR[MAXCOL];
int ROWMAX[MAXROW];
int COLMAX[MAXCOL];

char buf[32*1024];
int mr,mc;

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))

void verify_board_brute(board_t * board) {
  int r,c,max;
  // calc row max
  for( r=0; r < mr; r++) {
    max = 0;
    for( c=0;c < mc;c++) {
      max = MAX(board->b[r][c], max);
    }
    ROWMAX[r] = max;
  }
  // calc row max
  for( c=0;c < mc;c++) {
    max = 0;
    for( r=0; r < mr; r++) {
      max = MAX(board->b[r][c], max);
    }
    COLMAX[c] = max;
  }
  // calc valid
  for(r=0;r < mr; r++) {
    if ( board->b[r][0] >= ROWMAX[r])  {
      ROWVALIDL[r] = 1;
    } else {
      ROWVALIDL[r] = 0;
    }
    if ( board->b[r][mc-1] >= ROWMAX[r])  {
      ROWVALIDR[r] = 1;
    } else {
      ROWVALIDR[r] = 0;
    }
  }
  for(c=0;c < mc; c++) {
    if ( board->b[0][c] >= COLMAX[c]) {
      COLVALIDL[c] = 1;
    } else {
      COLVALIDL[c] = 0;
    }
    if ( board->b[mr-1][c] >= COLMAX[c]) {
      COLVALIDR[c] = 1;
    } else {
      COLVALIDR[c] = 0;
    }
  }

  // check all squares
  for(r=0;r<mr;r++) {
    for(c=0;c<mc;c++) {
      if((board->b[r][c] >= ROWMAX[r]) ||
	 (board->b[r][c] >= COLMAX[c]) ) {
	continue;
      }
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
}

void verify_board_brute2(board_t * board) {
  int r,c,max;
  // calc row max
  for( r=0; r < mr; r++) {
    max = 0;
    for( c=0;c < mc;c++) {
      max = MAX(board->b[r][c], max);
    }
    ROWMAX[r] = max;
  }
  // calc row max
  for( c=0;c < mc;c++) {
    max = 0;
    for( r=0; r < mr; r++) {
      max = MAX(board->b[r][c], max);
    }
    COLMAX[c] = max;
  }
  // calc valid
  for(r=0;r < mr; r++) {
    if ( board->b[r][0] >= ROWMAX[r])  {
      ROWVALIDL[r] = 1;
    } else {
      ROWVALIDL[r] = 0;
    }
    if ( board->b[r][mc-1] >= ROWMAX[r])  {
      ROWVALIDR[r] = 1;
    } else {
      ROWVALIDR[r] = 0;
    }
  }
  for(c=0;c < mc; c++) {
    if ( board->b[0][c] >= COLMAX[c]) {
      COLVALIDL[c] = 1;
    } else {
      COLVALIDL[c] = 0;
    }
    if ( board->b[mr-1][c] >= COLMAX[c]) {
      COLVALIDR[c] = 1;
    } else {
      COLVALIDR[c] = 0;
    }
  }

  // check all squares
  for(r=0;r<mr;r++) {
    for(c=0;c<mc;c++) {
      if(board->b[r][c] == 100) {
	continue;
      }
      if((board->b[r][c] == board->b[r][0]) &&
	 ROWVALIDL[r]) {
	continue;
      }
      if((board->b[r][c] == board->b[r][mc-1]) &&
	 ROWVALIDR[r]) {
	continue;
      }
      if((board->b[r][c] == board->b[0][c]) &&
	 COLVALIDL[c]) {
	continue;
      }
      if((board->b[r][c] == board->b[mr-1][c]) &&
	 COLVALIDR[c]) {
	continue;
      }
      printf("NO\n");
      return;

    }
  }
  printf("YES\n");
}

#if 0
void verify_board(board_t * board) {
  int r,c,max;
  // calc row max
  for( r=0; r < mr; r++) {
    max = 0;
    for( c=0;c < mc;c++) {
      max = MAX(board->b[r][c], max);
    }
    ROWMAX[r] = max;
  }
  // calc row max
  for( c=0;c < mc;c++) {
    max = 0;
    for( r=0; r < mr; r++) {
      max = MAX(board->b[r][c], max);
    }
    COLMAX[c] = max;
  }
  // calc valid
  for(r=0;r < mr; r++) {
    if ( (board->b[r][0] == board->b[r][mc-1]) &&
	 (board->b[r][0] >= ROWMAX[r]) ) {
      ROWVALID[r] = 1;
    } else {
      ROWVALID[r] = 0;
    }
  }
  for(c=0;c < mc; c++) {
    if ( (board->b[0][c] == board->b[mr-1][c]) &&
	 (board->b[0][c] >= COLMAX[c]) ) {
      COLVALID[c] = 1;
    } else {
      COLVALID[c] = 0;
    }
  }

  // check all squares
  for(r=0;r<mr;r++) {
    for(c=0;c<mc;c++) {
      if(board->b[r][c] == 100) {
	continue;
      }
      if((board->b[r][c] == board->b[r][0]) &&
	 ROWVALID[r]) {
	continue;
      }
      if((board->b[r][c] == board->b[0][c]) &&
	 COLVALID[c]) {
	continue;
      }
      printf("NO\n");
      return;

    }
  }
  printf("YES\n");
}
#endif
void dump_board(board_t *board) {
  int r,c;
  for(r=0;r< mr; r++){
    for (c=0;c<mc; c++) {
      printf("%3d ",board->b[r][c]);
    }
    printf("\n");
  }
}

void main(int argc, char **argv) {
  FILE *fd = fopen(argv[1], "r");
  
  assert(fd);
  
  fgets((char*)buf, 1024, fd);
  int NUMCASE;
  sscanf(buf, "%d", &NUMCASE);
  
  int curcase;
  board_t board;
  char *str, *saveptr, *tok;
  for( curcase = 1; curcase <= NUMCASE; curcase++ ) {
    printf( "Case #%d: ", curcase );
    fgets((char*)buf, 1024, fd);
    sscanf(buf, "%d %d", &mr, &mc);
    int r, c;
    for( r = 0; r < mr; r++ ) {
      fgets((char*)buf, sizeof(buf), fd);
      str = buf;
      for( c = 0; c < mc; c++ ) {
	tok = strtok_r( str, " ", &saveptr );
	str = NULL;
	int h;
	h = atoi(tok);
	board.b[r][c] = h;
      }
    }
    verify_board_brute(&board);
    //    dump_board(&board);
  }
}
