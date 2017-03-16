#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cstdint>
using namespace std;


int64_t counts[51];
void s() {
    int64_t M;
    int B;
    cin>>B>>M;
    vector<int> selected;
    for(int i=B-2;i>=0;i--) {
        if(M >= counts[i]) {
            M -= counts[i];
            selected.push_back(i);
        }
    }

    if(M != 0) {
        cout<<"IMPOSSIBLE\n";
        return;
    }
    cout<<"POSSIBLE\n";

    vector<vector<int> > board(B);
    for(int i=0;i<B;i++) board[i].resize(B,0);

    for(int i=0;i<B;i++) {
        for(int j=0;j<B;j++) {
            if(i<j) board[i][j] = 1;
        }
    }

    for(int i=0;i<B;i++) board[0][i] = 0;
    for(auto& l : selected) {
        int house = B-1-l;
        board[0][house] = 1;
    }
    for(int i=0;i<B;i++) {
        for(int j=0;j<B;j++) cout<<board[i][j];
        cout<<endl;
    }


}

int main() {
    counts[0]=1;
    counts[1]=1;
    for(int i=2;i<51;i++) counts[i]=counts[i-1]*2;

    int t;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cout<<"Case #"<<i<<": ";
        s();
    }
}
