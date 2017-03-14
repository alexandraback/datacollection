#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <list>

using namespace std;

list<pair<int, int> > reflectLeft(const int axis, list < pair <int, int> >& plist,  set <pair<int, int> >& xset)
{
  list <pair <int, int> >::iterator it    = plist.begin();
  list <pair <int, int> >::iterator itEnd = plist.end();

  list <pair <int, int> > flist;

  for(; it != itEnd;++it)
  {
    // ignore checked point
    set<pair<int, int> >::iterator setit = xset.find(*it);
    if(xset.end() != setit) {
      continue;
    }
    int x = (*it).first;
    int y = (*it).second;
    if(x <= axis) 
    {
      continue;
    }
    int rx = axis - abs(x - axis);
    //printf("(%d, %d) -> (%d, %d)\n", x, y, rx, y);
    pair <int, int> p;
    p.first  = rx;
    p.second = y;
    flist.push_back(p);
  }
  return flist;
}

list<pair<int, int> > reflectRight(const int axis, list < pair <int, int> >& plist,  set <pair<int, int> >& xset)
{
  list <pair <int, int> >::iterator it    = plist.begin();
  list <pair <int, int> >::iterator itEnd = plist.end();

  list <pair <int, int> > flist;

  for(; it != itEnd;++it)
  {
    // ignore checked point
    set<pair<int, int> >::iterator setit = xset.find(*it);
    if(xset.end() != setit) {
      continue;
    }
    int x = (*it).first;
    int y = (*it).second;
    if(x >= axis) 
    {
      continue;
    }
    int rx = axis + abs(x - axis);
    //printf("(%d, %d) -> (%d, %d)\n", x, y, rx, y);
    pair <int, int> p;
    p.first  = rx;
    p.second = y;
    flist.push_back(p);
  }
  return flist;
}

list<pair<int, int> > reflectDown(const int axis, list < pair <int, int> >& plist,  set <pair<int, int> >& xset)
{
  list <pair <int, int> >::iterator it    = plist.begin();
  list <pair <int, int> >::iterator itEnd = plist.end();

  list <pair <int, int> > flist;

  for(; it != itEnd;++it)
  {
    // ignore checked point
    set<pair<int, int> >::iterator setit = xset.find(*it);
    if(xset.end() != setit) {
      continue;
    }
    int x = (*it).first;
    int y = (*it).second;
    if(y <= axis) 
    {
      continue;
    }
    int ry = axis - abs(y - axis);
    //printf("(%d, %d) -> (%d, %d)\n", x, y, x, ry);
    pair <int, int> p;
    p.first  = x;
    p.second = ry;
    flist.push_back(p);
  }
  return flist;
}

list<pair<int, int> > reflectUp(const int axis, list < pair <int, int> >& plist,  set <pair<int, int> >& xset)
{
  list <pair <int, int> >::iterator it    = plist.begin();
  list <pair <int, int> >::iterator itEnd = plist.end();

  list <pair <int, int> > flist;

  for(; it != itEnd;++it)
  {
    // ignore checked point
    set<pair<int, int> >::iterator setit = xset.find(*it);
    if(xset.end() != setit) {
      continue;
    }
    int x = (*it).first;
    int y = (*it).second;
    if(y >= axis) 
    {
      continue;
    }
    int ry = axis + abs(y - axis);
    //printf("(%d, %d) -> (%d, %d)\n", x, y, x, ry);
    pair <int, int> p;
    p.first  = x;
    p.second = ry;
    flist.push_back(p);
  }
  return flist;
}

int checkplist(list <pair<int, int> >& flist ,list <pair<int, int> >& plist, set<pair<int, int> >& s, const int D)
{
  int d = D * 2;
  int nb = 0;
  list <pair <int, int> >::iterator it    = flist.begin();
  list <pair <int, int> >::iterator itEnd = flist.end();
  for(;it != itEnd;++ it)
  {
    set<pair<int, int> >::iterator setit = s.find(*it);
    if(s.end() != setit) {
      continue;
    }
    int x = (*it).first;
    int y = (*it).second;
    //printf("(%d, %d)\n", x, y);
    plist.push_back(*it);
    s.insert(*it);
    if(sqrt(x*x + y*y) <= d)
    {
      ++ nb;
    }
  }
  return nb;
}

int reflect(const int up, const int down, const int left, const int right, list < pair <int, int> >& plist, set <pair<int, int> >& xset, const int D)
{
  list <pair<int, int> > llist = reflectLeft(left,   plist, xset);
  list <pair<int, int> > rlist = reflectRight(right, plist, xset);
  list <pair<int, int> > dlist = reflectDown(down,   plist, xset);
  list <pair<int, int> > ulist = reflectUp(up,       plist, xset);
  list <pair <int, int> >::iterator it    = plist.begin();
  list <pair <int, int> >::iterator itEnd = plist.end();
  for(;it != itEnd;++ it)
  {
    xset.insert(*it);
  }
  set <pair<int, int> > s;
  int nb = 0;
  nb += checkplist(llist, plist, s, D);
  nb += checkplist(rlist, plist, s, D);
  nb += checkplist(dlist, plist, s, D);
  nb += checkplist(ulist, plist, s, D);
  return nb;
}

