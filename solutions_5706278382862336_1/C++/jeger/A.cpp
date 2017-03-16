#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <sstream>    /* printf, fgets */
#include <stdlib.h>
#include <fstream>
using namespace std;
long long LNKO (long long a, long long b)
{
    if(a>b)
    {
        swap(a,b);
    }
  if(a==0)
  {
      return b;
  }
  else
  {
      return LNKO(b%a, a);
  }

};
int main()
{
    long long kettohatvanyok[51];
    kettohatvanyok[0]=1;
    for (int i=1;i<=50;i++)
    {
        kettohatvanyok[i]=kettohatvanyok[i-1]*2;
    }
  //  cout << LNKO(19,37);
    int T;
    ifstream be;
    be.open("A-large.in");
    ofstream ki;
    ki.open("A.txt");
    be >> T;

    for(int t=1;t<=T;t++)
    {
        ki << "Case #" <<t << ": ";
        string temp1, temp2;
        getline(be,temp1,'/');
        getline(be,temp2);
       // cout <<temp1 <<" " <<temp2 <<endl;
        long long a;
        long long b;
        stringstream is(temp1);
        is >> a;
      //  cout <<a <<endl;
        stringstream is1(temp2);
        is1 >> b;
       // cout <<b <<endl;
       long long c=LNKO(a,b);
        a=a/c;
        b=b/c;
       // cout << a << " " <<b <<endl;
        int j=0;
        while(j<=40 and kettohatvanyok[j]!=b)
        {
            j++;
        }
        if(j>=40)
        {
            ki << "impossible" <<endl;
        }
        else
        {
            if(a==1)
            {
                ki <<j <<endl;
            }
            else
            {
                while(a!=1)
                {
                    a++;
                    c=LNKO(a,b);
                    a/=c;
                    b/=c;
                }
                j=0;
                while(b!=kettohatvanyok[j])
                {
                    j++;
                }
                ki << j+1 <<endl;
            }

        }
    }
    be.close();
    ki.close();
    return 0;
}
