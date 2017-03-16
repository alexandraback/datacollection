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
int T;
ll steps[1000010];
int rev(int n){
    int n2=0;
    while(n){
        n2=n2*10+n%10;
        n/=10;
    }
    return n2;
}
void f(int i, int step){
    //cout << i <<" " << steps[i] << " " << step   << endl;
    if(i>1000000)return;
    if(steps[i]!=0 && steps[i]<=step)return;
    steps[i]=step;

    f(i+1,step+1);
    f(rev(i),step+1);
    f(rev(rev(i+1)),step+1);
}
void fill(){
    //steps[1]=1;
    //f(1,1);
    ll mx=1000001;
    for(int i=0;i<mx;i++){
        steps[i]=mx+2;
    }
    steps[1]=1;
    for(int i=1;i<mx;i++){
        steps[i+1]=min(steps[i+1],steps[i]+1);
        steps[rev(i)]=min(steps[rev(i)],steps[i]+1);
        steps[rev(rev(i))]=min(steps[rev(rev(i))],steps[i]+1);
    }
}
int main()
{
    freopen("txt.in","r",stdin);
    freopen("out","w",stdout);
    fill();
    cin >> T;
    int nn;
    for(int t=0;t<T;t++){
            cin >> nn;
        cout << "Case #" << t+1 << ": " << steps[nn] << endl;
    }
    return 0;
}
