/*
Author: LotK
LANG: C++
*/

#include <cstdio>
#include <algorithm>
using namespace std;

struct CC {
    int sum, index;
}c[1<<21];
int a[1000];
int cntW;
int check;
int cmp(CC i, CC j) {
    return i.sum < j.sum;
}

int gen(int cnt, int n, int sum, int index) {
    if(cnt == n) {
        if(sum>0) {
            c[cntW].sum = sum;
            c[cntW].index = index;
            cntW++;
        }
        return 0;
    }
    gen(cnt+1, n, sum, index);

    sum += a[cnt];
    index = index | (1<<cnt);
    gen(cnt+1, n, sum, index);
}
int BS(int l, int r, CC x) {
    while(l<=r) {
        int mid = (l+r)/2;
        if(c[mid].sum == x.sum) {

            while(c[mid].sum == x.sum && mid>0) mid--;
            if(c[mid].sum != x.sum) mid++;
           // printf("%d\n", mid);

            while( (c[mid].index & x.index) > 0 && mid<cntW && c[mid].sum == x.sum) mid++;
            if(mid>=cntW || c[mid].sum != x.sum) return 0;

            //printf("%d %d %d %d %d %d\n", mid, c[mid].index & x.index, c[mid].index, x.index, c[mid].sum, x.sum);
            check = 1;
            return mid;
        }
        else if(c[mid].sum < x.sum)
            l = mid+1;
        else
            r = mid-1;
    }
}
int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);

    int t, tt, i, j, n;
    scanf("%d", &tt);
    for(t=0 ; t<tt ; t++) {
        scanf("%d", &n);
        for(i=0 ; i<n ; i++) {
            scanf("%d", &a[i]);
        }
        cntW = 0;
        check = 0;
        gen(0, n, 0, 0);
        sort(c, c+cntW, cmp);

        int ansPos;
        for(i=0 ; i<cntW ; i++) {
            ansPos = BS(0, cntW, c[i]);
            if(check == 1) {
                break;
            }
        }

        printf("Case #%d:\n", t+1);
        if(check == 0) printf("Impossible\n");
        else {
            for(j=0 ; j<20 ; j++) {
                if( ((1<<j) & (c[i].index)) > 0) printf("%d ", a[j]);
            }
            printf("\n");

            for(j=0 ; j<20 ; j++) {
                if( ((1<<j) & (c[ansPos].index)) > 0) printf("%d ", a[j]);
            }
            printf("\n");
        }
    }
}
