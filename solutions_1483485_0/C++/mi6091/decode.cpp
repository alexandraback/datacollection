#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

char decs[] = "yhesocvxduiglbkrztnwjpfmaq";

string solve()
{
  string s1, ret = ""; 
  
  getline (cin, s1);
  
  int i; 
  for (i = 0; i < s1.size (); i ++)
  {
    int e = s1[i] - 'a';
    if (e >=0 && e < 26)
      ret += decs[e];
    else
      ret += s1[i];
  }
  return ret;
}
int main ()
{
  
  int t; 
  scanf ("%d\n", &t);
  
  int i ; 
  for (i = 1; i <= t; i ++)
     printf ("Case #%d: %s\n",i, solve ().c_str());
  
  return 0;
  map <char, char> m;
   
  for (i = 0; i < 6; i ++)
  {
    string s1, s2;
    
    getline (cin, s1);
    getline (cin, s2);
    
    int j; 
    for (j = 0; j < s1.size (); j ++)
      m[s1[j]] = s2[j];
  }
  
  char c;
  for (c = 'a'; c <= 'z'; c ++)
    printf ("%c, ", m[c]);
  
  printf ("\n");
  
  return 0;
}