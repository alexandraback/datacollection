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
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,N;
    cin>>T;
    for(int ca=1;ca<=T;ca++) {
        cin>>N;
        cout<<"Case #"<<ca<<": ";
        if(N==0) cout<<"INSOMNIA"<<endl;
        else {
            int cnt = 10;
            bool flag[10];
            memset(flag,0,sizeof(flag));
            int M=0;
            while(cnt!=0) {
                M+=N;
                int tmp = M;
                while(tmp != 0) {
                    int x = tmp%10;
                    tmp = tmp / 10;
                    if(!flag[x]) {
                        flag[x] = 1;
                        cnt --;
                    }
                }
            }
            cout<<M<<endl;
        }
    }
    return 0;
}
