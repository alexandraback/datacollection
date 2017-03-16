#include <cstdio>

int main() {
  int cases, size, tmp, moves, stars, next, maxone;
  bool possible, foundtwo, found;
  scanf("%d", &cases);
  for(int c=0; c<cases; c++) {
    scanf("%d", &size);
    int ones[size], twos[size], state[size];
    for(int i=0; i<size; i++) {
      state[i] = 0;
      scanf("%d%d", &ones[i], &twos[i]);
    }
    moves = 0;
    possible = true;
    stars = 0;

    while(possible && stars < size*2) {
      next = -1;
      maxone = -1;
      foundtwo = false;
      found = false;
      for(int i=0; i<size; i++) {
        if(state[i]<2 && twos[i]<=stars) {
          stars += (2-state[i]);
          state[i] = 2;
          found=true;
          foundtwo=true;
          //printf("move %d - found 2 star at %d\n", moves, i);
          break;
        }
        else if(state[i]<1 && ones[i]<=stars && maxone < twos[i]) {
          found=true;
          next=i;        
          maxone = twos[i];
        }
      }
      if(!found) possible = false;
      else if(next != -1 && !foundtwo) {
        stars++;
        state[next] = 1;
        //printf("move %d - found 1 star at %d\n", moves, next);
      }
      moves ++;
    }

    if(possible)
      printf("Case #%d: %d\n", c+1, moves);
    else
      printf("Case #%d: Too Bad\n", c+1);
  }
}
