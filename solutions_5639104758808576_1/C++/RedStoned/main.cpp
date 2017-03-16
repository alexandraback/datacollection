#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
using namespace std;
int n;
string s;

int main()
{
//    freopen("file.in","r",stdin);
//    freopen("file.out","w",stdout);
    int T,tc(1);
    cin >> T;
    while(T--){
        cin >> n >> s;
        int cnt(0),tot(0);
        for(int i=0;i<n+1;i++){
            int x = s[i] - '0';
            if(x==0) continue;
            int extra(0);
            if(tot<i) extra = i-tot;
            cnt += extra;
            tot += x + extra;
        }
        cout << "Case #" << tc++ << ": " << cnt << endl;
    }
    return 0;
}
