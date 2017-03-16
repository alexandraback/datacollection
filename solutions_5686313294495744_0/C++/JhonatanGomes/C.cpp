#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <stack>
#include <vector>
using namespace std;


int main(){
    int t, n, TC=1, ans;
    string w1, w2;
    vector<pair<string, string> > v;

    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        for(int i = 0 ; i < n ; i++){
            cin >> w1 >> w2;
            v.push_back( make_pair(w1, w2) );
        }

        sort(v.begin(), v.end());

        ans = 0;
        for(int i = 1 ; i < n ; i++){
            if(v[i].first == v[i-1].first){
                for(int j = 0 ; j < n ; j++){
                    if(j != i-1 && (v[i-1].second == v[j].second)){
                        ans++;
                    }
                    if(j != i && (v[i].second == v[j].second)){
                        ans++;
                    }
                }

            }
        }

        printf("Case #%d: %d\n", TC++, (int)round(ans/2.0));
        v.clear();
    }

    return 0;
}
