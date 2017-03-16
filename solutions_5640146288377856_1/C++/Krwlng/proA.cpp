#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
using namespace std;

int n, m, p;

void conduct() {
    scanf("%d%d%d", &n, &m, &p);
    if (p==1) { printf("%d\n", n*m); return; }
    printf("%d\n", (m-1)/p+p+m/p*(n-1));
}

int main() {
    int time; scanf("%d", &time);
    for (int i=1; i<=time; ++i) {
        printf("Case #%d: ", i);
        conduct();
    }
    return 0;
}
