#include <iostream>
#include <cassert>
using std::cin;
const unsigned max_M = 200, max_N = 200;

int Lawn[max_M][max_N], max_row[max_N], max_col[max_M];

int main(void)
{
  int  number_of_test_cases;
  cin >> number_of_test_cases;
  for(auto test_case=1; 
      test_case <= number_of_test_cases;
      test_case++) {
    int rows, columns;
    cin >> rows >> columns;
    for(auto r=0; r<rows; r++) max_row[r]=0;
    for(auto c=0; c<columns; c++) max_col[c]=0;
    for(auto r=0; r<rows; r++) 
      for(auto c=0; c<columns; c++) {
	int e;
	cin >> e;
	Lawn[r][c]=e;
	if(max_row[r]<e) max_row[r]=e;
	if(max_col[c]<e) max_col[c]=e;
      }
    const char *verdict="YES";
    for(auto r=0; r<rows; r++) 
      for(auto c=0; c<columns; c++) 
	if(Lawn[r][c]<max_row[r] && Lawn[r][c]<max_col[c]) verdict="NO";
    std::cout << "Case #" << test_case << ": " << verdict << std::endl;
  }
  return 0;
}

