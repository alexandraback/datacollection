#include<iostream>
#include<cmath>
#include<string.h>
#include<stdio.h>
using namespace std;

int t;
int l;
long long x;
char s[10011];
int d[100011];


int map[5][5]={0,0,0,0,0,0,1,2,3,4,0,2,-1,4,-3,0,3,-4,-1,2,0,4,3,-2,-1};

int main()
{
    int i,j,k,times;
    int p,q;
    int temp;
    int u;
    int xx,yy;
    
    freopen("C-small-attempt0.in","r",stdin);
    freopen("ans.out","w",stdout);
    
    cin>>t;
    
    for(times=1;times<=t;times++)
    {
        cin>>l>>x;
        cin>>s;
        
        for(i=0;i<l;i++)
        {
            d[i]=s[i]-'i'+2;
        }
        
        
        if(x<=10)
        {
            k=l;
            for(i=1;i<=x;i++)
            {
                for(j=0;j<l;j++)
                {
                    d[k]=d[j];
                    k++;
                }
            }
            
            l=l*x;
            
            temp=d[0];
            u=1;
            for(i=1;i<l;i++)
            {
                //cout<<u<<' '<<temp<<' '<<d[i]<<endl;
                temp=map[temp][d[i]];
                
                if(temp<0)
                {
                    temp=-temp;
                    u=-u;
                }
            }
            
            if(u!=-1 || temp!=1)
            {
                cout<<"Case #"<<times<<": NO"<<endl;
                continue;
            }
            //cout<<")(*&^%$"<<endl;
            
            
            p=1;q=l-2;
            temp=d[0];
            u=1;
            
            if(temp!=2)
            {
            while(p<q)
            {
                
                temp=map[temp][d[p]];
                
                if(temp<0)
                {
                    temp=-temp;
                    u=-u;
                }
                
                if(u==1 && temp==2)break;
                
                p++;
            }
            }
            else
            {
                p=0;
            }
            
            temp=d[l-1];
            u=1;
            
            if(temp!=4)
            {
            while(p<q)
            {
                temp=map[d[q]][temp];
                if(temp<0)
                {
                   temp=-temp;
                   u=-u;
                }
                
                if(u==1 && temp==4)break;
                
                q--;
            }
            }
            else
            {
               q=l-1;
            }
            
            if(p<q)
            {
                cout<<"Case #"<<times<<": YES"<<endl;
            }
            else
            {
                cout<<"Case #"<<times<<": NO"<<endl;
            }
            
        }
        else
        {
            temp=d[0];
            u=1;
            for(i=1;i<l;i++)
            {
                temp=map[temp][d[i]];
                
                if(temp<0)
                {
                    temp=-temp;
                    u=-u;
                }
            }
            
            if(temp==1 && u==1)
            {
               cout<<"Case #"<<times<<": NO"<<endl;
               continue;
            }
            else if(temp==1 && u==-1)
            {
               if(x%2==0)
               {
                   cout<<"Case #"<<times<<": NO"<<endl;
                   continue;
               }
            }
            else if(x%4!=2)
            {
                cout<<"Case #"<<times<<": NO"<<endl;
                continue;
            }
            
            
            k=l;
            for(i=1;i<=4;i++)
            {
                for(j=0;j<l;j++)
                {
                    d[k]=d[j];
                    k++;
                }
            }
            
            l=l*4;
            
            
            p=1;q=l-2;
            temp=d[0];
            u=1;
            
            if(temp!=2)
            {
            while(p<=l-1)
            {
                
                temp=map[temp][d[p]];
                
                if(temp<0)
                {
                    temp=-temp;
                    u=-u;
                }
                
                if(u==1 && temp==2)break;
                
                p++;
            }
            }
            else
            {
                p=0;
            }
            
            temp=d[l-1];
            u=1;
            
            if(temp!=4)
            {
            while(0<=q)
            {
                temp=map[d[q]][temp];
                if(temp<0)
                {
                   temp=-temp;
                   u=-u;
                }
                
                if(u==1 && temp==4)break;
                
                q--;
            }
            }
            else
            {
                q=l-1;
            }
            
            if(p<=l-1 && q>=0)
            {
                cout<<"Case #"<<times<<": YES"<<endl;
            }
            else
            {
                cout<<"Case #"<<times<<": NO"<<endl;
            }
            
            
        }
    }
    
    
    return 0;
}
