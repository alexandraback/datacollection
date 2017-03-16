#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>



long long tester(long long a){
    
    a=a*a;
    
    
    if(a/10==0) {
                return(a); 
                }
    else        {
                if(a/100==0){
                             if(a/10==a%10) return(a);
                             }
                else        {
                                if(a/1000==0){
                                             if(a/100==a%10) return(a);
                                             }
                                else          {
                                              if(a/10000==0){
                                                             if(a/1000==a%10 && (a%1000)/100==(a%100)/10 ) return(a);
                                                             }
                                              else           {
                                                             if(a/100000==0){
                                                                             if(a/10000==a%10 && (a%10000)/1000==(a%100)/10) return(a);
                                                                             }
                                                             else            {
                                                                             if(a/1000000==0){
                                                                                             if(a/100000==a%10 && (a%100000)/10000==(a%100)/10 && (a%10000)/1000==(a%1000)/100) return(a);           
                                                                                              }
                                                                             else            {
                                                                                             if(a/10000000==0){
                                                                                                              if(a/1000000==a%10 && (a%1000000)/100000==(a%100)/10 && (a%100000)/10000==(a%1000)/100) return(a);
                                                                                                              }
                                                                                             else             {
                                                                                                              if(a/100000000==0){
                                                                                                                                 if(a/10000000==a%10 && (a%10000000)/1000000==(a%100)/10 && (a%1000000)/100000==(a%1000)/100 && (a%100000)/10000==(a%10000)/1000) return(a);
                                                                                                                                 }
                                                                                                              else               {
                                                                                                                                 if(a/1000000000==0){
                                                                                                                                                     if(a/100000000==a%10 && (a%100000000)/10000000==(a%100)/10 && (a%10000000)/1000000==(a%1000)/100 && (a%1000000)/100000==(a%10000)/1000) return(a);
                                                                                                                                                     }
                                                                                                                                 else                {
                                                                                                                                                    
                                                                                                                                                     if(a/10000000000LL==0){
                                                                                                                                                                           if(a/1000000000==a%10 && (a%1000000000)/100000000==(a%100)/10 && (a%100000000)/10000000==(a%1000)/100 && (a%10000000)/1000000==(a%10000)/1000 && (a%1000000)/100000==(a%100000)/10000) return(a);
                                                                                                                                                                          }
                                                                                                                                                     else                  {
                                                                                                                                                                             if(a/100000000000LL==0){
                                                                                                                                                                                                    if(a/10000000000LL==a%10 && (a%10000000000LL)/1000000000==(a%100)/10 && (a%1000000000)/100000000==(a%1000)/100 && (a%100000000)/10000000==(a%10000)/1000 && (a%10000000)/1000000==(a%100000)/10000) return(a);
                                                                                                                                                                                                     }
                                                                                                                                                                             else                   {
                                                                                                                                                                                                    if(a/1000000000000LL==0){
                                                                                                                                                                                                                            if(a/100000000000LL==a%10 && (a%100000000000LL)/10000000000LL==(a%100)/10 && (a%10000000000LL)/1000000000==(a%1000)/100 && (a%1000000000)/100000000==(a%10000)/1000 && (a%100000000)/10000000==(a%100000)/10000  && (a%10000000)/1000000==(a%1000000)/100000) return(a);
                                                                                                                                                                                                                             }
                                                                                                                                                                                                    else                     {
                                                                                                                                                                                                                              if(a/10000000000000LL==0){
                                                                                                                                                                                                                                                       if(a/1000000000000LL==a%10 && (a%1000000000000LL)/100000000000LL==(a%100)/10 && (a%100000000000LL)/10000000000LL==(a%1000)/100 && (a%10000000000LL)/1000000000==(a%10000)/1000 && (a%1000000000LL)/100000000==(a%100000)/10000  && (a%100000000)/10000000==(a%1000000)/100000) return(a);
                                                                                                                                                                                                                                                       }
                                                                                                                                                                                                                             }
                                                                                                                                                                                                    }                       
                                                                                                                                                                           }
                                                                                                                                                    
                                                                                                                                                     }
                                                                                                                                 }
                                                                                                                                 
                                                                                                              }
                                                                                             }
                                                                             }
                                                             }
                                              
                                              }
                              }
                             
                }
    
    return(0);
    
    }
    
