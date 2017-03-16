#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>
#include<cmath>
using namespace std;

#define LL long long int 
#define PII pair<int,int> 
#define PB push_back
#define MP make_pair
#define INF 1000000000
int a[104][104];
int f[116][115];
int main(){
    int t,m,n,i,j,cmx,ct =0;
    scanf("%d",&t);
    while(t--){
        ct ++;
        printf("Case #%d: ",ct);
        scanf("%d %d",&m,&n);
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        priority_queue<PII> pqr;
        priority_queue<PII> pqc;
        for(i=0;i<m;i++){
            cmx = 0;
            for(j=0;j<n;j++)
                cmx = max(cmx,a[i][j]);
            pqr.push(MP(cmx,i));
        }
        for(i=0;i<n;i++){
            cmx=0;
            for(j=0;j<m;j++)
                cmx= max(cmx,a[j][i]);
            pqc.push(MP(cmx,i));
        }
        pqr.push(MP(-100,-100));
        pqc.push(MP(-100,-100));
        int cr,cc;
        for(i=0;i<105;i++){
            for(j=0;j<105;j++)
                f[i][j]= 101;
        }
        while(1){
            if(pqr.size() == 1&& pqc.size() == 1)
                break;
            if(pqr.top().first > pqc.top().first){
                cr = pqr.top().second;
                for(i=0;i<n;i++)
                    f[cr][i] = pqr.top().first; 
                pqr.pop();
            }
            else{
                cc = pqc.top().second;
                for(i=0;i<m;i++)
                    f[i][cc] = pqc.top().first;
                pqc.pop();
            }
        }
        for(i=0;i<m;i++)for(j=0;j<n;j++){
            if(f[i][j] != a[i][j]){
                i = 1000;
                break;
            }
        }
        if(i== 1001)
            printf("NO\n");
        else
            printf("YES\n");
        
    }
    return 0;
}
