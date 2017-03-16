#include <stdio.h>

int r, c, m;
int rr, cc;
int map[51][51];
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};

void dfs(int x, int y) {
  if (map[x][y] != -1)
    return;
  int sum = 0;
  for (int k = 0; k < 8; ++k) {
    int xx = x + dx[k];
    int yy = y + dy[k];
    if (xx > 0 && xx <= rr && yy > 0 && yy <= cc)
      if (map[xx][yy] == -2)
        ++sum;
  }
  map[x][y] = sum;
  if (sum > 0)
  	return;
  for (int k = 0; k < 8; ++k) {
    int xx = x + dx[k];
    int yy = y + dy[k];
    if (xx > 0 && xx <= rr && yy > 0 && yy <= cc)
      dfs(xx, yy);
  }
}

bool test(int x, int y) {
  dfs(x, y);
  bool finished = true;
  for (int i = 1; i <= r; ++i)
    for (int j = 1; j <= c; ++j)
      if (map[i][j] == -1)
        finished = false;
  if (!finished)
    for (int i = 1; i <= r; ++i)
      for (int j = 1; j <= c; ++j)
        if (map[i][j] != -2)
          map[i][j] = -1;
  return finished;
}

int main(int argc, char* argv[]) {
  freopen("C-small-attempt0.in", "r", stdin);
  freopen("output.txt", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int o = 1; o <= T; ++o) {
    printf("Case #%d:\n", o);

    scanf("%d%d%d", &r, &c, &m);
    //printf("%d %d %d\n", r, c, m);
    for (int i = 1; i <= r; ++i)
      for (int j = 1; j <= c; ++j)
        map[i][j] = -1;
    rr = r, cc = c;
    while (m > 0 && r != c) {
      if (r > c) {
        if (m < c)
          break;
        for (int i = 1; i <= c && m > 0; ++i)
          map[r][i] = -2, --m;
        --r;
      } else {
        if (m < r)
          break;
        for (int i = 1; i <= r && m > 0; ++i)
          map[i][c] = -2, --m;
        --c;
      }
    }
    while (m > 0) {
      if (r == c) {
        if (m < r)
          break;
        for (int i = 1; i <= r; ++i)
          map[i][c] = -2, --m;
        --c;
      } else {
        if (m < c)
          break;
        for (int i = 1; i <= c; ++i)
          map[r][i] = -2, --m;
        --r;
      }
    }
    if (m > 0) {
      if (r < 3 || c < 3) {
        printf("Impossible\n");
        continue;
      } else if (r - m >= 2) {
        for (int i = r; i >= 1 && m > 0; --i)
          map[i][c] = -2, --m;
      } else if (c - m >= 2) {
        for (int i = c; i >= 1 && m > 0; --i)
          map[r][i] = -2, --m;
      } else {
        if (r > c) {
	        for (int i = r; i >= 1 && m > 0; --i)
  	        map[i][c] = -2, --m;
  	      map[2][c] = -1;
          map[r][c-1] = -2;
        } else {
	        for (int i = c; i >= 1 && m > 0; --i)
  	        map[r][i] = -2, --m;
          map[r][2] = -1;
          map[r-1][c] = -2;
        }
      }
    }
    bool finished = false;
    for (int i = 1; i <= r; ++i)
      for (int j = 1; j <= c; ++j)
        if (test(i, j)) {
          finished =true;
          break;
        }

    int num = 0;
    for (int i = 1; i <= r; ++i)
      for (int j = 1; j <= c; ++j)
        if (map[i][j] == 0)
        	++num;
    if (finished) {
      bool start = false;
      for (int i = 1; i <= rr; ++i) {
        for (int j = 1; j <= cc; ++j)
          if (map[i][j] == -2)
            printf("*");
          else if ((map[i][j] == 0 && !start) || (map[i][j] != 0 && num == 0))
            printf("c"), start = true;
          else
            printf(".");
        printf("\n");
      }
    } else {
      printf("Impossible\n");
    }
  }
  return 0;
}
