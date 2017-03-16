#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<cmath>

using namespace std;

int main() {

    int T;
    cin>>T;

    int n,len,n_val,j,k,temp,l;
    char * str;
    str=(char *)malloc(1000*sizeof(char));
    for(int i=1;i<=T;i++){
        scanf("%s",str);
        scanf("%d",&n);
        len = strlen(str);
        n_val = 0;
        for(j=0;j<len;j++){
            temp = 0;
            for(k=j;k<len;k++){
                temp=0;
                for(l=j;l<=k;l++){
                if(str[l]=='a' || str[l]=='e' || str[l]=='i' || str[l]=='o' || str[l]=='u'){
                    temp=0;
                }
                else{
                    temp++;
                }
                if(temp==n){
                    n_val++;
                    break;
                }
                }
            }
        }
        printf("Case #%d: %d\n",i,n_val);
    }

    return 0;
}
