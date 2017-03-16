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
map<ll,int> m;
int money[101];
ll C,D,V;
int main()
{
    freopen("txt.in","r",stdin);
    freopen("out","w",stdout);
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        cin >> C >> D >> V;
        for(int i=0;i<D;i++){
            cin >> money[i];
        }
        int cnt=0;
        int start=1;
        ll range=0;
        if(money[0]!=1){
            cnt++;
            start=0;
        }
        range=C;
        sort(money,money+D);
        for(int i=start;i<D;i++){

            if(range+1==money[i]){
                range=range+(range+1)*C;
            }
            else if(range<money[i]){
                cnt++;
                range=range+(range+1)*C;
                i--;
            } else {
                range=range+(money[i])*C;
            }
            //cout << range << " " << money[i];
            //cout << " " << cnt << endl;
        }
        while(range<V){
            range=range+(range+1)*C;
            cnt++;
        }
        cout << "Case #" << (t+1) << ": " << cnt << endl;
    }
    return 0;
}
