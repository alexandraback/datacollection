#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <limits>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>

#define all(c) (c).begin(),(c).end()

using namespace std;

typedef long long llong;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int caseNum=1;
ifstream fin("B.in");
ofstream fout("B.out");

#define gout fout << "Case #" << caseNum++ << ": ", fout

int solve(string& s, int L) {
    if (L == 1) {
        if (s[0] == '+')
            return 0;
        else
            return 1;
    }

    if (s[L-1] == '+')
        return solve(s, L-1);

    int ans=500;
    for (int i=0; i<L; i++) {
        if (s[i] == '-') {
            string s2 = s.substr(0,L);
            reverse(s2.begin()+i, s2.begin()+L);
            for (int j=i; j<L; j++) {
                if (s2[j] == '+')
                    s2[j] = '-';
                else
                    s2[j] = '+';
            }
            ans = min(ans, solve(s2, L-1)+1);
        }
    }

    return ans;
}

int solve(string s) {
    return solve(s, s.size());
}

struct State {
    string str;
    int count;

    State(string s) {
        this->str = s;
        count = 0;
    }

    State(const State& st) {
        str = st.str;
        count = st.count;
    }
};

int main (int argc, char* argv[]) {
    int T;
    fin >> T;

    string s;
    getline(fin, s);

    while (T--) {
        getline(fin, s);
        int L = s.size();

        unordered_map<string,bool> visitedStates;

        queue<State> states;
        states.push(State(s));

        while (!states.empty()) {
            State s = states.front();
            states.pop();
            if (visitedStates[s.str] == true)
                continue;
            visitedStates[s.str] = true;

            int p=1;
            for (int i=1; i<s.str.size(); i++) {
                if (s.str[i] != s.str[i-1])
                    s.str[p++] = s.str[i];
            }
            int l = p;
            while (l != 0 && s.str[l-1] == '+')
                l--;
            if (l == 0) {
                gout << s.count << '\n';
                states = queue<State>();
                break;
            }
            s.str = s.str.substr(0,l);

            for (int i=1; i<=s.str.size(); i++) {
                string str(s.str);
                reverse(str.begin(), str.begin()+i);
                for (int j=0;j<i;j++) {
                    if (str[j] == '+')
                        str[j] = '-';
                    else
                        str[j] = '+';
                }
                State s2(str);
                s2.count = s.count+1;
                states.push(s2);
            }
        }

//         int count=0;
//         cout << '\n';
//         while (count < 100) {
//             int i;
//             for (i=L-1; i>=0; i--) {
//                 if (s[i] == '-') {
//                     string s2 = s.substr(0,i+1);
//                     for (int j=0; j<i+1; j++) {
//                         if (s2[j] == '+')
//                             s2[j] = '-';
//                         else
//                             s2[j] = '+';
//                     }
//                     reverse(all(s2));
//                     s.replace(0, i+1, s2);
//                     cout << i << ", " << s2 << ", " << s << endl;
//                     break;
//                 }
//             }
//             if (i == -1)
//                 break;
//             count++;
//         }
//         gout << count << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}
