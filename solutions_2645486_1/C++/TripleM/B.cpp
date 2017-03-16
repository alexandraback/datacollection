#include <iostream>
using namespace std;
long long val[10000];
long long ans[10000];
int themax[10000][10001];
long long tot;
long long E,R,N; 
void solve(int x, int y, long long startE, long long endE) {
    if (x==y) return;
//    printf("Have %I64d energy at %d, %I64d energy at %d\n",startE,x,endE,y);
    // find max in this range
    int pos = themax[x][y];
//    printf("Max poss in between is %d\n",pos);
  //  system("PAUSE");
    // how much could we spend if nothing
    long long maxposs = min(E,startE + (pos-x)*R);
//    printf("Max we can have there is %I64d\n",maxposs);
    long long minposs = max(0LL,endE - (y-pos)*R);
//    printf("Min we can have there is %I64d\n",minposs);    
    
    assert(maxposs>=minposs);
    
    long long spend = maxposs - minposs;
    
//    printf("So spend %I64d there\n",spend);
    
    tot += spend * val[pos];
//    printf("So add %I64d * %I64d\n",spend,val[pos]);
    
    solve(x,pos,startE,maxposs);
    solve(pos+1,y,min(E,minposs+R),endE);
}
int main() {
    int T; scanf("%d",&T); for (int t=1; t<=T; t++) {
        scanf("%I64d %I64d %I64d",&E,&R,&N);
        for (int i=0; i<N; i++) scanf("%I64d",&val[i]);        
        
        ans[N-1] = 0;
        
        for (int i=0; i<N; i++) {
            themax[i][i+1] = i;
            for (int j=i+1; j<N; j++) {
                themax[i][j+1] = themax[i][j];
                if (val[j] > val[themax[i][j+1]]) themax[i][j+1]=j;
            }
        }
        tot = 0;
        solve(0,N,E,R);
        
        printf("Case #%d: %I64d\n",t,tot);
//        printf("Case #%d: %I64d\n",t,ans
        // suppose we have no energy at point i
        // what is the next one we put all our energy into
    }
}
