#include<bits/stdc++.h>
using namespace std;
 int main()
 {
    ifstream IF;
     ofstream OF;
     IF.open("input.txt");
     OF.open("output.txt");
     int t,R,C,W,j;
     IF>>t;
     for(int trm=1;trm<=t;trm++)
     {
         IF>>R>>C>>W;
         j=C/W;
         if(C%W==0)
            j--;
         j+=W;
          OF<<"Case #"<<trm<<": "<<j<<endl;
     }



IF.close();
OF.close();
return 0;
 }
