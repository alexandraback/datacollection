#include <bits/stdc++.h>

#define cin fin
#define cout fout

using namespace std;

ifstream fin("A-small-attempt0.in");
ofstream fout("A-small-attempt0.out");

int T;
string S;
deque < char > ans;

int main()
{
    cin >> T;

    for (int t=1; t<=T; t++) {
        cin >> S;
        for (int i=0; i<S.size(); i++) {
            if (ans.empty()) ans.push_back(S[i]);
            else if (ans.front() <= S[i]) ans.push_front(S[i]);
            else ans.push_back(S[i]);
        }
        cout << "Case #" << t << ": ";
        while (!ans.empty()) {
            cout << ans.front();
            ans.pop_front();
        }
        cout << endl;
    }

    return 0;
}
