#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>


using namespace std;

int main()
{
   freopen ("in.in", "r",stdin);
   freopen("out.out","w",stdout);
   
   int t,k,x,y,X,Y,i;
   cin>>t;
   k=0;
   while(k<t){k++;

printf("Case #%d: ",k);
   cin>>X>>Y;

i=1;x=0;y=0;
     if(X>0)
     {while(i+x<=X  && x!=X)
     {  x+=i;
      i++; cout<<"E";
     }
     while(x!=X)
     { i+=2;
       x++;
       cout<<"WE";
     }
     }
     else
     {while(x-i>=X  && x!=X)
     {  x-=i;
      i++; cout<<"W";
     }
     while(x!=X)
     { i+=2;
       x--;
       cout<<"EW";
     }
     }
     if(Y>0)
     {while(i+y<=Y  && y!=Y)
     {  y+=i;
      i++; cout<<"N";
     }
     while(y!=Y)
     { i+=2;
       y++;
       cout<<"SN";
     }
     }
     else
     {while(y-i>=Y  && y!=Y)
     {  y-=i;
      i++; cout<<"S";
     }
     while(y!=Y)
     { i+=2;
       y--;
       cout<<"NS";
     }}

cout<<endl;
}


}
