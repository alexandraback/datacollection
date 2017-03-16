#include <iostream>

using namespace std;

const char tbl[] = "yhesocvxduiglbkrztnwjpfmaq";

void calc(){
  char line[101];
  char* c = (char*)line;
  cin.getline(line, sizeof(line));
  while(*c){
    if(*c == ' ')
      cout << ' ';
    else
      cout << tbl[*c - 'a'];
    c++;
  }
}

int main(){
  int N;
  cin >> N;
  cin.getline(NULL, 0);
  for(int i=1; i<=N; i++){
    cout << "Case #" << i << ": ";
    calc();
    cout << endl;
  }
  return 0;
}
