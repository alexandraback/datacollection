#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

int t;
string s;
int n;
int hasil=0;

void hitung()
{
//     s='a'+s;
     vector <int> cx;
     
     int cw=0;
     for (int i=0; i<s.length(); i++)
     {
         cx.push_back(0);
         
         char c=s[i];
         
//         cout << c << endl;
         if ((c=='a') || (c=='i') || (c=='u') || (c=='e') || (c=='o'))
         {
//              cout << "True\n";
              cw=0;
         }
         else
         {
             cw+=1;
             cx[i]+=cw;
         }
//         cout << i << " " << cw << endl;
     }
  
  /*   
     for (int i=0; i<cx.size(); i++)
     {
         printf("%d ",cx[i]);
     }
     printf("\n");
*/     
     int ct=0;
     int mx=0;
     for (int i=0; i<cx.size(); i++)
     {
         for (int j=i; j<cx.size(); j++)
         {
             mx=0;
             int bound=0;
             if ((cx[i]>0) && (i>0))
             {
                 bound = cx[i-1];
             }
             


             for (int k=i; k<=j; k++)
             {
                 if (cx[k]==0) bound=0;
                 if (cx[k]-bound > mx) mx=cx[k]-bound;
             }
             if (mx>=n) ct+=1;
             
//             if (mx>=n) cout << i << " " << j << " " << mx << endl;
         }
         
         
         
     }
     
     hasil=ct;
     
 }

int main ()
{
    scanf("%d",&t);
    for (int z=1; z<=t; z++)
    {
        cin >> s >> n;
//        cout << s << " " << n << endl;
        
        hitung();
        printf("Case #%d: %d\n",z, hasil);
        
    }
    return 0;
}
