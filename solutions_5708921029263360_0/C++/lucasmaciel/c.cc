#include <bits/stdc++.h>
using namespace std;

int tab[51][51];

int powerlevel(long long m){
    int c = 0;
    for (long long p = 1; p <= m; p<<=1){
        c++;
    }
    return c-1;
}

int main(){
    int t, cases = 1;
    cin >> t;
    while (t--){
        int J, P, S, K;
        cin >> J >> P >> S >> K;

        vector<int> vlrJP(J*P, 0), vlrJS(J*S, 0), vlrPS(P*S, 0);

        vector< tuple<int, int, int> > ans;

        for (int j = 0; j < J; j++){
            for (int p = 0; p < P; p++){
                for (int s = 0; s < S; s++){
                    if (vlrJP[j*P+p] >= K || vlrJS[j*S+s] >= K || vlrPS[p*S+s] >= K)
                        continue;
                    vlrJS[j*S+s]++;
                    vlrPS[p*S+s]++;
                    vlrJP[j*P+p]++;
                    ans.push_back(make_tuple(j, p, s));
                }
            }
        } 

        cout << "Case #" << cases++ << ": " << ans.size() << endl;
        for (auto t : ans){
            int j, p, s;
            tie(j, p, s) = t;
            cout << j+1 << " " << p+1 << " " << s+1 << endl;
        }
        
    }
    return 0;
}
