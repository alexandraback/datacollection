#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstring>
using namespace std;

#define MAX 2000001

bool vis[MAX];

int num_digits(int a) {
    return int(log10(a));
}

bool same_digits(int a, int b) {
    return num_digits(a)==num_digits(b);
}

int solve(int low, int high, int start) {
    if(vis[start]) return 0;
    int cur=start;
    int num=0;
    do {
        if(cur>=low&&cur<=high&&same_digits(start,cur)) {
            vis[cur]=1;
            num++;
        }
        cur=(cur/10)+(cur%10)*pow(10.0,num_digits(start));
    }while(cur!=start);
    return num*(num-1)/2;
}

int solve() {
    memset(vis,0,sizeof(vis));
    int a,b;
    cin>>a>>b;
    int ret=0;
    for(int i=a;i<=b;i++) {
        ret+=solve(a,b,i);
    }
    return ret;
}

int main() {
    int cases;
    cin>>cases;
    for(int cnum=1;cnum<=cases;cnum++) {
        cout<<"Case #"<<cnum<<": "<<solve()<<endl;
    }
}
