#include<iostream>
#include "stdio.h"
using namespace std;

int arr[300], brr[300], total, length;

void getavg(int *arr, int *brr, int avg)
{
   int i, open = 0, count = 0, sum = 0;
   for(i=0;i<length;i++)
   {
      if(arr[i] == 0)
      {
         if(brr[i] > avg)
         {
            open = 1;
            arr[i] = 1;
         }
      }
   }
   for(i=0;i<length;i++)
   {
      if(arr[i] == 1)
      {
         sum = sum + brr[i];
      }
      else
      {
         count++;
      }
   }
   avg = total - sum;
   avg = avg/count;
   if(open)
   {
      getavg(arr, brr, avg);
   }
}

int main()
{
   int test,i,j;
   cin >> test;
   for(i=0;i<test;i++)
   {
      cin >> length;
      total = 0;
      for(j=0;j<length;j++)
      {
         cin >> brr[j];
         arr[j] = 0;
         total = total + brr[j];
      }
      total = total*2;
      int av = total/(length);
      getavg(arr, brr, av);
      int sum = 0, count = 0;
      for(j=0;j<length;j++)
      {
         if(arr[j] == 1)
         {
            sum = sum + brr[j];
         }
         else
         {
            count++;
         }
      }
      float avg = total - sum;
      avg = avg/count;
      total = total /2;
      cout<<"Case #"<<i+1<<":";
      for(j=0;j<length;j++)
      {
         if( arr[j] == 0 )
         {
            float need = avg - brr[j];
            float needp = need/total * 100;
            //cout<<need<<"  " << total<<"\n";
	    printf(" %.7f",needp);//
          //  cout << needp << "\n";
         }
         else
            cout << " 0.000000";
      }
      cout<<"\n";
   }
}
