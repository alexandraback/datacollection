#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream IF;
    IF.open("input.txt");
    ofstream OF;
    OF.open("output.txt");
    int t,i;

    IF >> t;
    string str;
    int n;

    char te[30010];
    for(int tc=1;tc<=t;tc++)
    {
      OF <<"Case #" << tc << ": ";
       IF>>str;
       n=str.length();
       int frst=10000;
     int lst=10000;
       te[frst]=str[0];

       for(i=1;i<n;i++)
       {
          if(str[i]>=te[frst])
            {
              frst--;
              te[frst]=str[i];
            }
            else
            {
               lst++;
               te[lst]=str[i];
            }
       }

       for(i=frst;i<=lst;i++)
         OF<<te[i];
         OF<<endl;



    }

    OF.close();
    IF.close();
}
