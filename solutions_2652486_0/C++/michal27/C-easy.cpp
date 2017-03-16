#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define For(i,n) for(int i=0; i<(n); i++)
#define mp(a,b) make_pair((a),(b))
typedef long long ll;

int main() {
    int t1;
    scanf("%d",&t1);
    For(i1,t1) {
        printf("Case #%d:\n",i1+1);
        int r;
        int n,m,k;
        scanf(" %d %d %d %d",&r,&n,&m,&k);
        For(j1,r) {
            vector<vector<int> > D;
            For(i,k) {
                int x;
                scanf(" %d",&x);
                vector<int> P;
                while(x%2==0) {P.push_back(2); x/=2;}
                while(x%3==0) {P.push_back(3); x/=3;}
                while(x%5==0) {P.push_back(5); x/=5;}
                D.push_back(P);
            }
            /*For(i,D.size()) {
                For(j,D[i].size()) printf("%d ",D[i][j]); printf("\n");
            }*/
            int d=0,t=0,p=0,s=0;
            //pohladaj 3 a 5 a 4
            For(i,D.size()) {
                int p3=0,p5=0;
                For(j,D[i].size()) {
                    if(D[i][j]==3) p3++;
                    if(D[i][j]==5) p5++;
                }
                if(p<p5) p=p5;
                if(t<p3) t=p3;
            }
            int moze=3-t-p;
            For(i,D.size()) {
                int p2=0;
                For(j,D[i].size()) {
                    if(D[i][j]==2) p2++;
                }
                int p4=0;
                if(p2==moze+1) p4=1;
                else if(p2==moze+2) p4=2;
                else if(p2==moze+3) p4=3;
                if(s<p4) s=p4;
            }
            d=3-t-s-p;
            For(i,d) printf("2");
            For(i,t) printf("3");
            For(i,s) printf("4");
            For(i,p) printf("5");
            printf("\n");
        }
    }
return 0;
}
