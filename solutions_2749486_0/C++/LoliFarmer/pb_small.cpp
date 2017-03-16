#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char str[1000010];

long long int LL[1000010];
long long int RR[1000010];

int main(){
    int T,p;
    scanf("%d",&T);
    int x,y;
    for(int f = 1; f<=T ; f++){
        scanf("%d %d",&x,&y);
        int st = 1;
        printf("Case #%d: ",f);
        if(x>0){
            printf("E");
            for(int i=1;i<x;i++){
                printf("WE");
            }
            st = 0;
        }else if(x<0){
            x = -x;
            printf("W");
            for(int i=1;i<x;i++){
                printf("EW");
            }
            st = 0;
        }
        if(y>0){
            if(st){
                printf("N");
            }
            for(int i=st;i<y;i++){
                printf("SN");
            }
        }else if(y<0){
            y = -y;
            if(st){
                printf("S");
            }
            for(int i=st;i<y;i++){
                printf("NS");
            }
        }
        puts("");
    }
    return 0;
}
