#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

const int inf=10000;

int r,c,w;

int check1(int c){
    return c/w;
}

int check2(int c){
    if(c%w==0)return c/w+w-1;
    return c/w+w;
}

int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    static int T,Cas;
    scanf("%d",&T);
    for(Cas=1;Cas<=T;Cas++){
        scanf("%d%d%d",&r,&c,&w);
        printf("Case #%d: %d\n",Cas,check1(c)*(r-1)+check2(c));
    }
    return 0;
}
