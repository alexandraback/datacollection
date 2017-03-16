#include <cstring>
#include <iostream>
#include <queue>
#include <string>


#define INF    1000000000
#define OFFSET 1000


int count[2048][2048];

std::string hist[2048][2048];


const int dy[] = {1, 0, -1,  0};
const int dx[] = {0, 1,  0, -1};

const char* dir = "NESW";


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int T;

  std::cin >> T;

  for (int t = 1; t <= T; t ++) {
    for (int i = 0; i < 2048; i ++)
      for (int j = 0; j < 2048; j ++) {
        count[i][j] = 0;
        hist[i][j].clear();
      }

    int X, Y;

    std::cin >> X >> Y;

    Y += OFFSET;
    X += OFFSET;

    count[OFFSET][OFFSET] = 1;

    std::queue<std::pair<int, int> > queue;

    queue.push(std::make_pair(OFFSET, OFFSET));

    while (! queue.empty()) {
      int y = queue.front().first, x = queue.front().second; queue.pop();
      
      if (y == Y && x == X)
        break;
      
      for (int i = 0; i < 4; i ++) {
        int ny = y + count[y][x] * dy[i];
        int nx = x + count[y][x] * dx[i];

        if (count[ny][nx] == 0) {
          count[ny][nx] = count[y][x] + 1;

          hist[ny][nx] = hist[y][x] + dir[i];

          queue.push(std::make_pair(ny, nx));
        }
      }
    }

    std::cout << "Case #" << t << ": " << hist[Y][X] << std::endl;
  }
}
