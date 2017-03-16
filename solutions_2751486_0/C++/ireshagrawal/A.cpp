#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
   int T,i,j,n,count,flag,l;
   char a[4][4],temp;
   string G;
   ifstream fin; 
   ofstream fout;
   fin.open("A.in", ios::in);    // open the streams
   fout.open("ans.txt", ios::out);
   fin>>T;
   
   for(int t=0;t<T;t++)
   {
           //cout<<endl;
           fout<<"\nCase #"<<t+1<<": ";
           fin>>G>>n;
           
           count=0;
           l=G.length();
           for(j=0;j<l;j++){
           flag=0;
           for(i=j;i<l;i++)
           {               
                           if(G[i]!='a'&&G[i]!='e'&&G[i]!='i'&&G[i]!='o'&&G[i]!='u')
                           flag++;
                           else
                           flag=0;
                           
                           if(flag==n)
                           break;
                           }
                           //cout<<flag<<endl;
           if(flag==n)
           count+=l-i;
           else
           break;}
           fout<<count;}
           //system("pause");
   return 0;
}
                      
                           
