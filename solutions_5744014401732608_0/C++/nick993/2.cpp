#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define rep(i,a,b) for(int i=a;i<b;i++)

using namespace std;


int nummat[6];
int msize;
bool cal ;
int target_ways;
int mat[6][6];
bool ans_found;


void convert_to_mat() {
    memset(mat,0,sizeof mat);
    cal = true;
    rep(i,0,msize) {
        int tmp = nummat[i];
        rep(j,0,msize) {
             mat[i][msize-1-j]= (tmp%2);
             tmp/=2;
        }
        if(mat[i][i] == 1){
            cal = false;
            return;
        }
    }


}

int dp[7];

int count_num_ways(int x) {
    int res = 0;
    if(cal == false)
        return -1;
    if(x== (msize-1))
        return 1;
    if(dp[x]!=-1)
            return dp[x];
    for(int i=0; i<msize;i++) {
        if(mat[x][i]){
            res+=count_num_ways(i);
        }
    }
    return dp[x] = res;
}

bool is_possible() {

    rep(i,0,msize) {
        dp[i]=-1;
    }
    if(count_num_ways(0) == target_ways)
        return true;
    return false;
}
int cnt = 0;
void print_out() {
        ans_found = true;
        cout<<"POSSIBLE"<<endl;
        rep(i,0,msize) {
            rep(j,0,msize) {
                    cout<<mat[i][j];
            }
            cout<<endl;
        }
}

void create_num_mat(int x) {

    if(ans_found)
        return;
    if(x==-1){
        cnt++;
        cout<<cnt<<endl;
        convert_to_mat();
       /* cout<<"---------------------------------"<<endl;
        rep(i,0,msize){
            rep(j,0,msize) {
                cout<<mat[i][j];
            }
            cout<<endl;
        }
*/

        if(is_possible()) {
            print_out();
        }
        return;
    }
    rep(i,0,(1<<(msize-1))){
        nummat[x]=i;
        create_num_mat(x-1);
    }
}


int main() {
    //freopen("f2.in","r",stdin);
    int T;
    cin>>T;
    rep(t,0,T) {
        memset(nummat,0,sizeof nummat);
        memset(mat,0,sizeof mat);
        cin>>msize>>target_ways;
        cout<<"Case #"<<t+1<<": ";
        ans_found = false;
        create_num_mat(msize-2);
        if(!ans_found) {
            cout<<"IMPOSSIBLE"<<endl;
        }




    }
}
