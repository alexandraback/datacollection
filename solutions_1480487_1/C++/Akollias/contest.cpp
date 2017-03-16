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
     int k = 0, n = 0, sa[200], flag =0;// p = 0, b = 0;
     char s[1000], buf[3];//ftiaxto meta
     fin >> k;
     double per[200],temp[200],temp1[200];
     fin.getline(s,1000);
     for (int i = 0; i < k; i++)
     {
         flag =0;
         fin >> n;
         int sum=0;
         double vot =1.0;
         for (int j = 0; j < n; j++)
         {
             fin >> sa[j];
             sum = sum+ sa[j];
         }
         for (int j = 0; j < n; j++)
         {
             per[j]= sa[j]*1.0/sum;
         }
         
         for (int j = 0; j < n; j++)
         {
             temp[j]=per[j];
         }
         while (vot > 0)
         {
             double tempf = 1;
             for (int j = 0; j < n; j++)
             {
                 if (temp[j] < tempf)
                    tempf= temp[j];
             }
             int count = 0;
             for (int j = 0; j < n; j++)
             {
                 if (temp[j] == tempf)
                    count++;
             }
             double temp2f = 1;
             for (int j = 0; j < n; j++)
             {
                 if (temp[j] < temp2f && temp[j]!= tempf)
                    temp2f= temp[j];
             }
             if (temp2f != 1)
             {
                double ak = temp2f - tempf;
                if (ak <= (vot / count) )
                {
                   for (int j = 0; j < n; j++)
                   {
                       if (temp[j] == tempf)
                          temp[j] = temp2f;
                   }
                   vot = vot - ak*count;
                }
                else 
                {
                     for (int j = 0; j < n; j++)
                     {
                         if (temp[j] == tempf)
                            temp[j] = temp[j] + vot / count;
                     }
                     vot = 0;
                }
             }
             else 
             {
                for (int j = 0; j < n; j++)
                {
                    if (temp[j] == tempf)
                       temp[j] = temp[j] + vot / count;
                }
                vot = 0;  
             }
         }
         
         
         fout << "Case #" << (i+1) << ":";
         for (int j = 0; j < n; j++)
         {
            fout << " " << (temp[j] - per[j])*100.0;  
         }
         fout << endl;
     }
     
}


int main()
{
    solve();
    //system("PAUSE");
    return 0;
}
