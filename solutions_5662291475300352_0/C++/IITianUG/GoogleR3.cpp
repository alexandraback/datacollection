#include<bits/stdc++.h>
using namespace std;
 int main()
 {
    ifstream IF;
     ofstream OF;
     int t,trm,i,d[100],h[100],m[100],n,xx,yy;
     IF.open("input.txt");
     OF.open("output.txt");
   IF>>t;
   for(trm=1;trm<=t;trm++)
   {
      IF>>n;
      for(i=0;i<n;i++)
      {
     IF>>d[i]>>h[i]>>m[i];
      }
    if(n==1)
         OF<<"Case #"<<trm<<": "<<0<<endl;
    else {
        m[0]=m[0]/360+m[0]%360+d[0];
        m[1]=m[1]/360+m[1]%360+d[1];

        xx =max(m[0],m[1]);
        yy = min(m[0],m[1]);
        xx  = xx/yy;
            if(xx>=2)
            OF<<"Case #"<<trm<<": "<<1<<endl;
        else OF<<"Case #"<<trm<<": "<<0<<endl;

    }

   }


IF.close();
OF.close();
return 0;
 }
