#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    map<string, string> replace;
    replace["ii"]  = "-";
    replace["ij"]  = "k";
    replace["ik"]  = "-j";
    replace["ji"]  = "-k";
    replace["jj"]  = "-";
    replace["jk"]  = "i";
    replace["ki"]  = "j";
    replace["kj"]  = "-i";
    replace["kk"]  = "-";

    for (int t = 0; t < T; ++t) {
        int L, X;
        cin >> L >> X;
        string Stmp;
        cin >> Stmp;
        stringstream Sstream;
        for (int i = 0; i < X; ++i) {
            Sstream << Stmp;
        }
        string S = Sstream.str();

        bool all_npos = false;
        while (! all_npos) {
            //cout << "------------" << endl;
            int start = 0;
            if (S.size() > 0 && S[0] == 'i') {
                start = 1;
                if (S.size() > 1 && S[1] == 'j') {
                    start = 2;
                }
            }

            all_npos = true;
            size_t min_pos = string::npos;
            string min_src;
            for (auto r = replace.begin(), last = replace.end(); r != last; ++r) {
                string src = r->first;
                string dst = r->second;

                size_t pos = S.find(src, start);
                //cout << S << " : " << src << " : " << pos << endl;
                if (pos != string::npos && pos < min_pos) {
                    min_pos = pos;
                    min_src = src;
                }
            }
            size_t pos = min_pos;
            if (pos != string::npos) {
                S.replace(pos, min_src.size(), replace[min_src]);
                all_npos = false;
            }

            pos = S.find("-");
            int minus_count = 0;
            while (pos != string::npos) {
                minus_count++;
                S.replace(pos, 1, "");
                pos = S.find("-");
            }
            if (minus_count % 2 == 1) {
                S.push_back('-');
            }
        }

        cout << "Case #" << (t + 1) << ": " << (S.compare("ijk") == 0 ? "YES" : "NO") << endl;
        //cout << "Case #" << (t + 1) << ": " << S << " : " << (S.compare("ijk") == 0 ? "YES" : "NO") << endl;
    }

    return 0;
}
