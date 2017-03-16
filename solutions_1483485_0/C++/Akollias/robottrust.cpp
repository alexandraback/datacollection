#include <iostream>
#include <fstream>
#include <string>

#define LearnN 0.1

using namespace std;


void solve()
{
     ifstream fin("input.txt", ios::in);
     ofstream fout("output.txt", ios::out);
     int k = 0,a = 0, *turn, w, *o,*b;
     char s[1000], j[1000], buf[60];//ftiaxto meta
     fin >> k;
     /*for(int i = 0;i<26;i++)
             buf[i*2]=97+i;
     buf[52] = ' ';
     buf[54] = '\0';
     */
     buf[0]='a', buf[1]='y';
     buf[2]='b', buf[3]='h';
     buf[4]='c', buf[5]='e';
     buf[6]='d', buf[7]='s';
     buf[8]='e', buf[9]='o';
     buf[10]='f', buf[11]='c';
     buf[12]='g', buf[13]='v';
     buf[14]='h', buf[15]='x';
     buf[16]='i', buf[17]='d';
     buf[18]='j', buf[19]='u';
     buf[20]='k', buf[21]='i';
     buf[22]='l', buf[23]='g';
     buf[24]='m', buf[25]='l';
     buf[26]='n', buf[27]='b';
     buf[28]='o', buf[29]='k';
     buf[30]='p', buf[31]='r';
     buf[32]='q', buf[33]='z';
     buf[34]='r', buf[35]='t';
     buf[36]='s', buf[37]='n';
     buf[38]='t', buf[39]='w';
     buf[40]='u', buf[41]='j';
     buf[42]='v', buf[43]='p';
     buf[44]='w', buf[45]='f';
     buf[46]='x', buf[47]='m';
     buf[48]='y', buf[49]='a';
     buf[50]='z', buf[51]='q';
     buf[52]=' ', buf[53]=' ';

     fin.getline(s,1000);
     for (int i = 0; i < k; i++)
     {
         fin.getline(s,200);
         //fin.getline(j,200);
         int n = 0;
         
         while (s[n] != '\0')
         {
               int m;
               for (m = 0;m<27;m++)
                   if (buf[m*2]==s[n])
                      break;
               j[n]=buf[m*2+1];      
               n++;
         }
         j[n]='\0';
         //ta exoume diavasei kai ta valame stous pinakes
         fout << "Case #" << (i+1) << ": " << j << endl;
     }
}


int main()
{
    solve();
    //system("PAUSE");
    return 0;
}
