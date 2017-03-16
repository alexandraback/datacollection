#include <iostream>
#include <fstream>
#include <string>

#define LearnN 0.1

using namespace std;

unsigned int NumOfData,NumOftestData;



void solve()
{
     ifstream fin("input.txt", ios::in);
     ofstream fout("output.txt", ios::out);
     int k = 0, n = 0, sa = 0, p = 0, b = 0;
     char s[1000], buf[3];//ftiaxto meta
     fin >> k;
     
     fin.getline(s,1000);
     for (int i = 0; i < k; i++)
     {
         int count = 0;
         fin >> n;
         fin >> sa;
         fin >> p;
         for (int j = 0; j < n; j++)
         {
             int ak = 0;
             int tem;
             fin >> b;
             ak = b/3;
             tem = b - ak*3;
             if (tem > 0)
                ak++;
             if (ak >= p)
             {
                count++;
             }
             else if (sa > 0 && ak > 0)
             {
                 if (tem != 1)
                 {
                    ak++;
                    if (ak >= p)
                    {
                       sa--;
                       count++;
                    }
                 }
             }
         }
         fout << "Case #" << (i+1) << ": " << count << endl;
     }
     
}


int main()
{
    solve();
    //system("PAUSE");
    return 0;
}
