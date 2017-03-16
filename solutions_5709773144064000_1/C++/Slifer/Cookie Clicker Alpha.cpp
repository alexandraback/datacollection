#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//*************************
//****  Cookie_Clicker ****
//************************* 

class CookieClicker
{
public:
       CookieClicker(double ,double ,double );
       void examine();
       void printMessage(int ,ostream & = std::cout) const;
private:
        const double C;
        const double F;
        const double X;
        double time;
};

CookieClicker::CookieClicker(double c,double f,double x):C(c),F(f),X(x),time(-1) { }

void CookieClicker::examine()
{
  double time2 = 0;
  double production = 2;
  
  time = X/production;
  
  //while ((X/production > 1) && time2<time){  !!! becareful !!! C/production might be <<1 !!!
  while (time2 < time){
      time2 += C/production;
      production += F;
      if ((time2 + X/production) < time) time = time2 + X/production;
  }
}

void CookieClicker::printMessage(int k,ostream &out) const
{ out << "Case #" << k << ": " << setprecision(7) << fixed << time; }



//*******************
//*****  MAIN   *****
//*******************

int main()
{
  ifstream input("B-large.in");
  if (!input) exit(1);
  ofstream output("out.txt");
  if (!output) exit(1);
  
  int T;
  double C,F,X;
  input >> T;
  
  for (int k=1;k<=T;k++){
      input >> C >> F >> X;
      CookieClicker cc(C,F,X);
      cc.examine();
      cc.printMessage(k,output);
      output << endl;
  }
  input.close();
  output.close();
  
  scanf("%*c");
  return 0;
}
