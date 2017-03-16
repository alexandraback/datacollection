#include <cstdio>
#include <cstring>
#include <algorithm>

int N, M, K;

bool cell[20][20];
int  border  = 0;
int  covered = 0;
int  ans;

int  search_count = 0;
const int MAX_SEARCH_COUNT = 500000000;

void print()
{
  printf("covered = %d, border = %d\n", covered, border);
  for ( int i=0; i<N; ++i ) {
    for ( int j=0; j<M; ++j ) {
      putchar(cell[i][j] ? '#' : '-');
    }
    putchar('\n');
  }
  putchar('\n');
}

int dj[3] = {0, -1, +1};

bool search(int i, int L, int R)
{
  if ( search_count > MAX_SEARCH_COUNT )
    return false;
  else
    ++search_count;

  if ( i==0 ) border += R-L+1;
  else        border += L==R ? 1 : 2;

  cell[i][L] = cell[i][R] = true;  covered += R-L+1;
  if ( covered >= K ) {
    border += L==R ? 0 : R-L-1;
    if ( border < ans ) {
      ans = border;
      //print();
    }
    border -= L==R ? 0 : R-L-1;
  }
  else if ( i < N-1 ) {
    for ( int dL=0; dL<3; ++dL ) {
      for ( int dR=0; dR<3; ++dR ) {
	int nL = L + dj[dL];
	int nR = R + dj[dR];
	if ( nL>=0 && nL<M && nR>=0 && nR<M && nL<=nR ) {
          if ( search(i+1, nL, nR) == false ) 
	    return false;
	}
      }
    }
  }
  cell[i][L] = cell[i][R] = false;  covered -= R-L+1;

  if ( i==0 ) border -= R-L+1;
  else        border -= L==R ? 1 : 2;

  return true;
}

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    printf("Case #%d: ", t);
    scanf("%d %d %d", &N, &M, &K);
    memset(cell, 0, sizeof(cell));

    ans     = K;
    border  = 0;
    covered = 0;
    search_count = 0;
    for ( int L=0; L<M; ++L ) {
      for ( int R=std::min(L+K-1,M-1); R>=L; --R ) {
	search(0, L, R);
      }
    }
    printf("%d\n", ans);
  }
}
