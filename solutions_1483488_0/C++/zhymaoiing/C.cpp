#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

typedef long long LL;

int main(){
    freopen("W:\\C-small-attempt0.in","r",stdin);
    freopen("W:\\C-small-attempt0.out","w",stdout);
//    freopen("W:\\B-large.in","r",stdin);
//    freopen("W:\\B-large.out","w",stdout);
    int tCase;
    scanf("%d",&tCase);
    for (int ct = 1;ct <= tCase;ct++){
        int A,B;
        scanf("%d%d",&A,&B);
        LL res = 0;
        for (int x = A;x <= B;x++){
            int D[16],dn = 0;
            int d = x;
            while (d) D[dn++] = d % 10,d /= 10;
            reverse(D,D + dn);
            for (int i = 0;i < dn;i++)
                D[dn + i] = D[i];
            //for (int i = 0;i < dn;i++)printf("%d ",D[i]);puts("");
            set <int> st;
            for (int i = 1;i < dn;i++){
                if (D[i] == 0) continue;
                int r = 0;
                for (int j = 0;j < dn;j++)
                    r = r * 10 + D[i + j];
                if (B >= r && r > x)
                    st.insert(r);
            }
            res += st.size();
        }
        printf("Case #%d: %I64d\n",ct,res);
    }
    return 0;
}
