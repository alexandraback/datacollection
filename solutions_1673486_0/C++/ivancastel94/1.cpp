#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int cases,i,j,t,a,b;
    double acum,min,res,p[100002];
    cin>>t;
    cases=1;
    while(t>0){
        cin>>a>>b;
        acum=1;
        for(i=0;i<a;i++){
            cin>>p[i];
            acum=acum*p[i];
            }
        min=acum*(b-a+1)+(1-acum)*(2*b-a+2);
        for(i=a-1;i>=0;i--){
            acum=acum/p[i];
            res=acum*(b+a-2*i+1)+(1-acum)*(2*b+a-2*i+2);
            if(res<min)min=res;
            }
        res=b+2;
        if(res<min)min=res;
        printf("Case #%d: %lf\n",cases,min);
        cases++;
        t--;
        }
    //system("pause");
    }
