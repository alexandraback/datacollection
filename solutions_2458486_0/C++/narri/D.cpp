#include <bitset>
#include <vector>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <unordered_set>

using namespace std;

const size_t LIMIT = 100000000;
struct Solver {
    int output[256];
    short have[256];
    int type[256];
    short thave[256][401];
    bitset<256> used;
    unordered_set<bitset<256> > cache;
    int numkeys;
    int N;
    bool rec(int left)
    {
        if(left == 0){
            return true;
        }
        if(cache.count(used)) {
            //cerr << "HIT" << endl;
            return false;
        }
        for(int i=0;i<N;++i)
        {
            if(used[i])continue;
            if(!have[type[i]])continue;
            //valid, type to do it
            const short *arr = &thave[i][1];
            const int T = arr[-1];
            have[type[i]]--;
            for(int j=0;j<T;++j)
            {
                ++have[arr[j]];
            }
            numkeys += T;
            used[i] = true;
            output[N-left] = i;
            if(rec(left-1)){return true;}
            numkeys -= T;
            used[i] = false;
            have[type[i]]++;
            for(int j=0;j<T;++j)
            {
                --have[arr[j]];
            }
        }
        if(cache.size() == LIMIT) {
            cache.erase(cache.cbegin());
        }
        cache.insert(used);
        return false;
    }
};

int main(int argc, char **argv)
{
    if(argc > 1){freopen(argv[1], "r", stdin);}
    int cases;
    cin >> cases;
    for(int cn=1;cn<=cases;++cn)
    {
        Solver s;
        memset(s.have, 0, sizeof(s.have));
        memset(s.thave, 0, sizeof(s.thave));
        int K;
        cin >> K >> s.N;
        for(int t=0;t<K;++t)
        {
            int x;cin >> x;
            s.have[x]++;
        }
        for(int i=0;i<s.N;++i)
        {
            cin >> s.type[i] >> s.thave[i][0];
            for(int j=0;j<s.thave[i][0];++j)
            {
                cin >> s.thave[i][j+1];
            }
        }
        s.numkeys = K;
        //s.cache.reserve(LIMIT+1);
        bool ok = s.rec(s.N);
        if(!ok)
        {
            printf("Case #%d: IMPOSSIBLE\n", cn);
        }
        else
        {
            cout << "Case #" << cn << ":";
            for(int i=0;i<s.N;++i)
            {
                cout << " " << s.output[i]+1;
            }
            cout << endl;
        }
    }
    return 0;
}
