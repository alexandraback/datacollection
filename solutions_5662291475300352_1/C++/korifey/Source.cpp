#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//int flip(int x)
//{
//  int res = 0;
//  while (x > 0)
//  {
//    res = res * 10 + (x % 10);
//    x /= 10;
//  }
//  return res;
//}

//int main() {
//  ifstream in("a-small.in");
//  ofstream out("a-small.out");
//
//
//  int ncases = 0;
//  in >> ncases;
//  auto arr = vector<int>(1000001);
//  for (int icase = 0; icase < ncases; icase++)
//  {
//    int l;
//    //long long n;
//    int n;
//    in >> n;
//    //auto arr = vector<int>(n+1);
//    arr[0] = 0;
//    arr[1] = 1;
//
//    for (int i = 2; i <= n; i++)
//    {
//      arr[i] = arr[i - 1]+1;
//      auto f = flip(i);
//      if (i % 10 != 0 && f < i && (arr[f] + 1) < arr[i]) arr[i] = arr[f] + 1;
//    }
//
//    out << "Case #" << (icase + 1) << ": " << arr[n] << endl;  
//  }
//
//  in.close();
//  out.close();
//  return 0;
//}

//auto arr = vector<int>(16);
//int best;
//int maxpos;
//int r, c;
//
//int idx(int x, int y)
//{
//  return c*x + y;
//}
//
//void check()
//{
//  int res = 0;
//  for (int i = 0; i < r; i++)
//  {
//    for (int j = 0; j < c; j++)
//    {
//      if (j>0 && arr[idx(i, j)] && arr[idx(i, j - 1)]) res++;
//      if (i >0 && arr[idx(i, j)] && arr[idx(i - 1, j)]) res++;
//    }
//  }
//  if (res < best) best = res;
//}
//
//void rec(int pos, int left)
//{
//  for (int i = pos; i <= maxpos-left; i++)
//  {
//    arr[i] = 1;
//    if (left == 1) check();
//    else
//    {
//      rec(i + 1, left-1);
//    }
//    arr[i] = 0;
//  }
//}
//
//int main() {
//  ifstream in("b-small.in");
//  ofstream out("b-small.out");
//
//  for (int i = 0; i < 16; i++) arr[i] = 0;
//
//  int ncases = 0;
//  in >> ncases;
//  for (int icase = 0; icase < ncases; icase++)
//  {
//    int n;
//    in >> r;
//    in >> c;
//    in >> n;
//    
//    best = 1000000;
//    maxpos = r*c;
//    if (n > 0) rec(0, n);
//    else best = 0;
//
//    out << "Case #" << (icase + 1) << ": " << best << endl;
//  }
//
//  in.close();
//  out.close();
//  return 0;
//}

int n = 0;
auto hpos = vector<long long>(10);
auto hspeed = vector<long long>(10);

int check(int test)
{
  long long low = 0, high = 1000000000000;

  for (int i = 0; i < n; i++)
  {
    if (!(test & (1 << i)))
    {
      long long l = (360 - hpos[i])*hspeed[i];
      if (l > low) low = l;
      long long h = (720 - hpos[i])*hspeed[i];
      if (h < high) high = h;

      if (low >= high) return 0;
    }
  }
  return 1;
}
int bitset(int test)
{
  int res = 0;
  while (test >0)
  {
    if (test & 1) res++;
    test /= 2;
  }
  return res;
}

int main() {
  ifstream in("c-small-2.in");
  ofstream out("c-small-2.out");



  int ncases = 0;
  in >> ncases;
  for (int icase = 0; icase < ncases; icase++)
  {
    int nn;
    in >> nn;
    hpos.clear();
    hspeed.clear();
    n = 0;
    for (int i = 0; i < nn; i++)
    {
      int d, h, m;
      in >> d;
      in >> h;
      in >> m;
      for (int j = 0; j < h; j++)
      {
        hpos.push_back(d);
        hspeed.push_back(m + j);
        n++;
      }
    }

    int best = 100;
    for (int test = 0; test < (1 << n); test++)
    {
      if (!check(test)) continue;
      int b = bitset(test);
      if (b < best) best = b;
    }
    


    out << "Case #" << (icase + 1) << ": " << best << endl;
  }

  in.close();
  out.close();
  return 0;
}