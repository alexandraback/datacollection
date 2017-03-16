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
int tot[1000];
int N,e,standing;
int main()
{
    freopen("txt.in","r",stdin);
    //freopen("out","w",stdout);
    int T;
    cin >> T;
    string s;
    for(int t=0;t<T;t++){
        memset(tot,0,sizeof(tot));
        cin >> N >> s;
        N++;
        e=0,standing=0;
        for(int i=0;i<N;i++){
            tot[i]=s[i]-'0';
        }
        for(int i=0;i<N;i++){
            if(standing>=i){
                standing+=tot[i];
            } else {
                e=e+i-standing;
                standing=tot[i]+i;
            }
        }
        cout << "Case #" << (t+1) <<": " << e << endl;
    }
    return 0;
}
