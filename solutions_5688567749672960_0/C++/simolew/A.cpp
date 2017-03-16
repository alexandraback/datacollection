#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cstring>
#include<cstdint>
#include<cstdlib>
using namespace std;

vector<int> dyn;
vector<int> prv;
int reverse(int num) {
    int ans=0;
    while(num > 0) {
        ans = ans * 10;
        ans += num % 10;
        num /= 10;
    }
    return ans;
}

int bfs() {
    queue<int> q;
    dyn[1]=1;
    q.push(1);
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        if(t>= 1111111) continue;
        if(t+1 < 1111111 && dyn[t+1] == -1) {
            dyn[t+1] = dyn[t]+1;
            prv[t+1] = t;
            q.push(t+1);
        }
        if(reverse(t) < 1111111 && dyn[reverse(t)] == -1) {
            dyn[reverse(t)] = dyn[t] + 1;
            prv[reverse(t)] = t;
            q.push(reverse(t));
        }

    }
}

int f() {
    int n;
    cin>>n;
/*    int resp=dyn[n];
    while(n != 1) {
        cout<<n<<" -> ";
        n = prv[n];
    }
    cout<<".\n";*/
    return dyn[n];
}
int main() {
    int T;
    dyn.resize(1111111,-1);
    prv.resize(1111111);
    bfs();
 //   for(int i=1;i<10;i++) {
 //       cout<<pw(10,i)<<": "<<g(pw(10,i))<<endl;
 //   }

    cin>>T;
    for(int i=1;i<=T;i++) {
        cout<<"Case #"<<i<<": ";
        cout<<f();
        cout<<endl;

    }
}