int main(){
  int actuel,i=0,second,third,calcul,l,n;
  long long palindrome=0,T[10000],a,debut,last;
     FILE* in = NULL;
     FILE* out = NULL;
    in = fopen("C-small-0.in", "r");
    out = fopen("C-small-0.out", "w");
  while(palindrome<9){
                      palindrome++;
                      a=tester(palindrome);
                      if(a!=0){
                               T[i]=a;
                               i++;
                               }
                      }
               
                      
  palindrome=0;
  while(palindrome<99){
                       palindrome=palindrome+11;
                       a=tester(palindrome);
                      if(a!=0){
                               T[i]=a;
                               i++;
                               }
                       }

palindrome=91;
actuel=1;
while(palindrome<999){
                      palindrome=palindrome+10;
                      
                      if(palindrome/100!=actuel){
                                                 palindrome++;
                                                 actuel++;
                                                 }    
                      a=tester(palindrome);
                      if(a!=0){
                               T[i]=a;
                               i++;
                               }
                      }

palindrome=891;
actuel=1;
while(palindrome<9999){
                       palindrome=palindrome+110;
                       if(palindrome/1000!=actuel){
                                                  palindrome=palindrome-99;
                                                  actuel++;
                                                  }
                       a=tester(palindrome);
                       if(a!=0){
                               T[i]=a;
                               i++;
                               }    
                       }
           
             
 palindrome=9901;
 actuel=1;
 second=10;   
 while(palindrome<99999){
                         palindrome=palindrome+100;
                         if(palindrome/10000==actuel){
                                                      if(second!=palindrome/1000){
                                                                                  palindrome=palindrome+10;
                                                                                  second++;
                                                                                  }
                                                      }
                         else                         {
                                                      actuel++;
                                                      palindrome=actuel*10000+actuel;
                                                      second=actuel*10;
                                                      }
                        a=tester(palindrome);
                       if(a!=0){
                               T[i]=a;
                               i++;
                               }   
                         } 
                         
   palindrome=98901;
   actuel=1;
   second=10;                      
 while(palindrome<999999){
                          palindrome=palindrome+1100;
                          if(palindrome/100000==actuel){ 
                                                        if(palindrome/10000!=second){
                                                                                     palindrome=palindrome-990;
                                                                                     second++;
                                                                                     
                                                                                     }
                                                        }
                          else                          {
                                                        actuel++;
                                                        palindrome=actuel*100000+actuel;
                                                        second=actuel*10;  
                                                        }
                            a=tester(palindrome);
                       if(a!=0){
                               T[i]=a;
                               i++;
                               }  
                          }               
 
 
 palindrome=999001;
 actuel=1;
 second=10;
 third=100;
 while(palindrome<9999999){
                   palindrome=palindrome+1000;
                   if(actuel==palindrome/1000000){
                                 if(second==palindrome/100000){
                                                               if(third!=palindrome/10000){
                                                                                           palindrome=palindrome+100;
                                                                                           third++;
                                                                                           }
                                                               }
                                 else                          {
                                                               second++;
                                                               palindrome=palindrome-900;
                                                               palindrome=palindrome+10;
                                                               third=second*10;
                                                              
                                                               }
                                                  }             
                   else                          {
                                                 actuel++;
                                                 palindrome=actuel*1000000+actuel;
                                                 second=actuel*10;
                                                 third=actuel*100;
                                                 }
                       a=tester(palindrome);
                       if(a!=0){
                               T[i]=a;
                               i++;
                               }  
                   }
 
 
fscanf(in,"%d",&n);
fgetc(in);
       for(l=0;l<n;l++){calcul=0; 
                         fscanf(in,"%I64d",&debut);
                         
                         fscanf(in,"%I64d",&last);  
                         
                                    fgetc(in);
                      for(i=0;i<39;i++){
                                         if(debut<T[i]+1 && T[i]<last+1) calcul++;
                                         }
                                         
                                         
        
     fprintf(out,"Case #%d: %d",l+1,calcul); 
     
     if(l!=n) fprintf(out,"\n");            }
    fclose(in);
    fclose(out);
    
}
