#include <bits/stdc++.h>
using namespace std;

int N,M;
int B[11][11];long long F[11];

int main () {
    int casenum;
    cin>>casenum;
    for (int casen=1;casen<=casenum;casen++) {
        memset(B,0,sizeof B);
        memset(F,0,sizeof F);
        cin>>N>>M;
        int l=N*(N-1)/2;
        bool solved=0;
        for (int mask=0;mask<(1<<l);mask++) {
            int t=0;
            for (int i=1;i<=N;i++) for (int j=i+1;j<=N;j++) {
                B[i][j]=(bool)(mask&(1<<t));
                t++;
            }

            F[1]=1;
            for (int i=2;i<=N;i++) F[i]=0;
            for (int i=2;i<=N;i++) for (int j=1;j<i;j++) {
                if (B[j][i]) F[i]+=F[j];
            }
            if (F[N]==M) {
                solved=true;
                break;
            }
        }
        printf("Case #%d: ",casen);
        if (solved) {
            cout<<"POSSIBLE"<<endl;
            for (int i=1;i<=N;i++) {
                for (int j=1;j<=N;j++) cout<<B[i][j];
                cout<<endl;
            }
        }
        else cout<<"IMPOSSIBLE"<<endl;
    }


}
