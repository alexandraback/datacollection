#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool visb[11],vis[11][11];
int al[1111][3],an;
int main () {
    int casenum;
    cin>>casenum;
    for (int casen=1;casen<=casenum;casen++) {
        int A,B,C;int K;
        cin>>A>>B>>C>>K;
        int l=min(K,C);
        an=0;
        memset(vis,0,sizeof vis);
        memset(visb,0,sizeof visb);
        printf("Case #%d: ",casen);

        for (int i=1;i<=A;i++) for (int j=1;j<=B;j++) {
            for (int p=1;p<=l;p++) {
                int x;
                for (int k=1;k<=C;k++) {
                    if (!vis[p][k]&&!visb[k]) {
                        visb[k]=vis[p][k]=true;
                        x=k;break;
                    }
                }
                al[an][0]=i;
                al[an][1]=j;
                al[an][2]=x;
                an++;
            }
            memset(visb,0,sizeof visb);
        }
        cout<<an<<endl;
        //if (an<est) cerr<<"aaaaaaa"<<casen<<endl;
        for (int i=0;i<an;i++)
            cout<<al[i][0]<<' '<<al[i][1]<<' '<<al[i][2]<<endl;
    }


}
