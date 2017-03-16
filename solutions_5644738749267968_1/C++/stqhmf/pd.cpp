#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 1000;

int n; // number of items

struct Item
{
  int player;
  int index;
  double value;
} items[2*MAX_N];

bool operator< (const Item &a, const Item &b)
{
  return a.value < b.value;
}

int  block[2][MAX_N];
bool used [2][MAX_N];

void read()
{
  scanf("%d", &n);
  int k = 0;
  for ( int i=0; i<2; ++i ) {
    for ( int j=0; j<n; ++j ) {
      items[k].player = i;
      items[k].index  = j;
      scanf("%lf", &items[k].value);
      ++k;
    }
  }
  sort(items, items+2*n);
  int cnt[2] = {0,0};
  for ( int i=0; i<2*n; ++i ) {
    int player = items[i].player;
    int index  = items[i].index;
    block[player][index] = 2*(i+1);
  }

  //for ( int i=0; i<n; ++i ) printf("%2d ", block[0][i]); putchar('\n');
  //for ( int i=0; i<n; ++i ) printf("%2d ", block[1][i]); putchar('\n');
}

int playGame_1()
{
  int win_count = 0;
  memset(used, 0, sizeof(used));
  
  for ( int round=0; round<n; ++round ) {
    int a_max = 0;  
    int a_idx = -1;
    for ( int i=0; i<n; ++i ) {
      if ( !used[0][i] && block[0][i] > a_max ) {
	a_max = block[0][i];
	a_idx = i;
      }
    }

    int b_min = INT_MAX;
    int b_idx = -1;
    for ( int i=0; i<n; ++i ) {
      if ( !used[1][i] && block[1][i] > a_max && block[1][i] < b_min ) {
	b_min = block[1][i];
	b_idx = i;
      }
    }

    if ( b_min==INT_MAX ) {
      for ( int i=0; i<n; ++i ) {
	if ( !used[1][i] && block[1][i] < b_min ) {
	  b_min = block[1][i];
	  b_idx = i;
	}
      }
    }

    //printf("a_max=%d, b_min=%d\n", a_max, b_min);

    used[0][a_idx] = true;
    used[1][b_idx] = true;

    if ( a_max > b_min ) ++win_count;
  }

  return win_count;
}

int playGame_2()
{
  int win_count = 0;
  memset(used, 0, sizeof(used));
  
  for ( int round=0; round<n; ++round ) {
    int a_max = 0;  
    int a_idx = -1;
    for ( int i=0; i<n; ++i ) {
      if ( !used[0][i] && block[0][i] > a_max ) {
	a_max = block[0][i];
	a_idx = i;
      }
    }

    int b_max = 0;
    int b_idx = -1;
    for ( int i=0; i<n; ++i ) {
      if ( !used[1][i] && block[1][i] < a_max && block[1][i] > b_max ) {
	b_max = block[1][i];
	b_idx = i;
      }
    }
    if ( b_max==0 ) {
      for ( int i=0; i<n; ++i ) {
	if ( !used[1][i] && block[1][i] > b_max ) {
	  b_max = block[1][i];
	  b_idx = i;
	}
      }
      //printf("a_max=%d, b_max=%d\n", a_max, b_max);
      used[0][a_idx] = true;
      used[1][b_idx] = true;
    }
    else {
      //printf("a_max=%d, b_max=%d\n", a_max, b_max);
      used[0][a_idx] = true;
      used[1][b_idx] = true;
      ++win_count;
    }
  }

  return win_count;
}

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    read();
    printf("Case #%d: %d %d\n", t, playGame_2(), playGame_1());
  }
}
