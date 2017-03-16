#include <bits/stdc++.h>

using namespace std;

int X, W, H;

void Input() {
  cin >> X >> W >> H;
}

struct Shape {
  Shape(const vector<string>& vs_) : vs(vs_) {
    for (const string& s: vs) {
      assert(s.size() == vs[0].size());
    }
  }

  int Count() {
    int count = 0;
    for (const string& s : vs) {
      for (char c : s) {
        if (c == '#') count++;
      }
    }
    return count;
  }

  int Width() const {
    return vs[0].size();
  }

  int Height() const {
    return vs.size();
  }

  vector<string> vs;
};

vector<Shape> GenerateShapes(int L) {
  if (L == 1) {
    return {
      Shape({ "#" })
          };
  } else if (L == 2) {
    return {
      Shape({ "##" })
          };
  } else if (L == 3) {
    return {
      Shape({ "###" }),
      Shape({ "##",
              "# " }),
            };
  } else if (L == 4) {
    return {
      Shape({ "####" }),
      Shape({ "###",
              "#  " }),
      Shape({ "###",
              " # " }),
      Shape({ " ##",
              "## " }),
      Shape({ "##",
              "##" }),
    };
  } else if (L == 5) {
    return {
      Shape({ " ##",
              "## ",
              " # " }),
      Shape({ "#####" }),
      Shape({ "####",
              "#   " }),
      Shape({ "### ",
              "  ##" }),
      Shape({ "###",
              " ##" }),
      Shape({ "###",
              " # ",
              " # " }),
      Shape({ "# #",
              "###" }),
      Shape({ "#  ",
              "#  ",
              "###" }),
      Shape({ "#  ",
              "## ",
              " ##" }),
      Shape({ " # ",
              "###",
              " # " }),
      Shape({ " #",
              "##",
              " #",
              " #" }),
      Shape({ "## ",
              " # ",
              " ##" }),
    };
  } else if (L == 6) {
    return {
      Shape({ "####",
              " ## " }),
      Shape({ "#####",
              "#    " }),
      Shape({ "#####",
              " #   " }),
      Shape({ "#####",
              "  #  " }),
      Shape({ "#### ",
              "   ##" }),
      Shape({ "####",
              "  ##" }),
      Shape({ "####",
              " # #" }),
      Shape({ "####",
              "#  #" }),
      Shape({ "###",
              "#  ",
              "#  ",
              "#  "  }),
      Shape({ "#  ",
              "###",
              "#  ",
              "#  "  }),
      Shape({ "###  ",
              "  ###" }),
      Shape({ "### ",
              " ###" }),
      Shape({ "### ",
              "# ##" }),
      Shape({ "### ",
              "  ##",
              "   #" }),
      Shape({ "### ",
              "  ##",
              "  # " }),
      Shape({ "###",
              "###" }),
      Shape({ "###",
              "## ",
              "#  " }),
      Shape({ "## ",
              "###",
              "#  " }),
      Shape({ "###",
              "#  ",
              "## " }),
      Shape({ "  #",
              "###",
              "#  ",
              "#  "}),
      Shape({ " ##",
              " # ",
              "## ",
              "#  "}),
      Shape({ " # ",
              " ##",
              "## ",
              "#  "}),
      Shape({ " # ",
              " # ",
              "###",
              "#  "}),
      Shape({ " ##",
              "## ",
              "## " }),
      Shape({ " # ",
              "###",
              "## " }),
      Shape({ "  #",
              " ##",
              "## ",
              "#  "}),
      Shape({ " # ",
              "###",
              "# #" }),
      Shape({ " #  ",
              "####",
              "#   " }),
      Shape({ "###",
              " # ",
              "## " }),
      Shape({ " ##",
              " # ",
              " # ",
              "## "}),
      Shape({ " # ",
              " ##",
              " # ",
              "## "}),
      Shape({ " # ",
              " ##",
              "## ",
              " # "}),
      Shape({ " # ",
              " # ",
              "###",
              " # "}),
      Shape({ "###",
              " # ",
              " # ",
              " # "}),
      Shape({ "######", })
    };
  }
  assert(0);
}

const int dx[4] = { 1, 0, -1, 0, };
const int dy[4] = { 0, 1, 0, -1, };

int dfs(vector<string>& A, int x, int y, char color) {
  int res = 1;
  A[y][x] = color;
  for (int d = 0; d < 4; d++) {
    int ny = y + dy[d];
    int nx = x + dx[d];
    if (ny < 0 || ny >= A.size() || nx < 0 || nx >= A[0].size()) continue;
    //    cerr << A << " " << nx << " " << ny << " " << color << endl;
    assert(A[ny][nx] == '.' || A[ny][nx] == '#' || A[ny][nx] == ' ' || A[ny][nx] == color);
    if (A[ny][nx] == '.' || A[ny][nx] == ' ') {
      res += dfs(A, nx, ny, color);
    }
  }
  return res;
}

bool CanOccupy(const Shape& shape, int sx, int sy, int w, int h) {
  vector<string> A(h, string(w, '.'));
  assert(A.size() >= sy + shape.Height());
  assert(A[0].size() >= sx + shape.Width());
  for (int dy = 0; dy < shape.Height(); dy++) {
    for (int dx = 0; dx < shape.Width(); dx++) {
      A[sy + dy][sx + dx] = shape.vs[dy][dx];
    }
  }

  char color = 'a';
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      if (A[y][x] != '.') continue;
      int count = dfs(A, x, y, color);
      if (count % X != 0) return false;
      color++;
    }
  }
  return true;
}

bool CanOccupy(const Shape& s) {
  /*
  if ((s.Width() > W || s.Height() > H) &&
      (s.Width() > H || s.Height() > W)) {
    return false;
  }
  */

  for (int y = 0; y + s.Height() - 1 < H; y++) {
    for (int x = 0; x + s.Width() - 1 < W; x++) {
      if (CanOccupy(s, x, y, W, H)) {
        return true;
      }
    }
  }

  // rotate
  for (int y = 0; y + s.Height() - 1 < W; y++) {
    for (int x = 0; x + s.Width() - 1 < H; x++) {
      if (CanOccupy(s, x, y, H, W)) {
        return true;
      }
    }
  }

  return false;
}

bool CanGenerateImpossibleFilling() {
  // impossible to occupy
  if (X >= 7) return true;
  if ((W * H) % X != 0) {
    return true;
  }

  for (Shape& s : GenerateShapes(X)) {
    if (!CanOccupy(s)) return true;
  }

  return false;
}

void Solve() {
  if (CanGenerateImpossibleFilling()) {
    printf("RICHARD");
  } else {
    printf("GABRIEL");
  }
}

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  //  string inputFile  = "./data/D-practice.in";
  //  string outputFile = "./data/D-practice.out";
  string inputFile  = "./data/D-small-attempt0.in";
    string outputFile = "./data/D-small-attempt0.out";
  //  string inputFile  = "./data/D-large.in";
  //  string outputFile = "./data/D-large.out";

  freopen(inputFile.c_str(), "r", stdin);
  freopen(outputFile.c_str(), "w", stdout);

  fprintf(stderr, "Read from input: %s\n", inputFile.c_str());
  fprintf(stderr, "Write to output: %s\n", outputFile.c_str());

  int T;
  string line;
  {
    getline(cin, line);
    istringstream is(line);
    is >> T;
  }

  for (int test_case = 1; test_case <= T; ++test_case) {
    Input();
    printf("Case #%d: ", test_case);
    Solve();
    printf("\n");
  }

  return 0;
}
