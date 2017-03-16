#include<iostream>
#include<queue>
using namespace std;

int minStep[1000006];
queue<int> q;

int reverse(int n){
    int rev = 0;
    while(n){
        rev = rev * 10 + n%10;
        n = n/10;
    }
    return rev;
}

int main(){
    for(int i=0; i<1000006; i++){
        minStep[i] = -1;
    }
    minStep[1] = 1;
    q.push(1);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x>=1000000)continue;

        int nx = x + 1;
        if(minStep[nx]==-1){
            minStep[nx] = minStep[x]+1;
            q.push(nx);
        }
        nx = reverse(x);
        if(minStep[nx]==-1){
            minStep[nx] = minStep[x]+1;
            q.push(nx);
        }
    }
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        int x;
        cin>>x;
        cout<<"Case #"<<i<<": "<<minStep[x]<<endl;
    }

}
