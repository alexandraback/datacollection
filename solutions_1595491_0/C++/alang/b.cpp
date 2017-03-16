
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <string>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;



int main() {
 
   
        
        int N;
        cin>>N;
        int count=1;
        while(N--)
        {
             int T,S,P;
             cin>>T>>S>>P;
             int score[200];
             for(int i=0;i<T;i++)
            	 cin>>score[i];
             
             int cross=0,nok=0;
             
             for(int k=0;k<T;k++)
             {
                 if(score[k]==0)
                 {
                    if(P==0)
                        nok++;
                    continue;
                 }
            	 int i=score[k]/3;
            	 int j=score[k]%3;
            	 int nmax=0,nmin=0;
            	 if(j==1)
            	 {
            		 nmax=nmin=i+1;
            	 }
            	 else if(j==0)
            	 {
            		 nmax=i+1;
            		 nmin=i;
            	 }
            	 else
            	 {
            		 nmax=i+2;
            		 nmin=i+1;
            	 }
            	 
            	 if(nmin>=P)
            		 nok++;
            	 else
            	 {
            		 if(nmax>=P)
            			 cross++;
            	 }
             }

             cout<<"Case #"<<count++<<": "<<(nok+min(cross,S))<<endl;
         }



        return 0;
}
