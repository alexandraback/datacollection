#include <iostream>

using namespace std;

int main()
{
  int t; char g[30][101];
  int i, j;
  cin >> t;
  gets(g[0]);
  for (i=0;i<t;i++)
    gets(g[i]);
  for (i=0;i<t;i++) {
    for (j=0;g[i][j]!=0;j++) {
      switch (g[i][j]) {
        case 'a': g[i][j] = 'y'; break;
        case 'b': g[i][j] = 'h'; break;
        case 'c': g[i][j] = 'e'; break;
        case 'd': g[i][j] = 's'; break;
        case 'e': g[i][j] = 'o'; break;
        case 'f': g[i][j] = 'c'; break;
        case 'g': g[i][j] = 'v'; break;
        case 'h': g[i][j] = 'x'; break;
        case 'i': g[i][j] = 'd'; break;
        case 'j': g[i][j] = 'u'; break;
        case 'k': g[i][j] = 'i'; break;
        case 'l': g[i][j] = 'g'; break;
        case 'm': g[i][j] = 'l'; break;
        case 'n': g[i][j] = 'b'; break;
        case 'o': g[i][j] = 'k'; break;
        case 'p': g[i][j] = 'r'; break;
        case 'q': g[i][j] = 'z'; break;
        case 'r': g[i][j] = 't'; break;
        case 's': g[i][j] = 'n'; break;
        case 't': g[i][j] = 'w'; break;
        case 'u': g[i][j] = 'j'; break;
        case 'v': g[i][j] = 'p'; break;
        case 'w': g[i][j] = 'f'; break;
        case 'x': g[i][j] = 'm'; break;
        case 'y': g[i][j] = 'a'; break;
        case 'z': g[i][j] = 'q'; break;
      }
    }
  }
  for (i=1;i<=t;i++)
    cout << "Case #" << i << ": " << g[i-1] << endl;
  return 0;
}
