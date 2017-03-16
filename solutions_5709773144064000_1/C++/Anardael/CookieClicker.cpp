#include <fstream>
using namespace std;

int main()
{
  ifstream f("input.txt");
  ofstream w("output.txt");
  int T;
  f>>T;
  double C,F,X;
  for (int ti=1;ti<=T;ti++)
  {
    f>>C>>F>>X;
    double seconds=0;
    double farms=0;
    w.precision(15);
    while (true)
    {
      if (X/(2+farms*F)>X/(2+(farms+1)*F)+C/(2+farms*F))
      {
	seconds+=C/(2+farms*F);farms+=1;
	
      } else
      {
	w<<"Case #"<<ti<<": "<<X/(2+farms*F)+seconds<<endl;
	break;
      }
    }
  }
  
  
  return 0;
}