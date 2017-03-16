#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin("C-small-attempt1.in");
ofstream fout("output.txt");
int sumofsub(int x[],int w[],int s,int k,int r,int m,int* count,int n,int c[])
{
    
    int z;
    if(k>=n)
    return 0;
    if(*count==2)
    return 1;
    x[k]=1;
    
    
    //fout<<w[k]<<" "<<m<<" "<<s<<" "<<*count<<endl;
  //  system("pause");
    if((s+w[k])==m)
    {
                //   cout<<"first"<<endl;
                   (*count)=*count+1;
                  // cout<<"count "<<*count<<endl;
                   if(*count==1)
                   {
                         for(int z=0;z<n;z++)
                         c[z]=x[z];     
                                           
                               }   
                               if((*count)==2)
                               {
                                              int s=0;
                                            //  cout<<"yes"<<endl;
                                           for(z=0;z<n;z++)
                                           if(c[z]==1)
                                           {
                                                      s=s+w[z];
                                                      if(s<=m)
                                                       fout<<w[z]<<" ";
                                                       }
                                           fout<<endl;
                                           s=0;
                                           for(z=0;z<n;z++)
                                           if(x[z]==1)
                                           {
                                                      s=s+w[z];
                                                      if(s<=m)
                                                 fout<<w[z]<<" ";
                                                 }
                                           fout<<endl;
                                           return 1;
                                           }                 
                           }
        else if((s+w[k]+w[k+1])<=m)
        {
    //         cout<<"second"<<endl;
             
        sumofsub(x,w,s+w[k],k+1,r-w[k],m,count,n,c);
        }
       if(((s+r-w[k])>=m)&&((s+w[k+1])<=m))
        {
      //                                       cout<<"third"<<endl;
                                            
                                            x[k]=0;
                                            sumofsub(x,w,s,k+1,r-w[k],m,count,n,c);
                                            }                           
}
int main()
{
    
int t,sum,n,ar[1000],x[1000],i,l,cl[1000],c,p=1,flag;
int *count;    
    fin>>t;
    while(t--)
    {
              flag=0;
              count=(int *)malloc(sizeof(int));
              sum=0;
              fin>>n;
              for(i=0;i<n;i++)
              {fin>>ar[i];
              sum=sum+ar[i];
              x[i]=0;
              }
              
              sort(ar,ar+n);
              fout<<"Case #"<<p<<":"<<endl;
              c=0;            
              for(i=1;i<sum;i++)
              {
                                for(l=0;l<n;l++)
                                {x[l]=0;
                                cl[l]=0;
                                }
                                *count=0;
                                                                  
                               c=sumofsub(x,ar,0,0,sum,i,count,n,cl);
                              if((*count)==2)
                               {
                               //fout<<"hello "<<flag<<endl;
                               flag=1;
                               break;
                               }
                               }
                               
                                
                               if(flag!=1)
                               fout<<"Impossible"<<endl;
p++;              
              
}
return 0;
}
