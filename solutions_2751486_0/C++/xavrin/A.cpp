#include <cstdio>
#include <utility>
#include <queue>
#include <set>
#include <list>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef long long LL;
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); ––x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)x.size()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define MP make_pair
#define PII pair<int, int>

int main(){
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; k++){
        vector<bool> T;
        getchar();
        char t = getchar();
        while (t != ' '){
            if (t == 'a' || t == 'i' || t == 'o' || t == 'e' || t == 'u')
                T.PB(false);
            else
                T.PB(true);
            t = getchar();
        }
        int n;
        scanf("%d", &n);
        long long sum = 0;
        int i(0), j(0);
        int counter = 0;
        while ( i < T.size() && j < T.size()){
            if (T[j])
                counter++;
            else
                counter = 0;
            if (counter == n){
                sum += (LL)(j-i-n+2) * (LL) (T.size() - j);
                i = j-n+2;
                counter--;
            }
            j++;
        }
        cout << "Case #" << k << ": " << sum << endl;
    }
    return 0;
}
