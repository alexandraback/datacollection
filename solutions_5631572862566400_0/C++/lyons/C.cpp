#include <iostream>
#include <vector>
using namespace std;

int T, N;
        int maxlen = 0;

int main() {
    cin >> T;
    for (int ncase = 1; ncase <= T; ++ ncase) {
        cin >> N;
        int f[1010];
        for (int i = 0; i < N; ++ i) {
           cin >> f[i]; 
           -- f[i];
           //cout << i << '-' << f[i] << endl;
        }
        int belong[1010];
        vector< vector<int> > chains;
        memset(belong, -1, sizeof(belong));

        maxlen = 0;
        for (int i = 0; i < N; ++ i) {
            //cout << i << endl;
            if (belong[i] != -1) {
                continue;
            }
            int p = i;
            vector<int> chain;
            chain.push_back(i);
            belong[i] = -2;
            while (true) {
                p = f[p];
             //   cout << p << ' ' << belong[p] << endl;
                if (belong[p] == -2) {
                    // find max circle
                    int j;
                    for (j = 0; j < chain.size(); ++ j)
                        if (chain[j] == p) break;
             //       cout << "chain-j = " << j << endl;
                    if (j == chain.size() - 2) {
                        // open end;
                        chains.push_back(chain);
                        for (j = 0; j < chain.size(); ++ j)
                            belong[chain[j]] = chains.size() - 1;
                        break;
                    } else {
                        int len = chain.size() - j;
                        /*
                        cout << "update max: i=" << i << ", #chain" << chain.size() << ", j = " << j << ", len = " << len << endl;
           cout << "max-chain: ";
             for (int j = 0; j < chain.size(); ++ j)
               cout << " " << chain[j];
                 cout << endl;
                 */
                        if (len > maxlen) maxlen = len;
                        for (int j = 0; j < chain.size(); ++ j)
                            belong[chain[j]] = -1;
                    }
                    break;
                } else if (belong[p] != -1) {
                    int bb = belong[p];
                    int j;
                    for (j = 0; j < chains[bb].size(); ++ j)
                        if (chains[bb][j] == p) break;
                    if (j == chains[bb].size() - 1) {
                        chain.push_back(chains[bb][j]);
                        chain.push_back(chains[bb][j-1]);
                        chains.push_back(chain);

                        for (j = 0;j < chain.size(); ++ j)
                            belong[chain[j]] = chains.size() - 1;
                    } else if (chain.size() > j) {
                        // replace chains[bb] with chain
                        for ( ; j < chains[bb].size(); ++ j)
                            chain.push_back(chains[bb][j]);
                        for (j = 0;j < chain.size(); ++ j)
                            belong[chain[j]] = bb;
                        chains[bb] = chain;
                    }
                    break;
                }
                belong[p] = -2;
                chain.push_back(p);
            }
        }
        //cout << "#chains = " << chains.size() << endl;
        for (int i = 0; i < chains.size(); ++ i)
            for (int j = i + 1; j < chains.size(); ++ j)
                if (chains[i].size() < chains[j].size())
                    swap(chains[i], chains[j]);
        int len = 0;
        bool valid[1010];
        for (int i = 0; i < chains.size(); ++ i)
            valid[i] = true;
        for (int i = 0; i < chains.size(); ++ i) {
            if (!valid[i]) continue;
            int ni = chains[i].size();
            int curr = -1;
            for (int j = i + 1; j < chains.size(); ++ j) {
                if (!valid[j]) continue;
                int nj = chains[j].size();
                if (chains[j][nj - 1] == chains[i][ni - 1] && chains[j][nj-2] == chains[i][ni-2]) {
                    valid[j] = false;
                } else if (chains[j][nj-1] == chains[i][ni-2] && chains[j][nj-2] == chains[i][ni-1]) {
                    valid[j] = false;
                    if (curr < 0) curr = ni + nj - 2;
                }
            }
            if (curr < 0) curr = ni;
            len += curr;
        }
        /*
        for (int i = 0; i < chains.size(); ++ i) {
            cout << "chain " << i << ":";
            for (int j = 0; j < chains[i].size(); ++ j)
                cout << " " << chains[i][j];
            cout << endl;
        }*/
        if (len > maxlen) maxlen = len;

        cout << "Case #" << ncase << ": " << maxlen << endl;
    }
    return 0;
}