void mulReflect(const int up, const int down, const int left, const int right, list <pair <int, int> >& plist, const int D)
{
  set <pair<int, int> > xset;
  int nb = 0;
  do
  {
    nb = reflect(up, down, left, right, plist, xset, D);
  } while(nb != 0);
}

void checkPhase(set <float>& pSet, const float& fd, const int x, const int y, int& nb)
{
  float fx = static_cast<float>(x);
  float fy = static_cast<float>(y);
  float r = fy/fx;
  set<float>::iterator setit = pSet.find(r);
  if(pSet.end() == setit) {
    float f = sqrt(x * x + y * y);
    if(fd >= f) {
      pSet.insert(r);
      ++ nb;
      //printf("add (%d, %d)\n", x, y);
    }
  }
}

int result(list <pair <int, int> >& plist, const int D)
{
  set <pair<int, int> > pset;
  set <float> phase1Set;
  set <float> phase2Set;
  set <float> phase3Set;
  set <float> phase4Set;
  bool positiveX = false;
  bool negativeX = false;
  bool positiveY = false;
  bool negativeY = false;
  int d = D * 2;
  float fd = static_cast<float>(d);
  int nb = 0;

  list <pair <int, int> >::iterator it    = plist.begin();
  list <pair <int, int> >::iterator itEnd = plist.end();
  for(;it != itEnd;++ it)
  {
    pair <int, int > p = *it;
    int x = p.first;
    int y = p.second;
    if((0 == x) && (0 == y)) {
      continue;
    }
    set<pair<int, int> >::iterator setit = pset.find(p);
    if(pset.end() != setit) {
      continue;
    }
    pset.insert(p);
    if((0 == y) && (0 < x)) {
      if(false == positiveX) {
        if(d >= x) {
          positiveX = true;
          ++nb;
          //printf("add (%d, %d)\n", x, y);
        }
      }
    } else if((0 == y) && (0 > x)) {
      if(false == negativeX) {
        if(d >= abs(x)) {
          negativeX = true;
          ++nb;
          //printf("add (%d, %d)\n", x, y);
        }
      }
    } else if((0 == x) && (0 < y)) {
      if(false == positiveY) {
        if(d >= y) {
          positiveY = true;
          ++nb;
          //printf("add (%d, %d)\n", x, y);
        }
      }
    } else if((0 == x) && (0 > y)) {
      if(false == negativeY) {
        if(d >= abs(y)) {
          negativeY = true;
          ++nb;
          //printf("add (%d, %d)\n", x, y);
        }
      }
    } else if((0 < x) && (0 < y)) {
      // phase 1
      checkPhase(phase1Set, fd, x, y, nb);
    } else if((0 > x) && (0 < y)) {
      // phase 2
      checkPhase(phase2Set, fd, x, y, nb);
    } else if((0 > x) && (0 > y)) {
      // phase 3
      checkPhase(phase3Set, fd, x, y, nb);
    } else if((0 < x) && (0 > y)) {
      // phase 4
      checkPhase(phase4Set, fd, x, y, nb);
    }
  }
  return nb;
}

int main ()
{
  int T;
  scanf("%d", &T);
  //printf("%d\n", T);
  for(int tc = 1; tc <= T; ++ tc)
  {
    int H;
    int W;
    int D;
    scanf("%d %d %d\n", &H, &W, &D);
    //printf("%d %d %d\n", H, W, D);
    int x = 0;
    int y = 0;
    for(int h = H - 1; h > -1; --h) 
    {
      for(int w = W - 1; w >= -1; --w) 
      {
        char c;
        scanf("%c", &c);
        //printf("%c", c);
        if('\n' == c) {
        } else if('X' == c) {
          x = w;
          y = h;
        } else if('.' == c) {
        } else if('#' == c) {
        }
      }
    }
    //printf("X: %d %d\n", x, y);
    int up    = H - 1;
    int down  = 0;
    int left  = 0;
    int right = W - 1;
    up    -= y;
    down  -= y;
    left  -= x;
    right -= x;
    //printf("u: %d d: %d l: %d r: %d\n", up, down, left, right);
    pair <int, int> p;
    p.first  = 0;
    p.second = 0;
    list <pair <int, int> > plist;
    plist.push_back(p);
    mulReflect(up, down, left,  right, plist, D);
    int res = result(plist, D);
    printf("Case #%d: %d\n", tc, res);

  }
}
