#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

unsigned int NumOfData,NumOftestData;

int checkre(int n,int b, int le)
{
    char s[20],d[20];
    int count =0, tem = 0;
    itoa (n,s,10);
    int temp[12];
    for (int i = 0; i <12;i++)
        temp[i]=0;
    //itoa (n,d,10);
    for (int i =1; i < le; i++)
    {
        char ka = s[0];
        for (int j =0; j < le - 1; j++)
        {
            s[j] = s[j+1];
        }
        s[le-1] = ka;
        tem = 0;
        for (int j =0; j < le; j++)
            tem = 10*tem + (s[j]-48);    
        if (tem <= b && tem > n)
        {
           int aj;
           for (aj=0;aj<le;aj++)
               if (tem==temp[aj])
                  break; 
           //cout << n << " , " << tem<< endl;
           if (aj == le)
              count++;
        }
        temp[i-1]= tem;
    }
    return count;
}

void solve()
{
     ifstream fin("input.txt", ios::in);
     ofstream fout("output.txt", ios::out);
     int k = 0, a = 0, b = 0, n = 0, m = 0;
     char s[1000], buf[20];//ftiaxto meta
     fin >> k;
     
     fin.getline(s,1000);
     for (int i = 0; i < k; i++)
     {
         int count = 0;
         fin >> a;
         n = a;
         fin >> b;
         itoa (a,buf,10);
         int le = 0;
         while (buf[le] != '\0')
               le++;
         if (le > 1)
         {
            while (n < b)
            {
                  count = count + checkre(n,b,le);
                  n++;
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
