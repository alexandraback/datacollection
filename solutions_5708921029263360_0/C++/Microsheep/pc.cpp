#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main(){
    int T=0,k=1;
    cin >> T;
    while(T--){
        int J,P,S,K;
        cin >> J >> P >> S >> K; 
        //cout << "!!! " << J << " " << P << " " << S << " " << K << endl;
        
        int minn=min(S,K);
        int ans=J*P*minn;
        cout << "Case #" << k << ": " << ans << endl;
        int test[1100];
        memset(test,0,sizeof(test));
        for(int x=0;x<P;x++){
            for(int y=0;y<S;y++){
                test[10*x+y]=minn;
            }
        }
        for(int a=0;a<J;a++){
            for(int b=0;b<P;b++){
                for(int c=0;c<minn;c++){
                    int tmp_c=0,tmp_max=-1;
                    for(int d=10*b;d<10*(b+1);d++){
                        if(test[d]>tmp_max){
                            tmp_c=d;
                            tmp_max=test[d];
                        }
                    }
                    test[tmp_c]--;
                    /* 
                    cout << "& " << tmp_c << endl;
                    cout << "@ ";
                    for(int gg=0;gg<10*P+S;gg++){
                        cout << test[gg] << " ";
                    }
                    cout << endl;
                    */
                    cout << a+1 << " " << b+1 << " " << (tmp_c%10)+1 << endl;
                }
            }
        }
        



        k++;
    }
    return 0;
}

