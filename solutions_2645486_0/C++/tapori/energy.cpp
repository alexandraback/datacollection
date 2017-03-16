#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#define LINT long long

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("A1.out","w",stdout);

   LINT T;
   cin>>T;
   
   LINT i,j,k;

   for(k =0; k <T; k++)
   {
      LINT E,R,N;
      LINT *arr;
      cin>>E>>R>>N;
      arr = (LINT*)malloc(sizeof(LINT)*N);
      for(i =0; i <N;i++)
      {
            cin>>arr[i];
      }

      i=0;
      LINT gain = 0;
      LINT egy = E;
      while(i<N)
      {
//          cout<<arr[i]<<endl;
         for(j = i+1;j<N && arr[j] <= arr[i]; j++);
         
         LINT diff = j-i;;
         if(j==N)
         {
             //spend all
             gain += arr[i]*egy;
             egy = R;
         }
         else if((egy + diff*R) <= E)
         {
             egy = egy + R; 
         }
         else if((diff*R) <= E)
         {

             LINT spend = egy - (E - diff*R);
             gain += spend * arr[i];
             egy = egy - spend + R; 
         }
         else if(diff*R > E)
         {
              //spend all;
             gain += arr[i]*egy;
             egy = R;
         }
     
  //    cout<<"egy "<<egy<<" "<<gain<<endl;
        i++;         
      }

     
     cout<<"Case #"<<k+1<<": "<<gain<<endl;
   }

//  int y;
//  cin>>y;
  return 0;
	}

