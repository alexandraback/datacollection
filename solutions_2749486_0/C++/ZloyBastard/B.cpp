#include <iostream>
#include <algorithm>
#define TASK "B"
#define Small "-small-attempt"
#define NUM "0"
#include <string>
#include <map>
#include <set>

using namespace std;

int test;
int n;
int x,y;

void readinput(){
    scanf("%i %i",&x,&y);    
}

void solve(){
    
}

void writeoutput(int t){
    printf("Case #%i: ",t+1);        
    if (x>0)
    {
        for (int i=0;i<x;i++){
            printf("WE");    
        }    
    }else{
        for (int i=0;i<-x;i++){
            printf("EW");    
        }
    }
    if (y>0)
    {
        for (int i=0;i<y;i++){
            printf("SN");    
        }    
    }else{
        for (int i=0;i<-y;i++){
            printf("NS");    
        }
    }
    
    printf("\n");
}

int main(void){
    //freopen("input.txt","r",stdin);    
    freopen(TASK""Small""NUM".in","r",stdin);
    //freopen(TASK"-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%i\n",&test);

    for (int i=0;i<test;i++){
        readinput();
        solve();
        writeoutput(i);
    }
    
    return 0;    
}
