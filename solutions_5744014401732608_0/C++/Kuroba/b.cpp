#include <bits/stdc++.h>
using namespace std;

int T;


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas<=T; cas++){
        printf("Case #%d: ", cas);
        long long B, M;
        scanf("%lld%lld", &B, &M);

        long long hi;


        hi = 1;
        for(int i = 0; i<B-2; i++){
            hi *= 2;
        }


        if (M > hi) printf("IMPOSSIBLE\n");
        else{
            printf("POSSIBLE\n");
            if (M == hi){ // first row
                printf("0");
                for (int i = 1; i < B; i++){
                    printf("1");
                }
                printf("\n");
            }
            else{
                string s = "";
                long long k = M;
                for(int i = 0; i<B-2; i++){
                    if (k%2 == 1){
                        s = "1" + s;
                    }
                    else{
                        s = "0" + s;
                    }
                    k/=2;
                }
                cout << "0" << s << "0" << endl;
            }


            // print triangle
            for(int i = B-2; i>=0; i--){
                for (int j = i; j < B; j++){
                    printf("0");
                }
                for (int j = 0; j < i; j++){
                    printf("1");
                }
                printf("\n");
            }


        }



    }


}
