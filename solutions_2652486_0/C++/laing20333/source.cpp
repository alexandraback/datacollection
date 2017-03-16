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
int product[10];
int pos[6] = {};

void factor(int num){
    int tmp[10] = {};
    for(int i=5; i>=2; i--){
        while(num % i == 0){
            tmp[i]++;
            num/=i;
        }
    }
    for(int i=2; i<=5; i++){
        pos[i] = max(tmp[i], pos[i]);
    }
    return;
}
int main(){
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        freopen("C-small-1-attempt0.in", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


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
            for(int i=2; i<=5; i++){
                while(pos[i]--){
                    cout<<i;
                    cnt++;
                }
            }
            while(cnt < num){
                cout<<"2";
                cnt++;
            }
            cout<<endl;

        }
    }


    return 0;
}
