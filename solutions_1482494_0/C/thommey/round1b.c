#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

#define MAXSTARS 2002

struct level {
  int ai; // minimum star requirements for 1 star
  int halfdone; // 1-star rating done but not two star?
  struct level *next;
} *levels[MAXSTARS] = {NULL};

// add a level to the levels array, index of it is bi, linked list internally
void addlevel(int ai, int bi) {
  struct level *L;

  L = malloc(sizeof(*L));
  L->ai = ai;
  L->halfdone = 0;
  L->next = levels[bi];
  levels[bi] = L;
}

int onecase(N) {
  int ai, bi, levelsplayed = 0, stars = 0;
  struct level *temp;

  for (bi = 0; bi < MAXSTARS; bi++) {
    if (!(temp = levels[bi]))
      continue;
// play 2-star ratings directly if possible
    if (stars >= bi) {
      fprintf(stderr, "I have %d stars, finishing levels\n", stars);
      while (temp) {
        fprintf(stderr, "I have %d stars, playing level with (%d %d) to get %d stars.\n", stars, temp->ai, bi, 2 - temp->halfdone);
        levelsplayed++;
        stars += 2 - temp->halfdone;
        temp = temp->next;
      }
    } else {
// play a 1-star rating of the level with the highest 2-star rating that I can afford
// (to give a maximum chance of big steps now)
      fprintf(stderr, "I have %d stars, trying to move forward (MAX..%d).\n", stars, bi);
      for (ai = MAXSTARS - 1; stars < bi && ai >= bi; ai--) {
        for (temp = levels[ai]; temp; temp = temp->next) {
          if (!temp->halfdone && stars >= temp->ai) {
            fprintf(stderr, "I have %d stars, played 1-star level with (%d %d).\n", stars, temp->ai, bi);
            temp->halfdone = 1;
            stars++;
            levelsplayed++;
            ai = MAXSTARS - 1;
            if (stars >= bi)
              break;
          }
        }
      }
// dead end
      if (stars < bi)
        return -1;
      bi--; // try again
    }
  }
  return levelsplayed;
}

int main(int argc, char **argv) {
  int t, testcases, N, ai, bi, i, oc;
  FILE *fd;
  char buf[102400];

  fd = fopen("in.txt", "r");
  assert(fd != NULL);
  fgets(buf, sizeof(buf), fd);
  testcases = atoi(buf);
  assert(testcases != 0);
  fprintf(stderr, "Total test cases: %d\n", testcases);
  for (t = 1; t <= testcases; t++) {
    for (i = 0; i < MAXSTARS; i++)
      levels[i] = NULL;
    fprintf(stderr, "Case (%d/%d)\n", t, testcases);
    assert(fgets(buf, sizeof(buf), fd) != NULL);
    sscanf(buf, "%d", &N);
    for (i = 1; i <= N; i++) {
      assert(fgets(buf, sizeof(buf), fd) != NULL);
      assert(sscanf(buf, "%d %d", &ai, &bi) == 2);
      addlevel(ai, bi);
    }
    oc = onecase(N);
    if (oc == -1)
      printf("Case #%d: Too Bad\n", t);
    else
      printf("Case #%d: %d\n", t, oc);
  }
  fclose(fd);
  return 0;
}
