#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int T, R, N, M, K;
int p[4] = {2, 3, 5, 7};
int pro;
int factor_num[4][10];

multiset<int> ans;

void depart(int pro)
{
    int ptr = 0, num;
    while(pro != 1){
        num = 0;
        while(pro % p[ptr] == 0){
            num ++; pro = pro/p[ptr];
        }
        factor_num[ptr][num] = 1;
        ptr ++ ;
        //printf("%d %d %d\n", pro, ptr, num);
    }
}

int main()
{
    //freopen("C.in", "r", stdin);
    //freopen("C.out","w", stdout);
    cin >> T;
    for(int Case = 1; Case <= T; Case ++){
        cout<<"Case #1:"<<endl;
        cin >> R >> N >> M >> K;
        for(int i = 0; i < R; i++){
            ans.clear();
            memset(factor_num, 0, sizeof(factor_num));
            for(int k = 0; k < K; k++){
                cin >> pro;
                depart(pro);
            }
            /*for(int i=0; i<4; i++, puts(""))
                for(int j=0; j<10; j++)
                    printf("%d", factor_num[i][j]);*/

            for(int i=1; i<4; i++)
                for(int j=10; j>=0; j--)
                    if(factor_num[i][j]){
                        for(int kk = 0; kk < j; kk++)
                            ans.insert(p[i]);
                        break;
                    }
            for(int i = 1, two = 2; i < 5; i++, two *= 2){
                if(factor_num[0][i]){
                    ans.insert(two);
                    break;
                }
            }
            while(ans.size() < N)ans.insert(2);
            for(multiset<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
                cout<<*iter;
            cout<<endl;
        }
    }
    return 0;
}
