#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fornn(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vi_it;
typedef vector<vi> vvi;

typedef long long i64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
int t,a,c;
long b;
long q[20];

long count(long inp){
    if(inp==0)return 0;
    int s[15],n=0;
    long tmp=inp;
    while(tmp){
        s[n++]=tmp%10;tmp/=10;
    }
    tmp=0;
    fornn(i,(n+1)/2,n){
        tmp=tmp*10+s[i];
    }
    long tmp2=0;
    for(int i=(n+1)/2-1;i>=0;i--){
        tmp2=tmp2*10+s[i];
    }
    if(tmp==1){
        return q[n]+tmp2;
    }
    if(tmp2==0){
        return count(inp-1)+1;
    }
    return q[n]+tmp+tmp2;
}


int main(int argc, char* argv[]){
    q[1]=1;
    q[2]=10;
    for(int i=3;i<16;i++){
        long s=pow(10,i-1)-1;
        q[i]=count(s)+1;
    }
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>b;
        long num=count(b);
        cout<<"Case #"<<i+1<<": "<<num<<endl;
    }
    return 0;
}
