// =====================================================================================
//
//       Filename:  B.cpp
//         Author:  Reyno Tilikaynen, r.tilikaynen@gmail.com
//   Organization:  University of Waterloo
//
// =====================================================================================

#include <bits/stdc++.h>

using namespace std; 

typedef long long ll;

vector <int> l (18);
vector <int> r (18);
int n;

ll diff (pair <ll, ll> p){
    return abs(p.first - p.second);
}

ll big (vector <int> v, int ind){
    ll ret = 0;
    for (int i = ind; i < n; i++){
        if (v[i] == -1)
            v[i] = 9;
        ret = ret*10 + v[i];
    }
    return ret;
}

ll small (vector <int> v, int ind){
    ll ret = 0;
    for (int i = ind; i < n; i++){
        if (v[i] == -1)
            v[i] = 0;
        ret = ret*10 + v[i];
    }
    return ret;
}

ll val (int v, int i){
    return ((long long) v)*pow (10, n-i-1);
}

pair <ll, ll> rec (int i){
    if (i == n)
        return pair <ll, ll> (0, 0);
    if (l[i] >= 0 && r[i] >= 0){
        if (l[i] > r[i])
            return pair <ll, ll> (val (l[i], i) + small (l, i+1), val (r[i], i) + big (r, i+1));
        if (l[i] < r[i])
            return pair <ll, ll> (val (l[i], i) + big (l, i+1), val (r[i], i) + small (r, i+1));
        pair <ll, ll> ret = rec (i+1);
        return pair <ll, ll> (val (l[i], i) + ret.first, val (r[i], i) + ret.second); 
    }
    if (l[i] == -1 && r[i] >= 0){
        pair <ll, ll> smaller (val (r[i] - 1, i) + big (l, i+1), val(r[i], i) + small (r, i+1));
        pair <ll, ll> next = rec (i+1);
        pair <ll, ll> same (val(r[i], i) + next.first, val(r[i], i) + next.second);
        pair <ll, ll> bigger (val (r[i] + 1, i) + small (l, i+1), val(r[i], i) + big (r, i+1));
        pair <ll, ll> best = same;
        if (r[i] != 0 && diff (smaller) <= diff (best))
            best = smaller;
        if (r[i] != 9 && diff (bigger) < diff (best))
            best = bigger;
        return best;
    }
    if (l[i] >= 0 && r[i] == -1){
        pair <ll, ll> smaller (val (l[i], i) + big (l, i+1), val(l[i]+1, i) + small (r, i+1));
        pair <ll, ll> next = rec (i+1);
        pair <ll, ll> same (val(l[i], i) + next.first, val(l[i], i) + next.second);
        pair <ll, ll> bigger (val (l[i], i) + small (l, i+1), val(l[i]-1, i) + big (r, i+1));
        pair <ll, ll> best = same;
        if (l[i] != 0 && diff (bigger) <= diff (best))
            best = bigger;
        if (l[i] != 9 && diff (smaller) < diff (best))
            best = smaller;
        return best;
    }
    pair <ll, ll> smaller (val (0, i) + big (l, i+1), val(1, i) + small (r, i+1));
    pair <ll, ll> next = rec (i+1);
    pair <ll, ll> same (val(0, i) + next.first, val(0, i) + next.second);
    pair <ll, ll> bigger (val (1, i) + small (l, i+1), val(0, i) + big (r, i+1));
    pair <ll, ll> best = same;
    if (l[i] != 0 && diff (smaller) < diff (best))
        best = smaller;
    if (l[i] != 9 && diff (bigger) < diff (best))
        best = bigger;
    return best;
}

int main (){ 
    int tt; 
    cin >> tt; 
    for (int cases = 1; cases <= tt; cases++){
        printf ("Case #%d: ", cases);
        string s, t;
        cin >> s >> t;
        for (int i = 0; i < s.length (); i++)
            l[i] = (s[i] == '?')?(-1):(s[i] - 48);
        for (int i = 0; i < t.length (); i++)
            r[i] = (t[i] == '?')?(-1):(t[i] - 48);
        n = s.length ();
        pair <ll, ll> ans = rec (0);
        s = to_string (ans.first);
        t = to_string (ans.second);
        while (s.length () < n)
            s = "0" + s;
        while (t.length () < n)
            t = "0" + t;
        cout << s + " " + t << "\n";
    }
}
