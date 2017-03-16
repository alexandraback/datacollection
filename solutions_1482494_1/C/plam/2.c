#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef long long LONG_T;

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))

typedef struct game_s {
  int onestar;
  int twostar;
} game_t;

#define MAXGAME (1000)
#define MAXVAL (999999)
game_t GAME[MAXGAME];
int cur_game;
int LOW[MAXGAME];
int HIGH[MAXGAME];


char buf[100000];
#ifdef LOCAL
#define INPUT   fgets(buf,sizeof(buf),FD)
#define USEFILEIO
#else
#define INPUT gets(buf)
#endif


int
cmpgamelo(const void *a, const void *b) {
  int inda = *((int*)a);
  int indb = *((int*)b);
  if (GAME[inda].onestar-GAME[indb].onestar) {
    return (GAME[inda].onestar-GAME[indb].onestar);
  } else {
    return (GAME[indb].twostar-GAME[inda].twostar);
  }
}

int
cmpgamehi(const void *a, const void *b) {
  int inda = *((int*)a);
  int indb = *((int*)b);
  return (GAME[inda].twostar-GAME[indb].twostar);
}

int
brute2(int N) {
  int i;
  for (i=0;i<N;i++) {
    LOW[i] = i;
    HIGH[i] = i;
  }
  long curstar = 0;
  int curlevel = 0;
  int needstar = 2*N;
  qsort(LOW,N,sizeof(LOW[0]),cmpgamelo);
  qsort(HIGH,N,sizeof(HIGH[0]),cmpgamehi);
  while (curstar < needstar) {
    // try min high
    long curfound = 0;
    for (i=0;i<N;i++) {
      if ((curstar >= GAME[HIGH[i]].twostar) && (GAME[HIGH[i]].twostar < MAXVAL)) {
        if (GAME[HIGH[i]].onestar == MAXVAL) {
          curstar++;
        } else {
          curstar+=2;
        }
        curfound++;
        curlevel++;
        assert(GAME[HIGH[i]].twostar < MAXVAL);
        GAME[HIGH[i]].twostar = MAXVAL;
        GAME[HIGH[i]].onestar = MAXVAL;
      } else {
        break;
      }
    }
    if (curfound == 0) {
      for (i=0;i<N;i++) {
        if (curstar >= GAME[LOW[i]].onestar && (GAME[LOW[i]].onestar< MAXVAL)) {
          curstar++;
          curfound++;
          curlevel++;
          assert(GAME[LOW[i]].twostar < MAXVAL);
          GAME[LOW[i]].onestar = MAXVAL;
          break;
        } else {
          break;
        }        
      }
    }
    if (curfound == 0) {
      return 0;
    }
    qsort(LOW,N,sizeof(LOW[0]),cmpgamelo);
    qsort(HIGH,N,sizeof(HIGH[0]),cmpgamehi);
//    N-=curfound;
  }
  return (curlevel);  
}

int
brute(int N) {
  int i;
  for (i=0;i<N;i++) {
    LOW[i] = i;
    HIGH[i] = i;
  }
  long curstar = 0;
  int curlevel = 0;
  int needstar = 2*N;
  qsort(LOW,N,sizeof(LOW[0]),cmpgamelo);
  qsort(HIGH,N,sizeof(HIGH[0]),cmpgamehi);
  while (curstar < needstar) {
    // try min high
    long curfound = 0;
    for (i=0;i<N;i++) {
      if ((curstar >= GAME[HIGH[i]].twostar) && (GAME[HIGH[i]].twostar < MAXVAL)) {
        if (GAME[HIGH[i]].onestar == MAXVAL) {
          curstar++;
        } else {
          curstar+=2;
        }
        curfound++;
        curlevel++;
        assert(GAME[HIGH[i]].twostar < MAXVAL);
        GAME[HIGH[i]].twostar = MAXVAL;
        GAME[HIGH[i]].onestar = MAXVAL;
      } else {
        break;
      }
    }
    if (curfound == 0) {
      for (i=N-1;i>=0;i--) {
        if (GAME[HIGH[i]].onestar == MAXVAL) {
          continue;
        }
        if (curstar >= GAME[HIGH[i]].onestar && (GAME[HIGH[i]].onestar< MAXVAL)) {
          curstar++;
          curfound++;
          curlevel++;
          assert(GAME[HIGH[i]].twostar < MAXVAL);
          GAME[HIGH[i]].onestar = MAXVAL;
          break;
        }        
      }
    }
    if (curfound == 0) {
      return 0;
    }
//    qsort(LOW,N,sizeof(LOW[0]),cmpgamelo);
    qsort(HIGH,N,sizeof(HIGH[0]),cmpgamehi);
    //    N-=curfound;
  }
  return (curlevel);  
}

int main (int argc, char *argv[]) {
  FILE *FD;
  char *saveptr;
  char *tok;
  int i;
  int T; 
  
//  gen_translate();
////  translate(OUT);
//  return;
  
  
#ifdef USEFILEIO
  FD = fopen(argv[1], "r");
  
  if (!FD) {
    printf("error cannot open %s\n",argv[1]);
    return -1;
  }
#endif

  
//  fgets(buf,sizeof(buf),FD);
  INPUT;
  int num_case;
  T = atoi(buf);
  for (num_case = 1;num_case <= T;num_case++) {
    int N;
    
    INPUT;
    tok = strtok_r(buf," ", &saveptr);
    N = atoi(tok);
    
    int i;
    cur_game=0;
    for (i=0;i<N;i++) {
      INPUT;
      int onestar,twostar;
      tok = strtok_r(buf," ", &saveptr);
      onestar = atoi(tok);
      tok = strtok_r(NULL," ",&saveptr);
      twostar = atoi(tok);
      GAME[cur_game].onestar = onestar;
      GAME[cur_game].twostar = twostar;
      cur_game++;
    }
//    
//    N = 1000;
//    for (i=0;i<N;i++) {
//      GAME[i].onestar = rand() % 2001;
//      GAME[i].twostar = rand() % 2001;
//      
//    }
    printf("Case #%d: ",num_case);
    int val = brute(N);
    if (val == 0) {
      printf("Too Bad\n");
    } else {
      printf("%d\n",val);
    }
  }
  return 0;
}
