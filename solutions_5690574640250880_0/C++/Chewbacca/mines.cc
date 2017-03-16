#include <iostream>
#include <cassert>
using std::cout;
unsigned R, C, M;
char transformed;
const unsigned  max_xy = 100;
char matrix[max_xy][max_xy];

void dump_it()
{
  matrix[0][0]='c';
  for(auto r=0u; r<R; r++) {
    for(auto c=0u; c<C; c++) 
      cout << matrix[r][c];
    cout << std::endl;
  }
}

void impossible() 
{
  cout << "Impossible" << std::endl;
}


void solve(unsigned R, unsigned C, unsigned M)
{
  for(auto r=0; r<max_xy; r++)
    for(auto c=0; c<max_xy; c++)
      matrix[r][c]='*';
  unsigned free = R*C-M;
    
  if(R==1) {
    for(auto c=0u; c<free; c++) matrix[0][c]='.';
    return dump_it();
  }

  if(C==1) {
    for(auto r=0u; r<free; r++) matrix[r][0]='.';
    return dump_it();
  }

  if(free==1) 
    return dump_it();

  if( (R==2 || C==2) & free%2)
    return impossible();

  assert(R>=2);
  assert(C>=2);

  if(free<4 || free==5 || free==7)
    return impossible();

  unsigned rC, rR, last;
  if(free>=2*C)
    rC=C;
  else 
    rC = free/2;
  assert(rC<=C);
  rR = free/rC;
  last = free % rC;
  // yet another special case 
  if(rR==2 && last==1) {
    assert(rC>2);
    rC--;
    rR=free/rC;
    last = free % rC;
    assert(rR<R || (rR==R && last==0));
  }
  for(auto r=0u; r<rR; r++)
    for(auto c=0u; c<rC; c++)
      matrix[r][c]='.';
  if(last==1) {
    last = 2;
    assert(matrix[rR-1][rC-1]=='.');
    matrix[rR-1][rC-1]='*';
  }
  for(auto c=0; c<last; c++)
    matrix[rR][c]='.';
  return dump_it();
}
  

int main()
{
  unsigned number_of_tests;
  std::cin >> number_of_tests;
  for(int test_no=1; test_no<=number_of_tests;
      test_no++) {
    std::cin >> R >> C >> M;
    cout << "Case #" << test_no << ":\n";
    solve(R,C,M);
  }
  return 0;
}
    


