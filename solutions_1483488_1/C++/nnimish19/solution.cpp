#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<cmath>
#define intin(a) scanf("%d",&a)
#define intsin(a,b) scanf("%d%d",&a,&b)
#define swap(a,b) c=a;a=b;b=c
#define MIN(a,b) a<b?a:b
using namespace std;
int main()
{
    freopen("C-large.in","r",stdin);
    ofstream file1("output.txt");
    int cases,x=0,a,b,n,m;
    int digits,pt,temp,j,k,a1[20];
    long long int cnt;
    intin(cases);
    while(++x<=cases)
    {
        intsin(a,b);cnt=0;

        for(n=a;n<b;n++)
        {
            digits=log10(n)+1;
            j=0;
            for(int i=digits-1;i>=1;i--)
            {
                pt=pow(10,digits-i);
                temp=n%pt *pow(10,i)+n/pt;
                if(temp>n && temp<=b )
                {
                    a1[j]=temp;
                    for(k=0;k<=j-1;k++)
                        if(a1[k]==temp)
                            break;
                    if(k==j)
                        cnt++;
                    j++;
                }
            }
        }
        //cout<<cnt<<endl;
        file1<<"Case #"<<x<<": "<<cnt<<endl;
    }
}
