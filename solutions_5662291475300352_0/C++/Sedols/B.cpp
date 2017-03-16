#include<iostream>
#include<fstream>
#include <iomanip>
#include <string>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
  ifstream in;
  in.open("in.txt");
  ofstream out;
  out.open("out.txt");
  long long  T, N;
  in >> T;
  for (long long k = 1; k <= T; k++)
  {
        in >> N;
        long long st1=0, n1=0, sp1=0;
        long long st2=0, n2=0, sp2=0;
        in >> st1 >> n1 >> sp1;
        in >> st2 >> n2 >> sp2;

        if(sp1 == sp2) 
        {
              out << "Case #" << k << ": " << 0 << endl;  
              continue;
        }
        if(sp1 < sp2)
        {
            long long temp = sp1;
            sp1 = sp2;
            sp2 = temp;       
            
            temp = st1;
            st1 = st2;
            st2 = temp;   
        }
        double spead1 = sp1/360;
        double spead2 = sp2/360;
        double timeTo = 360 * fabs(spead2-spead1);

        if((360LL - st1)*spead1  <= timeTo)
        {  
            out << "Case #" << k << ": " << 1 << endl;  
        }
        else
        {
            out << "Case #" << k << ": " << 0 << endl;  
        }
  }
  out.close();
  in.close();

}
