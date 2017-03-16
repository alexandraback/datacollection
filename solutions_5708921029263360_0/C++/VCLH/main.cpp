#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        int a, b, c, k;
        scanf("%d %d %d %d", &a, &b, &c, &k);
        int ans=0, jp[a+1][b+1], js[a+1][c+1], ps[b+1][c+1], jps[a*b*c][3];
        for(int x=1; x<=a; x++) for(int y=1; y<=b; y++) for(int z=1; z<=c; z++){
            jp[x][y]=js[x][z]=ps[y][z]=0;
        }
        for(int x=1; x<=a; x++) for(int y=1; y<=b; y++) for(int z=1; z<=c; z++){
            if(jp[x][y]<k && js[x][z]<k && ps[y][z]<k){
                jp[x][y]++;
                js[x][z]++;
                ps[y][z]++;
                jps[ans][0]=x;
                jps[ans][1]=y;
                jps[ans][2]=z;
                ans++;
            }
        }
        printf("Case #%d: %d\n", i, ans);
        for(int j=0; j<ans; j++) printf("%d %d %d\n", jps[j][0], jps[j][1], jps[j][2]);
    }
    return 0;
}