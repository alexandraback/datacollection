#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <cmath>

using namespace std;

typedef vector< vector<char> > matrix_t;

matrix_t make_matrix(int R, int C)
{
  matrix_t m;
  m.resize(C);
  for (auto& row : m)
    row.resize(R, '*');
  return m;
}

void print_matrix_transpose(matrix_t& m)
{
  int rows = m.size();
  int cols = m[0].size();
  
  //cout << rows << " " << cols << endl;
  
  for (int y=0; y < cols; y++)
  {
    for (int x=0; x < rows; x++)
    {
      cout << m[x][y];
 
    }
    cout << endl;
  }
}

void print_matrix(matrix_t& m, bool transpose)
{
  if (transpose)
  {
    print_matrix_transpose(m);
    return;
  }
  
  int rows = m.size();
  int cols = m[0].size();
  
  for (int y=0; y < rows; y++)
  {
    for (int x=0; x < cols; x++)
    {
      cout << m[y][x];
 
    }
    cout << endl;
  }
}

bool is_out( int R, int C, int x, int y)
{
  return (x < 0 || y < 0 || x >= R || y >= C);
}

bool is_mine(matrix_t& m, int R, int C, int x, int y)
{ 
  return m[y][x] == '*';
}

void count_visible_free_impl(matrix_t& m, int R, int C, int x, int y, int& nvfree, set<int>& mem)
{
  int id = y*R + x;
  
  if (mem.count(id) || is_mine(m, R, C, x, y))
    return;
  
  nvfree++;
  mem.insert(id);
  
  for (int action=0; action <=1; action++)
  for (int ymove = -1; ymove <= 1; ymove++)
    for (int xmove = -1; xmove <=1; xmove++)
    {
      if (xmove ==0 and ymove==0)
	continue;
      
      if (is_out(R,C, x+xmove, y+ymove))
	continue;
      
      if (action)
	count_visible_free_impl(m, R, C, x+xmove, y+ymove, nvfree, mem);
      else if (is_mine(m, R, C, x+xmove, y+ymove))
	return;
      
    }
  
}

int count_visible_free(matrix_t& m, int R, int C, int x, int y)
{
  int nvfree = 0;
  set<int> mem;
  count_visible_free_impl(m, R, C, x, y, nvfree, mem);
  return nvfree;
}

bool solve1( matrix_t& m, int R, int C, int M, int free)
{
  m[0][0] = 'c';
  for (int i=1; i < free; i++)
    m[i][0] = '.';
  
  return true;
}

bool solve2( matrix_t& m, int R, int C, int M, int free)
{
  if (free == 1)
  {
     m[0][0] = 'c';
     return true;
  }
  
  if (free == 2)
    return false;
  
  m[0][0] = 'c';
  for (int i=1; i < free / 2; i++)
    m[i][0] = '.';
  for (int i=0; i < free / 2; i++)
    m[i][1] = '.';
  if (free % 2)
    m[free/2][0] = '.';
  
  return free % 2 == 0;
  
}

int isqrt(int n)
{
  int r = sqrt(n);
  
  if ((r+1)*(r+1) == n)
    return r+1; 
  return r;
}

bool solve_gen( matrix_t& m, int R, int C, int M, int free)
{
  if (free == 1)
  {
     m[0][0] = 'c';
     return true;
  }
  
  if ( free <=3 || free == 7 || free == 5)
    return false;
  
  if (free == 4)
  {
    m[0][0] = 'c';
    m[0][1] = '.';
    m[1][0] = '.';
    m[1][1] = '.';
    return true;
  }
  
  int cols = free / C;
  if (free % C)
    cols++;
  cols = max(cols, 3);
  int rows = free / cols;
  //cout << "# " << rows << " " << cols << endl;
  if ( cols > R || rows > C)
  {
    cout << "bad/////";
    exit(0);
  }
  
 

  for (int rowNo=0; rowNo<rows; rowNo++)
    for (int colNo=0; colNo<cols; colNo++)
      m[rowNo][colNo] = '.';
  m[0][0] = 'c'; 
  
   int extra = free % cols;
   
  if (rows >= C && extra !=0 )
  {
    cout << "bad2";
    exit(0);
  }
  
 
  for (int i=0; i < extra; i++)
    m[rows][i] = '.';
  
  
    
  if (extra == 1)
  {
    m[rows][extra] = '.';
    m[rows-1][cols-1] = '*';
  }
  
  return true;
}

void solve(int R, int C, int M, bool transpose=false)
{
 
  matrix_t m = make_matrix(R, C);
  int free = R*C - M;
   //cout << R << " " << C << " " << M << " ::" << free <<  endl;
 
  bool solved;
  
  if (R == 1)
  {
    solved = solve1(m, R, C, M, free);
  }
  else if (R == 2)
  {
     solved = solve2(m, R, C, M, free);
  }
  else
    solved = solve_gen(m, R, C, M, free);
  
  
  int visible =  count_visible_free(m, R, C, 0, 0);
  
  if (solved)
    print_matrix(m, transpose);
  else
  {
    cout << "Impossible" << endl;
    //cout << R << " " << C << " " << free << endl;
  } 
  //cout << ">" << visible << endl;
  if (solved and visible != free)
  {
    cout << "contradiction";
    exit(-1);
  }
  
  
}

void proc_case()
{
  int R,C,M;
  
  cin >> R >> C >> M;
  
  if (R < C)
    solve(R,C,M, true);
  else
    solve(C,R,M, false);
}


int main()
{
  int nCases;
  cin >> nCases;
  for (int caseNo=0; caseNo < nCases; caseNo++)
  {
      cout << "Case #" << caseNo+1 << ": " << endl;
      proc_case();
  }
}