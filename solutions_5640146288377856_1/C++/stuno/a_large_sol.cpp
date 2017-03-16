#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    //freopen("C:\\GCJ_1C\\in.txt", "r", stdin);
    //freopen("C:\\GCJ_1C\\a_large.in", "r", stdin);
    //freopen("C:\\GCJ_1C\\a_large.out", "w", stdout);
    int TC;
    scanf("%d", &TC);
    for(int test_case = 1; test_case<=TC; ++test_case){
        int r,c,w;
        cin >> r >> c >> w;
        int steps = c/w;
        int finishing_steps = w-1 + (c%w?1:0);
        //int one_row_res = steps + finishing_steps;
        int final_res = steps*r + finishing_steps;
        cout << "Case #" << test_case << ": "<< final_res << endl;
    }
    return 0;
}
