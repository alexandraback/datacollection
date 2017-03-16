#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main(){
    int T=0,k=1;
    cin >> T;
    int all[3000];
    while(T--){
        memset(all,0,sizeof(all));
        int N=0;
        cin >> N;
        for(int a=0;a<2*N-1;a++){
            for(int b=0;b<N;b++){
                int tmp;
                cin >> tmp;
                all[tmp]++;
            }
        }
        int ans[100],now=0;
        memset(ans,0,sizeof(ans));
        for(int a=0;a<2550 && now<N;a++){
            if(all[a]%2!=0){
                ans[now++]=a;
            }
        }
        sort(ans,ans+now);
        cout << "Case #" << k << ":";
        for(int a=0;a<now;a++){
            cout << " " << ans[a];
        }
        cout << endl;
        k++;
    }
    return 0;
}
