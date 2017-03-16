#include<stdio.h>
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t;
    cin >> t;
    for(int zz=1;zz<=t;zz++){
        int a,b,c;
        int count=0;
        cin >> a >> b >> c;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                //printf("%d %d %d\n",i,j,i&j);
                if((i&j) < c) count++;
            }
        }
        printf("Case #%d: %d\n",zz,count);
    }

    return 0;
}
