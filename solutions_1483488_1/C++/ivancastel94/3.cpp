#include<iostream>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int k,i,j,a,b,m,t,cases,d[20];
    set<int> numeros;
    long long int num;
    scanf("%d",&t);
    d[0]=1;
    for(i=1;i<10;i++)d[i]=d[i-1]*10;
    for(cases=1;cases<=t;cases++){
        scanf("%d %d",&a,&b);
        num=j=0;
        while(d[j]<=a)j++;
        for(i=a;i<b;i++){
            for(k=1;k<j;k++){
                m=(i%d[k])*d[j-k]+int(i/d[k]);
                if((m>i)&&(m<=b))numeros.insert(m);
                }
            num=num+numeros.size();
            numeros.clear();
            }
        cout<<"Case #"<<cases<<": "<<num<<endl;
        }
    }
