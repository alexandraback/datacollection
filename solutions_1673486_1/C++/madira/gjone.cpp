#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<memory.h>
#include<string.h>
#include<fstream>
#include<stdio.h>
using namespace std;
double e[100003],f[100003],g[100003];
int main(){
        int t,ii;
        freopen( "A-large.in", "r", stdin );
	    freopen( "output1.out", "w", stdout );
        cin>>t;
        cin.ignore();
        for(ii=1;ii<=t;ii++){
                long int a,b,i;
                double c,d,a1,a2,ats=99999999,a3;
                cin>>a >>b;
                f[0]=1;
                e[0]=0;
                for(i=a;i>=1;i--){
                        cin>>e[i];
                        f[0]*=e[i];
                }
                g[0]=f[0];
                for(i=1;i<=a;i++){
                        f[i]=((f[i-1]/(1-e[i-1]))*(1-e[i]))/e[i];
                        g[i]=g[i-1]+f[i];
                }

                a1=f[0]*(b-a+1)+(1-f[0])*(2*b-a+2);
                if(a1<ats){ats=a1;}
                a2=b+2;
                if(a2<ats){ats=a2;}
                for(i=1;i<=a;i++){
                        a3=(b-a+2*i+1)*(f[0]+g[i]-g[0])+(b-a+2*i+1+b+1)*(1-f[0]-g[i]+g[0]);
                        if(a3<ats){ats=a3;}
                }
                printf("Case #%d: %.6lf\n",ii,ats);
        }
        return 0;
}
