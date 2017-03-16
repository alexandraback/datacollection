#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll tuple_to_number(vector<ll> v, ll K)
{
    ll result=0LL;
    //for(const auto& it: v) result=result*K+it;
    for(int i=(int)v.size()-1; i>=0; i--) result=result*K+v[i];
    return result;
}

vector<ll> solve(ll K, ll C, ll S)
{
    if(S*C>=K)
    {
        vector<ll> result;
        for(int i=0; i<K; i+=C)
        {
            vector<ll> curr;
            for(int j=i; j<i+C; j++) curr.push_back(j < K ? j : 0);
            result.push_back(tuple_to_number(curr, K)+1);
        }
        return result;
    }
    else return vector<ll>();
}

int main()
{
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        ll K, C, S;
        cin >> K >> C >> S;
        auto temp=solve(K, C, S);
        cout << "Case #" << t << ": ";
        if(temp.size()==0) cout << "IMPOSSIBLE";
        else for(const auto& it: temp) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
