#include<iostream>
#include<math.h>
using namespace std;
int T;
//char num1[5];
//char num2[5];
//bool flag; 
int a,b,c,cnt;
int lenk;
bool f[10005];
int ans[1000][2];

int _pow(int b,int m)
{
   for(int i=1;i<=m-1;i++)
   b*=10;
  // cout<<b<<endl;
   return b;    
    
}

int len(int num)
{
    int i;
    for(i=3;i>=0;i--)
    {
       if(num/(_pow(10,i))>0)
       break;
    }    
    return i+1;
}

bool search(int kk, int cc)
{
     for(int i=cnt-1;i>=0;i--)
     {
         if(ans[i][0]==kk)
         {   
             if(ans[i][1]==c)
             return false;
         }
         else 
         return true;
     }
}

int main()
{
    freopen("inc.txt","r",stdin);
    freopen("outc.txt","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++)
    { 
       cnt=0;
       //memset(f,false,sizeof(f));
       memset(ans,0,sizeof(ans));
       //flag=0;
       cin>>a>>b;
       for(int k=a;k<=b;k++)
       {  
         // if(!f[k])     
          //{   
              lenk=len(k);
              //cout<<lenk;
              for(int j=1;j<lenk;j++)
              {
              
                  c=(k%(_pow(10,lenk-j)))*_pow(10,j)+(k/(_pow(10,lenk-j)));
                  //cout<<c<<endl;
                  if(c<=b&&c>=a&&c!=k&&c>k&&search(k,c))
                     //if(f[c]&&f[k]) continue;
                     //else
                     {
                        //f[c]=true;
                       // f[k]=true;
                        ans[cnt][0]=k;
                        ans[cnt][1]=c;
                        //cout<<cnt+1<<": "<<(k%(_pow(10,lenk-j)))<<" "<<(k/(_pow(10,lenk-j)))<<" "<<k<<" "<<c<<endl;
                        cnt++;
                     }      
               
              }
          //}
         // else continue;
       
        }
        /*//int cnt2=0;
        for(int k=a;k<=b;k++)
        if(f[k])
        {
          cout<<k<<endl;
          //cnt2++;
        }
       // cout<<cnt2<<endl;*/
        cout<<"Case #"<<i<<": "<<cnt<<endl;
    }
    return 1;   

}    
