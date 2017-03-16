#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const int INF = 1<<29;
const double EPS = 1e-8;
typedef vector<int> vec;
typedef pair<int,int> Pair;
typedef long long ll;

typedef tuple<int, int, int> tpl;

int main(){
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        int J, P, S, K;
        cin >> J >> P >> S >> K;
        set<tpl> garments;
        map<Pair, int> combCountJP, combCountPS, combCountSJ;
        for(int j=1;j<=J;j++){
            for(int p=1;p<=P;p++){
                for(int s=1;s<=S;s++){
                    tpl jps = tpl(j, p, s);
                    Pair jp = Pair(j, p);
                    Pair ps = Pair(p, s);
                    Pair sj = Pair(s, j);
                    if(garments.count(jps) == 0 &&
                        combCountJP[jp] < K &&
                        combCountPS[ps] < K &&
                        combCountSJ[sj] < K){
                        garments.insert(jps);
                        combCountJP[jp]++;
                        combCountPS[ps]++;
                        combCountSJ[sj]++;
                    }
                }
            }
        }
        cout << "Case #" << t+1 << ": " << garments.size() << endl;
        for(tpl jps: garments){
            cout << get<0>(jps) << " "  << get<1>(jps) << " " << get<2>(jps) << endl;
        }

    }
    return 0;
}