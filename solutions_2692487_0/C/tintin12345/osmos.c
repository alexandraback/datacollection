#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int find_oper(int *m, int n, int a,int pos){
    int temp,x,y;
    if(pos==n)return 0;
    if(a>m[pos]){
        a=a+m[pos];
        pos++;
        return find_oper(m,n,a,pos);
    }
    else{
        x = 1+find_oper(m,n-1,a,pos);
        if(a==1)return x;
        y = 1+find_oper(m,n,a+a-1,pos);
        if(x<y)return x;
        else return y;
    }
}

int main() {

    int T;
    cin>>T;

    int i,a,n,j,k,temp;
    int m[1001];
    for(int i=1;i<=T;i++){
        cin>>a;
        cin>>n;
        for(j=0;j<n;j++)cin>>m[j];
        for(j=0;j<n-1;j++){
            for(k=j+1;k<n;k++){
                if(m[j]>m[k]){
                    temp=m[j];
                    m[j]=m[k];
                    m[k]=temp;
                }
            }
        }
        printf("Case #%d: %d\n",i,find_oper(m,n,a,0));
    }

    return 0;
}
