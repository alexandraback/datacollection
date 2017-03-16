#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

int t, n, tab[3000], a;
vector<int> v;

int main() {
    int i, j, k;
    scanf("%d", &t);
    for (j=0; j<t; ++j) {
        scanf("%d", &n);
        fill(tab, tab+3000, 0);
        v.clear();
        for (i=0; i<2*n-1; ++i) {
            for (k=0; k<n; ++k) {
                scanf("%d", &a);
                tab[a]++;
            }
        }
        for (i=0; i<3000; ++i) {
            if (tab[i]%2==1) {
                v.push_back(i);
            }
        }
        printf("Case #%d:", j+1);
        for (i=0; i<v.size(); ++i) {
            printf(" %d", v[i]);
        }
        printf("\n");
    }
    return 0;
}
