#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstring>

#define MAXN 105
#define INFTY 1000000000

using namespace std;
long long s;
int n;
int a[MAXN];

int Solve(){
    sort(a, a+n);
    //for(int i=0; i<n; i++) cout<<a[i]<<" ";
    //cout<<endl;
    int i = 0;
    for(i=0; i<n; i++){
             if(s > a[i]) s += a[i];
             else break;
    }
    int res = n - i;
    int run = 0;
    for(;i<n;i++){
        res = min(res, run+n-i);
        if(s > a[i]){
             s += a[i];
        }
        else if(s<=1){
            run++;
        } 
        else{
            s += s-1;
            run++;
            if(s<=a[i]) i--;
            else s += a[i];
        }
    }
    res = min(res, run);
    return res;
}

int main () {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for(int ca=1; ca<=t; ca++){
        cin >> s >> n;
        for(int i=0; i<n; i++)
             cin >> a[i];
            
        cout<<"Case #"<<ca<<": ";
        cout<<Solve()<<endl;
    }
    return 0;
}
