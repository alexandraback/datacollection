
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

string repeat( const string &word, int times ) {
   string result ;
   result.reserve(times*word.length()); // avoid repeated reallocation
   for ( int a = 0 ; a < times ; a++ ) 
      result += word ;
   return result ;
}

string solve(int X, int Y)
{
    string ret;
    if (X > 0) ret += repeat("WE", X);
    if (X < 0) ret += repeat("EW", -X);
    if (Y > 0) ret += repeat("SN", Y);
    if (Y < 0) ret += repeat("NS", -Y);
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {

        int X;
        scanf("%d", &X);
        int Y;
        scanf("%d", &Y);

        printf("Case #%d: %s\n", i+1, solve(X, Y).c_str());
    }
}

