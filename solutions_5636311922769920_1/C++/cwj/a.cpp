#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;


int main()
{
    freopen("D-large.in","r",stdin);
    freopen("D-large.out","w",stdout);
    int T,C,S,K;
    cin>>T;
    for(int ca=1;ca<=T;ca++) {
        cin>>K>>C>>S;
        cout<<"Case #"<<ca<<": ";
        int ans = K/C;
        if((K%C) != 0) ans++;
        if(ans>S) cout<<"IMPOSSIBLE"<<endl;
        else {
            long long B[105];
            memset(B,0,sizeof(B));
            B[0] = 1;
            for(int i=1;i<C;i++) B[i] = B[i-1]*((long long)(K));
            int cnt = 0;
            for(int i=0;i<ans;i++) {
                long long sum = 0;
                for(int j=0;j<C;j++) {
                    if(cnt==K) continue;
                    sum += ((long long)(cnt))*B[j];
                    cnt++;
                }
                sum++;
                cout<<" "<<sum;
            }
            cout<<endl;
        }
    }
    return 0;
}
