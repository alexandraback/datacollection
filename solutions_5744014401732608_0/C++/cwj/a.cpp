#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

unsigned long long M,W[60];
int rec[60][60];

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);

    W[0] = 1;
    for(int i=1;i<60;i++) {
        W[i] = W[i-1] * 2;
    }

    int T,B;
    cin>>T;
    for(int ca=1;ca<=T;ca++) {
        cin>>B>>M;
        cout<<"Case #"<<ca<<": ";
        if(M > W[B-2]) {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        cout<<"POSSIBLE"<<endl;
        memset(rec,0,sizeof(rec));
        for(int i=1;i<B;i++) {
            for(int j=(i+1);j<B;j++) {
                rec[i][j] = 1;
            }
        }
        if(M == W[B-2]) {
            for(int i=1;i<B;i++) rec[i][B] = 1;
        } else {
            for(int i=(B-1);i>=2;i--) {
                if(M >= W[i-2]) {
                    rec[i][B] = 1;
                    M -= W[i-2];
                }
            }
        }
        for(int i=1;i<=B;i++) {
            for(int j=1;j<=B;j++) cout<<rec[i][j];
            cout<<endl;
        }
    }
    return 0;
}
