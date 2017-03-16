#include <cstdio>
#include <iostream>
using namespace std;
#define uint unsigned int

int TC, A, B, K;

int main(){

    scanf("%d",&TC);
    for(int tc=1; tc<=TC; ++tc){

        scanf("%d %d %d",&A,&B,&K);
        int res=0;
        for(int a=0; a<A; ++a){
            for(int b=0; b<B; ++b){
                //cout<<a<<' '<<b<<endl;
                if( (a&b) < K && (a&b) >= 0 ){
                    ++res;
                }
            }
        }
        printf("Case #%d: %d\n",tc,res);

    }
    return 0;
}
