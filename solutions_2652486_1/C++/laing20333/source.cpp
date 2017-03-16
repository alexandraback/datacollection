#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>
#include<cmath>
#include<memory.h>
#include<sstream>
#include<queue>
#include<time.h>

using namespace std;
typedef long long ll;
int product[15];
int pos[9] = {};

void factor(int num){
    int tmp[10] = {};
    for(int i=8; i>=2; i--){
        while(num % i == 0){
            tmp[i]++;
            num/=i;
        }
    }
    for(int i=2; i<=8; i++){
        pos[i] = max(tmp[i], pos[i]);
    }
    return;
}
int main(){
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        freopen("C-small-2-attempt4.in", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    srand(time(NULL));
    int T;
    while(cin>>T){
        printf("Case #1:\n");
        int ntest;
        int num, max_num, nproduct;
        cin>>ntest>>num>>max_num>>nproduct;
        for(int tt=1; tt<=ntest; tt++){
            memset(pos, 0, sizeof(pos));
            for(int i=0; i<nproduct; i++){
                cin>>product[i];
            }
            for(int i=0; i<nproduct; i++){
                if(product[i] == 1){
                    continue;
                }
                factor(product[i]);
            }
            int cnt = 0;
            while(cnt < num){
                int isok = 0;
            for(int i=2; i<=8; i++){
                if(rand()%2 && pos[i] > 0){
                    pos[i]--;
                    cout<<i;
                    cnt++;
                }




            }
             for(int i=2; i<=8; i++){
                    if(pos[i]){
                        isok =1;
                        break;
                    }
                }
                if(!isok){
                    break;
                }

            }
            while(cnt <num){
                for(int i=2; i<=8; i++){
                    if(rand()%2 ){

                        cout<<i;
                        cnt++;
                    }

                }
            }

            cout<<endl;

        }
    }


    return 0;
}
