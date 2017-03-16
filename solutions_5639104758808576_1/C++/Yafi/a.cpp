#include <iostream>
#include <cstdio>
using namespace std;


int T;
int n;
char inp[10000];
int seat[1005];

int main(){
    scanf("%d",&T);
    for(int tc = 0; tc < T; tc++){
        int clapnow = 0;
        int ans = 0;
        scanf("%d%s",&n,inp);
        for(int i = 0; i <= n; ++i){
            seat[i] = inp[i] - '0';
            
            //autoclap
            if (i == 0){
                clapnow += seat[i];
            } else {
                int needed = i;

                if (clapnow >= needed){
                    //no need
                } else {
                    int friends = (needed - clapnow);
                    clapnow += friends;
                    ans += friends;
                }
                //in the end, this member will clap
                clapnow += seat[i];
            }
        }
        printf("Case #%d: %d\n",(tc + 1),ans);
    }
    return 0;
}