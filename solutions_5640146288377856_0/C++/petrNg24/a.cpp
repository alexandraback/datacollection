
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <algorithm>
#define maxv 100000

using namespace std;


void input(){
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
}

int log2(int x) {
    int y=0;
    while (x!=0) {
        y++;
        x=x/2;
    }
    return y;
}

void solve(){
    int T,res;
    int R,C,W;

    cin>>T;

    for (int t=0; t<T; t++) {
        cin>>R>>C>>W;

        if (C%W==0) {
            res= (C/W)+W-1;
        } else {
            res=(C/W)-1+W+1;
        }
        res = max(res,(C/W)-2+W+1);
        res+=(R-1)*(C/W);
        cout<<"Case #"<<t+1<<": "<<res<<endl;
    }
}

void output(){

}

void process(){
    input();
    solve();
    output();
}

int main() {
    process();
    return 0;
}

