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

#define MAXN 10000
#define INFTY 1000000000

using namespace std;

long long a[MAXN];
int run = 0;


int firstIndex(long long x){
    for(int i=0; i<run; i++) if(a[i] >= x) return i;
    return -1;
}

int lastIndex(long long x){
    for(int i=run-1; i>=0; i--) if(a[i] <= x) return i;
    return -1;
}

bool IsPalin(long long x){
     long long t = x;
     long long y = 0;
     while(t>0){
          y = y*10 + t%10;
          t /= 10;
     }
     return x == y;
}

void Init(){
     for(int i=1; i<=10000000 ; i++) if(IsPalin(i)){
           if(IsPalin((long long)i*i)){
                 a[run] = (long long)i*i;
                 run++;
           }
     }
     //cout<<run<<endl;
     //for(int i=0; i<run; i++) cout<<a[i]<<endl;
}

int GetNum(long long A, long long B){
    int i = firstIndex(A);
    int j = lastIndex(B);
    if(i==-1 || j==-1 || i>j) return 0;
    return (j-i+1);
}

int main () {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    Init();
    int t;
    long long A, B;
    cin >> t;
    for(int ca=1; ca<=t; ca++){
        cin >> A>> B;            
        cout<<"Case #"<<ca<<": ";
        cout<<GetNum(A, B)<<endl;
    }
    return 0;
}
