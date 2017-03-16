#include <bits/stdc++.h>

using namespace std;

void solvre(){
    int n, x;
    int val[3000] = {0};
    scanf("%d", &n);
    for(int j = 2*n-1; j>0; j--){
        for(int i = 0; i<n; i++){
            scanf("%d", &x);
            val[x]++;
        }
    }
    for(int i = 0; i<3000; i++){
        if(val[i]%2!=0){
            printf(" %d", i);
        }
    }
    printf("\n");
}

int main(){
    int n;
    string s;

    cin>>n;
    for(int i = 1; i<=n; i++){
        printf("Case #%d:", i);
        solvre();
    }
}
