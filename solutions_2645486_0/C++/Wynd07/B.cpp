#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
vector<int> vec;
int e, r,w,n,T, ma;
void recur(int ee, int v, int cur){
    //cout << ee << " " << v << " " << cur << endl;;
    if( cur == n ){
        ma =max(ma, v);
        return;
    }
    for(int i = 0; i<=ee; i++){
        recur(min(e, ee-i+r), v+i*vec[cur], cur+1);
    }
}
int main ()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out", "w", stdout);
    cin >> T;
    for(int aa = 0; aa<T; aa++){
        cin >> e >> r >> n;
        vec = vector<int>(n);
        for(int i = 0; i<n; i++)
            cin >> vec[i];
        ma = 0;
        recur( e, 0, 0);
        cout << "Case #"<<aa+1<<": " << ma << endl;
    }
}