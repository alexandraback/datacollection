// 1A_A.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

bool next (vector <int>& perm) {
    int i;
    for (i = perm.size () - 1; i > 0; --i) {
        if (perm [i] > perm [i - 1])
            break;
    }
    if (i == 0)
        return false;
    int k = perm [i - 1];
    int min = perm [i];
    int mini = i;
    for (int j = i + 1; j < perm.size (); ++j) {
        if (perm [j] < min && perm [j] > k) {
            min = perm [j];
            mini = j;
        }
    }
    swap (perm [i - 1], perm [mini]);
    vector <int>::iterator iter = perm.begin ();
    for (int j = 0; j < i; ++j) {
        ++iter;
    }
    sort (iter, perm.end ());
    return true;
}

char process_string (vector <bool>& used, const vector <string>& trains, char first, map <char, int>& one_train, long long& ans, const vector <bool>& not_one, set <char>& was) {
    int n = trains.size ();
    vector <int> may;
    for (int i = 0; i < one_train [first]; ++i) {
        ans *= i + 1;
    }
    for (int i = 0; i < n; ++i) {
        if (not_one [i] && trains [i][0] == first) {
            may.push_back (i);
        }
    }
    if (may.size () == 0) {
        return '$';
    }
    if (may.size () > 1) {
        return '^';
    }
    used [may.front ()] = true;
    string train = trains [may.front ()];
    for (int i = 1; i < train.length (); ++i) {
        if (was.find (train [i]) == was.end ()) {
            was.insert (train [i]);
            continue;
        }
        if (train [i] != train [i - 1]) {
            return '^';
        }
    }
    return train [train.length () - 1];
}

int main(int argc, char* argv[])
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        vector <string> trains;
        set <char> firsts;
        map <char, int> one_train;
        vector <bool> not_one (n, true);
        vector <bool> used (n);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            trains.push_back (s);
            firsts.insert (s [0]);
        }
/*        vector <int> perm;
        for (int i = 0; i < n; ++i) {
            perm.push_back (i);
        }
        long long ans = 0;
        do {
            string s;
            for (int i = 0; i < n; ++i) {
                s += trains [perm [i]];
            }
            set <char> was;
            bool b = true;
            for (int i = 0; i < s.length (); ++i) {
                if (was.find (s [i]) == was.end ()) {
                    was.insert (s [i]);
                    continue;
                }
                if (s [i] != s [i - 1])
                    b = false;
            }
            ans += b;
        } while (next (perm));*/
        for (int i = 0; i < n; ++i) {
            bool b = false;
            for (int j = 0; j < trains [i].size (); ++j) {
                if (trains [i][j] != trains [i][0]) {
                    b = true;
                    break;
                }
            }
            not_one [i] = b;
            used [i] = !b;
            if (!b) {
                if (one_train.find (trains [i][0]) == one_train.end ()) {
                    one_train.insert (make_pair (trains [i][0], 1));
                }
                else {
                    ++one_train [trains [i][0]];
                }
            }
        }
        bool null_ans = false;
        for (int i = 0; i < n; ++i) {
            set <char> c;
            for (int j = 0; j < trains [i].length (); ++j) {
                if (c.find (trains [i][j]) == c.end ()) {
                    c.insert (trains [i][j]);
                    continue;
                }
                if (trains [i][j] != trains [i][j - 1]) {
                    null_ans = true;
                }
            }
        }
        if (null_ans) {
            cout << "Case #" << t + 1 << ": 0" << endl;
            continue;
        }
        for (int i = 0; i < n; ++i) {
            bool b = false;
            if (firsts.find (trains [i][0]) != firsts.end ()) {
               for (int j = 0; j < n; ++j) {
                    if (i != j && not_one [j]) {
                        int k = 0;
                        if (!not_one [i]) {
                            while (k < trains [j].length () && trains [i][0] == trains [j][k]) {
                                ++k;
                            }
                        }
                        for (; k < trains [j].length (); ++k) {
                            if (trains [i][0] == trains [j][k]) {
                                firsts.erase (trains [i][0]);
                                b = true;
                                break;
                            }
                        }
                    }
                    if (b)
                        break;
                }
            }
        }
        if (firsts.empty ()) {
            cout << "Case #" << t + 1 << ": 0" << endl;
            continue;
        }
        long long ans = 1;
        set <char> was;
        for (set <char>::const_iterator iter = firsts.begin (); iter != firsts.end (); ++iter) {
            char c = *iter;
            was.insert (c);
            while (c != '$' && c != '^') {
                c = process_string (used, trains, c, one_train, ans, not_one, was);
            }
            if (c == '^') {
                ans = 0;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!used [i]) {
                ans = 0;
            }
        }
        for (int i = 0; i < firsts.size (); ++i) {
            ans = ans * (i + 1) % 1000000007;
        }
        cout << "Case #" << t + 1 << ": " << ans << endl;
    }
	return 0;
}

