#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
char buff[100];
int main(){
    int T;
    scanf("%d", &T);
    for(int t=0;t++<T;){
        long long P, Q;
        scanf("%s",buff);
        //printf("%s\n",buff);
        char* second;
        for(int i=0;i<100;i++){
            if(buff[i]=='/'){
                buff[i] = '\0';
                second=buff+i+1;
            }
        }
        //printf("%s\n",buff);
        sscanf(buff,"%lld",&P);
        cerr << P << endl;
        sscanf(second,"%lld",&Q);
        cerr << Q << endl;
        if(P==1&&Q==1){
            printf("Case #%d: 0\n",t);
            continue;
        }
        while((P%2)&&(Q%2)){
            P/=2;Q/=2;
        }
        long long tmp=1;
        
        while(!(Q%tmp)){
            tmp*=2;
        }
        tmp/=2;
        if(tmp != Q){
            long long tmp2=Q/tmp;
            if(P%tmp2){
                printf("Case #%d: impossible\n",t);
                continue;
            }else{
                P/=tmp2;
                Q/=tmp2;
            }
                
        }


        tmp=1;
        
        while(tmp < Q)
            tmp*=2;
        if(tmp != Q){
            printf("Case #%d: impossible\n",t);
            continue;
        }
        tmp = Q;
        for(int i=0;;i++){
            if(tmp <= P){
                printf("Case #%d: %d\n", t, i);
                break;
                }
            tmp/=2;
        }
    }
}
