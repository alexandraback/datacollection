#include<stdio.h>
#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
  map<char,char>M;
  M[' '] = ' ';  //
  M['a'] = 'y';  // 
  M['b'] = 'h';  //
  M['c'] = 'e';  //
  M['d'] = 's';  //
  M['e'] = 'o';  //
  M['f'] = 'c';  //
  M['g'] = 'v';  //
  M['h'] = 'x';  //
  M['i'] = 'd';  //
  M['j'] = 'u';  //
  M['k'] = 'i';  //
  M['l'] = 'g';  //
  M['m'] = 'l';  //
  M['n'] = 'b';  //
  M['o'] = 'k';  //
  M['p'] = 'r';  //
  M['q'] = 'z';  
  M['r'] = 't';  //
  M['s'] = 'n';  //
  M['t'] = 'w';  //
  M['u'] = 'j';  //
  M['v'] = 'p';  //
  M['w'] = 'f';  //
  M['x'] = 'm';  //
  M['y'] = 'a';  //
  M['z'] = 'q';  

  int tc;
  scanf("%d",&tc);
  string str;
  getchar();
  for(int i=0; i<tc; i++){
      getline(cin, str);
      printf("Case #%d: ",i+1);
      for(int j=0; j<str.length(); j++){
	printf("%c",M[str[j]]);
      }
      cout << endl;
  }


  return 0;
}
