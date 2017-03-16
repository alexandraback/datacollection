#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int t,c;
    cin>>t;
    c=1;
    int n,m,k;
    while(c<=t)
    {
        cin>>n>>m>>k;
        if( n>m){
            int mid = n;
            n=m;
            m=mid;
        }
        if( n<=2 || k<=4)
            cout<<"Case #"<<c<<": "<<k<<endl;
        else {
            int num;
            if(n==3){
                if(m==3){
                    if(k==5)
                        num=4;
                    else
                        num=k-1;
                }
                else if(m==4){
                    if(k==5)
                        num=4;
                    else if(k>=6 && k<=7)
                        num=k-1;
                    else if(k>=8)
                        num=k-2;
                }
                else if(m==5){
                    if(k==5)
                        num=4;
                    else if(k>=6 && k<=7)
                        num=k-1;
                    else if(k>=8 && k<=10)
                        num=k-2;
                    else
                        num=k-3;
                }
                else if(m==6){
                    if(k==5)
                        num=4;
                    else if(k>=6 && k<=7)
                        num=k-1;
                    else if(k>=8 && k<=10)
                        num=k-2;
                    else if(k>=11 && k<=13)
                        num=k-3;
                    else
                        num=k-4;
                }
            } else if(n==4) {
                if(m==4){
                    if(k==5)
                        num=4;
                    else if(k>=6 && k<=7)
                        num=k-1;
                    else if(k>=8 && k<=9)
                        num=k-2;
                    else if(k>=10 && k<=11)
                        num=k-3;
                    else 
                        num=k-4;
                }
                else if(m==5) {
                    if(k==5)
                        num=4;
                    else if(k>=6 && k<=7)
                        num=k-1;
                    else if(k>=8 && k<=9)
                        num=k-2;
                    else if(k>=10 && k<=11)
                        num=k-3;
                    else if(k>=12 && k<=13)
                        num=k-4;
                    else if(k>=14 && k<=15)
                        num=k-5;
                    else 
                        num=k-6;
                }
            }

            cout<<"Case #"<<c<<": "<<num<<endl;
        }
        c++;
    }
    return 0;
}

