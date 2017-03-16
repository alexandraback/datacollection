#include <iostream>
#include <cstdio>
using namespace std;

bool bit[32];

int generatingRecursion(int n,int id,int j){
    if(id<4&&j>0){
        for(int i=n-1;i>=0;i--){
            printf("%d",(int)bit[i]);
        }
        puts(" 3 7 5 6 31 8 27 5 77");
        return 1;
    }
    int done = generatingRecursion(n,id-1,j);
    if(done!=j&&!bit[id]&&!bit[id-3]){
        bit[id] = bit[id-3] = 1;
        done += generatingRecursion(n,id-1,j-done);
        bit[id] = bit[id-3] = 0;
    }
    return done;
}

void generateWith1001(int n,int j){//
    if(n<8){
        printf("can generate with n<8\n");
        return;
    }
    for(int i=0;i<32;i++) bit[i] = 0;
    bit[0] = bit[3] = bit[n-1] = bit[n-4] = 1;
    int get = generatingRecursion(n,n,j);
    if(get!=j) printf("can only generate %d\n",get);
}

int main()
{
    puts("Case #1:");
    generateWith1001(32,500);
    return 0;
}
