#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <fstream>
using namespace std;
typedef long long LL;
const int inf=1000000000;//1e9
int sq(int n){
    int a[10];
    int k=0;
    while (n){
        a[k]=n%10;
        k++;
        n/=10;
    }
    int i=0,j=k-1;
    while (i<=j){
        if (a[i]!=a[j]) return 0;
        i++;j--;
    }
    return 1;
}

int f(int n){
    int cnt=0;
    for (int i=1;i*i<=n;i++){
        if (sq(i)&&sq(i*i)) cnt++;
    }
    return cnt;
}
int main(){
    ifstream icin("C-small-attempt0.in");
    ofstream icout("output.txt");
    int T,a,b;
    icin>>T;
    for (int t=1;t<=T;t++){
        icin>>a>>b;
        icout<<"Case #"<<t<<": "<<(f(b)-f(a-1))<<"\n";
    }
    icin.close();
    icout.close();
}
