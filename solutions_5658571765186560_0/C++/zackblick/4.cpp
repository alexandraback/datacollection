#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<cmath>

using namespace std;

int main()
{

    freopen("in4.txt", "r", stdin);
  freopen("4.txt", "w", stdout);
 int i,t,a1,b1,c1;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d %d %d",&a1,&b1,&c1);
        printf("Case #%d: ",i);
        if((b1*c1)%a1){
            printf("RICHARD\n");
        }else{
            if(a1<=2){
                printf("GABRIEL\n");
            }else if(a1==3){
                if(b1*c1==3) printf("RICHARD\n");
                else printf("GABRIEL\n");
            }else{
                if(b1*c1==4) printf("RICHARD\n");
                if(b1*c1==8) printf("RICHARD\n");
                if(b1*c1==12) printf("GABRIEL\n");
                if(b1*c1==16) printf("GABRIEL\n");
            }
        }
    }
}


          