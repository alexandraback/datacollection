#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <tuple>
#include <functional>
#include <sstream>
#include <cassert>


using namespace std;
class Grid
{
public:
   Grid() {}
   Grid(int aR, int aC) : R(aR), C(aC) {
      squares.resize(R*C, '.');
   }
   Grid(const Grid& g) : squares(g.squares), R(g.R), C(g.C) {}
   void fill(char c) {
      squares.assign(R*C, c);
   }
   char& at(int x, int y) {
      return squares.at(x + y*C);
   }
   const char& at(int x, int y) const {
      return squares.at(x + y*C);
   }
   bool inBound(int nx, int ny) const
   {
      if (nx < 0 || ny < 0 || nx >= C || ny >= R) return false;
      return true;
   }
   int setAdj(int x, int y, char c)
   {
      int change = 0;
      for (int dx = 0; dx < 3 ; dx++)
      {
      	for (int dy = 0; dy < 3 ; dy++)
      	{
            int nx = x + dx - 1;
            int ny = y + dy - 1;
            if (!inBound(nx,ny)) continue;
            if (at(nx,ny) != c)
            {
               at(nx,ny) = c;
               ++change;
            }
      	}
      }
      return change;
   }
   bool findAdj(int x, int y, char c) const
   {
      for (int dx = 0; dx < 3; dx++)
      {
         for (int dy = 0; dy < 3; dy++)
         {
            if (dx == dy && dx == 1) continue;
            int nx = x + dx - 1;
            int ny = y + dy - 1;
            if (!inBound(nx, ny)) continue;
            if (at(nx,ny) == c)
            {
               return true;
            }
         }
      }
      return false;
   }
   std::string print(int sx, int sy)
   {
      std::stringstream ss;
      ss << '\n';
      for (int y = 0; y < R; y++)
      {
         for (int x = 0; x < C; x++)
         {
            if (sx == x && sy == y) {
               ss << 'c';
            }
            else
               ss << at(x, y);
         }
         if (y < R-1) ss << '\n';
      }
      return ss.str();
   }
   std::vector<char> squares;
   int R, C;
};

class TestCase
{
public:
   int mSx, mSy;
   Grid solved;
   int R, C, M;
   void findGoodMoves(const Grid& g, vector<pair<int, int> >& moves)
   {
      for (int x = 0; x < C ; x++)
      {
      	for (int y = 0; y < R ; y++)
      	{
            if (g.at(x, y) == '.') {
               if (g.findAdj(x, y, '*'))
               {
                  moves.push_back(make_pair(x, y));
               }
            }
      	}
      }
   }
   bool solveRemove(const Grid& g, int bombsToTake, int x, int y, int fx, int fy)
   {
      if (g.inBound(x,y))
      {
         Grid g2 = g;
         if (bombsToTake == R*C - M)
         {
            mSx = x;
            mSy = y;
         }
         bombsToTake -= g2.setAdj(x, y, '.');
         if (bombsToTake == 0) {
            solved = g2;
            return true;
         }
         
         if (bombsToTake < 0) return false;
         vector<pair<int, int> > moves;
         findGoodMoves(g2, moves);
         return solveRemove(g2, bombsToTake, moves, fx, fy);
      }
      else return false;
   }
   bool solveRemove(const Grid& g, int bombsToTake, vector<pair<int, int> > moves, int fx, int fy)
   {
      for (size_t i = 0; i < moves.size(); ++i)
      {
         int x = moves[i].first;
         int y = moves[i].second;
         if (fx == -1) {
            fx = x;
            fy = y;
         }
         if (solveRemove(g, bombsToTake, x, y, fx, fy)) return true;
      }
      return false;
   }
   string eval(istream& is)
   {
      is >> R >> C >> M;
      std::stringstream ss; {
         ss << "RCM: " << R << " " << C << " " << M << " \n";
      }
      Grid g(R, C);;
      g.fill('*');
      bool good = false;
      if (R*C - 1 == M)
      {
         solved = g;
         mSx = 0; mSy = 0;
         g.at(0, 0) = 'c';
         good = true;
      }
      else
      {
         vector<pair<int, int> > moves;
         moves.push_back(make_pair(C / 2, R / 2));
         moves.push_back(make_pair(0, 0));
         moves.push_back(make_pair(1, 0));
         moves.push_back(make_pair(2, 0));
         moves.push_back(make_pair(3, 0));
         moves.push_back(make_pair(0, 1));
         moves.push_back(make_pair(0, 2));
         moves.push_back(make_pair(0, 3));
         good = solveRemove(g, R*C - M, moves, -1, -1);
      }
      if (good)
      {
         return solved.print(mSx, mSy);
      }
      else
      {
         return "\nImpossible";
      }
   }
};

int main(int argc, char* argv[])
{
   ifstream infile(argv[1]);
   int T;
   infile >> T;
   ofstream out("C.out");
   //ostream& out = std::cout;
   for (int tc = 0; tc < T; ++tc)
   {
      TestCase testcase;
      out << "Case #" << tc + 1 << ": " << testcase.eval(infile) << '\n';
   }
   return 0;
}

