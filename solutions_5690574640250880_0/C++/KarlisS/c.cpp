#include <iostream>
#include <cstring>
using namespace std;

char ans[64][64];

int solve(int r, int c, int m)
{
  memset(ans, '.', sizeof(ans));
  int f=r*c-m;
  if (r == 1)
  {
    for(int i=0; i<m; i++)ans[0][i]='*';
    ans[0][c-1] = 'c';
    return 1;
  }
  else if (c == 1)
  {
    for(int i=0; i<m; i++) ans[i][0] = '*';
    ans[r-1][0] = 'c';
    return 1;
  }
  memset(ans, '*', sizeof(ans));
  if (f ==1)
  {
    ans[0][0] = 'c';
    return 1;
  }
  else if(f == 2 || f==3 ) 
  {
    return 0;
  }
  if (r == 2 || c==2) {
    if (f%2)return 0;
    if (r==2) {
      for(int j=0; j<f/2;j++) {
        ans[0][j]=ans[1][j]='.';
      }
    }
    else
    {
      for(int j=0; j<f/2;j++) {
        ans[j][0]=ans[j][1]='.';
      }
    }
    ans[0][0]='c';
  }
  if (f == 5 || f == 7) return 0;
  ans[0][0]=ans[1][0]=ans[0][1]=ans[1][1] = '.';
  f -= 4;
  if (f>=2) {ans[2][0]=ans[2][1] = '.'; f-= 2;}
  if (f>=2) {ans[0][2]=ans[1][2] = '.'; f-= 2;}
  if (f%2) {ans[2][2] = '.'; f -= 1;}
  for (int j=3; j<c; j++) {
    if(f) {
        ans[0][j]=ans[1][j] ='.';
        f -= 2;
    }  
  }
  for (int j=3; j<r; j++) {
    if(f) {
        ans[j][0]=ans[j][1] ='.';
        f -= 2;
    }  
  }
  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++) {
        if (f && ans[i][j] == '*') {
            ans[i][j] = '.';
            f--;
        }
    }
  }
  ans[0][0] = 'c';
  return 1;
}

int main()
{
  int t;
  cin >> t;
  for(int i=1; i<=t; i++)
  {
    int r,c,m;
    cin >> r >> c >> m;
    cout << "Case #" << i << ":\n";
    if (solve(r, c, m)) {
      for(int i=0; i<r; i++) {
        ans[i][c] = '\0';
        cout << ans[i] << "\n";
      }
    } else {
      cout << "Impossible\n";
    }
  }
  return 0;
}
