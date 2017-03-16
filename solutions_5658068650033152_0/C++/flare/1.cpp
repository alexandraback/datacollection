#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

int main(void)
{
   int T,tt,i,ans,rec;
   cin>>T;
   tt=T;
   int N,M,K;

   for(tt=1;tt<=T;tt++)
   {
       cin>>N>>M>>K;
       if(N<=2||M<=2)
       {
    	   printf("Case #%d: %d\n",tt,K);
       }
       else if(N==3&&M==3)
       {
            if(K<=4)
            {
            	 printf("Case #%d: %d\n",tt,K);
            }
            else
            {
            	 printf("Case #%d: %d\n",tt,K-1);
            }
       }
       else if((N==3&&M==4)||(N==4&&M==3))
       {
    	   if(K<=4)
    	   {
    		   printf("Case #%d: %d\n",tt,K);
    	   }
    	   else if(K>4&&K<8)
    	   {
    		   printf("Case #%d: %d\n",tt,K-1);
    	   }
    	   else if(K>=8)
    	   {
    		   printf("Case #%d: %d\n",tt,K-2);
    	   }
       }
       else if(N==4&&M==4)
       {
    	   switch(K)
    	   {
    	   case 1:  ans=1;
    	               break;
    	   case  2:  ans=2;break;
    	   case    3:ans=3;break;
    	   case    4:ans=4;break;
    	   case 5: ans=4;break;
    	   case 6: ans=5;break;
    	   case 7: ans=6;break;
    	   case 8: ans=6;break;
    	   case 9: ans=7;break;
    	   case 10: ans=7;break;
    	   case 11: ans=7;break;
    	   case 12: ans=8;break;
    	   case 13: ans=9;break;
    	   case 14: ans=10;break;
    	   case 15: ans=11;break;
    	   case 16: ans=12;break;

    	   }
    	   printf("Case #%d: %d\n",tt,ans);
       }
       else if((N==3&&M==5)||(N==5&&M==3))
       {
    	   switch(K)
    	   {
    	   case 1: ans=1;break;
    	   case 2: ans=2;break;
    	   case 3: ans=3;break;
    	   case 4: ans=4;break;
    	   case 5: ans=4;break;
    	   case 6: ans=5;break;
    	   case 7: ans=6;break;
    	   case 8: ans=6;break;
    	   case 9: ans=7;break;
    	   case 10: ans=8;break;
    	   case 11: ans=8;break;
    	   case 12: ans=9;break;
    	   case 13: ans=10;break;
    	   case 14: ans=11;break;
    	   case 15: ans=12;break;

    	   }
    	   printf("Case #%d: %d\n",tt,ans);
       }
       else if((M==3&&N==6)||(M==6&&N==3))
		{
    	   switch(K){
           case 1: ans=1;break;
    	   case 2: ans=2;break;
    	   case 3: ans=3;break;
    	   case 4: ans=4;break;
    	   case 5: ans=4;break;
    	   case 6: ans=5;break;
    	   case 7: ans=6;break;
    	   case 8: ans=6;break;
    	   case 9: ans=7;break;
    	   case 10: ans=8;break;
    	   case 11: ans=8;break;
    	   case 12: ans=9;break;
    	   case 13: ans=10;break;
    	   case 14: ans=10;break;
    	   case 15: ans=11;break;
    	   case 16: ans=12;break;
    	   case 17: ans=13;break;
    	   case 18: ans=14;break;
    	   }
    	   printf("Case #%d: %d\n",tt,ans);
		}
       else if((M==4&&N==5)||(M==5&&N==4))
       {switch(K){
       case 1:  ans=1;
        	               break;
        	   case  2:  ans=2;break;
        	   case    3:ans=3;break;
        	   case    4:ans=4;break;
        	   case 5: ans=4;break;
        	   case 6: ans=5;break;
        	   case 7: ans=6;break;
        	   case 8: ans=6;break;
        	   case 9: ans=7;break;
        	   case 10: ans=7;break;
        	   case 11: ans=7;break;
        	   case 12: ans=8;break;
        	   case 13:  ans=9;break;
        	   case 14:  ans=9;break;
        	   case 15:  ans=10;break;
        	   case 16:  ans=10;break;
        	   case 17:  ans=11;break;
        	   case 18:  ans=12;break;
        	   case 19:  ans=13;break;
        	   case 20:  ans=14;break;

           }
       printf("Case #%d: %d\n",tt,ans);

       }
   }
   return 0;
}
