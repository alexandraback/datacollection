#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;


int main(){
	int T; cin>>T;
    for(int t=0;t<T;t++){
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++) {cin>>a[i]; a[i]--;}
        int is_bff[N] = {};
        for(int i=0;i<N;i++) is_bff[a[i]]++;
        int best_ring = 0;
        unordered_map<int, int> m;
        for(int s = 0; s<N; s++){
            int w = s;
            int len = 1;
            bool b[N] = {};
            b[w] = 1;
            while(!b[a[w]]){
                w = a[w];
                b[w] = 1;
                len++;
            }
            if (a[w]==s){
                best_ring = max(len, best_ring);
                if (len==2) m[w] = max(len, m[w]);
            }
            if (is_bff[s]==0 && a[a[w]]==w){
                if (len>m[w]) m[w]=len;
            }
        }
        int lines = 0;
        for(auto it = m.begin();it != m.end();it++){
            if (it->second==0) continue;
            lines += it->second;
            if (m[a[it->first]]>=2){
                lines+=m[a[it->first]]-2;
                m[a[it->first]] = 0;
            }
        }
        printf("Case #%d: %d\n", t+1, max(lines, best_ring));
    }
	
}