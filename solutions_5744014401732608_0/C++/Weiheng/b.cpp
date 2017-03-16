#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void construct(int n, unsigned long long k) {
    int i, j;
    k--;
    int matrix[100][100] = {0};
    matrix[0][n-1] = 1;
    unsigned long long sum = 1;
    int p = 1;
    while (k>=sum) {
        k-=sum;
        sum*=2;
        p++;
    }
    for (i=1; i<p; i++) {
        matrix[0][i] = 1;
        for (j=i+1; j<p; j++) {
            matrix[i][j] = 1;
        }
        matrix[i][n-1] = 1;
    }

    for (i=0; i<p; i++) {
        if ((k&(1<<i)) != 0) {
            matrix[i+1][p] = 1;
            matrix[p][n-1] = 1;
        }
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
}

int main() {
    int t, n;
    unsigned long long k;
    int ca = 1;
    int i, j;
    unsigned long long sum;
    scanf("%d", &t);
    while (ca <= t) {
        cin>>n>>k;
        sum = 1<<(n-2);
        cout<<"Case #"<<ca<<": ";
        if (sum < k) {
            cout<<"IMPOSSIBLE"<<endl;
            ca++;
            continue;
        }
        cout<<"POSSIBLE"<<endl;
        construct(n, k);
        ca++;
    }
    return 0;
}

