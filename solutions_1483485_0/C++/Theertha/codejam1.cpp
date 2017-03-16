#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
int main()
{
  int T; 
  string s;
  string s2;
  char c,d;
  cin >> T;
  getline(cin,s);
  int i=0;
  int j=0;
  while(i < T){
    getline(cin,s);
    cout << "Case #" << i+1 << ": ";
    for (j=0; j < s.length(); j++)
    {
      c = s[j];
     // cout << c;
      if(c == ' '){
	d=c;
      }
      if( c == 'a'){
	d = 'y';
      }
      if( c == 'b'){
	d = 'h';
      }
      if( c == 'c'){
	d = 'e';
      }
      if( c == 'd'){
	d = 's';
      }
      if( c == 'e'){
	d = 'o';
      }
      if( c == 'f'){
	d = 'c';
      }
      if( c == 'g'){
	d = 'v';
      }
      if( c == 'h'){
	d = 'x';
      }
      if( c == 'i'){
	d = 'd';
      }
      if( c == 'j'){
	d = 'u';
      }
      if( c == 'k'){
	d = 'i';
      }
      if( c == 'l'){
	d = 'g';
      }
      if( c == 'm'){
	d = 'l';
      }
      if( c == 'n'){
	d = 'b';
      }
      
      if( c == 'o'){
	d = 'k';
      }
      
      if( c == 'p'){
	d = 'r';
      }
      
      if( c == 'q'){
	d = 'z';
      }
      
      if( c == 'r'){
	d = 't';
      }
      
      if( c == 's'){
	d = 'n';
      }
      
      if( c == 't'){
	d = 'w';
      }
      
      if( c == 'u'){
	d = 'j';
      }
      
      if( c == 'v'){
	d = 'p';
      }
      
      if( c == 'w'){
	d = 'f';
      }
      
      if( c == 'x'){
	d = 'm';
      }
      
      if( c == 'y'){
	d = 'a';
      }
      
      if( c == 'z'){
	d = 'q';
      }
      s2.push_back(d);
    }
    cout << s2 << endl;
    i = i+1;    
    s.clear();
    s2.clear();
  }
  return 0;
}