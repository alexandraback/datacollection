#include <bits/stdc++.h>

using namespace std;

const int me = 1025;
typedef long long Long;

int t;
string aa, bb, x, y;
Long dif;
pair<Long, Long> v;

Long val(string s){
    Long v = 0LL;
    for(int i = 0; i < s.size(); i ++)
        v = 10LL * v + s[i] - '0';
    return v;
}
void rec(string a, string b, int pos){
    if(pos == aa.size()){
        Long s1 = val(a), s2 = val(b);
        if(abs(s1 - s2) < dif){
            dif = abs(s1 - s2);
            x = a, y = b;
            v = make_pair(s1, s2);
            return;
        }
        else if(abs(s1 - s2) == dif && make_pair(s1, s2) < v){
            v = make_pair(s1, s2);
            x = a, y = b;
        }
        return;
    }
    for(int i = '0'; i <= '9'; i ++)
    for(int j = '0'; j <= '9'; j ++){
        string ca = a, cb = b;
        if(a[pos] == '?')
            ca[pos] = i;
        else ca[pos] = a[pos];
        if(b[pos] == '?')
            cb[pos] = j;
        else cb[pos] = b[pos];
        rec(ca, cb, pos + 1);
    }
}
int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for(int cc = 0; cc < t; cc ++){
        cin >> aa >> bb;
        dif = 1LL << 62;
        v = make_pair(dif, dif);
        rec(aa, bb, 0);
        cout << "Case #" << cc + 1 << ": " << x << " " << y << endl;
    }


    return 0;
}
