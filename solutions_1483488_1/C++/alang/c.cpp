#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef pair<int,int> pp; 
set<pp> ss;
int main() {
 
   
        
        int N;
        cin>>N;
        int count=1;
        while(N--)
        {
             ss.clear();  
             char test[100];
             string A,B;
             int nA,nB;
             cin>>nA>>nB;
             sprintf(test,"%d",nA);
             A=string(test);
             sprintf(test,"%d",nB);
             B=string(test);

             int TLen=A.size();
             int dA[8],dB[8];
             for(int i=0;i<TLen;i++)
             {
            	 dA[i]=A[i]-'0';
            	 dB[i]=B[i]-'0';
             }
             int tnum=0;
             for(int k=nA;k<nB;k++)
             {
            	 char buff[255];
                 sprintf(buff,"%d",k);
            	 int dK[8];
            	 for(int i=0;i<TLen;i++)
            	 {
            	  	 dK[i]=buff[i]-'0';
            	 }
            	 
            	 for(int i=1;i<TLen;i++)
            	 {
                         int oo=0;
            		 bool same=true;
                         int j=0;
                         int lessB=1;
                         int moreN=1;
            		 for(;j<TLen;j++)
            		 {
            			 int mi=(i+j)%TLen;
                                 oo=oo*10+dK[mi];
                                 if(lessB==2&&moreN==2)
                                     break;
                                 if(lessB!=2)
                                 { 
                                     if(dK[mi]<dB[j])
                                         lessB=2;
                                     else if(dK[mi]>dB[j])
                                     {
                                         lessB=0;
                                         break;
                                     }    
                                 }
                                  if(moreN!=2)
                                 {
                                     if(dK[mi]>dK[j])
                                         moreN=2;
                                     else if(dK[mi]<dK[j])
                                     {
                                         moreN=0;
                                         break;
                                     }
                                 }

            		 }
                         if(lessB!=0&&moreN==2)
                         {
                            for(;j<TLen;j++)
                            {
                                 int mi=(i+j)%TLen;
                                 oo=oo*10+dK[mi];
                            }
                            ss.insert(make_pair(k,oo)); 
                         }
            	 }
            	 
             }
             
             

             cout<<"Case #"<<count++<<": "<<ss.size()<<endl;
         }



        return 0;
}
