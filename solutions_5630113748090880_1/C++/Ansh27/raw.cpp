#include <iostream>
#include <math.h>
#include <stack>
#include <fstream>
using namespace std;
#include <string.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    ifstream file("hope2.in");
   ofstream out("out2.out");
   string str;
   vector<long> l;
   long r=0;
   int n;
   int t=1;
   while(getline(file,str,'\n'))
   {
       int count[2505];

       for(int k=0;k<str.length();k++)
       {   //cout<<"st "<<str[k]<<endl;
      // getch();
           if(str[k]==' ')
           {
              // cout<<r<<endl;
              // getch();
               l.push_back(r);
               r=0;
           }
           else
           {
               r=(10*r)+(static_cast<int>(str[k])-48);
              // cout<<"r="<<r<<endl;
               if(k==str.length()-1){l.push_back(r); r=0;}
           }
       }
       n=l[0];
       cout<<"n="<<n<<endl;
        for(int y=0;y<2505;y++){count[y]=0;}
       l.clear();
       for(int i=1;i<=(2*n)-1;i++)
       {
           getline(file,str,'\n');
           for(int k=0;k<str.length();k++)
            {   //cout<<"st "<<str[k]<<endl;
      // getch();
           if(str[k]==' ')
           {
              // cout<<r<<endl;
              // getch();
               l.push_back(r);
               cout<<r<<" ";
               r=0;
           }
           else
           {
               r=(10*r)+(static_cast<int>(str[k])-48);
              // cout<<"r="<<r<<endl;
               if(k==str.length()-1){l.push_back(r);  cout<<r<<" ";r=0;}
           }
            }

            cout<<endl;
            for(int m=0;m<n;m++)
            {
                count[l[m]-1]++;
            }
            l.clear();
       }
       vector<int> ans;
       for(int m=0;m<2505;m++)
       {    cout<<count[m]<<endl;
           if(count[m]%2==1){ans.push_back(m+1);}
       }
       sort(ans.begin(),ans.end());
       out<<"Case #"<<t<<": ";
       t++;
       for(int m=0;m<n;m++){out<<ans[m]<<" ";}
       out<<endl;

    }
}
