#include<stdio.h>
#include <queue>  
#include<iostream>
//bfs idea...

//dp idea

using namespace std;


int main()
{
  //  freopen ("A_out.txt","w",stdout);
   // freopen ("A-small-attempt1.in","r",stdin);
    int t,cas=0;
    int r,c,w;
  
   cin>>t;
    int ans;
    
    while(cas++<t)
    {
          cin>>r>>c>>w;
          ans = 0;
          
          int ct[21]={0};
          ct[c]=r;
          int mx = c;
          while(1)
          {
                  

                  
                 ans++;
                 
               //  for(int j=0;j<=c;j++)cout<<" "<<ct[j];
               //  cout<<"\nans="<<ans<<endl;
                 
                 ct[mx]--;
                 ct[(mx-1)/2]++;
                 ct[(mx-1)-(mx-1)/2]++;
                 
                 int big = 0;
                 for(int j=w;j<=c;j++)
                 big+=ct[j];
                 
                /* if(ct[mx]==0 && big ==0)
                 {
                        //      puts("here1");
                     if(mx==w)ans+=w-1;
                     else ans+=w;
                      break;
                 }*/
                 
                 if(ct[mx]==0 && mx<=2*w && big==0)
                 {
                              // puts("here2");
                      if(mx==w)ans+=w-1;
                      else ans+=w;
                      break;
                 }
                 else if(ct[mx]==0)
                 {
                     //new mx
                  //   cout<<"mx="<<mx<<endl;
                     while(!ct[mx])
                     {
                                   mx--;
                                  // cout<<"\tmx="<<mx<<endl;
                     }
                     
                 }
              //   scanf("%*d");
          }
          
          
          printf("Case #%d: %d\n",cas,ans);
    }
    scanf("%*d");
    return 0;  
}
