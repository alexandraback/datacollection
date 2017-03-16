#include <cmath>
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>
#include <vector>
#include <list>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>

using namespace std;

#define sz(X) ((int)X.size())
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define fr(i,a,b) for(int i=a; i<=b; i++)
#define it(it) __typeof((it)->begin())
#define foreach(v) for(IT(v) it=(v)->begin(); it!=(v)->end(); it++)
#define all(x) (x).begin(),x.end()
#define pb(x) push_back(x)
#define VI vector<int> 
#define VVI vector<vector<int> >
#define VS vector<string>
typedef long long ll;


int main()
{
    int T;
    cin >> T;
    rep(zz,T) {
        int N;
        cin >> N;
        vector<pair<int,int> > vec;
        rep(i,N) {
            int a, b;
            cin >> a >> b;
            vec.push_back(make_pair(a,b));
        }
        vector<bool> visited(N);
        vector<bool> visited1(N);
        int moves=0;
        int done=0;
        int coins=0;
        int max;
        int marked;
        while (done < N) {
            int min=20000;
            rep(i,N) { 
                if (visited[i]) continue;
                if (vec[i].second <= coins) { visited[i]=true; done++; coins += visited1[i] ? 1 : 2; moves++; goto label;}
                else if (min>vec[i].second) min=vec[i].second; 
            }
            max=-1;
            marked=-1;
            rep(i,N) {
                if (visited1[i]) continue;
                if (vec[i].first <= coins) { if (visited[i]) { marked=i; break; } if (max<vec[i].second) { max=vec[i].second; marked=i; } }
            }
            if (marked == -1) {
                moves=-1;
                break;
            }
            visited1[marked]=true;
            moves++;
            coins++;
label:;
        }


        if (moves==-1)
            printf("Case #%d: Too Bad\n", zz+1);
        else
            printf("Case #%d: %d\n", zz+1, moves);
    }
}
