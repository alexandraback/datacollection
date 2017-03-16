#include <stdio.h>
#include <string>

using namespace std;

#if 0
int gShortest = 500;

string find(int startx, int starty, int endx, int endy, string path)
{
  int size = path.size();

  if (size >= gShortest) {
    return path;
  }

  if (startx == endx && starty == endy) {
    printf(" shortest \n");
    gShortest = path.size();
    return path;
  }


  string sp = find(startx+size+1, starty, endx, endy, path+'E');

  string w = find(startx-size-1, starty, endx, endy, path+'W');
  if (w.size() < sp.size()) {
    sp = w;
  }

  string s = find(startx, starty-size-1, endx, endy, path+'S');
  if (s.size() < sp.size()) {
    sp = s;
  }

  string n = find(startx, starty+size+1, endx, endy, path+'N');
  if (n.size() < sp.size()) {
    sp = n;
  }

  return sp;
}
#endif

string simplePath(int startx, int starty, int endx, int endy)
{
  string path;

  if (startx != endx) {
    while (startx > endx) {
      startx--;
      path += "EW";
    }
    while (startx < endx) {
      startx++;
      path += "WE";
    }
  }

  if (starty != endy) {
    while (starty > endy) {
      starty--;
      path += "NS";
    }
    while (starty < endy) {
      starty++;
      path += "SN";
    }
  }

  return path;
}

int main()
{
  int T;
  scanf("%d\n", &T);

  for (int t=1; t<=T; ++t) {
    int x,y;
    scanf("%d %d\n", &x, &y);

    string path = simplePath(0, 0, x, y);

    printf("Case #%d: %s\n", t, path.c_str());
  }

  return 0;
}
