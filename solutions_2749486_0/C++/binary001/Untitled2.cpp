#include<fstream>
#include<cmath>
#include<cstring>

#include<iostream>
using namespace std;

char ans[505];


int main(){
    int t,x,y;
  
  
//ofstream cout("out.txt");
//ifstream cin("in.txt");
    
      
    cin>>t;
    for(int ww=1;ww<=t;ww++){
int p=0;
cin>>x>>y;

int flg=0;
if(x<0)
{
flg=1;
}      
       for(int i=0;i<abs(x);i++){
         if(flg==0)
            {ans[p++]='W';
            
                   ans[p++]='E';
            }
            else
             {ans[p++]='E';
            
                   ans[p++]='W';
            }
            
            }
            
 flg=0;
if(y<0)
{
flg=1;
}      
       for(int i=0;i<abs(y);i++){
         if(flg==0)
            {ans[p++]='S';
            
                   ans[p++]='N';
            }
            else
             {ans[p++]='N';
            
                   ans[p++]='S';
            }
            
            }
                   
       
ans[p]='\0';
cout<<"Case #"<<ww<<": "<<ans<<"\n";



}
return 0;

}
