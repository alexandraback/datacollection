#include <cmath>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

ifstream in("balint.txt");
ofstream out("balint.out");
int countt;
int bitik;
int bitiA;
int bitiB;

#define int64 long long

/*
int64 findResult(int A,int B,int K)
{
     bitik=floor(log2(A))+1;
     bitiA=floor(log2(B))+1;
     bitiB=floor(log2(K))+1;
     countt=0;

      if (K<A && K<B)
      {
              for (int i=1;i<k;i++)
              {
                  int64 news=1;
                     for (int j=1;j<i;j=j<<1)
                        if (!i&j) news*=3;

              }

      }






}
*/

int64 calculate(int A,int B,int K)
{
    countt=0;
    for (int i=0;i<A;i++)
        for (int j=0;j<B;j++)
            if ((i&j)<K) countt++;
/*
    for (int i=0;i<B;i++)
        for (int j=0;j<A;j++)
           if ((i&j)<K) countt++;
*/
  return countt;
}


int main()
{
int A,B,K;
int T;
in >> T;
        for (int i=1;i<=T;i++)
        {
            in>>A;
            in>>B;
            in>>K;

            out << "Case #" << i << ": " << calculate(A,B,K) << '\n';
        }


return 0;
}
