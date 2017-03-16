#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>


using namespace std;

int main()
{
int t;
cin >> t;
for(int T = 0; T < t; T++)
{
   int rows, cols, width;
   cin >> rows >> cols >> width;

   int ans;
   if (cols%width == 0) ans = cols/width + width - 1;
   else ans = cols/width + width;

   printf("Case #%d: %d\n", T+1, ans*rows);




}

}
