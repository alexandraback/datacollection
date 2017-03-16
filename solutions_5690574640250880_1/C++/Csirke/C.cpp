#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long lglg;

int main()
{
  int T;
  scanf("%d", &T);

  for(int t = 0; t < T; ++t) {
    printf("Case #%d:\n", t+1);

    int R, C, M;

    scanf("%d%d%d", &R, &C, &M);

    int FreeM = R*C - M;

    if(R == 1) {
      printf("c");
      for(int i = 0; i < FreeM-1; ++i) {
        printf(".");
      }
      for(int i = 0; i < M; ++i) {
        printf("*");
      }
      printf("\n");
      continue;
    }

    if(C == 1) {
      printf("c\n");
      for(int i = 0; i < FreeM-1; ++i) {
        printf(".\n");
      }
      for(int i = 0; i < M; ++i) {
        printf("*\n");
      }
      continue;
    }

    if(FreeM == 1) {
      printf("c");

      for(int i = 0; i < C - 1; ++i) {
        printf("*");
      }
      printf("\n");

      for(int i = 0; i < R-1; ++i) {
        for(int j = 0; j < C; ++j) {
          printf("*");
        }
        printf("\n");
      }
      continue;
    }

    if(FreeM < 4 || FreeM == 5 || FreeM == 7) {
      printf("Impossible\n");
      continue;
    }

    if(FreeM == 6 && C == 2) {
      printf("c.\n..\n..\n");
      for(int i = 0; i < R-3; ++i) {
        printf("**\n");
      }
      continue;
    }

    if(FreeM == 4 || FreeM == 6) {
      printf("c");
      for(int i = 0; i < FreeM/2 - 1; ++i) {
        printf(".");
      }
      for(int i = 0; i < C - FreeM/2; ++i) {
        printf("*");
      }
      printf("\n");

      for(int i = 0; i < FreeM/2; ++i) {
        printf(".");
      }
      for(int i = 0; i < C - FreeM/2; ++i) {
        printf("*");
      }
      printf("\n");

      for(int i = 0; i < R-2; ++i) {
        for(int j = 0; j < C; ++j) {
          printf("*");
        }
        printf("\n");
      }
      continue;
    }

    // Only FreeM >= 8 left

    // 2 rows/columns

    if((R == 2 || C == 2) && (M % 2) == 1) {
      printf("Impossible\n");
      continue;
    }

    if(R == 2) {
      printf("c");
      for(int i = 0; i < FreeM/2 - 1; ++i) {
        printf(".");
      }
      for(int i = 0; i < C - FreeM/2; ++i) {
        printf("*");
      }
      printf("\n");

      for(int i = 0; i < FreeM/2; ++i) {
        printf(".");
      }
      for(int i = 0; i < C - FreeM/2; ++i) {
        printf("*");
      }
      printf("\n");

      continue;
    }

    if(C == 2) {
      printf("c.\n");
      for(int i = 0; i < FreeM/2 - 1; ++i) {
        printf("..\n");
      }
      for(int i = 0; i < R - FreeM/2; ++i) {
        printf("**\n");
      }

      continue;
    }

    // Free space can fill 3 rows/columns;
    if(FreeM >= 3*R) {
      int normal = FreeM / R;
      int remain = FreeM % R;

      if(remain == 1) {
        // First 2 rows +1 free, last row -1 free

        // First row;
        printf("c");
        for(int i = 0; i < normal; ++i) {
          printf(".");
        }
        for(int i = 0; i < C-normal-1; ++i) {
          printf("*");
        }
        printf("\n");

        // Second row;
        for(int i = 0; i < normal+1; ++i) {
          printf(".");
        }
        for(int i = 0; i < C-normal-1; ++i) {
          printf("*");
        }
        printf("\n");

        // "Normal" rows
        for(int i = 0; i < R-3; ++i) {
          for(int j = 0; j < normal; ++j) {
            printf(".");
          }
          for(int j = 0; j < C-normal; ++j) {
            printf("*");
          }
          printf("\n");
        }

        // Last row
        for(int j = 0; j < normal - 1; ++j) {
          printf(".");
        }
        for(int j = 0; j < C-normal + 1; ++j) {
          printf("*");
        }
        printf("\n");

        continue;
      }

      // First remain rows normal+1 free

      // First row;
      printf("c");
      if(remain == 0) {
        for(int i = 0; i < normal-1; ++i) {
          printf(".");
        }
        for(int i = 0; i < C-normal; ++i) {
          printf("*");
        }
      } else {
        for(int i = 0; i < normal; ++i) {
          printf(".");
        }
        for(int i = 0; i < C-normal-1; ++i) {
          printf("*");
        }
      }
      printf("\n");

      if(remain == 0) remain = 1;

      // "Normal" + 1 rows
      for(int i = 0; i < remain-1; ++i) {
        for(int j = 0; j < normal+1; ++j) {
          printf(".");
        }
        for(int j = 0; j < C-normal-1; ++j) {
          printf("*");
        }
        printf("\n");
      }

      // "Normal" rows
      for(int i = 0; i < R-remain; ++i) {
        for(int j = 0; j < normal; ++j) {
          printf(".");
        }
        for(int j = 0; j < C-normal; ++j) {
          printf("*");
        }
        printf("\n");
      }

      continue;
    }


    if(FreeM >= 3*C) {
      int normal = FreeM / C;
      int remain = FreeM % C;

      if(remain == 1) {
        // First "Normal" - 1 rows are free
        printf("c");
        for(int i = 0; i < C-1; ++i) {
          printf(".");
        }
        printf("\n");

        for(int i = 0; i < normal-2; ++i) {
          for(int j = 0; j < C; ++j) {
            printf(".");
          }
          printf("\n");
        }

        // A row with 1 mine
        for(int j = 0; j < C-1; ++j) {
          printf(".");
        }
        printf("*");
        printf("\n");

        // A row with 2
        printf("..");
        for(int j = 0; j < C-2; ++j) {
          printf("*");
        }
        printf("\n");

        // Remaining rows full
        for(int i = 0; i < R - normal - 1; ++i) {
          for(int j = 0; j < C; ++j) {
            printf("*");
          }
          printf("\n");
        }

        continue;
      }

      // First "Normal" rows free
      printf("c");
      for(int i = 0; i < C-1; ++i) {
        printf(".");
      }
      printf("\n");

      for(int i = 0; i < normal-1; ++i) {
        for(int j = 0; j < C; ++j) {
          printf(".");
        }
        printf("\n");
      }

      // handle remain == 0 separately
      if(remain == 0) {
        // Remaining rows full
        for(int i = 0; i < R - normal; ++i) {
          for(int j = 0; j < C; ++j) {
            printf("*");
          }
          printf("\n");
        }

        continue;
      }


      // A row with remain free spaces
      for(int j = 0; j < remain; ++j) {
        printf(".");
      }
      for(int j = 0; j < C-remain; ++j) {
        printf("*");
      }
      printf("\n");

      // Remaining rows full
      for(int i = 0; i < R - normal - 1; ++i) {
        for(int j = 0; j < C; ++j) {
          printf("*");
        }
        printf("\n");
      }

      continue;
    }

    // In the remaining cases, the upper left "square" will be free
    int size = 1;
    while(size*size <= FreeM) ++size;
    --size;

    int remain = FreeM - size*size;

    if(remain == 1) {
      // First 2 rows have size + 1 free

      // First row;
      printf("c");
      for(int i = 0; i < size; ++i) {
        printf(".");
      }
      for(int i = 0; i < C-size-1; ++i) {
        printf("*");
      }
      printf("\n");

      // Second row;
      for(int i = 0; i < size+1; ++i) {
        printf(".");
      }
      for(int i = 0; i < C-size-1; ++i) {
        printf("*");
      }
      printf("\n");

      // Then size-3 rows with size free
      for(int i = 0; i < size-3; ++i) {
        for(int j = 0; j < size; ++j) {
          printf(".");
        }
        for(int j = 0; j < C-size; ++j) {
          printf("*");
        }
        printf("\n");
      }

      // Then a row with size-1 free
      for(int i = 0; i < size-1; ++i) {
        printf(".");
      }
      for(int i = 0; i < C-size+1; ++i) {
        printf("*");
      }
      printf("\n");

      // Then remaining full
      for(int i = 0; i < R - size; ++i) {
        for(int j = 0; j < C; ++j) {
          printf("*");
        }
        printf("\n");
      }

      continue;
    }

    if(remain <= size) { //includes remain == 0
      // First remain rows with size+1

      // First row
      printf("c");
      for(int i = 0; i < size-1; ++i) {
        printf(".");
      }
      if(remain == 0) {
        printf("*");
      } else {
        printf(".");
      }
      for(int i = 0; i < C-size-1; ++i) {
        printf("*");
      }
      printf("\n");

      if(remain == 0) remain = 1;

      for(int i = 0; i < remain-1; ++i) {
        for(int j = 0; j < size+1; ++j) {
          printf(".");
        }
        for(int j = 0; j < C-size-1; ++j) {
          printf("*");
        }
        printf("\n");
      }

      // Next size-remain rows with size
      for(int i = 0; i < size-remain; ++i) {
        for(int j = 0; j < size; ++j) {
          printf(".");
        }
        for(int j = 0; j < C-size; ++j) {
          printf("*");
        }
        printf("\n");
      }

      // Then remaining full
      for(int i = 0; i < R - size; ++i) {
        for(int j = 0; j < C; ++j) {
          printf("*");
        }
        printf("\n");
      }

      continue;
    }

    if(remain == size + 1) {
      // First size-1 rows with size+1

      // First row
      printf("c");
      for(int i = 0; i < size; ++i) {
        printf(".");
      }
      for(int i = 0; i < C-size-1; ++i) {
        printf("*");
      }
      printf("\n");

      for(int i = 0; i < size-2; ++i) {
        for(int j = 0; j < size+1; ++j) {
          printf(".");
        }
        for(int j = 0; j < C-size-1; ++j) {
          printf("*");
        }
        printf("\n");
      }

      // One row with size
      for(int i = 0; i < size; ++i) {
        printf(".");
      }
      for(int i = 0; i < C-size; ++i) {
        printf("*");
      }
      printf("\n");

      // One with 2
      printf("..");
      for(int i = 0; i < C-2; ++i) {
        printf("*");
      }
      printf("\n");

      // Then remaining full
      for(int i = 0; i < R - size - 1; ++i) {
        for(int j = 0; j < C; ++j) {
          printf("*");
        }
        printf("\n");
      }

      continue;
    }

    // remain > size + 1

    // First size rows with size+1

    // First row
    printf("c");
    for(int i = 0; i < size; ++i) {
      printf(".");
    }
    for(int i = 0; i < C-size-1; ++i) {
      printf("*");
    }
    printf("\n");

    for(int i = 0; i < size-1; ++i) {
      for(int j = 0; j < size+1; ++j) {
        printf(".");
      }
      for(int j = 0; j < C-size-1; ++j) {
        printf("*");
      }
      printf("\n");
    }

    // One row with remain-size
    for(int i = 0; i < remain-size; ++i) {
      printf(".");
    }
    for(int i = 0; i < C-remain+size; ++i) {
      printf("*");
    }
    printf("\n");

    // Then remaining full
    for(int i = 0; i < R - size - 1; ++i) {
      for(int j = 0; j < C; ++j) {
        printf("*");
      }
      printf("\n");
    }

  }

  return 0;
}
