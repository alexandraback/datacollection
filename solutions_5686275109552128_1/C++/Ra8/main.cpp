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
map<int,int> s;
int D,P;
int nums[1100];
int mmx(){
    int mn=9999;
    for(int mx=1001;mx>0;mx--){
        int tot=0;
        for(int i=0;i<D;i++){
            tot=tot+max((nums[i]-1)/mx,0);
        }
        mn=min(mn,tot+mx);
    }
    return mn;
}
int main()
{
    freopen("txt.in","r",stdin);
    //freopen("out_old","w",stdout);
    int T,tmp;
    cin >> T;
    for(int t=0;t<T;t++){
        s.clear();
        cin >> D;
        for(int i=0;i<D;i++){
            cin >> tmp;
            nums[i]=tmp;
        }
        cout << "Case #" << (t+1) <<": " << mmx() << endl;
    }
    return 0;
}
