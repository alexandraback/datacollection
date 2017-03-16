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

int B[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int T,N,J;
    string s;
    cin>>T;
    for(int ca=1;ca<=T;ca++) {
        cin>>N>>J;
        cout<<"Case #"<<ca<<":"<<endl;
        N = N/2;
        int str[50];
        memset(str,0,sizeof(str));
        str[0] = 1;
        str[N-1] = 1;
        for(int i=0;i<J;i++) {
            for(int j=1;j<(N-1);j++) {
                if((i&B[j-1]) != 0) str[j]=1;
                else str[j]=0;
            }
            for(int j=0;j<N;j++) {
                if(str[j]==1) cout<<"11";
                else cout<<"00";
            }
            for(int j=3;j<=11;j++) {
                cout<<" "<<j;
            }
            cout<<endl;
        }
    }
    return 0;
}
