#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#define pb push_back
using namespace std;
int T,N,J;
int a[20],np[220];
vector<int> p;

long long rest(long long nr, int i, int x) {
    long long r = 0;
    long long curr = 1;
    while(nr) {
        if(nr%2) {
            r = (r + curr) % x;
        }
        curr = (curr*i)%x;
        nr /= 2;
    }
    return r;
}

void printBin(long long nr) {
    string s = "";
    while(nr) {
        s.pb('0' + (nr%2));
        nr /= 2;
    }
    reverse(s.begin(),s.end());
    cout<<s<<" ";
}

void solve(long long nr) {
    int ok=0;
    for(int i=2;i<=10;++i) {
        for(auto j: p) {
            if(!rest(nr,i,j)) {
                ++ok;
                a[i] = j;
                break;
            }
        }
    }
    if(ok == 9) {
        printBin(nr);
        for(int i=2;i<=10;++i) {
            printf("%d ",a[i]);
        }
        --J;
        printf("\n");
    }
}


int main() {
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    for(int i=2;i<=200;++i) {
        if(!np[i]) {
            p.pb(i);
        }
        for(int j=i;i*j<=200;++j) {
            np[i*j] = 1;
        }
    }
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        printf("Case #%d:\n",t);
        scanf("%d%d",&N,&J);
        long long x = (1LL<<N)-1;
        while(J && x > 0) {
            solve(x);
            x-=2;
            
        }
    }
}
