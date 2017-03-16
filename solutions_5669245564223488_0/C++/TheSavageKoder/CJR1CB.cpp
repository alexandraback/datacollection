#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define MOD 1000000007

using namespace std;

string trains[100];
int N;

int pos(char c) {
    return (int)(c-'a');
}

//long long F(int L, int mskTrain, int mskLetters, char C) {
//    if(mskTrain == (2<<N)-1)
//        return 1;
//
//}

bool valid(string train) {
    bool seen[27];
    char last = 'z'+1;
    memset(seen, false, sizeof seen);

    for(int i = 0; i < train.length(); i++)
        if(seen[ pos(train[i]) ])
            return false;
        else if(train[i] != last)
            seen[ pos(last) ] = true, last = train[i];
    return true;
}

string format(int in) {
    if(!in)
        return "0";
    string res = "";
    while(in) {
        if(in%2)
            res += "1";
        else
            res += "0";
        in /= 2;
    }
    return res;
}

int main() {
    freopen("CJR1CB.in", "r", stdin);
    freopen("CJR1CB.out", "w", stdout);
    int T;
    cin >> T;
    for(int cse = 1; cse <= T; cse++) {
        int N;
        cin >> N;

        int msks[N], order[N];
        memset(msks, 0, sizeof msks);
        for(int i = 0; i < N; i++) {
            order[i] = i;
            cin >> trains[i];

            for(char c = 'a'; c<= 'z'; c++) {
                int p = trains[i].find(c);
                char lc = trains[i][ trains[i].length()-1 ];
                if(trains[i].find(c) != string::npos && p != 0 && c != lc )
                    msks[i] |= (1<<pos(c));
            }

            if(trains[i][0] != trains[i][ trains[i].length() - 1])
                msks[i] |= (1<<pos(trains[i][0]));
        }
//        for(char c = 'a'; c<= 'z'; c++)
//            cout << c << ' ';
//        cout << endl;
//        for(int i = 0; i < N; i++) {
//            for(int j = 0; j < format(msks[i]).length(); j++)
//                cout <<  format(msks[i])[j] << ' ';
//            cout << endl;
//        }

        bool ok = true;
        for(int i = 0; i < N && ok; i++)
            if(!valid(trains[i]))
                ok = false;

        int res = 0;
        if(ok)
            do {
                bool valid = true;
                int seen = 0;
                char last = 'z'+1;
//                cout << "-------------" << endl;
//                for(int i = 0; i < N; i++)
//                    cout << order[i] << ' ';
//                cout << endl;

                for(int i = 0; i < N && valid; i++) {

                    int oi = order[i];
                    char lc = trains[ oi ][ trains[ oi ].length() - 1 ],
                         fc = trains[ oi ][0];
//                    cout << format(seen) << ':' << format(msks[oi]) << endl;

                    if(lc == fc) {
                        if(seen&(1<<pos(lc)))
                            valid = false;
                        else if(lc != last)
                            seen |= (1<<pos(last)), last = lc;
                    } else {
                        if( (msks[ oi ]&seen) || ((1<<pos(lc))&seen) || last == lc )
                            valid = false;
                        else {
                            seen |= msks[oi] | (1<<pos(last));
                            last = lc;
                        }
                    }
                }
//                cout << valid << endl;

                res += valid;
            } while(next_permutation(order, order+N));
        cout << "Case #" << cse << ": " << res << endl;
    }
}
