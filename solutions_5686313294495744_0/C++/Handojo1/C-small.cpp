#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<map>

using namespace std;

bool ada[2][20];
string s1,s2;
int T,t1,t2,N;
map<string,int> kata1,kata2;
pair<int,int> nomor[20];

int proses() {
    int best = 0;
    for (int i=0;i<(1<<N);++i) {
        memset(ada,0,sizeof(ada));
        for (int j=0;j<N;++j) {
            if (i & (1<<j)) {
                ada[0][nomor[j].first] = true;
                ada[1][nomor[j].second] = true;
            }
        }
        
        bool flag = true;
        for (int j=0;j<N;++j) {
            if (i & (1<<j)) continue;
            if (!ada[0][nomor[j].first] || !ada[1][nomor[j].second]) flag = false;
        }
        
        if (flag) best = max(best,N-__builtin_popcount(i));
    }
    return best;
}

int main() {
    scanf("%d",&T);
    for (int l=1;l<=T;++l) {
        scanf("%d",&N);
        kata1.clear();
        kata2.clear();
        t1 = t2 = 0;
        
        for (int i=0;i<N;++i) {
            cin>>s1>>s2;
            if (kata1.find(s1) == kata1.end()) kata1[s1] = ++t1;
            if (kata2.find(s2) == kata2.end()) kata2[s2] = ++t2;
            nomor[i] = make_pair(kata1[s1],kata2[s2]);
            //cout<<nomor[i].first<<" "<<nomor[i].second<<endl;
        }
        
        int jawab = proses();
        printf("Case #%d: %d\n",l,jawab);
    }
    return 0;
}
