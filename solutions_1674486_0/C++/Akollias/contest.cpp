#include <iostream>
#include <fstream>
#include <string>

#define LearnN 0.1

using namespace std;

unsigned int NumOfData,NumOftestData;

int cd[1001][11], flag, tr;

int findp(int n, int m)
{
    int sum = 0;
    for (int i=0; i < cd[n][10]; i++)
    {
        if (cd[n][i] == m)
        {
           sum++;
        }
        else
        {
            sum = sum + findp(cd[n][i],m);
        }
    }
    return sum;
}


void solve()
{
     ifstream fin("input.txt", ios::in);
     ofstream fout("output.txt", ios::out);
     int k = 0, n = 0, flag =0;// p = 0, b = 0;
     char s[1000], buf[3];//ftiaxto meta
     fin >> k;
     //double per[200],temp[200],temp1[200];
     fin.getline(s,1000);
     for (int i = 0; i < k; i++)
     {
         flag =0;
         fin >> n;
         for (int j = 0; j < n; j++)
         {
             fin >> cd[j][10];
             for (int ga = 0; ga < cd[j][10]; ga++)
             {
                 fin >> cd[j][ga];
                 cd[j][ga] = cd[j][ga] -1;
             }
         }
         /*for (int j = 0; j < n; j++)
         {
             for (int ga = 0; ga < n; ga++)
             {
                 inh[j][ga] = -1;
             }
         }*/
         for (int j = 0; j < n; j++)
         {
             for (int ga = 0; ga < n; ga++)
             {
                 if ( ga != j)
                 {
                    int boi = findp(j, ga);
                    if (boi > 1)
                       flag = boi;
                 }
             }
         }
         cout << i << endl;
         
         fout << "Case #" << (i+1) << ":";
         if (flag > 1)
         {
            fout << " Yes";
         }
         else
             fout << " No";
         fout << endl;
     }
     
}


int main()
{
    solve();
    //system("PAUSE");
    return 0;
}
