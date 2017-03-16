#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t, it=1,r,n,m,k,foo,i;
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d%d%d%d",&r,&n,&m,&k);
             int a[k];
             printf("Case #%d:\n",it++);
              while(r--)
              {
                        int ctr2=0;
                        int ctr3=0, ctr5=0,x;
             
                        for(i=0;i<k;i++)
                        {
                         scanf("%d",&a[i]);
                         }
                         
                         sort(a,a+k);
                         
                         foo = a[k-1];
                         //cout<<foo<<endl;
                         while(foo%5==0)
                         {
                             ctr5++;
                             foo=foo/5;
                             }
                             
                             while(foo%3==0)
                             {
                              ctr3++;
                              foo=foo/3;
                              }
                              
                              while(foo %2 ==0)
                              {
                                     ctr2++;
                                     foo=foo/2;
                              }
                              
                              x= ctr5+ctr3;
                              
                              if(x==3){
                                      for(i=0;i<ctr5;i++)
                                      cout<<"5";
                                      for(i=0;i<ctr3;i++)
                                      cout<<"3";
                                      }
                              if(x==2)
                              {
                                      for(i=0;i<ctr5;i++)
                                      cout<<"5";
                                      for(i=0;i<ctr3;i++)
                                      cout<<"3";
                                    if(ctr2==1)
                                    {
                                        cout<<"2";
                                        }
                                        else
                                        cout<<"4";
                              }
                              
                              if(x==1)
                              {
                                    for(i=0;i<ctr5;i++)
                                      cout<<"5";
                                      for(i=0;i<ctr3;i++)
                                      cout<<"3";
                                      
                                      if(ctr2==1)cout<<"22";
                                      if(ctr2==2)cout<<"22";
                                      if(ctr2==0)cout<<"24";
                                      else
                                        cout<<"24";
                              }
                              if(x==0)
                              {
                                      cout<<"222";
                                      
                                      }
                                      
                          cout<<endl;
                          }
              }
              return 0;
              }                                  
                                                
                        
