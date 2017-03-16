#define OSW2

#include <iostream>
#include <functional>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;




int main() {
#ifdef OSW
    freopen("//Users//osw//Desktop//in.txt", "r", stdin);
#endif
#ifdef OSW2
    string file_name = "B-small-attempt0";
    freopen(("//Users//osw//Downloads//" + file_name + ".in").c_str(), "r", stdin);
    freopen(("//Users//osw//Downloads//" + file_name + ".out").c_str(), "w", stdout);
#endif
    
    int T, t = 0;
    cin >> T;

    while (T - (t++)) {
        int K, T, S;
        cin >> K >> T >> S;
        string keyboard, target;
        cin >> keyboard >> target;
        
        double cnt[255] = {0};
        double pr[255] = {0};
        for (auto ch:keyboard) ++cnt[ch];

        for (int i = 0; i < T; ++i) {
            pr[i] = cnt[target[i]] / double(K);
            //cout << pr[i] << ' ';
        }
        //cout << endl;



        double dp[105][105] = {0};


        for (int s=0; s<S; ++s) {
            for (int t = 0; t < T && t<=s; ++t) {
                double tmp = 0;
                if (t==0) 
                    tmp = pr[0];
                else 
                    tmp = dp[s-1][t-1]*pr[t];

                dp[s][t] = tmp;
            }
        }

        double maxx=0, mean=0;
        
        for (int s=0; s<S; ++s) mean += dp[s][T-1];

        int MAX[105] = {0};

        if (dp[T-1][T-1]!=0) MAX[T-1] = 1;

        for (int s = T; s < S; ++s) {
            int bk = max(s-T, T-1);
            for (int l=T-(s-bk); l<T; ++l) {
                if (   dp[s][T-1]!=0 
                    && dp[s-T+l][T-1]!=0
                    && target.substr(0,l) == target.substr(T-l,l))
                {
                    MAX[s] = max(MAX[s], MAX[s-T+l] + 1 );
                }
            }        
            //cout << s  << ' ' << MAX[s] << ' ';

        }
        //cout << endl;

        for (int s = 0; s < S; ++s) maxx = max(maxx,(double)MAX[s]);

        //int l=2;
        //cout << target.substr(0,l) << ' ' <<  target.substr(T-l,l) << endl;

        double ans = maxx-mean;
        
        cout << "Case #" << t << ": ";
        printf("%.20f\n",ans);
        //cout << ' ' << mean << ' ' << maxx << endl;
    }
}



