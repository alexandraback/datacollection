#include <cstdio>
#include <cstdlib>
#include <cstring>

const int N = 32;
const int X = N/2, Y = 0;
int count[N][N], total, qtt;
char grid0[N][N];
const int M = 1<<18;
char grid_[M][N][N];

int nt0, nt;
int n;
int posx, posy;

// void debug(char grid[N][N]) {
//   printf("qtt = %d\n", qtt);
//   for(int i=2 ; i>=0 ; --i) {
//     for(int j=-5 ; j<=5 ; j+=2)
//       printf("%d ", count[i+Y][j+X]);
//     printf("\n");
//     putchar(' ');
//     for(int j=-4 ; j<=4 ; j+=2)
//       printf("%d ", count[i+Y][j+X]);
//     printf("\n");
//   }
// }

void run_count(char grid[N][N], bool yes) {
  if(yes) {
    for(int i=0 ; i<N ; i++)
      for(int j=0 ; j<N ; j++)
	count[i][j] += grid[i][j];
    ++qtt;
  }

  for(int i=0 ; i<N ; i++)
    for(int j=0 ; j<N ; j++)
      grid_[total%M][i][j] = grid[i][j];
  ++total;

  // debug(count);
  // printf("snap (%s)\n", yes?"yes":"no");
}

void slide(int y, int x, bool yes) {
  // grid0[y-1][x] has a diamond on it or is ground
  int k = ((x+1)%2+2)%2;

  // printf("> y=%d x=%d\n", y, x);

  if((y == 0 && k == 1) || (grid0[y-k+Y][x-1+X] && grid0[y-k+Y][x+1+X])) {
    // stops here
    grid0[y+Y][x+X] = 1;
    run_count(grid0, yes);
    grid0[y+Y][x+X] = 0;
  } else if(grid0[y-k+Y][x-1+X] && !grid0[y-k+Y][x+1+X]) {
    // slides to the right
    slide(y-k, x+1, yes);
  } else if(!grid0[y-k+Y][x-1+X] && grid0[y-k+Y][x+1+X]) {
    // slides to the left
    slide(y-k, x-1, yes);
  } else {
    // both
    slide(y-k, x+1, yes);
    slide(y-k, x-1, yes);
  }
}

void calc(int n) {
  memset(count, 0, sizeof(count));
  total = 0;
  qtt = 0;

  memset(grid0, 0, sizeof(grid0));
  grid0[Y][X] = 1;
  run_count(grid0, n==0);

  int a=0, b=total;
  while(n--) {
    // printf(" ( a=%d b=%d n=%d )\n", a, b, n);
    for(int k=a ; k<b ; ++k) {
      for(int i=0 ; i<N ; i++)
	for(int j=0 ; j<N ; j++)
	  grid0[i][j] = grid_[k%M][i][j];

      int i;
      for(i=0 ; i<N ; ++i)
  	if(!grid_[k%M][i+Y][X])
  	  break;

      slide(i, 0, n==0);
    }

    a = b;
    b = total;
  }
}

int main() {
  scanf(" %d", &nt0);

  for(nt=1 ; nt<=nt0 ; ++nt) {
    scanf(" %d %d %d", &n, &posx, &posy);

    calc(n-1);
    // debug(grid0);

    printf("Case #%d: ", nt);
    if (posx+X < 0 || posx+X >= N || posy/2+Y >= N) printf("0\n");
    else printf("%.6lf\n", double(count[posy/2+Y][posx+X]) / double(qtt));
  }

  return 0;
}
