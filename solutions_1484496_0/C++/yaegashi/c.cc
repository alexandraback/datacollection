#include <cstdio>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int
calc(vector<int> &S, int pat)
{
        int total = 0;
        for (int i = 0; i < S.size(); i++)
                if (pat & (1<<i))
                        total += S[i];
        return total;
}


void
output(vector<int> &S, int pat)
{
        for (int i = 0; i < S.size(); i++)
                if (pat & (1<<i))
                        cout << S[i] << " ";
        cout << endl;
}


int
main(int argc, char **argv)
{
        int T;

        string lineT;
        getline(cin, lineT);
        stringstream ssT(lineT);
        ssT >> T;

        for (int i = 0; i < T; i++) {

                string line;
                getline(cin, line);
                stringstream ss(line);

                int N;
                vector<int> S;
                ss >> N;
                for (int j = 0; j < N; j++) {
                        int s;
                        ss >> s;
                        S.push_back(s);
                }
                
                vector<int> totals;
                int patterns = 1 << N;
                int j, k;
                for (j = 0; j < patterns; j++) {
                        int total = calc(S, j);
                        for (k = 0; k < j; k++)
                                if (total == totals[k])
                                        goto out;
                        totals.push_back(total);
                }

out:
                cout << "Case #" << i+1 << ":" << endl;
                if (j == patterns && k == patterns) {
                        cout << "Impossible" << endl;
                        continue;
                }
                output(S, j);
                output(S, k);
        }

        return 0;
}
