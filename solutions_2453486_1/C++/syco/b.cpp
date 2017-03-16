#include<iostream>
#include<set>
#include<map>
#include<string>
#include<stdio.h>
#include<sstream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<string.h>
using namespace std ;
#define INF (int)1e9
string s[4] ;

bool check(int p)
{
 for(int i = 0;i < 4;i++)
 {
  int c[256] = {} ;
  for(int j = 0;j < 4;j++) c[s[i][j]]++ ;
  if(c[p] == 4 || c[p] == 3 && c['T'] == 1) return true ;

  memset(c,0,sizeof c) ;
  for(int j = 0;j < 4;j++) c[s[j][i]]++ ;
  if(c[p] == 4 || c[p] == 3 && c['T'] == 1) return true ;
 }
 int c[256] = {} ;
 for(int i = 0;i < 4;i++) c[s[i][i]]++ ;
 if(c[p] == 4 || c[p] == 3 && c['T'] == 1) return true ;

 memset(c,0,sizeof c) ;
 for(int i = 0;i < 4;i++) c[s[i][3 - i]]++ ;
 if(c[p] == 4 || c[p] == 3 && c['T'] == 1) return true ;
 return false ;
}

bool draw()
{
 for(int i = 0;i < 4;i++)
  for(int j = 0;j < 4;j++)
   if(s[i][j] == '.')
    return false ;
 return true ;
}

int main()
{
 int runs ;
 cin >> runs ;
 for(int t = 1;t <= runs;t++)
 {
  for(int i = 0;i < 4;i++) cin >> s[i] ;
  
  string s;
  if(check('X')) s = "X won" ;
  else if(check('O')) s = "O won" ;
  else if(draw()) s = "Draw" ;
  else s = "Game has not completed" ;
  
  printf("Case #%d: %s\n",t,s.c_str()) ;
 }
 return 0 ;
}
