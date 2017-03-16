#include<fstream>
#include<iostream>
#include<fstream>

using namespace std;

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");

  int tests, test = 0;
  in >> tests;

  while(tests--){
    ++test;
    string ans;
    int x, y;
    in >> x >> y;
    swap(x, y);

    for(int i = 1; i <= x; ++i)
      ans = ans + "SN";
    for(int i = -1; i >= x; --i)
      ans = ans + "NS";
    for(int i = 1; i <= y; ++i)
      ans = ans + "WE";
    for(int i = -1; i >= y; --i)
      ans = ans + "EW";

    out << "Case #" << test << ": " << ans;
    if(tests)
      out << "\n";
  }

  return 0;
}
