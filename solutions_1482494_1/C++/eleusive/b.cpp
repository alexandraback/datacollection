#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000

int n;
int a[MAX], b[MAX];
bool got[MAX][2];

int doit() {
    int ret=0;
    memset(got,0,sizeof(got));
    int stars=0;
    while(stars<2*n) {
        bool did=false;
        // get all reachable second stars
        for(int i=0;i<n;i++) if(!got[i][1]&&stars>=b[i]) {
            did=true;
            stars+=2-(got[i][0]);
            got[i][0]=got[i][1]=1;
            ret++;
        }
        if(did) continue;
        int best=-1;
        for(int i=0;i<n;i++) if(!got[i][0]&&stars>=a[i]) {
            if(best==-1||b[i]>b[best]) best=i;
        }
        if(best!=-1) {
            stars++;
            got[best][0]=1;
            ret++;
        }
        else return -1;
    }
    return ret;
}

int solve() {
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    int ret=doit();
    if(ret==-1) cout<<"Too Bad";
    else cout<<ret;
    cout<<endl;
}

int main() {
    int cases;
    cin>>cases;
    for(int i=1;i<=cases;i++) {
        cout<<"Case #"<<i<<": ";
        solve();
    }
}
