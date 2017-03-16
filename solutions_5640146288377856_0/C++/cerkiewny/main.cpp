#include<fstream>
#include<iostream>

using namespace std;



int main(){
  
  ifstream in("in");

  ofstream out("out");


  int ncases;

  in >> ncases;
  for(int i = 0; i < ncases; i++){

    int r, c, w;

    in >> r >> c >> w;

    cout << r << " " << c << " " << w << endl;

    if(c % w == 0 ){
      out << "Case #" << i+1 << ": " << (c/w) * r + w - 1 << endl;
      cout << "Case #" << i+1 << ": " << (c/w) * r + w - 1 << endl;
    }
    else
    {
      out << "Case #" << i+1 << ": " << (c/w) * r + w << endl;
      cout << "Case #" << i+1 << ": " << (c/w) * r + w << endl;
    }
  }

}
