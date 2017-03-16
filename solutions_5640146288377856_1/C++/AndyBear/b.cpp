#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#pragma comment(linker, "/STACK:1024000000,1024000000")

#define     IT              iterator
#define     PB(x)           push_back(x)
#define     CLR(a,b)        memset(a,b,sizeof(a))

using namespace std;

typedef     long long               ll;
typedef     unsigned long long      ull;
typedef     vector<int>             vint;
typedef     vector<ll>              vll;
typedef     vector<ull>             vull;
typedef     set<int>                sint;
typedef     set<ull>                sull;

int main() {
    freopen("A-large.in","r",stdin);
    freopen("a.out","w",stdout);
    int T;
    cin>>T;
    for (int t = 1; t <= T; t++) {
        int r,c,w;
        cin>>r>>c>>w;
        cout<<"Case #"<<t<<": "<<c/w*(r-1)+(c+w-1)/w+(w-1)<<endl;
    }
}
