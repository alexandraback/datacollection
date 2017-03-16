#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

int T;
int n;
int a[2600];
int main() {
	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

    scanf("%d",&T);
    int C = 1;
    while(T --) {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        for (int i = 0;i < 2 * n - 1;i ++) {
            for (int j = 0;j < n;j ++) {
                int tmp;
                scanf("%d",&tmp);
                a[tmp] ++;
            }
        }
        printf("Case #%d:",C++);
        for (int i = 0;i <= 2510;i ++) {
            if(a[i] % 2 == 1) {
                printf(" %d",i);
            }
        }
        puts("");
    }
}

