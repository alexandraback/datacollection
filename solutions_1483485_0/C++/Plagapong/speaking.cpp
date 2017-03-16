/*
ID: Plagapong
LANG: C++
TASK: speaking
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
#define INF 999999999

using namespace std;
char text[200];
                 //abcdefghijklmnopqrstuvwxyz
char mapper[30] = "yhesocvxduiglbkrztnwjpfmaq";

void preprocess() {
  // Preprocess
  
}

void clearVars() {
  // Clear variables
  memset(text, 0, 200);
}

void process() {
  // Code here!
  cin.getline(text, 200);  // \n is discarded.
  int i = 0;
  while (text[i]) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      text[i] = mapper[text[i] - 'a'];
    }
    i++;
  }
  cout << text;
}

int main(int argc, const char* argv[]) {
  preprocess();
  int times;
  cin >> times >> ws;
  for (int i = 1; i <= times; i++) {
	cout << "Case #" << i << ": ";
	clearVars();
	process();
	cout << endl;
  }
  return 0;
}
