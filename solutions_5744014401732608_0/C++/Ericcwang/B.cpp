using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
typedef long long LL;

int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int t;
    cin>>t;
    for (int time=1;time<=t;time++){
        LL B,M;
        cin>>B>>M;
        cerr<<(1LL<<50)<<endl;
        LL maxim=1LL<<(B-2);
        if (M>maxim){
            cout<<"case #"<<time<<": IMPOSSIBLE"<<endl;
            continue;
        }
        cout<<"case #"<<time<<": POSSIBLE"<<endl;
        int a[100][100];
        M--;
        memset(a,0,sizeof a);
        for (int i=B-1;i>=2;i--){
            for (int j=i+1;j<=B;j++) a[i][j]=1;
            LL digit=B-i;
            LL lasti=(M>>(digit-1))%2;
            if (lasti) a[1][i]=1;
        }
        a[1][B]=1;
        //if (M==maxim) {for (int i=2;i<=B;i++) a[1][i]=1;}
        for (int i=1;i<=B;i++){
            for (int j=1;j<=B;j++){
                cout<<a[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
