#include <iostream>
#include <cassert>
using std::cin;



char get_char() {
  char c;
  cin >> c;
  switch(c) {
  case '.': 
  case 'X': 
  case 'O': 
  case 'T': return c;
  default:  return get_char();
  }
}

char tcc[4*4];
inline char test_dx(int idx0, int dx) {
  char found=tcc[idx0];
  if(found=='T') found=tcc[idx0+dx];
  if(found=='.') return 0;
  if(0) for(auto i=0; i<4*4; i++) std::cerr << tcc[i];
  if(0) std::cerr << " idx=" << idx0 << ", dx=" << dx << ", found=" << found << "\n";
  assert(found=='X' || found=='O');
  for(auto i=0; i<4; i++, idx0+=dx) 
    if(tcc[idx0]!=found && tcc[idx0]!='T') return 0;
  if(found=='X' || found=='O') return found;
  assert(found=='.');
  return 0;
}

char make_tests()
{
  char c = 0;
  for(auto i=0; i<4; i++) {
#define TRY_RETURN(expr) if((c=expr)!=0) return c;
    TRY_RETURN(test_dx(i,4));
    TRY_RETURN(test_dx(i*4,1));
  }
  TRY_RETURN(test_dx(0,5));
  TRY_RETURN(test_dx(3,3));
  for(auto i=0; i<4*4; i++) 
    if(tcc[i]=='.') return 0;
  return 'D';
}

int main(void) {
  unsigned number_of_test_cases;

  cin >> number_of_test_cases;

  for(unsigned test_no=1; test_no <= number_of_test_cases; test_no++) {
    for(auto i=0; i<4*4; i++)
	tcc[i]=get_char();
    const char *verdict;
    switch(make_tests()) {
    case 'X': verdict = "X won"; break;
    case 'O': verdict = "O won"; break;
    case 'D': verdict = "Draw";  break;
    case 0:   verdict = "Game has not completed"; break;
    default: verdict = "BUG";
    }
    std::cout << "Case #" << test_no << ": " << verdict << std::endl;
  }
  return 0;
}
