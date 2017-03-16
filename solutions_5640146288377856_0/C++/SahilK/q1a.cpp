#include <iostream>
int solve(int c, int w) {
	if (w==c)
		return c;
	if (w==1)
		return c;
	if (w >= (c+1)/2)
		return (w+1);
	else
		return 1 + solve(c-w,w);
	return 100;
}

int main()
{
  int t;
  int r,c,w;
  
  std::cin >> t;
  
  for (int i = 1; i<=t; i++) {
	std::cin >> r >> c >> w;
	std::cout << "Case #" << i << ": " << solve(c,w) << std::endl;
  }
  return 0;
}