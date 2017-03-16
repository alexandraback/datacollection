#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector <pair <int , int> > v;
bool cmp (const pair <int , int> &a , const pair <int , int> &b)  {
    return (a.first != b.first) ? a.first < b.first : a.second > b.second;
}
int main () {
    // freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        int n;
        scanf ("%d" , &n);
        v.clear ();
        for (int i = 0 ; i < n ; i ++) {
            int d , h , m;
            scanf ("%d %d %d" , &d , &h , &m);
            for (int j = 0 ; j < h ; j ++) {
                v.push_back (make_pair (d , m + j));
            }
        }
        int ans = 0;
        if ((int)v.size () > 1) {
            sort (v.begin () , v.end () , cmp);
            LL A = v[0].second * (360LL - v[0].first) , B = 360;
            LL C = v[1].second * (360LL - v[1].first + 360) , D = 360;
            // C/D <= A/B
            if (C <= A) {
                ans = 1;
            }
            A = v[0].second * (360LL - v[0].first + 360);
            C = v[1].second * (360LL - v[1].first);
            if (A <= C)
                ans = 1;
        } 
        printf ("Case #%d: %d\n" , ++ cas , ans);

    }
    return 0;
}