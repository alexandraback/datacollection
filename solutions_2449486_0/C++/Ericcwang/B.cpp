#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <fstream>
using namespace std;
typedef long long LL;
const int inf=1000000000;//1e9
const int N = 109;
int coverx[N],covery[N];
vector< pair<int,int> > a[N];
int main(){
    ifstream icin("B-small-attempt0.in");
    ofstream icout("output.txt");
    int T,n,m;
    icin>>T;
    for (int t=1;t<=T;t++){
        icin>>n>>m;
        //cout<<n<<" "<<m<<endl;
        memset(coverx,0,sizeof coverx);
        memset(covery,0,sizeof covery);
        for (int i=0;i<N;i++) a[i].clear();
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                int tmp;
                icin>>tmp;
                a[tmp].push_back(make_pair(i,j));
            }
        }
        int ok=1;
        for (int i=N-1;i>=1&&ok;i--){
            for (int j=0;j<a[i].size()&&ok;j++){
                int x=a[i][j].first;
                int y=a[i][j].second;
               // cout<< x<<" "<<y<<endl;
                if (coverx[x]>i&&covery[y]>i) ok=0;
                if (!coverx[x]) coverx[x]=i;
                if (!covery[y]) covery[y]=i;
            }
        }
        icout<<"Case #"<<t<<": ";
        if (ok) icout<<"YES\n";else icout<<"NO\n";
    }
    icin.close();
    icout.close();
}
