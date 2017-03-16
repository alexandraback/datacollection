#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
typedef long long ll;
using namespace std;
int T,X,R,C;
string gaby="GABRIEL";
string rich="RICHARD";
string solve(){
    int N=C*R;
    if(X>=7)return rich;
    if(X==1)return gaby;
    if(X==2){
        if(N%2==0)return gaby;
        return rich;
    }
    if(X==3){
        if(N%3==0 && C>=2 && R>=2)return gaby;
        return rich;
    }
    if(X==4){
        if(N%4==0 && C>=3 && R>=3)return gaby;
        return rich;
    }
    if(X==5){
        if(N%5==0 && C>=4 && R>=4)return gaby;
        return rich;
    }
    if(X==6){
        if(N%6==0 && C>=4 && R>=4)return gaby;
        return rich;
    }
    return "..............................................................................................................................................................................................................................................................................";
}
int main()
{
    freopen("txt.in","r",stdin);
    freopen("out","w",stdout);

    cin >> T;
    for(int t=0;t<T;t++){
        cin >> X>>R>>C;
        cout << "Case #" << (t+1) <<": " << solve() << endl;
    }
    return 0;
}
