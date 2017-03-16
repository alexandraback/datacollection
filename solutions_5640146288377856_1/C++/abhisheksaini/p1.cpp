#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long int R,T,C,W,i,j,k,count;
    cin>>T;
    for(i=1;i<=T;i++){
        cin>>R>>C>>W;
        k=R*(C/W)+W-1;
        if(C%W!=0) k++;
        cout<<"Case #"<<i<<": "<<k<<endl;
    }
    return 0;
}
