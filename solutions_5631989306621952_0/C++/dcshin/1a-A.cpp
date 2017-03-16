#include <iostream>
#include <cstring>

using namespace std;

int T, tcase, N;
string S, tstr, res;

int main()
{
    cin >> T;
    tcase = 1;
    while (tcase<=T) {
        cin >> S;

        res = "";
        for (int i=0; i<S.size(); ++i) {
            tstr = S.substr(i,1);
            if (res[0]<=S[i]) {
                res.insert(res.begin(),tstr.c_str()[0]);
            } else {
                res.append(tstr.c_str());
            }
        }

        cout << "Case #" << tcase++ << ": " << res << endl; 
    }
}
