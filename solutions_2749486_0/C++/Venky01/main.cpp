#include <fstream>
#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");
    int t;
    input>>t;
    int p=1;
    int x,y;
    for(int i=1;i<=t;i++)
    {
            output<<"Case #"<<p<<": ";
            input>>x>>y;
            
            int tempX=0;
            int tempY=0;
            string s="";
            int flag=1;
            
            int m=1;
            while(tempX != x){
                if(flag == 1){
                   s=s+"E";
                   tempX+=m;
                }else{
                   s=s+"W";
                   tempX-=m;
                }
                m++;
                flag = flag*-1;
            }
            
            
            flag = 1;
            if(y>0){ 
               flag = -1;
            }
            cout<<m;
            
            int n=m;
            while(tempY != y){
                if(flag == 1){
                   s=s+"N";
                   tempY+=n;
                }else{
                   s=s+"S";
                   tempY-=n;
                }
                n++;
                flag = flag*-1;
            }
            
            output<<s<<endl;
            p++;        
    }
    system("pause");
    return 0;   
}
