#include <bits/stdc++.h>
using namespace std;

int t,c;
long long n;
bool v[10];

void f(long long i){
    stringstream ss;
    ss << i;
    string s = ss.str();
    for(char ch : s){
        if(!v[ch-'0']){
            v[ch-'0'] = 1;
            c--;
        }
    }
}

int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&t);
    for(int i = 0; i < t; i++){
        scanf("%lld",&n);
        printf("Case #%d: ",i+1);
        if(n == 0){
            printf("INSOMNIA\n");
            continue;
        }
        memset(v,0,sizeof(v));
        c = 10;
        for(long long j = n; 1; j += n){
            f(j);
            if(c == 0){
                printf("%lld\n",j);
                break;
            }
        }
    }
}